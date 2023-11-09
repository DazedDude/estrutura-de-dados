#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main()
{

    init_hash_table(100);

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    if (hash_table_contains("chave2"))
    {
        printf("A chave 'chave2' existe na tabela.\n");
    }
    else
    {
        printf("A chave 'chave2' nao existe na tabela.\n");
    }

    char *valor = hash_table_get("chave1");
    if (valor != NULL)
    {
        printf("O valor associado a chave 'chave1' e: %s\n", valor);
    }
    else
    {
        printf("A chave 'chave1' nao existe na tabela.\n");
    }

    hash_table_remove("chave3");

    if (hash_table_contains("chave3"))
    {
        printf("A chave 'chave3' existe na tabela.\n");
    }
    else
    {
        printf("A chave 'chave3' nao existe na tabela.\n");
    }

    free_hash_table();

    return 0;
}
