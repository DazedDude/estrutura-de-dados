#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define MAX_TABLE_SIZE 100

typedef struct KeyValue
{
    char *chave;
    char *dado;
    struct KeyValue *next;
} KeyValue;

static KeyValue *hash_table[MAX_TABLE_SIZE];

int hash(char *chave)
{
    int hash = 0;
    while (*chave)
    {
        hash = (hash * 31 + *chave) % MAX_TABLE_SIZE;
        chave++;
    }
    return hash;
}

void init_hash_table(int size)
{
    for (int i = 0; i < size; i++)
    {
        hash_table[i] = NULL;
    }
}

char *hash_table_get(char *chave)
{
    int index = hash(chave);
    KeyValue *current = hash_table[index];
    while (current != NULL)
    {
        if (strcmp(current->chave, chave) == 0)
        {
            return current->dado;
        }
        current = current->next;
    }
    return NULL;
}

void hash_table_put(char *chave, char *dado)
{
    int index = hash(chave);
    KeyValue *new_pair = (KeyValue *)malloc(sizeof(KeyValue));
    new_pair->chave = strdup(chave);
    new_pair->dado = strdup(dado);
    new_pair->next = hash_table[index];
    hash_table[index] = new_pair;
}

int hash_table_contains(char *chave)
{
    int index = hash(chave);
    KeyValue *current = hash_table[index];
    while (current != NULL)
    {
        if (strcmp(current->chave, chave) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void hash_table_remove(char *chave)
{
    int index = hash(chave);
    KeyValue *current = hash_table[index];
    KeyValue *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->chave, chave) == 0)
        {
            if (previous == NULL)
            {
                hash_table[index] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current->chave);
            free(current->dado);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void free_hash_table()
{
    for (int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        KeyValue *current = hash_table[i];
        while (current != NULL)
        {
            KeyValue *temp = current;
            current = current->next;
            free(temp->chave);
            free(temp->dado);
            free(temp);
        }
    }
}
