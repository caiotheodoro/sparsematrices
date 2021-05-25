#include "func.h"

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

    for (int i = 0; i < M->linhas; i++)
    {
        VE_MultiplicaEscalar(M->linhasVetor[i],alpha);
    }


}

MatrizEsparsa* ME_Carregar(MatrizEsparsa* M,char* nome_do_arquivo){

 FILE *arquivo;
    char palavra[100];
    char *linha;
    unsigned int i = 0;
    int valores[3];
    int lin, col, val;
    int flag, counter;

    arquivo = fopen(nome_do_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("arquivo vazio");
    }
    for(int i=0;i<3;i++){
        linha = fgets(palavra, 100, arquivo);
        valores[i] = (int)linha;
    }

    while (!feof(arquivo))
    {
        linha = fgets(palavra, 100, arquivo);
        if (linha)
        {
            linha[0] = lin;
            linha[2] = col;           
            linha[4] = val;
            ME_Atribuir(M, lin,col,val);
            
        }
    }
    fclose(arquivo);

}