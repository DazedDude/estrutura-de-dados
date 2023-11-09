#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *no(float valor, No *proximo_no)
{
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No *H, No *no)
{

    if (H != NULL)
    {
        no->proximo_no = H->proximo_no;
        H->proximo_no = no;
    }
}

void lista_imprimir(No *H)
{
    while (H != NULL)
    {
        printf("%.2f\n", H->valor);
        H = H->proximo_no;
    }
}

void lista_inserir_no_ordenado(No **H, No *no)
{
    if (H != NULL)
    {
        No *atual = *H;
        No *anterior = NULL;

        while (atual != NULL && no->valor > atual->valor)
        {
            anterior = atual;
            atual = atual->proximo_no;
        }

        if (anterior == NULL)
        {
            no->proximo_no = *H;
            *H = no;
        }
        else
        {
            anterior->proximo_no = no;
            no->proximo_no = atual;
        }
    }
}
