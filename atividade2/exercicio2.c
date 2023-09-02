#include <stdio.h>

void encontra_maior_menor(int arr[], int tamanho, int *maior, int *menor) {
    *maior = *menor = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > *maior) {
            *maior = arr[i];
        }
        if (arr[i] < *menor) {
            *menor = arr[i];
        }
    }
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

    int maior, menor;
    encontra_maior_menor(numeros, tamanho, &maior, &menor);

    printf("Maior elemento do array: %d\n", maior);
    printf("Menor elemento do array: %d\n", menor);

    return 0;
}