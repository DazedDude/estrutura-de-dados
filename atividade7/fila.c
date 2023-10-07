#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *criarFila(int tamanho) {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->itens = (double *)malloc(sizeof(double) * tamanho);
    fila->tamanho = tamanho;
    fila->frente = 0;
    fila->tras = -1;
    fila->quantidade = 0;
    return fila;
}

void enfileirar(Fila *fila, double valor) {
    if (fila->quantidade < fila->tamanho) {
        fila->tras = (fila->tras + 1) % fila->tamanho;
        fila->itens[fila->tras] = valor;
        fila->quantidade++;
    } else {
        printf("Erro: Fila cheia.\n");
    }
}

double desenfileirar(Fila *fila) {
    if (!estaVaziaFila(fila)) {
        double valor = fila->itens[fila->frente];
        fila->frente = (fila->frente + 1) % fila->tamanho;
        fila->quantidade--;
        return valor;
    } else {
        printf("Erro: Fila vazia.\n");
        return -1.0;
    }
}

int tamanhoFila(Fila *fila) {
    return fila->quantidade;
}

int estaVaziaFila(Fila *fila) {
    return fila->quantidade == 0;
}

void destruirFila(Fila *fila) {
    free(fila->itens);
    free(fila);
}