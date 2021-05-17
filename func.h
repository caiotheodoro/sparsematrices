#define tamHash 5
typedef struct VetorEsparso{
  int coluna;
  THEA *tabela;
}VetorEsparso;

typedef enum ESTADO {
 E_LIVRE,
 E_OCUPADO,
 E_APAGADO
} ESTADO;

typedef struct ELEM {
    int chave;
    int valor;
    ESTADO estado;
}ELEM;

typedef struct THEA{
 ELEM* tabela;
 int m; // tamanho total
 int n; // quantidade total de posições ocupadas
}THEA;


typedef struct MatrizEsparsa{
  VetorEsparso** linhasVetor;	//ponteiro para o VetorEsparso TAD (formando uma lista encadeada)
  VetorEsparso** colunasVetor;	//
  int linhas;	//Quantidade de linhas da MatrizEsparsa
  int colunas;	//Quantidade de colunas da MatrizEsparsa
}MatrizEsparsa;

// Funções de Hash
static void  THEA_Redimensionar(THEA* TH, int m_novo);
int THEA_Hash(VetorEsparso * v, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar (THEA * TH, int chave);
int THEA_Remover(THEA *TH,int chave);
void THEA_Imprimir(THEA* TH);

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
      //  printf("redimensionada de %d para %d n = %d\n",TH->m, TH->m*2, TH->n);
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

//==========================================
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


}


void VE_MultiplicaEscalar(VetorEsparso* v, double alpha){


}


VetorEsparso* VE_MultiplicaVetor(VetorEsparso* v, VetorEsparso* u){


}

VetorEsparso* VE_SomaVetor(VetorEsparso* v, VetorEsparso* u){ //soma por coluna
  if( v->coluna != u->coluna){
    printf("Error! O número de colunas dos vetores devem ser iguais para a execução.");
    return 0;
  }else {

  }
}

void VE_Destruir(VetorEsparso* v){
  free(v->tabela->tabela);
  free(v->tabela);
  free(v);
}