#include "vetor.h"

#define tamHash 5


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
 int m; // tam total
 int n; // qtde total de posições ocupadas
}THEA;

// Funções de Hash
static void  THEA_Redimensionar(THEA* TH, int m_novo);
int THEA_Hash(VetorEsparso * v, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar (THEA * TH, int chave);
int THEA_Remover(THEA *TH,int chave);
void THEA_Imprimir(THEA* TH);