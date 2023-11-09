
typedef struct No
{
    char valor;
    struct No *proximo_no;
} No;

No *no(char valor, No *proximo_no);
void lista_inserir_no(No *H, No *no);
void lista_imprimir(No *H);
No *lista_copiar(No *H);
void lista_concatenar(No *H, No *Hc);
void lista_liberar(No *H);
int lista_tamanho(No *H);
int verifica_existencia(No *H, char valor_busca);
int lista_verificar_ocorrencias(No *H, char valor_busca);
void lista_imprimir_inversa(No *H);
void lista_inserir_no_i(No *H, int i, char valor);
void lista_remover_no_i(No *H, int i);
void lista_remover_no(No *H, char valor_busca);