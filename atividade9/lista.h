typedef struct No
{
    float valor;
    struct No *proximo_no;
} No;

No *no(float valor, No *proximo_no);
void lista_inserir_no(No *H, No *no);
void lista_imprimir(No *H);
void lista_inserir_no_ordenado(No **H, No *no);
No *lista_copiar(No *H);