#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";

    if (bubbleSortFile(inputFileName, outputFileName)) {
        printf("Palavras ordenadas e gravadas em '%s'.\n", outputFileName);
    } else {
        printf("Erro ao ordenar as palavras.\n");
    }

    return 0;
}
