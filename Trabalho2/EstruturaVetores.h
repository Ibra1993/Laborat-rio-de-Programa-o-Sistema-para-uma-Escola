#include <stdio.h> 
#include <stdlib.h>

#define TAM 10
#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11

typedef struct reg {
	
	int conteudo;
    struct reg *prox;
  
} No;

struct estrutura{
	
	int quantidade;
	int tamanho;
	int *vetAux;
	
	
};

 struct estrutura vetorPrincipal[TAM];
                           //int vetorPrincipal[TAM];  inusitado o tipo INT incompatível com o tipo struct
void inicializar();
int criarEstruturaAuxiliar(int tamanho, int posicao);
int ehPosicaoValida(int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
void shiftEsquerda(int posicao, int posicaoElemento); 
void finalizar();
void insertionSort(int *vetor, int tamanho);
int getQuantidadeTotalElementos();


No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void inserirFimListaEncadeada(No **inicio, int valor);
void destruirListaEncadeadaComCabecote(No** inicio);





