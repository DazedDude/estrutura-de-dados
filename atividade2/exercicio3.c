#include <stdio.h>
#include <string.h>

int verifica_string(char arr[][50], int tamanho, char busca[]) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(arr[i], busca) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    char strings[tamanho][50];
    printf("Digite as strings do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    char busca[50];
    printf("Digite a string de busca: ");
    scanf("%s", busca);

    int resultado = verifica_string(strings, tamanho, busca);

    if (resultado) {
        printf("A string foi encontrada no array.\n");
    } else {
        printf("A string nao foi encontrada no array.\n");
    }

    return 0;
}