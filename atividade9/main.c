#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <time.h>

int main(int argc, char *argv)
{
    FILE *arquivo;

    No *n0_ordenado;
    No *n0;

    arquivo = fopen("1kk_rand_float.csv", "r");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    float valor;
    No *noToken;
    No *noToken1;
    int contador = 1;

    clock_t inicio, fim;
    double tempo_lista_inserir_no = 0.0;
    double tempo_lista_inserir_no_ordenado = 0.0;

    printf("Rodando...\n");
    while (fscanf(arquivo, "%f", &valor) != EOF)
    {
        if (contador < 2)
        {
            n0_ordenado = no(valor, NULL);
            n0 = no(valor, NULL);
        }
        while (contador > 1)
        {
            inicio = clock();
            noToken = no(valor, NULL);
            lista_inserir_no(n0, noToken);
            fim = clock();
            tempo_lista_inserir_no += ((double)(fim - inicio)) / CLOCKS_PER_SEC;

            inicio = clock();
            noToken1 = no(valor, NULL);
            lista_inserir_no_ordenado(&n0_ordenado, noToken1);
            fim = clock();
            tempo_lista_inserir_no_ordenado += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            break;
        }
        contador++;
    }
    fclose(arquivo);

    printf("Tempo de execucao de lista_inserir_no: %.6f segundos\n", tempo_lista_inserir_no);
    printf("Tempo de execucao de lista_inserir_no_ordenado: %.6f segundos\n", tempo_lista_inserir_no_ordenado);

    return 0;
}