#include <vetor.h>>
#define tamHash 2

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
    if(VE_NNaoZeros(v) <= VE_NNaoZeros(u)){
        for(){} //falta terminar
    }

}


void VE_MultiplicaEscalar(VetorEsparso* v, double alpha){


}


VetorEsparso* VE_MultiplicaVetor(VetorEsparso* v, VetorEsparso* u){
    if( v->coluna != u->coluna){
        printf("Error! O número de colunas dos vetores devem ser iguais para a execução.");
        return 0;
    }
    //falta terminar

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
