#include "semantica.h"

// variables globales

int cubo[NUM_TYPES][NUM_TYPES][NUM_OPS];

TablaVariables tablaGlobal;

TablaVariables *tablaActual = NULL;

DirectorioFunciones directorio;

Funcion *funcionActual = NULL;

StackIDs pilaIDs;


const char* tipoToString(int tipo) { // convertir el tipo a string para imprimir

    switch(tipo) {

        case INT:
            return "entero";

        case FLT:
            return "flotante";

        case NULA:
            return "nula";

        default:
            return "error";
    }
}

// cubo semantico 

void initCubo() {

    for(int i = 0; i < NUM_TYPES; i++) {

        for(int j = 0; j < NUM_TYPES; j++) {

            for(int k = 0; k < NUM_OPS; k++) {

                cubo[i][j][k] = ERR; // por defecto, todas las combinaciones son error
            }
        }
    }

    // definir las combinaciones válidas en el cubo semántico
    // suma 

    cubo[INT][INT][OP_ADD] = INT;
    cubo[INT][FLT][OP_ADD] = FLT;
    cubo[FLT][INT][OP_ADD] = FLT;
    cubo[FLT][FLT][OP_ADD] = FLT;

    // resta 

    cubo[INT][INT][OP_SUB] = INT;
    cubo[INT][FLT][OP_SUB] = FLT;
    cubo[FLT][INT][OP_SUB] = FLT;
    cubo[FLT][FLT][OP_SUB] = FLT;

    // multiplicacion 

    cubo[INT][INT][OP_MUL] = INT;
    cubo[INT][FLT][OP_MUL] = FLT;
    cubo[FLT][INT][OP_MUL] = FLT;
    cubo[FLT][FLT][OP_MUL] = FLT;

    // division

    cubo[INT][INT][OP_DIV] = FLT;
    cubo[INT][FLT][OP_DIV] = FLT;
    cubo[FLT][INT][OP_DIV] = FLT;
    cubo[FLT][FLT][OP_DIV] = FLT;

    // relacionales 
    cubo[INT][INT][OP_GT] = INT;
    cubo[INT][INT][OP_LT] = INT;
    cubo[INT][INT][OP_EQ] = INT;
    cubo[INT][INT][OP_NEQ] = INT;

    cubo[FLT][FLT][OP_GT] = INT;
    cubo[FLT][FLT][OP_LT] = INT;
    cubo[FLT][FLT][OP_EQ] = INT;
    cubo[FLT][FLT][OP_NEQ] = INT;

    cubo[INT][FLT][OP_GT] = INT;
    cubo[INT][FLT][OP_LT] = INT;

    cubo[FLT][INT][OP_GT] = INT;
    cubo[FLT][INT][OP_LT] = INT;

    // asignacion

    cubo[INT][INT][OP_ASG] = INT;

    cubo[FLT][FLT][OP_ASG] = FLT;

    cubo[FLT][INT][OP_ASG] = FLT;
}

// consultar el cubo semantico para verificar si la operacion es valida y obtener el tipo resultante
int consultarCubo(int izq,
                  int der,
                  int op) {

    return cubo[izq][der][op];
}

//hash 
//transformar un string en un indice para la tabla hash
unsigned int hash(char *str) {

    unsigned int hash = 0;

    while(*str) {

        hash = hash * 31 + *str;

        str++;
    }

    return hash % TABLE_SIZE;
}

// tabla de variables

void initTabla(TablaVariables *tabla) {

    for(int i = 0; i < TABLE_SIZE; i++) {

        tabla->buckets[i] = NULL;
    }
}

int insertarVariable(TablaVariables *tabla,
                     char *nombre,
                     int tipo) {

    int idx = hash(nombre);

    Variable *actual = tabla->buckets[idx];

    while(actual != NULL) { // verificar si la variable ya existe en la tabla

        if(strcmp(actual->nombre, nombre) == 0) {

            return -1; // variable ya existe, no se puede insertar
        }

        actual = actual->next;
    }

    Variable *nueva = malloc(sizeof(Variable)); // crear una nueva variable

    strcpy(nueva->nombre, nombre); 

    nueva->tipo = tipo;

    nueva->next = tabla->buckets[idx]; // insertar al inicio de la lista enlazada del bucket

    tabla->buckets[idx] = nueva;

    return 0;
}

Variable* buscarVariable(TablaVariables *tabla,
                         char *nombre) {

    int idx = hash(nombre);

    Variable *actual = tabla->buckets[idx];

    while(actual != NULL) {

        if(strcmp(actual->nombre, nombre) == 0) {

            return actual;
        }

        actual = actual->next;
    }

    return NULL;
}

void imprimirTabla(TablaVariables *tabla) {

    for(int i = 0; i < TABLE_SIZE; i++) {

        Variable *actual = tabla->buckets[i];

        while(actual != NULL) {

            printf("%s : %s\n",
                   actual->nombre,
                   tipoToString(actual->tipo));

            actual = actual->next;
        }
    }
}

// directorio de funciones

void initDirectorio(DirectorioFunciones *dir) {

    for(int i = 0; i < TABLE_SIZE; i++) {

        dir->buckets[i] = NULL;
    }
}

int insertarFuncion(DirectorioFunciones *dir,
                    char *nombre,
                    int tipo) {

    int idx = hash(nombre);

    Funcion *actual = dir->buckets[idx];

    while(actual != NULL) {

        if(strcmp(actual->nombre, nombre) == 0) {

            return -1;
        }

        actual = actual->next;
    }

    Funcion *nueva = malloc(sizeof(Funcion));

    strcpy(nueva->nombre, nombre);

    nueva->tipoRetorno = tipo;

    initTabla(&nueva->locales);

    nueva->next = dir->buckets[idx];

    dir->buckets[idx] = nueva;

    return 0;
}

Funcion* buscarFuncion(DirectorioFunciones *dir,
                       char *nombre) {

    int idx = hash(nombre);

    Funcion *actual = dir->buckets[idx];

    while(actual != NULL) {

        if(strcmp(actual->nombre, nombre) == 0) {

            return actual;
        }

        actual = actual->next;
    }

    return NULL;
}

// imprimir el directorio de funciones y sus variables locales
void imprimirDirectorio(DirectorioFunciones *dir) {

    printf("\nDIRECTORIO FUNCIONES\n");

    for(int i = 0; i < TABLE_SIZE; i++) {

        Funcion *actual = dir->buckets[i];

        while(actual != NULL) {

            printf("\nFuncion: %s\n",
                   actual->nombre);

            printf("Retorno: %s\n",
                   tipoToString(actual->tipoRetorno));

            printf("Variables locales:\n");

            imprimirTabla(&actual->locales);

            actual = actual->next;
        }
    }
}

// stacks de id 

void initStack(StackIDs *s) {

    s->top = -1;
}

void push(StackIDs *s,
          char *nombre) {

    s->top++;

    strcpy(s->datos[s->top], nombre);
}

char* pop(StackIDs *s) {

    return s->datos[s->top--];
}

int stackVacio(StackIDs *s) {

    return s->top == -1;
}