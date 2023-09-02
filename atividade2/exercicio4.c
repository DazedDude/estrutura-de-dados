#include <stdio.h>

int conta_ocorrencias(int arr[], int tamanho, int busca) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == busca) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int numeros[tamanho];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int busca;
    printf("Digite o numero de busca: ");
    scanf("%d", &busca);

    int quantidade = conta_ocorrencias(numeros, tamanho, busca);

    printf("O numero %d aparece %d vezes no array.\n", busca, quantidade);

    return 0;
}