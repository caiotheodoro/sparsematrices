#include <hash.h>

static void  THEA_Redimensionar(THEA* TH, int m_novo){
    ELEM  *nova, *antiga; // ponteiro para a nova tabela e uma para a tabela velha
    int i, m_antigo; 

    nova = malloc(sizeof(ELEM) * m_novo);
    for(i = 0; i < m_novo;i ++){
        nova[i].estado = E_LIVRE;
    }
    antiga = TH->tabela;
    m_antigo = TH->m;
    TH->tabela = nova;
    TH->m = m_novo;
    TH->n = 0;

    for(i = 0; i < m_antigo; i++){
        if(antiga[i].estado == E_OCUPADO){
            THEA_Inserir(TH,antiga[i].chave, antiga[i].valor);
        }
    }
    free(antiga);
}

int THEA_Hash(VetorEsparso * v, int chave, int k) {
    return ((chave % v ->coluna) + k) % v -> coluna;
}

THEA* THEA_Criar(int m){
  int i;

  THEA *novo = (THEA *)malloc(sizeof(THEA));
  novo->tabela = (ELEM *)malloc(sizeof(ELEM)*m);
  novo->m = m;

  novo->n = 0;

  for(i = 0; i < m; i++){ 
      novo->tabela[i].estado = E_LIVRE;
  }
    return novo;
}

int THEA_Inserir(THEA *TH, int chave, int valor){
    int h, k, h_inicial;
    k = 0;

    if(TH->n > TH->m / 2){
      // printf("redimensionada de %d para %d n = %d\n",TH->m, TH->m*2, TH->n);
        THEA_Redimensionar(TH,TH->m * 2);
    }

    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

  while(TH->tabela[h].estado == E_OCUPADO){
      TH->m++;
      if(TH->tabela[h].chave == chave){
          TH->n--;
          break;
      }
      k++;
      h = THEA_Hash(TH, chave, k);

      if(h == h_inicial)
        return -1;
  }
  
    TH->n++;
    TH->tabela[h].chave = chave;
    TH->tabela[h].valor = valor;
    TH->tabela[h].estado = E_OCUPADO;

    return h;

}
int THEA_Buscar (THEA * TH, int chave){
  int h, h_inicial,k;
  k = 0;

  h = THEA_Hash(TH, chave,k);
  h_inicial = h;

  while(TH->tabela[h].estado != E_LIVRE){
      if(TH->tabela[h].estado == E_OCUPADO && TH->tabela[h].chave == chave){
          return h;
      }
      k++;
      h = THEA_Hash(TH,chave, k );
       
      if(h_inicial == h){
          return -1;
      }
  }
  return -1;
}

int THEA_Remover(THEA *TH,int chave){
    int pos;

    pos = THEA_Buscar(TH, chave);
    if( pos != -1) return -1;
        TH->tabela[pos].estado = E_APAGADO;
        TH->n--;
        return pos;
}

void THEA_Imprimir(THEA* TH){
  int i;
  char estado;

  for(i = 0; i < TH->m; i ++){
      if(TH->tabela[i].estado == E_OCUPADO)
      estado = 'O';

      else if(TH->tabela[i].estado == E_APAGADO)
      estado = 'A';

      else
      estado = 'L';

      printf("%d: %d , %c \n",i,TH->tabela[i].chave,estado);
  }

}