#define max 10

typedef struct Fila{
   char fila[max][30]; 
   int inicio;
   int final;
   int n;
}Fila;

Fila* Cria_fila();

Fila* Insere(pt);
void ConsultaPosicao(Fila* pt);
Fila* IrAoBanheiro(Fila* pt);
void EspiarFila(Fila* pt);

Fila* Libera_fila(Fila *pt);