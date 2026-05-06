%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Importa variables 
extern int  yylineno;
extern int  errlexicos;
extern FILE *yyin;

void yyerror(const char *s);
int  yylex(void);

static int errsintx = 0;
%}

// Declara tokens 

// Palabras reservadas 
%token PROGRAM VARS INICIO FIN SI SINO MIENTRAS HAZ ESCRIBE ENTERO FLOTANTE NULA

// Constantes, id y string
%token CTE_ENT
%token CTE_FLT
%token ID
%token LETRERO

// Operadores
%token OPEQ
%token OPNEQ
%token OPGT
%token OPLT

%%
// Inicio de definir las gramaticas

// Programa 
programa
    : PROGRAM ID ';' opc_var list_funciones INICIO cuerpo FIN
      {
        printf("\nprograma Patito es valido.\n"); // Si pasa la regla
      }
    ;

list_funciones
    : funcs list_funciones
    | /* epsilon */
    ;

opc_var
    : vars
    | /* epsilon */
    ;

// Variables 

vars
    : VARS mas_vars
    ;

mas_vars // Derivado 
    : ID decl_id ':' tipo ';' mas_vars
    | /* epsilon */
    ;

decl_id // Derivado
    : ',' ID decl_id
    | /* epsilon */
    ;

tipo
    : ENTERO
    | FLOTANTE
    ;

// Funciones

funcs
    : func_tipo ID '(' list_func_def ')' '{' hay_var cuerpo '}' ';'
    ;

func_tipo
    : NULA
    | tipo
    ;

list_func_def
    : ID ':' tipo cont_lista
    | /* epsilon */
    ;

cont_lista
    : ',' list_func_def
    | /* epsilon */
    ;

hay_var
    : vars
    | /* epsilon */
    ;

// Cuerpo y estatuto

cuerpo
    : '{' bloq_cuerpo '}'
    ;

bloq_cuerpo
    : estatuto bloq_cuerpo
    | /* epsilon */
    ;

estatuto
    : ID '=' expresion ';'
    | ID '(' argum ')' ';'
    | condicion
    | ciclo
    | imprime
    ;

// Argumentos de llamada
argum
    : expresion lista_exp
    | /* epsilon */
    ;

lista_exp
    : ',' expresion lista_exp
    | /* epsilon */
    ;


// Expresiones

expresion
    : exp comp_exp
    ;

comp_exp
    : OPGT  exp
    | OPLT  exp
    | OPNEQ exp
    | OPEQ  exp
    | /* epsilon */
    ;

exp
    : termino op_exp
    ;

op_exp
    : '+' termino op_exp
    | '-' termino op_exp
    | /* epsilon */
    ;

termino
    : factor op_term
    ;

op_term
    : '*' factor op_term
    | '/' factor op_term
    | /* epsilon */
    ;

factor
    : '+' factor
    | '-' factor
    | '(' expresion ')'
    | ID '(' argum ')'
    | ID
    | cte
    ;

cte
    : CTE_ENT
    | CTE_FLT
    ;



// Ciclo 

ciclo
    : MIENTRAS '(' expresion ')' HAZ cuerpo ';'
    ;

// Condicional 

condicion
    : SI '(' expresion ')' cuerpo condicional_sino ';'
    ;

condicional_sino
    : SINO cuerpo
    | /* epsilon */
    ;

// Print

imprime
    : ESCRIBE '(' conte_imprimir ')' ';'
    ;

conte_imprimir
    : LETRERO  mas_imp
    | expresion mas_imp
    ;

mas_imp
    : ',' conte_imprimir
    | /* epsilon */
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr,
        "Error Sintactico, Linea %d: %s\n",
        yylineno, s);
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

    printf("Errores lexicos:     %d\n", errlexicos);
    printf("Errores sintacticos: %d\n", errsintx);

    if (argc > 1) fclose(yyin);

    return (errlexicos + errsintx > 0) ? 1 : 0;
}
