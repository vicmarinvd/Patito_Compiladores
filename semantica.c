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

        case TIPO_INT:
            return "entero";

        case TIPO_FLT:
            return "flotante";

        case TIPO_NULA:
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

                cubo[i][j][k] = TIPO_ERR; // por defecto, todas las combinaciones son error
            }
        }
    }

    // definir las combinaciones válidas en el cubo semántico
    // suma 

    cubo[TIPO_INT][TIPO_INT][OP_ADD] = TIPO_INT;
    cubo[TIPO_INT][TIPO_FLT][OP_ADD] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_INT][OP_ADD] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_FLT][OP_ADD] = TIPO_FLT;

    // resta 

    cubo[TIPO_INT][TIPO_INT][OP_SUB] = TIPO_INT;
    cubo[TIPO_INT][TIPO_FLT][OP_SUB] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_INT][OP_SUB] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_FLT][OP_SUB] = TIPO_FLT;

    // multiplicacion 

    cubo[TIPO_INT][TIPO_INT][OP_MUL] = TIPO_INT;
    cubo[TIPO_INT][TIPO_FLT][OP_MUL] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_INT][OP_MUL] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_FLT][OP_MUL] = TIPO_FLT;

    // division

    cubo[TIPO_INT][TIPO_INT][OP_DIV] = TIPO_FLT;
    cubo[TIPO_INT][TIPO_FLT][OP_DIV] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_INT][OP_DIV] = TIPO_FLT;
    cubo[TIPO_FLT][TIPO_FLT][OP_DIV] = TIPO_FLT;

    // relacionales 
    cubo[TIPO_INT][TIPO_INT][OP_GT] = TIPO_INT;
    cubo[TIPO_INT][TIPO_INT][OP_LT] = TIPO_INT;
    cubo[TIPO_INT][TIPO_INT][OP_EQ] = TIPO_INT;
    cubo[TIPO_INT][TIPO_INT][OP_NEQ] = TIPO_INT;

    cubo[TIPO_FLT][TIPO_FLT][OP_GT] = TIPO_INT;
    cubo[TIPO_FLT][TIPO_FLT][OP_LT] = TIPO_INT;
    cubo[TIPO_FLT][TIPO_FLT][OP_EQ] = TIPO_INT;
    cubo[TIPO_FLT][TIPO_FLT][OP_NEQ] = TIPO_INT;

    cubo[TIPO_INT][TIPO_FLT][OP_GT] = TIPO_INT;
    cubo[TIPO_INT][TIPO_FLT][OP_LT] = TIPO_INT;

    cubo[TIPO_FLT][TIPO_INT][OP_GT] = TIPO_INT;
    cubo[TIPO_FLT][TIPO_INT][OP_LT] = TIPO_INT;

    // asignacion

    cubo[TIPO_INT][TIPO_INT][OP_ASG] = TIPO_INT;

    cubo[TIPO_FLT][TIPO_FLT][OP_ASG] = TIPO_FLT;

    cubo[TIPO_FLT][TIPO_INT][OP_ASG] = TIPO_FLT;
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

void pushID(StackIDs *s,
          char *nombre) {

    s->top++;

    strcpy(s->datos[s->top], nombre);
}

char* popID(StackIDs *s) {

    return s->datos[s->top--];
}

int stackVacio(StackIDs *s) {

    return s->top == -1;
}