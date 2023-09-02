#include <stdio.h>

int soma_array(int arr[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return soma;
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

    int resultado = soma_array(numeros, tamanho);

    printf("Soma dos elementos do array: %d\n", resultado);

    return 0;
}