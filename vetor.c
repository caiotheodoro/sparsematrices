#include "vetor.h"
#include "hash.h"


VetorEsparso *VE_Criar( int m){
  int *v;
  int tam;
    VetorEsparso *novo = (VetorEsparso *)malloc(sizeof(VetorEsparso));
    novo->tabela = THEA_Criar(tamHash);
    novo->coluna = m;
    return novo;
}

int VE_Dimensao(VetorEsparso* v){ 
  return v->coluna;
}


int VE_NNaoZeros(VetorEsparso* v){ // matriz nao grava numero 0 na matriz
 return v->tabela->n;
}


void VE_Atribuir(VetorEsparso* v, int col, double valor){

}


double VE_Buscar(VetorEsparso* v, int col){
  if(col >= 0 && col < v->coluna ) return 0;
  if(col > 0 && col < v->coluna-1){
    printf("Error! Acesso ilegal da posicao\n");
  }
  if(THEA_Buscar(v->tabela, col)  == 1) return 0;

  else return v->tabela->tabela[THEA_Buscar(v->tabela, col)].valor;
}

double VE_ProdutoEscalar(VetorEsparso* v, VetorEsparso* u){

    double res = 0;
    for (int i = 0; i < n; i++){
        res += v->tabela[i]->tabela->chave* u->tabela[i]->tabela->chave;
    }

    return res;

}


void VE_MultiplicaEscalar(VetorEsparso* v, double alpha){

    for(int i=0;i<v->coluna;i++){
      v->tabela[i]->tabela->valor *= alpha;
      v->tabela[i]->tabela->chave *= alpha;   
    }

}


VetorEsparso* VE_MultiplicaVetor(VetorEsparso* v, VetorEsparso* u){

  if(v->colunas != u->colunas) return -1;

  VetorEsparso *novo = (VetorEsparso *)malloc(sizeof(VetorEsparso));
    novo->tabela = THEA_Criar(v->coluna);
    novo->coluna = v->coluna;
 
    for(int i=0; o< v->coluna;i++){

    novo->tabela[i]->tabela->valor = v->tabela[i]->tabela->valor * u->tabela[i]->tabela->valor;

    }

  return novo;
}

VetorEsparso* VE_SomaVetor(VetorEsparso* v, VetorEsparso* u){ //soma por coluna
  if( v->coluna != u->coluna){
    printf("Error! O número de colunas dos vetores devem ser iguais para a execução.");
    return 0;
  }else {
      // falta terminar 
  }
}

void VE_Destruir(VetorEsparso* v){
  free(v->tabela->tabela);
  free(v->tabela);
  free(v);
}