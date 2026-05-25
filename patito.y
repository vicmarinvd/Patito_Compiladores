%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuadruplos.h"

// Variables externas del lexer
extern int  yylineno;
extern int  errores_lexicos;
extern FILE *yyin;

void yyerror(const char *s);
int  yylex(void);

static int errsintx  = 0;
static int errsemant = 0;
%}

// Valor semantico compartido entre lexer y parser
%union { char sval[64]; int tval; }

// Tokens con valor
%token <sval> ID CTE_ENT CTE_FLT LETRERO

// Palabras reservadas
%token PROGRAM VARS INICIO FIN SI SINO MIENTRAS HAZ ESCRIBE NULA ENTERO FLOTANTE

// Operadores relacionales
%token OPEQ OPNEQ OPGT OPLT

// Precedencia de menor a mayor
%left OPEQ OPNEQ
%left OPGT OPLT
%left '+' '-'
%left '*' '/'
%right UMINUS

// Tipos de no-terminales que retornan valor
%type <sval> expresion cte
%type <tval> tipo func_tipo

%%

// ─────────────────────────────────────────────
// PROGRAMA
// ─────────────────────────────────────────────

programa
    : PROGRAM ID ';'
      {
        // PN-1: inicializar todas las estructuras
        initCubo();
        initTabla(&tablaGlobal);
        initDirectorio(&directorio);
        initStack(&pilaIDs);
        initPilaOperandos(&pilaOperandos);
        initPilaTipos(&pilaTipos);
        initPilaOperadores(&pilaOperadores);
        initPilaJumps(&pilaJumps);
        initFila(&filaCuadruplos);
        tablaActual = &tablaGlobal;
        printf("Leyendo: %s\n", $2);
      }
      opc_var list_funciones INICIO cuerpo FIN
      {
        printf("\nprograma Patito es valido.\n");
        imprimirDirectorio(&directorio);
        imprimirFila(&filaCuadruplos);
      }
    ;

// ─────────────────────────────────────────────
// VARIABLES
// ─────────────────────────────────────────────

opc_var : vars | /* epsilon */ ;
vars    : VARS mas_vars ;

mas_vars
    : ID
      {
        // PN-2: acumular el primer ID de la declaracion
        pushID(&pilaIDs, $1);
      }
      decl_id ':' tipo ';'
      {
        // PN-3: vaciar la pila de IDs a la tabla activa
        // detecta variable doblemente declarada
        while (!stackVacio(&pilaIDs)) {
            char *nombre = popID(&pilaIDs);
            if (insertarVariable(tablaActual, nombre, $5) != 0)
                fprintf(stderr,
                    "Error Semantico: variable doblemente declarada '%s'\n",
                    nombre);
        }
      }
      mas_vars
    | /* epsilon */
    ;

decl_id
    : ',' ID
      {
        // PN-4: acumular IDs adicionales (x, y, z : entero)
        pushID(&pilaIDs, $2);
      }
      decl_id
    | /* epsilon */
    ;

tipo
    : ENTERO   { $$ = TIPO_INT; }
    | FLOTANTE { $$ = TIPO_FLT; }
    ;

// ─────────────────────────────────────────────
// FUNCIONES
// ─────────────────────────────────────────────

list_funciones
    : funcs list_funciones
    | /* epsilon */
    ;

func_tipo
    : NULA { $$ = TIPO_NULA; }
    | tipo { $$ = $1; }
    ;

funcs
    : func_tipo ID
      {
        // PN-5: registrar funcion en el directorio
        // detecta funcion doblemente declarada
        // cambia el ambito activo a las locales de la funcion
        if (insertarFuncion(&directorio, $2, $1) != 0) {
            fprintf(stderr,
                "Error Semantico: funcion doblemente declarada '%s'\n", $2);
            errsemant++;
            funcionActual = NULL;
        } else {
            funcionActual = buscarFuncion(&directorio, $2);
            tablaActual   = &funcionActual->locales;
        }
      }
      '(' list_func_def ')' '{' hay_var cuerpo '}' ';'
      {
        // PN-6: cerrar ambito de la funcion, volver a global
        funcionActual = NULL;
        tablaActual   = &tablaGlobal;
      }
    ;

list_func_def
    : ID ':' tipo
      {
        // PN-7: registrar parametro formal en locales de la funcion
        // detecta parametro doblemente declarado
        if (funcionActual) {
            if (insertarVariable(&funcionActual->locales, $1, $3) != 0) {
                fprintf(stderr,
                    "Error Semantico: parametro duplicado '%s'\n", $1);
                errsemant++;
            }
        }
      }
      cont_lista
    | /* epsilon */
    ;

cont_lista : ',' list_func_def | /* epsilon */ ;
hay_var    : vars | /* epsilon */ ;

// ─────────────────────────────────────────────
// CUERPO Y ESTATUTOS
// ─────────────────────────────────────────────

cuerpo     : '{' bloq_cuerpo '}' ;
bloq_cuerpo: estatuto bloq_cuerpo | /* epsilon */ ;

estatuto
    : ID '=' expresion ';'
      {
        // PN-8: asignacion
        // verificar compatibilidad de tipos con el cubo semantico
        // generar cuadruplo de asignacion
        int t_expr = popTipo(&pilaTipos);
        int t_var  = getTipoVar($1);
        if (t_var == TIPO_ERR) {
            fprintf(stderr,
                "Error Semantico: variable no declarada '%s'\n", $1);
            errsemant++;
        } else if (consultarCubo(t_var, t_expr, OP_ASG) == TIPO_ERR) {
            fprintf(stderr,
                "Error Semantico: asignacion incompatible %s = %s\n",
                tipoToString(t_var), tipoToString(t_expr));
            errsemant++;
        }
        generarCuad("=", $3, "_", $1);
      }

    | ID '('
      {
        // PN-9a: preparar llamada como estatuto
        contadorArgs = 0;
        strncpy(funcCallBuf, $1, 63);
      }
      argum ')' ';'
      {
        // PN-9b: generar cuadruplo CALL (resultado descartado)
        char cnt[10];
        sprintf(cnt, "%d", contadorArgs);
        generarCuad("CALL", funcCallBuf, cnt, "_");
      }

    | condicion
    | ciclo
    | imprime
    ;

// ─────────────────────────────────────────────
// EXPRESIONES
// ─────────────────────────────────────────────

expresion
    // Suma
    : expresion '+' expresion
      {
        // PN-E1: verificar tipos con cubo, generar cuadruplo +
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_ADD);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '+'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("+", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, t_res);
      }

    // Resta
    | expresion '-' expresion
      {
        // PN-E2: verificar tipos con cubo, generar cuadruplo -
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_SUB);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '-'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("-", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, t_res);
      }

    // Multiplicacion
    | expresion '*' expresion
      {
        // PN-E3: verificar tipos con cubo, generar cuadruplo *
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_MUL);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '*'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("*", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, t_res);
      }

    // Division (siempre produce flotante)
    | expresion '/' expresion
      {
        // PN-E4: generar cuadruplo / (resultado siempre FLT)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_DIV);
        char *tmp = nuevoTemp();
        generarCuad("/", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, t_res);
      }

    // Mayor que
    | expresion OPGT expresion
      {
        // PN-E5: relacional >, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_GT);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '>'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad(">", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      }

    // Menor que
    | expresion OPLT expresion
      {
        // PN-E6: relacional <, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_LT);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '<'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("<", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      }

    // Igual
    | expresion OPEQ expresion
      {
        // PN-E7: relacional ==, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        char *tmp = nuevoTemp();
        generarCuad("==", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      }

    // Diferente
    | expresion OPNEQ expresion
      {
        // PN-E8: relacional !=, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        char *tmp = nuevoTemp();
        generarCuad("!=", $1, $3, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      }

    // Negacion unaria
    | '-' expresion %prec UMINUS
      {
        // PN-E9: genera cuadruplo UMINUS, conserva el tipo
        int t = popTipo(&pilaTipos);
        char *tmp = nuevoTemp();
        generarCuad("UMINUS", $2, "_", tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, t);
      }

    // Positivo unario (no-op)
    | '+' expresion %prec UMINUS
      { strcpy($$, $2); }

    // Parentesis
    | '(' expresion ')'
      { strcpy($$, $2); }

    // Llamada a funcion dentro de expresion
    | ID '('
      {
        // PN-E10a: preparar nombre y contador de args
        contadorArgs = 0;
        strncpy(funcCallBuf, $1, 63);
      }
      argum ')'
      {
        // PN-E10b: generar CALL, empujar tipo de retorno
        char cnt[10];
        sprintf(cnt, "%d", contadorArgs);
        Funcion *f = buscarFuncion(&directorio, funcCallBuf);
        char *tmp = nuevoTemp();
        generarCuad("CALL", funcCallBuf, cnt, tmp);
        strcpy($$, tmp);
        pushTipo(&pilaTipos, f ? f->tipoRetorno : TIPO_ERR);
      }

    // Variable
    | ID
      {
        // PN-E11: empujar nombre e tipo a las pilas
        strcpy($$, $1);
        int t = getTipoVar($1);
        if (t == TIPO_ERR)
            fprintf(stderr,
                "Error Semantico: variable no declarada '%s'\n", $1);
        pushTipo(&pilaTipos, t);
      }

    // Constante
    | cte
      { strcpy($$, $1); }
    ;

cte
    : CTE_ENT { strcpy($$, $1); pushTipo(&pilaTipos, TIPO_INT); }
    | CTE_FLT { strcpy($$, $1); pushTipo(&pilaTipos, TIPO_FLT); }
    ;

// ─────────────────────────────────────────────
// ARGUMENTOS DE LLAMADA
// ─────────────────────────────────────────────

argum
    : expresion
      {
        // PN-A1: generar ARG para el primer argumento
        generarCuad("ARG", $1, "_", "_");
        popTipo(&pilaTipos);
        contadorArgs++;
      }
      lista_exp
    | /* epsilon */
    ;

lista_exp
    : ',' expresion
      {
        // PN-A2: generar ARG para cada argumento adicional
        generarCuad("ARG", $2, "_", "_");
        popTipo(&pilaTipos);
        contadorArgs++;
      }
      lista_exp
    | /* epsilon */
    ;

// ─────────────────────────────────────────────
// CICLO MIENTRAS
// ─────────────────────────────────────────────

ciclo
    : MIENTRAS
      {
        // PN-C1: guardar posicion de inicio del ciclo en PilaJumps
        // este indice sera el destino del GOTO al final del cuerpo
        pushJump(&pilaJumps, filaCuadruplos.count);
      }
      '(' expresion ')'
      {
        // PN-C2: condicion evaluada
        // generar GOTOF con destino pendiente (??)
        // guardar su indice para backpatching posterior
        popTipo(&pilaTipos);
        generarCuad("GOTOF", $4, "_", "???");
        pushJump(&pilaJumps, filaCuadruplos.count - 1);
      }
      HAZ cuerpo ';'
      {
        // PN-C3: fin del cuerpo
        // sacar indice del GOTOF y del inicio del ciclo
        // generar GOTO de regreso al inicio
        // rellenar el GOTOF con la posicion actual (salida del ciclo)
        int fin     = popJump(&pilaJumps);
        int retorno = popJump(&pilaJumps);
        char buf[12];
        sprintf(buf, "%d", retorno);
        generarCuad("GOTO", "_", "_", buf);
        fillJump(&filaCuadruplos, fin, filaCuadruplos.count);
      }
    ;

// ─────────────────────────────────────────────
// CONDICIONAL SI / SINO
// ─────────────────────────────────────────────

condicion
    : SI '(' expresion ')'
      {
        // PN-IF1: condicion evaluada
        // generar GOTOF con destino pendiente
        // guardar su indice para backpatching
        popTipo(&pilaTipos);
        generarCuad("GOTOF", $3, "_", "???");
        pushJump(&pilaJumps, filaCuadruplos.count - 1);
      }
      cuerpo condicional_sino ';'
    ;

condicional_sino
    : SINO
      {
        // PN-IF2: fin del bloque verdadero
        // generar GOTO para saltar el bloque sino (destino pendiente)
        // rellenar el GOTOF anterior con la posicion actual
        generarCuad("GOTO", "_", "_", "???");
        int falso = popJump(&pilaJumps);
        pushJump(&pilaJumps, filaCuadruplos.count - 1);
        fillJump(&filaCuadruplos, falso, filaCuadruplos.count);
      }
      cuerpo
      {
        // PN-IF3: fin del bloque sino
        // rellenar el GOTO con la posicion actual
        int fin = popJump(&pilaJumps);
        fillJump(&filaCuadruplos, fin, filaCuadruplos.count);
      }
    | /* epsilon */
      {
        // PN-IF-END: si no hay sino, rellenar el GOTOF con la posicion actual
        int fin = popJump(&pilaJumps);
        fillJump(&filaCuadruplos, fin, filaCuadruplos.count);
      }
    ;

// ─────────────────────────────────────────────
// INSTRUCCION ESCRIBE
// ─────────────────────────────────────────────

imprime
    : ESCRIBE '(' conte_imprimir ')' ';'
    ;

conte_imprimir
    : LETRERO
      {
        // PN-P1: imprimir string literal
        generarCuad("PRINT", $1, "_", "_");
      }
      mas_imp

    | expresion
      {
        // PN-P2: imprimir resultado de expresion
        generarCuad("PRINT", $1, "_", "_");
        popTipo(&pilaTipos);
      }
      mas_imp
    ;

mas_imp
    : ',' conte_imprimir
    | /* epsilon */
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error Sintactico, Linea %d: %s\n", yylineno, s);
    errsintx++;
}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            fprintf(stderr, "Error: no se pudo abrir '%s'\n", argv[1]);
            return 1;
        }
        yyin = f;
        printf("Leyendo: %s\n", argv[1]);
    } else {
        printf("Leyendo desde stdin:\n");
    }

    yyparse();

    printf("Errores lexicos:     %d\n", errores_lexicos);
    printf("Errores sintacticos: %d\n", errsintx);
    printf("Errores semanticos:  %d\n", errsemant);

    if (argc > 1) fclose(yyin);

    return (errores_lexicos + errsintx + errsemant > 0) ? 1 : 0;
}
