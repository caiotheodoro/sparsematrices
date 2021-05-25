#include "vetor.h"
#include "hash.h"
#include "func.h"

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
    if(col >= 0 && col < v->coluna ) return 0;
    if(col > 0 && col < v->coluna-1){
       printf("Error! Acesso ilegal da posicao\n");
       return 0;
    }

    int posicao = THEA_Buscar(v->tabela, col);

    if(valor == 0 && posicao != -1)
        THEA_Remover(v->tabela, col);
    
    else if(valor != 0 && posicao == -1)
        v->tabela->tabela[posicao].valor;

    else THEA_Inserir(v->tabela, col, valor);
}


double VE_Buscar(VetorEsparso* v, int col){
  if(col >= 0 && col < v->coluna ) return 0;
  if(col > 0 && col < v->coluna-1){
    printf("Error! Acesso ilegal da posicao\n");
    return 0;
  }
  if(THEA_Buscar(v->tabela, col)  == 1) return 0;

  else return v->tabela->tabela[THEA_Buscar(v->tabela, col)].valor;
}

double VE_ProdutoEscalar(VetorEsparso* v, VetorEsparso* u){
    if(VE_Dimensao(v->coluna) != VE_Dimensao(u->coluna)){
        printf("Error! Para que a operacao seja possivel o numero de coluna dos vetores devem ser iguais.");
        return 0;
    }

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
    if( v->coluna != u->coluna){
        printf("Error! O número de colunas dos vetores devem ser iguais para a execução.");
        return 0;
    }

  VetorEsparso *novo = (VetorEsparso *)malloc(sizeof(VetorEsparso));
    novo->tabela = THEA_Criar(v->coluna);
    novo->coluna = v->coluna;
 
<<<<<<< HEAD
    for(int i=0; i< v->coluna;i++){
=======
    for(int i=0; i < v->coluna;i++){
>>>>>>> f67900c17c2dcea45c8e499c25c5f666618c575b

      novo->tabela[i]->tabela->valor = v->tabela[i]->tabela->valor * u->tabela[i]->tabela->valor;

    }

  return novo->tabela[i]->tabela->valor;
}

VetorEsparso* VE_SomaVetor(VetorEsparso* v, VetorEsparso* u){ 
  VetorEsparso *novo = (VetorEsparso *)malloc(sizeof(VetorEsparso));
  int i;

  if( v->coluna != u->coluna){
    printf("Error! O número de colunas dos vetores devem ser iguais para a execução.");
    return 0;
  }
    novo->tabela = THEA_Criar(v->coluna);
    novo->coluna = v->coluna;
 
    for( i=0; i< v->coluna;i++){

      novo->tabela[i]->tabela->valor = v->tabela[i]->tabela->valor + u->tabela[i]->tabela->valor;

    }

  return novo->tabela[i]->tabela->valor;
}

void VE_Destruir(VetorEsparso* v){
  free(v->tabela->tabela);
  free(v->tabela);
  free(v);
}
