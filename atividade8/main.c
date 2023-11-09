#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv)
{
    No *n0 = no('a', NULL);
    No *n1 = no('b', NULL);
    No *n2 = no('c', NULL);
    No *n3 = no('c', NULL);
    No *n4 = no('c', NULL);

    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n3);
    lista_inserir_no(n0, n4);

    lista_imprimir(n0);

    // No *n0Copia = lista_copiar(n0);
    // printf("\n");
    // lista_imprimir(n0Copia);

    // lista_concatenar(n0, n0Copia);

    // lista_imprimir(n0);

    // int verificado = verifica_existencia(n0, 'b');
    // printf("\n%d", verificado);

    // int ocorrencias = lista_verificar_ocorrencias(n0, 'c');
    // printf("\n%d", ocorrencias);

    printf("\n");
    lista_imprimir_inversa(n0);

    printf("\n");
    // lista_remover_no_i(n0, 3);
    lista_inserir_no_i(n0, 3, 'z');
    lista_remover_no(n0, 'c');
    lista_imprimir(n0);

    lista_liberar(n0);

    exit(0);
}
