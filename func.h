#include <vetor.h>



typedef struct MatrizEsparsa{
  VetorEsparso** linhasVetor;	//ponteiro para o VetorEsparso TAD (formando uma lista encadeada)
  VetorEsparso** colunasVetor;	//
  int linhas;	//Quantidade de linhas da MatrizEsparsa
  int colunas;	//Quantidade de colunas da MatrizEsparsa
}MatrizEsparsa;





// Funções MatrizEsparsa
MatrizEsparsa* ME_Criar(int n, int m);
int ME_NLinhas(MatrizEsparsa* M);
int ME_MColunas(MatrizEsparsa* M);
void ME_Atribuir(MatrizEsparsa* M, int lin, int col, double valor);
double ME_Buscar(MatrizEsparsa* M, int lin, int col);
VetorEsparso* ME_ObterLinha(MatrizEsparsa* M, int lin);
void ME_MultiplicaEscalar(MatrizEsparsa* M, double alpha);
VetorEsparso* ME_MultiplicaVetor(MatrizEsparsa* M, VetorEsparso* v);
MatrizEsparsa* ME_SomaMatriz(MatrizEsparsa* M, VetorEsparso* A);
MatrizEsparsa* ME_Carregar(char* nome_do_arquivo);
void ME_Salvar(MatrizEsparsa* M, char* nome_do_arquivo);
void ME_Destruir(MatrizEsparsa* M);


double** MD_Carregar(char* nome_do_arquivo, int* n, int* m);
void MD_MultiplicarMatrizVetor(double** M, int n, int m, double *v, double *resultado);



