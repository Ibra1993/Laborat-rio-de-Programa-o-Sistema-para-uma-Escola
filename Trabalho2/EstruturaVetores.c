#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"


void inicializar(){
	
	int i;
	
	for( i = 0; i < TAM; i ++){
		vetorPrincipal[i].vetAux = NULL;
		vetorPrincipal[i].tamanho = 0;
		vetorPrincipal[i].quantidade = 0;
	}
	
}

int criarEstruturaAuxiliar(int tamanho, int posicao){
	
	int retorno = 0;
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
		retorno = POSICAO_INVALIDA;
	}
	
	else if(vetorPrincipal[posicao-1].vetAux != NULL){
		
		   retorno = JA_TEM_ESTRUTURA_AUXILIAR;
		   
	}else if(tamanho < 1){
		retorno = TAMANHO_INVALIDO;
		
	}
	
	else{
		vetorPrincipal[posicao-1].vetAux = (int *) malloc(sizeof(int));
		if(vetorPrincipal[posicao-1].vetAux != NULL){
		vetorPrincipal[posicao-1].tamanho = tamanho;
		retorno = SUCESSO;
	  }
	  
	  else{
	  	retorno =  SEM_ESPACO_DE_MEMORIA;
	  }
	  
	}
	return (retorno);
	
}

int ehPosicaoValida(int posicao){
	
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        return  POSICAO_INVALIDA;
    }
	else {
		return SUCESSO;
	}
	

    

}

int inserirNumeroEmEstrutura(int valor, int posicao){
	
	int retorno = 0;
    
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
	
	retorno = POSICAO_INVALIDA;

	
	}else{
		
		if(vetorPrincipal[posicao-1].vetAux != NULL){
			
			if(vetorPrincipal[posicao-1].quantidade < vetorPrincipal[posicao-1].tamanho){
				
				vetorPrincipal[posicao-1].vetAux[vetorPrincipal[posicao-1].quantidade] = valor;
				
				vetorPrincipal[posicao-1].quantidade ++;
				
				retorno = SUCESSO;
				
			}else{
				retorno = SEM_ESPACO;
			}
			
		}else{
			
			retorno = SEM_ESTRUTURA_AUXILIAR;
		}
			
	}
	
	
	return (retorno);
	
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
	
	int retorno = 0;
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
	
	retorno = POSICAO_INVALIDA;
	
    }else if(vetorPrincipal[posicao-1].vetAux == NULL){
    	
    	   retorno = SEM_ESTRUTURA_AUXILIAR;
    	   
	}else if(vetorPrincipal[posicao-1].quantidade < 1){
		    retorno = ESTRUTURA_AUXILIAR_VAZIA;
	}else{
		vetorPrincipal[posicao-1].quantidade --;
		retorno = SUCESSO;
	}
    
    return (retorno);

}



int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
	
	int retorno = 0;
	int i;
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
	
	retorno = POSICAO_INVALIDA;
	
    }else if(vetorPrincipal[posicao-1].vetAux == NULL){
    	retorno = SEM_ESTRUTURA_AUXILIAR;
	}else if(vetorPrincipal[posicao-1].quantidade < 1){
		
		retorno =  ESTRUTURA_AUXILIAR_VAZIA;
		
	}
	
	else{
		
		int i;
		for( i = 0; i < vetorPrincipal[posicao-1].quantidade; i ++){
			if(vetorPrincipal[posicao-1].vetAux[i] != valor){
				
				retorno = NUMERO_INEXISTENTE;
				
			}else{
				
				shiftEsquerda( posicao,  i);
				vetorPrincipal[posicao-1].quantidade --;
				retorno = SUCESSO;
			}
		}
		
		
	}
    return (retorno);
    
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	
	int retorno = 0;
	
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
	
	retorno = POSICAO_INVALIDA;
	
    }else if( vetorPrincipal[posicao-1].vetAux == NULL ){
    	
    retorno =  SEM_ESTRUTURA_AUXILIAR;
    
	}else if(vetorPrincipal[posicao-1].quantidade == 0){
		
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
		
	}
	
	else{
		
		int i;
		for( i = 0; i < vetorPrincipal[posicao-1].quantidade; i ++){
			vetorAux[i] = vetorPrincipal[posicao-1].vetAux[i];
			
		}
		retorno = SUCESSO;
	}
	return (retorno);
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	
	int retorno = 0;
	
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
	
	retorno = POSICAO_INVALIDA;
	
    }else if( vetorPrincipal[posicao-1].vetAux == NULL ){
    	
    retorno =  SEM_ESTRUTURA_AUXILIAR;
    
	}else if(vetorPrincipal[posicao-1].quantidade == 0){
		
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
		
	}
	
	else{
		
		int i;
		int Total_de_Elementos;
		int j;
		int k;
		int aux;
		
		for( i = 0; i < vetorPrincipal[posicao-1].quantidade; i ++){
			Total_de_Elementos = i;
			vetorAux[i] = vetorPrincipal[posicao-1].vetAux[i];
		}
		
		for( j = 0; j <= Total_de_Elementos; j ++){
			for( k = j + 1; k <= Total_de_Elementos; k ++){
				if( vetorAux[k] < vetorAux[j] ){
					aux = vetorAux[j];
					vetorAux[j] = vetorAux[k];
					vetorAux[k] = aux;
					retorno = SUCESSO;
					
				}
			}
		}
			
	}
	return (retorno);
	
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	
		
	int i, j, k = 0, count = 0;
    int retorno = 0, l;
    
    for(i = 0 ; i < TAM ; i++){

        if(vetorPrincipal[i].quantidade > 0){

            for(j = 0 ; j < vetorPrincipal[i].quantidade; j++){
                vetorAux[k] = vetorPrincipal[i].vetAux[j];
                k++;
              
              
            }

        }else{
		
            count++;
       }
       
   }


    if(count == 10)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        return SUCESSO;
        
        
}

	
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

     int retorno = 0;
	 int tamanho, memoria_insuficeinte;

     tamanho = vetorPrincipal[posicao-1].tamanho + novoTamanho;
     
    
	if(ehPosicaoValida(posicao) != SUCESSO)
	
	retorno = POSICAO_INVALIDA;

	

     else if( vetorPrincipal[posicao-1].vetAux == NULL )
    	
    	retorno =  SEM_ESTRUTURA_AUXILIAR;

  	
	    else if( tamanho  < 1)

             retorno =  NOVO_TAMANHO_INVALIDO;
         
   else{
   	
   
  	vetorPrincipal[posicao-1].vetAux = (int*) realloc (vetorPrincipal[posicao-1].vetAux,  tamanho * sizeof(int));

   	if(vetorPrincipal[posicao-1].vetAux == NULL){
	   
        retorno = SEM_ESPACO_DE_MEMORIA;
        
        }else{
        	
          vetorPrincipal[posicao-1].tamanho = tamanho;
          retorno = SUCESSO;

        if(tamanho < vetorPrincipal[posicao-1].quantidade ){
		vetorPrincipal[posicao-1].quantidade = tamanho;
		  retorno = SUCESSO; 
	}

	} 
                               
   }
   
   return retorno; 
   
   
     
}
  
    

int getQuantidadeElementosEstruturaAuxiliar(int posicao){

	int retorno = 0;
   
   if(ehPosicaoValida(posicao) != SUCESSO){
   
        retorno =  POSICAO_INVALIDA;
        
   } else if( vetorPrincipal[posicao-1].vetAux == NULL){
   
        retorno = SEM_ESTRUTURA_AUXILIAR;
        
   }else if( vetorPrincipal[posicao-1].quantidade < 1){
   
       retorno = ESTRUTURA_AUXILIAR_VAZIA;
       
   }else {
   
   	
   	   retorno = vetorPrincipal[posicao-1].quantidade;
   }
       
       
      return (retorno);  
     
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

	 int i, j, k = 0, cont = 0, retorno;

		for( i = 0; i < 10; i++){
			if(vetorPrincipal[i].quantidade > 0){
				for(j = 0; j < vetorPrincipal[i].quantidade ; j++){
					vetorAux[k] = vetorPrincipal[i].vetAux[j];
					k++;

				}

			}else
			cont++;
		}
		if(cont == 10)
			return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
		else{
		      
			  insertionSort( vetorAux, getQuantidadeTotalElementos());

		return SUCESSO;

		}

	}


void finalizar(){
 	int i;
    for( i=0; i < TAM; i++){

        if( vetorPrincipal[i].vetAux != NULL)
            free( vetorPrincipal[i].vetAux);
    }
}

void shiftEsquerda(int posicao, int posicaoElemento){
	
	 int i;
	 for( i = posicaoElemento; i < (vetorPrincipal[posicao-1].tamanho)-1; i ++){
	 	vetorPrincipal[posicao-1].vetAux[i] = vetorPrincipal[posicao-1].vetAux[i+1];
	 	
	 }
}

int getQuantidadeTotalElementos(){

	int qtdTotal = 0;
    int i;
    for( i = 1; i <= TAM; i++){
        if(getQuantidadeElementosEstruturaAuxiliar(i) > 0)
            qtdTotal = qtdTotal + getQuantidadeElementosEstruturaAuxiliar(i);
    }
    return qtdTotal;


}

void insertionSort(int *vetor, int tamanho){

	int i;
	int j;
	int aux;

	for( i = 0; i < tamanho; i++){

		for( j = i+1; j < tamanho; j++){
		    if(vetor[j] < vetor[i]){
		    	aux = vetor[i];
		    	vetor[i] = vetor[j];
		    	vetor[j] = aux;
			}
	   }
   }

}


No* montarListaEncadeadaComCabecote(){
    
    int ret = 0;
    No *ini = NULL; 
    
    
    int qtdTotalElementos = getQuantidadeTotalElementos();
     int vetorAux[qtdTotalElementos];
    
    ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    
    
    int i;
    if(ret == SUCESSO){
    	
    for( i = 0 ; i < qtdTotalElementos; i++)
    		
    inserirFimListaEncadeada(&ini, vetorAux[i]);
    
    return ini;
			
	}else{

		return NULL;

	}
			   
   

}

/*
Objetivo: retorna os números da lista encadeada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){

    No *atual = inicio;
    int i = 0;

           	
		while( atual != NULL){
		
            vetorAux[i] = atual->conteudo; 
             atual = atual->prox;
             i++;
            
        }

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
    
      
      
      No* atual = *inicio;  
      No* proximo;  
  
        while ( atual != NULL)  
        {  
            proximo = atual->prox;  
            free(atual);  
            atual = proximo;  
        }  
              

        *inicio = NULL;
     
}
      




void inserirFimListaEncadeada(No **inicio, int valor){

    
    No *novo = (No *)malloc(sizeof(No));       
    novo->conteudo = valor;
	    
	    if(*inicio == NULL){
	    	
	    	novo->prox = NULL;
	    	*inicio = novo;
	    		
		}else{
			
			No *aux;
			
			aux = *inicio;
			
			while(aux->prox != NULL){
				
				aux = aux->prox;
				
			}
			
	      novo->prox = NULL;
		  aux->prox = novo;
		  		
		}
		
    
}






