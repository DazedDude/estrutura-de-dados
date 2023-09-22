#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

void bubbleSort(char *arr[], int n) {
    int swapped;
    char *temp;

    do {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (strcmp(arr[i - 1], arr[i]) > 0) {
                // Troca as palavras arr[i - 1] e arr[i]
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int bubbleSortFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        return 0;
    }

    // Contar o número de palavras no arquivo
    int count = 0;
    char buffer[100]; // Tamanho máximo de uma palavra
    while (fscanf(inputFile, "%s", buffer) != EOF) {
        count++;
    }

    // Voltar ao início do arquivo
    rewind(inputFile);

    // Ler as palavras em um array dinâmico
    char **words = (char **)malloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) {
        words[i] = (char *)malloc(100 * sizeof(char)); // Tamanho máximo de uma palavra
        fscanf(inputFile, "%s", words[i]);
    }

    // Fechar o arquivo de entrada
    fclose(inputFile);

    // Ordenar as palavras usando o Bubble Sort
    bubbleSort(words, count);

    // Criar o arquivo de saída
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        return 0;
    }

    // Escrever as palavras ordenadas no arquivo de saída
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s\n", words[i]);
    }

    // Fechar o arquivo de saída
    fclose(outputFile);

    // Liberar a memória alocada
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);

    return 1;
}
