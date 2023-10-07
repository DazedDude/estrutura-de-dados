#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
    Pilha *pilha = criarPilha(10);
    Fila *fila = criarFila(10);

    // Simulação de operações de uma caixa registradora
    empilhar(pilha, 50.0);
    empilhar(pilha, 30.0);
    empilhar(pilha, 20.0);

    while (!estaVaziaPilha(pilha)) {
        double valor = desempilhar(pilha);
        printf("Item na Pilha: %.2lf\n", valor);
        enfileirar(fila, valor);
    }

    printf("\nItens na Fila (do primeiro ao último):\n");
    while (!estaVaziaFila(fila)) {
        double valor = desenfileirar(fila);
        printf("%.2lf\n", valor);
    }

    // Liberar memória
    destruirPilha(pilha);
    destruirFila(fila);

    return 0;
}