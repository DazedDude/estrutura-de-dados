#ifndef TABELA_HASH_H
#define TABELA_HASH_H

void init_hash_table(int size);
char *hash_table_get(char *chave);
void hash_table_put(char *chave, char *dado);
int hash_table_contains(char *chave);
void hash_table_remove(char *chave);
void free_hash_table();

#endif
