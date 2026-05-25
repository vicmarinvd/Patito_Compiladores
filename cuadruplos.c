#include "cuadruplos.h"

PilaOperandos  pilaOperandos;
PilaTipos      pilaTipos;
PilaOperadores pilaOperadores;
FilaCuadruplos filaCuadruplos;
int            contadorTemp = 0;
int            contadorArgs = 0;
char           funcCallBuf[64];

// Pila saltos

PilaJumps pilaJumps;

//inicializa la pilaJ 
void initPilaJumps(PilaJumps *s) { s->top = -1; }

//push de indice de cuadruplo a la pilaJumps
void pushJump(PilaJumps *s, int idx) {
    if (s->top >= MAX_PILA - 1) {
        fprintf(stderr, "[Error] PilaJumps: desbordamiento\n"); return;
    }
    s->datos[++s->top] = idx;
}

//pop de indice de cuadruplo de la pilaJumps
int popJump(PilaJumps *s) {
    if (s->top < 0) {
        fprintf(stderr, "[Error] PilaJumps: pop en pila vacia\n"); return -1;
    }
    return s->datos[s->top--];
}

//top de indice de cuadruplo en la pilaJumps sin removerlo
int topJump(PilaJumps *s) {
    if (s->top < 0) return -1;
    return s->datos[s->top];
}

//verificar si la pilaJumps esta vacia
int pilaJumpsVacia(PilaJumps *s) { return s->top < 0; }

// rellenar el campo result del cuadruplo en posicion quadIdx con el indice de destino dest (backpatching)
// cuando encuentra el resultado, regresa al quadIdx y lo actualiza con el dest, si no encuentra el quadIdx, imprime un error
void fillJump(FilaCuadruplos *fila, int quadIdx, int dest) {
    char buf[12];
    sprintf(buf, "%d", dest);
    for (NodoCuad *cur = fila->front; cur; cur = cur->next) {
        if (cur->num == quadIdx) {
            strncpy(cur->quad.result, buf, 49);
            cur->quad.result[49] = '\0';
            return;
        }
    }
    fprintf(stderr, "[Error] fillJump: cuadruplo %d no encontrado\n", quadIdx);
}

//Pila operandos

void initPilaOperandos(PilaOperandos *s) { s->top = -1; }

void pushOperando(PilaOperandos *s, char *nombre) {
    if (s->top >= MAX_PILA - 1) {
        fprintf(stderr, "[Error] PilaOperandos: desbordamiento\n");
        return;
    }
    s->top++;
    strncpy(s->datos[s->top], nombre, 49);
    s->datos[s->top][49] = '\0';
}

char* popOperando(PilaOperandos *s) {
    if (s->top < 0) {
        fprintf(stderr, "[Error] PilaOperandos: pop en pila vacia\n");
        return "_";
    }
    return s->datos[s->top--];
}

char* topOperando(PilaOperandos *s) {
    if (s->top < 0) return "_";
    return s->datos[s->top];
}

int pilaOperandosVacia(PilaOperandos *s) { return s->top < 0; }

//Pila tipos

void initPilaTipos(PilaTipos *s) { s->top = -1; }

void pushTipo(PilaTipos *s, int tipo) {
    if (s->top >= MAX_PILA - 1) {
        fprintf(stderr, "[Error] PilaTipos: desbordamiento\n");
        return;
    }
    s->datos[++s->top] = tipo;
}

int popTipo(PilaTipos *s) {
    if (s->top < 0) {
        fprintf(stderr, "[Error] PilaTipos: pop en pila vacia\n");
        return TIPO_ERR;
    }
    return s->datos[s->top--];
}

int topTipo(PilaTipos *s) {
    if (s->top < 0) return TIPO_ERR;
    return s->datos[s->top];
}

int pilaTiposVacia(PilaTipos *s) { return s->top < 0; }

// Pila operadores

//inicializa la pilaOperadores
void initPilaOperadores(PilaOperadores *s) { s->top = -1; }

//op es un string con el operador
void pushOperador(PilaOperadores *s, char *op) {
    if (s->top >= MAX_PILA - 1) {
        fprintf(stderr, "[Error] PilaOperadores: desbordamiento\n");
        return;
    }
    s->top++;
    strncpy(s->datos[s->top], op, 9);
    s->datos[s->top][9] = '\0';
}

char* popOperador(PilaOperadores *s) {
    if (s->top < 0) {
        fprintf(stderr, "[Error] PilaOperadores: pop en pila vacia\n");
        return "_";
    }
    return s->datos[s->top--];
}

char* topOperador(PilaOperadores *s) {
    if (s->top < 0) return "_";
    return s->datos[s->top];
}

int pilaOperadoresVacia(PilaOperadores *s) { return s->top < 0; }

// fila de cuadruplos, lista enlazada, se mantiene el orden de generacion, se recorre desde el frente para imprimirlos

void initFila(FilaCuadruplos *fila) {
    fila->front = NULL;
    fila->rear  = NULL;
    fila->count = 0;
}

// encolar un nuevo cuadruplo al final de la fila, asignando un numero secuencial basado en el count actual de la fila, el numero se asigna antes de incrementar el count para que empiece en 0
void encolarCuadruplo(FilaCuadruplos *fila,
                       char *op, char *arg1, char *arg2, char *result) {
    NodoCuad *nodo = malloc(sizeof(NodoCuad));
    if (!nodo) { fprintf(stderr, "[Error] Sin memoria para cuadruplo\n"); return; }

    strncpy(nodo->quad.op,     op,     9);  nodo->quad.op[9]     = '\0';
    strncpy(nodo->quad.arg1,   arg1,  49);  nodo->quad.arg1[49]  = '\0';
    strncpy(nodo->quad.arg2,   arg2,  49);  nodo->quad.arg2[49]  = '\0';
    strncpy(nodo->quad.result, result,49);  nodo->quad.result[49]= '\0';
    nodo->num  = fila->count;
    nodo->next = NULL;

    if (!fila->rear) {
        fila->front = fila->rear = nodo;
    } else {
        fila->rear->next = nodo;
        fila->rear = nodo;
    }
    fila->count++;
}

void imprimirFila(FilaCuadruplos *fila) {
    printf("\n-- FILA DE CUADRUPLOS (%d) ------------------\n", fila->count);
    printf("  %-4s  %-8s  %-20s  %-20s  %-20s\n",
           "Num", "Op", "Arg1", "Arg2", "Resultado");
    printf("  %-4s  %-8s  %-20s  %-20s  %-20s\n",
           "----", "--------", "--------------------",
           "--------------------", "--------------------");
    NodoCuad *cur = fila->front;
    while (cur) {
        printf("  %-4d  %-8s  %-20s  %-20s  %-20s\n",
               cur->num,
               cur->quad.op,
               cur->quad.arg1,
               cur->quad.arg2,
               cur->quad.result);
        cur = cur->next;
    }
    printf("-----------------------------------------\n\n");
}

// funciones de apoyo

char* nuevoTemp(void) {
    static char buf[20];
    sprintf(buf, "t%d", ++contadorTemp);
    return buf;
}

int getTipoVar(char *nombre) {
    if (funcionActual) {
        Variable *v = buscarVariable(&funcionActual->locales, nombre);
        if (v) return v->tipo;
    }
    Variable *v = buscarVariable(&tablaGlobal, nombre);
    if (v) return v->tipo;
    return TIPO_ERR;
}

void generarCuad(char *op, char *arg1, char *arg2, char *result) {
    encolarCuadruplo(&filaCuadruplos, op, arg1, arg2, result);
}

/*
 * operacionBinaria:
 *   - Saca los dos operandos y sus tipos de las pilas
 *   - Consulta el cubo semantico
 *   - Genera el cuadruplo
 *   - Empuja el temporal resultado y su tipo
 */
void operacionBinaria(char *op, char *izq, char *der, int opCubo) {
    int t_der = popTipo(&pilaTipos);   /* der fue pushed despues */
    int t_izq = popTipo(&pilaTipos);   /* izq fue pushed primero */

    int t_res = consultarCubo(t_izq, t_der, opCubo);
    if (t_res == TIPO_ERR) {
        fprintf(stderr,
            "[Error Semantico] Tipos incompatibles en operacion '%s': %s %s %s\n",
            op, tipoToString(t_izq), op, tipoToString(t_der));
    }

    char *tmp = nuevoTemp();
    generarCuad(op, izq, der, tmp);
    pushOperando(&pilaOperandos, tmp);
    pushTipo(&pilaTipos, t_res);
}