#include "hash.h"

typedef struct VetorEsparso{
  int coluna;
  THEA *tabela;
}VetorEsparso;

// Funções VetorEsparso
VetorEsparso* VE_Criar( int m);
int VE_Dimensao(VetorEsparso* v);
int VE_NNaoZeros(VetorEsparso* v);
void VE_Atribuir(VetorEsparso* v, int col, double valor);
double VE_Buscar(VetorEsparso* v, int col);
double VE_ProdutoEscalar(VetorEsparso* v, VetorEsparso* u);
void VE_MultiplicaEscalar(VetorEsparso* v, double alpha);
VetorEsparso* VE_MultiplicaVetor(VetorEsparso* v, VetorEsparso* u);
VetorEsparso* VE_SomaVetor(VetorEsparso* v, VetorEsparso* u);
void VE_Destruir(VetorEsparso* v);