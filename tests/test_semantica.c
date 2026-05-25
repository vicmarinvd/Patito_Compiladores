/*
 * test_semantica.c
 * Compilar:  gcc -Wall test_semantica.c semantica.c -o test_semantica
 * Ejecutar:  ./test_semantica
 *
 * Usa la interfaz exacta de semantica.h del alumno:
 *   initCubo / consultarCubo
 *   initTabla / insertarVariable / buscarVariable / imprimirTabla
 *   initDirectorio / insertarFuncion / buscarFuncion / imprimirDirectorio
 *   initStack / pushID / popID / stackVacio
 *   Globales: tablaGlobal, tablaActual, directorio, funcionActual, pilaIDs
 */

#include <stdio.h>
#include <string.h>
#include "semantica.h"

static int passed = 0;
static int failed = 0;

#define CHECK(desc, cond) \
    do { if (cond) { printf("  [OK]   %s\n", desc); passed++; } \
         else      { printf("  [FAIL] %s\n", desc); failed++; } } while(0)

void sep(const char *t) {
    printf("\n=== %s ===\n", t);
}

/* ─────────────────────────────────────────────────
   1. CUBO SEMANTICO
   ───────────────────────────────────────────────── */
void test_cubo() {
    sep("CUBO SEMANTICO");
    initCubo();

    CHECK("int + int = int",  consultarCubo(TIPO_INT, TIPO_INT, OP_ADD) == TIPO_INT);
    CHECK("int + flt = flt",  consultarCubo(TIPO_INT, TIPO_FLT, OP_ADD) == TIPO_FLT);
    CHECK("flt + int = flt",  consultarCubo(TIPO_FLT, TIPO_INT, OP_ADD) == TIPO_FLT);
    CHECK("flt + flt = flt",  consultarCubo(TIPO_FLT, TIPO_FLT, OP_ADD) == TIPO_FLT);
    CHECK("int - flt = flt",  consultarCubo(TIPO_INT, TIPO_FLT, OP_SUB) == TIPO_FLT);
    CHECK("int * int = int",  consultarCubo(TIPO_INT, TIPO_INT, OP_MUL) == TIPO_INT);

    /* division siempre produce flotante */
    CHECK("int / int = flt",  consultarCubo(TIPO_INT, TIPO_INT, OP_DIV) == TIPO_FLT);
    CHECK("flt / int = flt",  consultarCubo(TIPO_FLT, TIPO_INT, OP_DIV) == TIPO_FLT);

    /* relacionales producen int (booleano) */
    CHECK("int > int  = int", consultarCubo(TIPO_INT, TIPO_INT, OP_GT)  == TIPO_INT);
    CHECK("flt < flt  = int", consultarCubo(TIPO_FLT, TIPO_FLT, OP_LT) == TIPO_INT);
    CHECK("int == flt = int", consultarCubo(TIPO_INT, TIPO_FLT, OP_EQ)  == TIPO_INT);
    CHECK("flt != int = int", consultarCubo(TIPO_FLT, TIPO_INT, OP_NEQ) == TIPO_INT);

    /* asignacion */
    CHECK("int = int  -> TIPO_INT", consultarCubo(TIPO_INT, TIPO_INT, OP_ASG) == TIPO_INT);
    CHECK("flt = flt  -> TIPO_FLT", consultarCubo(TIPO_FLT, TIPO_FLT, OP_ASG) == TIPO_FLT);
    CHECK("flt = int  -> TIPO_FLT", consultarCubo(TIPO_FLT, TIPO_INT, OP_ASG) == TIPO_FLT);
    CHECK("int = flt  -> TIPO_ERR", consultarCubo(TIPO_INT, TIPO_FLT, OP_ASG) == TIPO_ERR);

    /* con TIPO_NULA -> error */
    CHECK("nula + int -> TIPO_ERR", consultarCubo(TIPO_NULA, TIPO_INT, OP_ADD) == TIPO_ERR);
    CHECK("int  + nula-> TIPO_ERR", consultarCubo(TIPO_INT, TIPO_NULA, OP_ADD) == TIPO_ERR);
}

/* ─────────────────────────────────────────────────
   2. TABLA DE VARIABLES
   ───────────────────────────────────────────────── */
void test_tabla() {
    sep("TABLA DE VARIABLES");

    TablaVariables t;
    initTabla(&t);

    CHECK("insertar 'x' : entero  -> 0",  insertarVariable(&t, "x",    TIPO_INT) == 0);
    CHECK("insertar 'pi': flotante -> 0",  insertarVariable(&t, "pi",   TIPO_FLT) == 0);
    CHECK("insertar 'suma': entero -> 0",  insertarVariable(&t, "suma", TIPO_INT) == 0);

    /* duplicados */
    CHECK("insertar 'x' de nuevo -> -1",  insertarVariable(&t, "x",  TIPO_INT) == -1);
    CHECK("insertar 'pi' de nuevo -> -1", insertarVariable(&t, "pi", TIPO_FLT) == -1);

    /* busqueda */
    Variable *v = buscarVariable(&t, "x");
    CHECK("buscar 'x' -> encontrada",    v != NULL);
    CHECK("buscar 'x' -> tipo TIPO_INT",      v && v->tipo == TIPO_INT);

    v = buscarVariable(&t, "pi");
    CHECK("buscar 'pi' -> tipo TIPO_FLT",     v && v->tipo == TIPO_FLT);
    CHECK("buscar 'nope' -> NULL",       buscarVariable(&t, "nope") == NULL);

    /* 30 variables para forzar colisiones en los buckets */
    char nombre[16];
    int ok = 1;
    for (int i = 0; i < 30; i++) {
        sprintf(nombre, "var%d", i);
        if (insertarVariable(&t, nombre, TIPO_INT) != 0) { ok = 0; break; }
    }
    CHECK("insertar 30 vars -> todas ok", ok);

    ok = 1;
    for (int i = 0; i < 30; i++) {
        sprintf(nombre, "var%d", i);
        if (buscarVariable(&t, nombre) == NULL) { ok = 0; break; }
    }
    CHECK("buscar las 30 vars -> todas encontradas", ok);
}

/* ─────────────────────────────────────────────────
   3. DIRECTORIO DE FUNCIONES
   ───────────────────────────────────────────────── */
void test_directorio() {
    sep("DIRECTORIO DE FUNCIONES");

    initDirectorio(&directorio);

    CHECK("insertar 'sumar'    TIPO_INT  -> 0", insertarFuncion(&directorio, "sumar",    TIPO_INT)  == 0);
    CHECK("insertar 'saludar'  TIPO_NULA -> 0", insertarFuncion(&directorio, "saludar",  TIPO_NULA) == 0);
    CHECK("insertar 'promedio' TIPO_FLT  -> 0", insertarFuncion(&directorio, "promedio", TIPO_FLT)  == 0);

    /* duplicado */
    CHECK("insertar 'sumar' de nuevo -> -1", insertarFuncion(&directorio, "sumar", TIPO_INT) == -1);

    /* busqueda */
    Funcion *f = buscarFuncion(&directorio, "sumar");
    CHECK("buscar 'sumar' -> encontrada",    f != NULL);
    CHECK("buscar 'sumar' -> retorno TIPO_INT",   f && f->tipoRetorno == TIPO_INT);

    f = buscarFuncion(&directorio, "promedio");
    CHECK("buscar 'promedio' -> retorno TIPO_FLT", f && f->tipoRetorno == TIPO_FLT);
    CHECK("buscar 'noExiste' -> NULL",        buscarFuncion(&directorio, "noExiste") == NULL);

    /* variables locales dentro de la funcion */
    f = buscarFuncion(&directorio, "sumar");
    CHECK("sumar: insertar local 'a' -> 0",   insertarVariable(&f->locales, "a", TIPO_INT) == 0);
    CHECK("sumar: insertar local 'b' -> 0",   insertarVariable(&f->locales, "b", TIPO_INT) == 0);
    CHECK("sumar: insertar 'a' dup  -> -1",   insertarVariable(&f->locales, "a", TIPO_INT) == -1);
    CHECK("sumar: buscar 'a' en locales",     buscarVariable(&f->locales, "a") != NULL);

    /* scope aislado: 'a' no existe en tablaGlobal */
    initTabla(&tablaGlobal);
    CHECK("'a' no existe en global (scopes aislados)",
          buscarVariable(&tablaGlobal, "a") == NULL);

    printf("\n");
    imprimirDirectorio(&directorio);
}

/* ─────────────────────────────────────────────────
   4. STACK DE IDs
   ───────────────────────────────────────────────── */
void test_stack() {
    sep("STACK DE IDs");

    initStack(&pilaIDs);
    CHECK("stack vacio al inicio",    stackVacio(&pilaIDs));

    pushID(&pilaIDs, "x");
    pushID(&pilaIDs, "y");
    pushID(&pilaIDs, "z");
    CHECK("no vacio tras 3 pushID",    !stackVacio(&pilaIDs));

    /* LIFO */
    CHECK("popID -> 'z'",  strcmp(popID(&pilaIDs), "z") == 0);
    CHECK("popID -> 'y'",  strcmp(popID(&pilaIDs), "y") == 0);
    CHECK("popID -> 'x'",  strcmp(popID(&pilaIDs), "x") == 0);
    CHECK("vacio tras 3 popID", stackVacio(&pilaIDs));

    /* simular declaracion multiple: a, b, c : entero */
    pushID(&pilaIDs, "a");
    pushID(&pilaIDs, "b");
    pushID(&pilaIDs, "c");

    TablaVariables t;
    initTabla(&t);
    while (!stackVacio(&pilaIDs))
        insertarVariable(&t, popID(&pilaIDs), TIPO_INT);

    CHECK("flush -> 'a' en tabla", buscarVariable(&t, "a") != NULL);
    CHECK("flush -> 'b' en tabla", buscarVariable(&t, "b") != NULL);
    CHECK("flush -> 'c' en tabla", buscarVariable(&t, "c") != NULL);
    CHECK("stack vacio tras flush", stackVacio(&pilaIDs));
}

/* ─────────────────────────────────────────────────
   5. FLUJO COMPLETO (simula lo que hara el parser)

   programa calc;
   vars
       a, b : entero;
       pi   : flotante;

   entero sumar(x : entero, y : entero) { vars res : entero; }
   nula   imprimir(n : entero)          { }

   inicio { ... } fin
   ───────────────────────────────────────────────── */
void test_flujo_completo() {
    sep("FLUJO COMPLETO (simula parser)");

    initCubo();
    initTabla(&tablaGlobal);
    initDirectorio(&directorio);
    initStack(&pilaIDs);
    tablaActual = &tablaGlobal;

    /* PN: vars globales a, b : entero */
    pushID(&pilaIDs, "a");
    pushID(&pilaIDs, "b");
    while (!stackVacio(&pilaIDs))
        insertarVariable(tablaActual, popID(&pilaIDs), TIPO_INT);

    /* PN: vars globales pi : flotante */
    pushID(&pilaIDs, "pi");
    while (!stackVacio(&pilaIDs))
        insertarVariable(tablaActual, popID(&pilaIDs), TIPO_FLT);

    CHECK("global 'a'  : entero",
          buscarVariable(&tablaGlobal,"a")  && buscarVariable(&tablaGlobal,"a")->tipo  == TIPO_INT);
    CHECK("global 'b'  : entero",
          buscarVariable(&tablaGlobal,"b")  && buscarVariable(&tablaGlobal,"b")->tipo  == TIPO_INT);
    CHECK("global 'pi' : flotante",
          buscarVariable(&tablaGlobal,"pi") && buscarVariable(&tablaGlobal,"pi")->tipo == TIPO_FLT);

    /* PN: entrar a funcion sumar */
    insertarFuncion(&directorio, "sumar", TIPO_INT);
    funcionActual = buscarFuncion(&directorio, "sumar");
    tablaActual   = &funcionActual->locales;

    insertarVariable(tablaActual, "x",   TIPO_INT);
    insertarVariable(tablaActual, "y",   TIPO_INT);
    insertarVariable(tablaActual, "res", TIPO_INT);

    CHECK("sumar: local 'x' existe",   buscarVariable(&funcionActual->locales,"x")   != NULL);
    CHECK("sumar: local 'res' existe",  buscarVariable(&funcionActual->locales,"res") != NULL);

    /* variable local con mismo nombre que global: scopes separados */
    CHECK("sumar: insertar 'a' local (mismo nombre que global) -> ok",
          insertarVariable(tablaActual, "a", TIPO_INT) == 0);

    /* PN: salir de sumar, volver a global */
    funcionActual = NULL;
    tablaActual   = &tablaGlobal;

    /* PN: entrar a funcion imprimir */
    insertarFuncion(&directorio, "imprimir", TIPO_NULA);
    funcionActual = buscarFuncion(&directorio, "imprimir");
    tablaActual   = &funcionActual->locales;
    insertarVariable(tablaActual, "n", TIPO_INT);

    /* PN: salir */
    funcionActual = NULL;
    tablaActual   = &tablaGlobal;

    /* global intacta */
    CHECK("global 'a' sigue siendo TIPO_INT", buscarVariable(&tablaGlobal,"a")->tipo == TIPO_INT);

    /* validaciones con cubo */
    int tA  = buscarVariable(&tablaGlobal,"a")->tipo;
    int tPi = buscarVariable(&tablaGlobal,"pi")->tipo;

    CHECK("a + b  -> TIPO_INT (cubo)",  consultarCubo(tA, tA,  OP_ADD) == TIPO_INT);
    CHECK("a + pi -> TIPO_FLT (cubo)",  consultarCubo(tA, tPi, OP_ADD) == TIPO_FLT);
    CHECK("pi = a -> TIPO_FLT (cubo)",  consultarCubo(tPi, tA, OP_ASG) == TIPO_FLT);
    CHECK("a  = pi-> TIPO_ERR (cubo)",  consultarCubo(tA, tPi, OP_ASG) == TIPO_ERR);

    printf("\n  Directorio final:\n");
    printf("  Tabla global:\n");
    imprimirTabla(&tablaGlobal);
    imprimirDirectorio(&directorio);
}

/* ─────────────────────────────────────────────────
   MAIN
   ───────────────────────────────────────────────── */
int main() {
    printf("\n=== TEST SUITE: semantica.h / semantica.c ===\n");

    test_cubo();
    test_tabla();
    test_directorio();
    test_stack();
    test_flujo_completo();

    printf("\n=== RESULTADO ===\n");
    printf("  Pasaron: %d\n", passed);
    printf("  Fallaron: %d\n", failed);
    printf("  Total:    %d\n\n", passed + failed);

    return failed > 0 ? 1 : 0;
}