#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *criarPilha(int tamanho) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->itens = (double *)malloc(sizeof(double) * tamanho);
    pilha->tamanho = tamanho;
    pilha->topo = -1;
    return pilha;
}

void empilhar(Pilha *pilha, double valor) {
    if (pilha->topo < pilha->tamanho - 1) {
        pilha->itens[++pilha->topo] = valor;
    } else {
        printf("Erro: Pilha cheia.\n");
    }
}

double desempilhar(Pilha *pilha) {
    if (!estaVaziaPilha(pilha)) {
        return pilha->itens[pilha->topo--];
    } else {
        printf("Erro: Pilha vazia.\n");
        return -1.0;
    }
}

int tamanhoPilha(Pilha *pilha) {
    return pilha->topo + 1;
}

int estaVaziaPilha(Pilha *pilha) {
    return pilha->topo == -1;
}

void destruirPilha(Pilha *pilha) {
    free(pilha->itens);
    free(pilha);
}