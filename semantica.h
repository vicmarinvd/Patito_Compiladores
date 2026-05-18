#ifndef SEMANTICA_H
#define SEMANTICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tipos

#define ERR   0
#define INT   1
#define FLT   2
#define NULA  3

const char* tipoToString(int tipo);

// operadores

#define OP_ADD  0
#define OP_SUB  1
#define OP_MUL  2
#define OP_DIV  3
#define OP_GT   4
#define OP_LT   5
#define OP_EQ   6
#define OP_NEQ  7
#define OP_ASG  8

#define NUM_TYPES 4
#define NUM_OPS   9

// cubo semantico

extern int cubo[NUM_TYPES][NUM_TYPES][NUM_OPS];

void initCubo();

int consultarCubo(int izq,
                  int der,
                  int op);

// hash 

#define TABLE_SIZE 53

// variables
typedef struct Variable {

    char nombre[50];

    int tipo;

    struct Variable *next; //las variables se almacenan en listas enlazadas para manejar colisiones

} Variable;

// tabla de variables

typedef struct {

    Variable *buckets[TABLE_SIZE]; //cada bucket es una lista enlazada de variables

} TablaVariables;

void initTabla(TablaVariables *tabla);

unsigned int hash(char *str);

int insertarVariable(TablaVariables *tabla,
                     char *nombre,
                     int tipo);

Variable* buscarVariable(TablaVariables *tabla,
                         char *nombre);

void imprimirTabla(TablaVariables *tabla);

// funciones 

typedef struct Funcion {

    char nombre[50];

    int tipoRetorno;

    TablaVariables locales; // cada función tiene su propia tabla de variables locales

    struct Funcion *next;

} Funcion;

// directorio de funciones

typedef struct {

    Funcion *buckets[TABLE_SIZE]; 

} DirectorioFunciones;

void initDirectorio(DirectorioFunciones *dir); 

int insertarFuncion(DirectorioFunciones *dir,
                    char *nombre, 
                    int tipo);

Funcion* buscarFuncion(DirectorioFunciones *dir,
                       char *nombre);

void imprimirDirectorio(DirectorioFunciones *dir); 

// stack de ids 

typedef struct {
 
    char datos[100][50]; // stack de ids con capacidad para 100 ids, cada id puede tener hasta 50 caracteres
 
    int top;

} StackIDs;

void initStack(StackIDs *s);

void push(StackIDs *s,
          char *nombre);

char* pop(StackIDs *s);

int stackVacio(StackIDs *s);

// variables globales

extern TablaVariables tablaGlobal; // tabla de variables globales

extern TablaVariables *tablaActual;

extern DirectorioFunciones directorio;

extern Funcion *funcionActual;

extern StackIDs pilaIDs;

#endif