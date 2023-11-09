#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *no(char valor, No *proximo_no)
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
        if (H->proximo_no == NULL)
        {
            H->proximo_no = no;
        }
        else
        {
            lista_inserir_no(H->proximo_no, no);
        }
    }
}

void lista_imprimir(No *H)
{
    if (H != NULL)
    {
        printf("%c ", H->valor);
        lista_imprimir(H->proximo_no);
    }
}

No *lista_copiar(No *H)
{
    if (H != NULL)
    {
        return no(H->valor, lista_copiar(H->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No *H, No *Hc)
{
    lista_inserir_no(H, Hc);
}

void lista_liberar(No *H)
{
    if (H != NULL)
    {
        lista_liberar(H->proximo_no);
        free(H);
    }
}

int lista_tamanho(No *H)
{
    if (H != NULL)
    {
        return 1 + lista_tamanho(H->proximo_no);
    }
    return 0;
}

int verifica_existencia(No *H, char valor_busca)
{
    if (H == NULL)
    {
        return 0;
    }
    if (H->valor == valor_busca)
    {
        return 1;
    }

    return verifica_existencia(H->proximo_no, valor_busca);
}

int lista_verificar_ocorrencias(No *H, char valor_busca)
{
    if (H == NULL)
    {
        return 0;
    }

    if (H->valor == valor_busca)
    {
        return 1 + lista_verificar_ocorrencias(H->proximo_no, valor_busca);
    }
    lista_verificar_ocorrencias(H->proximo_no, valor_busca);
}

void lista_imprimir_inversa(No *H)
{
    if (H == NULL)
    {
        return;
    }
    lista_imprimir_inversa(H->proximo_no);

    printf("%c ", H->valor);
}

void lista_inserir_no_i(struct No *H, int i, char valor)
{
    if (i < 0)
    {
        printf("Posição inválida.\n");
        return;
    }

    if (i == 0)
    {
        struct No *novoNo = no(valor, H->proximo_no);
        H->proximo_no = novoNo;
    }
    else
    {
        lista_inserir_no_i(H->proximo_no, i - 1, valor);
    }
}
void lista_remover_no_i(struct No *H, int i)
{
    if (i < 0)
    {
        printf("Posição inválida.\n");
        return;
    }

    if (i == 0)
    {
        struct No *temp = H->proximo_no;
        if (temp == NULL)
        {
            printf("A lista está vazia.\n");
            return;
        }
        H->proximo_no = temp->proximo_no;
        free(temp);
    }
    else
    {
        lista_remover_no_i(H->proximo_no, i - 1);
    }
}

void lista_remover_no(No *H, char valor_busca)
{
    if (H == NULL)
    {
        return;
    }
    while (H != NULL && H->valor == valor_busca)
    {
        No *temp = H;
        H = H->proximo_no;
        free(temp);
    }
    No *atual = H;
    while (atual != NULL)
    {
        No *proximo = atual->proximo_no;
        if (proximo != NULL && proximo->valor == valor_busca)
        {
            atual->proximo_no = proximo->proximo_no;
            free(proximo);
        }
        else
        {
            atual = proximo;
        }
    }
}
