typedef struct no{
   struct no* prox;
   char nome[30];
}no;
typedef struct Fila{
   struct no* prim;
   struct no* ult;
}Fila;

Fila* Cria_fila();

Fila* Insere(pt);
void ConsultaPosicao(Fila* pt);
Fila* IrAoBanheiro(Fila* pt);
void EspiarFila(Fila* pt);

Fila* Libera_fila(Fila *pt);