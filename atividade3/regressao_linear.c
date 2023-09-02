#include <stdio.h>

typedef struct {
    float x;
    float y;
} Ponto;

int main(int argc, char *argv[]) {
    FILE *arquivo;
    Ponto p;
    int contador = 0;
    float soma_x = 0, soma_y = 0;
    float media_x, media_y;
    float soma_1 = 0, soma_2 = 0;
    float inclinacao;

    if (argc < 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", argv[1]);
        return 1;
    }

    while (fscanf(arquivo, "%f %f", &p.x, &p.y) == 2) {
        soma_x += p.x;
        soma_y += p.y;
        contador++;
    }

    fclose(arquivo);

    if (contador > 0) {
        media_x = soma_x / contador;
        media_y = soma_y / contador;

        arquivo = fopen(argv[1], "r");
        while (fscanf(arquivo, "%f %f", &p.x, &p.y) == 2) {
            soma_1 += (p.x - media_x) * (p.y - media_y);
            soma_2 += (p.x - media_x) * (p.x - media_x);
        }
        fclose(arquivo);

        inclinacao = soma_1 / soma_2;
        printf("y = %.2fx + 7\n", inclinacao);
    } else {
        printf("Nenhum ponto lido do arquivo.\n");
    }

    return 0;
}