#ifndef PILHA_H
#define PILHA_H

typedef struct {
    double *itens;
    int tamanho;
    int topo;
} Pilha;

Pilha *criarPilha(int tamanho);
void empilhar(Pilha *pilha, double valor);
double desempilhar(Pilha *pilha);
int tamanhoPilha(Pilha *pilha);
int estaVaziaPilha(Pilha *pilha);
void destruirPilha(Pilha *pilha);

#endif 