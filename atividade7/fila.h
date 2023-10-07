#ifndef FILA_H
#define FILA_H

typedef struct {
    double *itens;
    int tamanho;
    int frente;
    int tras;
    int quantidade;
} Fila;

Fila *criarFila(int tamanho);
void enfileirar(Fila *fila, double valor);
double desenfileirar(Fila *fila);
int tamanhoFila(Fila *fila);
int estaVaziaFila(Fila *fila);
void destruirFila(Fila *fila);

#endif