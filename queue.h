#ifndef QUEUE_H
#define QUEUE_H
#define TRUE 1
#define FALSE 0

//DEFINE OS DADOS DA FILA
typedef struct {
    int i, j;
    int numero;
} Dado;

//DEFINE OS NODES DA FILA
typedef struct Nodo {
    Dado dado;
    struct Nodo *prox;
} node;

//DEFINE A FILA
typedef struct {
    node *prox;
    int sizeF;
} fila;


fila *create();

int qEmpty(fila *f);

node *alocar(fila *f, Dado d);

node *insertNode(fila *f, Dado d);

node *remover(fila *f);

void first(fila *f);

void destroy(fila *f);

void listar(fila *f);

void ordenarFila(fila *f);

#endif
