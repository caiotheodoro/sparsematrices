/* #include "func.h"

VetorEsparso *VE_Criar(int n, int m, int valor)
{
    VetorEsparso *novo = (VetorEsparso *)malloc(sizeof(VetorEsparso));

    novo->coluna = m;


    return novo;
}

MatrizEsparsa *ME_Criar(int n, int m)
{
    MatrizEsparsa *novo = (MatrizEsparsa *)malloc(sizeof(MatrizEsparsa));
    novo->linhasVetor = (VetorEsparso **)malloc(sizeof(VetorEsparso *) * n);
    novo->colunasVetor = (VetorEsparso **)malloc(sizeof(VetorEsparso *) * m);
    novo->linhas = n;
    novo->colunas = m;

    for (int i = 0; i < novo->colunas; i++)
    {
        novo->linhasVetor[i] = VE_Criar(i, 0, 0);
    }
        for (int i = 0; i < novo->linhas; i++)
        {
            novo->colunasVetor[i] = VE_Criar(0, i, 0);
        }

    return novo;
}

ME_NLinhas(MatrizEsparsa* M){

    return M->linhas;
}
ME_MColunas(MatrizEsparsa* M){

    return M->colunas;
}

void ME_Atribuir(MatrizEsparsa* M, int n, int m, double valor){
    VetorEsparso *v;
    v = M->linhasVetor[n];
    return VE_Atribuir(v, m, valor);
}


double ME_Buscar(MatrizEsparsa *M, int n, int m)
{
    VetorEsparso *v;
    v = M->linhasVetor[n];
    return VE_Buscar(v, m);
}



VetorEsparso* ME_ObterLinha(MatrizEsparsa* M, int lin){
    if(lin >= M->linhas-1){
        printf("Erro. Valor fora de range.");
        return -1;
    }

    return M->linhasVetor[lin];

}

void ME_MultiplicaEscalar(MatrizEsparsa* M, double alpha){
    
}
 */