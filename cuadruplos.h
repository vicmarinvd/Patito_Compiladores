#ifndef CUADRUPLOS_H
#define CUADRUPLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantica.h"

// cuadruplo (op, arg1, arg2, result) 
typedef struct {
    char op[10];
    char arg1[50];
    char arg2[50];
    char result[50];
} Cuadruplo;

// pilaO, LIFO, almacena variables, temporales, constantesm crece con subexpresiones, se reduce al generar cuadruplo
#define MAX_PILA 200

typedef struct {
    char datos[MAX_PILA][50];
    int  top;
} PilaOperandos;

void  initPilaOperandos(PilaOperandos *s);
void  pushOperando(PilaOperandos *s, char *nombre);
char* popOperando(PilaOperandos *s);
char* topOperando(PilaOperandos *s);
int   pilaOperandosVacia(PilaOperandos *s);

// pilaT, LIFO, almacena tipos de los operandos en la pilaO, se mantiene sincronizada con pilaO
typedef struct {
    int datos[MAX_PILA];
    int top;
} PilaTipos;

void initPilaTipos(PilaTipos *s);
void pushTipo(PilaTipos *s, int tipo);
int  popTipo(PilaTipos *s);
int  topTipo(PilaTipos *s);
int  pilaTiposVacia(PilaTipos *s);

// pilaOperadores, LIFO, almacena operadores de expresiones, se mantiene sincronizada con pilaO y pilaT
typedef struct {
    char datos[MAX_PILA][10];
    int  top;
} PilaOperadores;

void  initPilaOperadores(PilaOperadores *s);
void  pushOperador(PilaOperadores *s, char *op);
char* popOperador(PilaOperadores *s);
char* topOperador(PilaOperadores *s);
int   pilaOperadoresVacia(PilaOperadores *s);

// fila de cuadruplos, FIFO, linked list, en el orden que se geenra y se recorren desde el frente para imprimirlos, lista enlazada dado el numero de cuadruplos aun no se conoce al compilar
typedef struct NodoCuad {
    Cuadruplo       quad;
    int             num;
    struct NodoCuad *next;
} NodoCuad;

typedef struct {
    NodoCuad *front;
    NodoCuad *rear;
    int       count;
} FilaCuadruplos;

void      initFila(FilaCuadruplos *fila);
void      encolarCuadruplo(FilaCuadruplos *fila,
                            char *op,
                            char *arg1,
                            char *arg2,
                            char *result);
void      imprimirFila(FilaCuadruplos *fila);


//Pjumps, LIFO, almacena indices de cuadruplos con destino pendiente, se usa para manejar saltos condicionales e incondicionales (GOTOF, GOTO) cuando el destino aun no se conoce (ej. al inicio de un bloque), se rellena el destino con fillJump cuando se conoce (ej. al final del bloque)
 typedef struct {
    int datos[MAX_PILA];
    int top;
} PilaJumps;
 
void initPilaJumps(PilaJumps *s);
void pushJump(PilaJumps *s, int idx);
int  popJump(PilaJumps *s);
int  topJump(PilaJumps *s);
int  pilaJumpsVacia(PilaJumps *s);
 
/* Rellena el campo result del cuadruplo en posicion quadIdx
   con el indice de destino dest (backpatching). */
void fillJump(FilaCuadruplos *fila, int quadIdx, int dest);
 
//var globales 
extern PilaOperandos  pilaOperandos;
extern PilaTipos      pilaTipos;
extern PilaOperadores pilaOperadores;
extern PilaJumps      pilaJumps;
extern FilaCuadruplos filaCuadruplos;
extern int            contadorTemp;
extern int            contadorArgs;
extern char           funcCallBuf[64];
 
// otras funciones 

/* Genera un nuevo nombre temporal: t1, t2, t3 ... */
char* nuevoTemp(void);

/* Lookup de tipo: busca primero en locales, luego en global */
int getTipoVar(char *nombre);

/* Encola un cuadruplo y muestra mensaje de debug */
void generarCuad(char *op, char *arg1, char *arg2, char *result);

/* Genera cuadruplo de operacion binaria (usa las pilas) */
void operacionBinaria(char *op, char *izq, char *der, int opCubo);

#endif