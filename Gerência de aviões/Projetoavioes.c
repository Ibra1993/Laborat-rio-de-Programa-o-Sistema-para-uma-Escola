

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILA_VAZIA -1
#define DECOLOU_COM_SUCESSO 1
#define NAO_DECOLOU_COM_SUCESSO -1

struct avioes{

  int numero_do_aviao;
  char nome_do_aviao[100];
  char origem[100];
  char destino[100];

};

struct guardaElementos{

     struct avioes GUARDA;
     struct guardaElementos *proximo;
     
};

struct fila{

     struct guardaElementos *inicio;
     struct guardaElementos *fim;
     int quantidade;
};


typedef struct fila RETORNO;
typedef struct guardaElementos ESTRUTURA;

void flush_in();
void Listar_avioes_da_fila(RETORNO *ptr);
RETORNO *Cria_fila();
int Inserir_aviao_na_fila(RETORNO *ponteiro, struct avioes ins);
int numero_de_avioes_na_fila(RETORNO *ponteiro);
int Autorizar_decolagem_do_primeiro_aviao_da_fila(RETORNO *ptr);
void Listar_caracteristica_do_primeiro_aviao(RETORNO *ptr);
void liberar_a_fila(RETORNO *ptr);

void liberar_a_fila(RETORNO *ptr){

 if( ptr != NULL){

  ESTRUTURA *aux;

  while(ptr->inicio != NULL){

        aux = ptr->inicio;
        ptr->inicio = ptr->inicio->proximo;
        free(aux);
     }
     free(ptr);
  }


}


void Listar_caracteristica_do_primeiro_aviao_da_fila(RETORNO *ptr){

    ESTRUTURA *aux = ptr->inicio;
       

   printf("\n ========== Caracteristica do primeiro aviao da fila ========== \n\n");
  

   	  printf(" Numero de aviao: %d\n",  aux->GUARDA.numero_do_aviao);
      printf(" Nome do aviao: %s\n",    aux->GUARDA.nome_do_aviao);
      printf(" Origem do aviao: %s\n",  aux->GUARDA.origem);
      printf(" Destino do aviao: %s\n", aux->GUARDA.destino);

  

}


int Autorizar_decolagem_do_primeiro_aviao(RETORNO *ptr){

    int t;
	ESTRUTURA *aux;
	
	if(ptr == NULL){
		
    t =  FILA_VAZIA;
	
    }
    
	if(ptr->inicio == ptr->fim){
	
	  free(ptr->inicio);
	  ptr->inicio = NULL;
	  ptr->fim = NULL;
	  t =  DECOLOU_COM_SUCESSO;
	  ptr->quantidade --;
	  
    }else{
    	
    	aux = ptr->inicio;  
		ptr->inicio = ptr->inicio->proximo;
	    free(aux);
	    t =  DECOLOU_COM_SUCESSO;
	    ptr->quantidade--;
    }

    return t;
    return  NAO_DECOLOU_COM_SUCESSO;

}



int numero_de_avioes_na_fila(RETORNO *ponteiro){

   ESTRUTURA *aux = ponteiro->inicio;
   int cont = 0;

   while(aux != NULL){

   	  cont ++;
   	  aux = aux->proximo;
     
   }
    return cont;

}


void Listar_avioes_da_fila(RETORNO *ptr){

   ESTRUTURA *aux = ptr->inicio;
       

   printf("\n ========== Lista de  todos os avioes da fila ========== \n\n");
   while(aux != NULL){

   	  printf(" Numero de aviao: %d\n", aux->GUARDA.numero_do_aviao);
      printf(" Nome do aviao: %s\n", aux->GUARDA.nome_do_aviao);
      printf(" Origem do aviao: %s\n", aux->GUARDA.origem);
      printf(" Destino do aviao: %s\n", aux->GUARDA.destino);

   	  aux = aux->proximo;
      printf("\n\n");

   }

}



RETORNO *Cria_fila(){
   
   RETORNO *ptr = (RETORNO *) malloc(sizeof(RETORNO));

   if( ptr != NULL ){

     ptr->inicio = NULL;
     ptr->fim = NULL;
     ptr->quantidade = 0;

   }

   return ptr;

}

int Inserir_aviao_na_fila(RETORNO *ponteiro, struct avioes ins){

    if( ponteiro == NULL)
        return 0;

      ESTRUTURA *novo_no = (ESTRUTURA *) malloc(sizeof(ESTRUTURA));

      if(novo_no == NULL)
         return 0;

         novo_no->GUARDA = ins;
         novo_no->proximo = NULL;

      if(ponteiro->fim == NULL)
            ponteiro->inicio = novo_no;

      else
          ponteiro->fim->proximo = novo_no;
          ponteiro->fim = novo_no;
          ponteiro->quantidade ++;

          return 1;
            
}


void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}

}


int main(){

   struct avioes ins;
   RETORNO *RET;
   

    int opcao;
    int a, b, c;

   do{
		
		printf("\n ====================================================================\n\n");
        printf("\n =============== Menu =========== .\n");
		printf("\n LEMBRE-SE DE PRIMEIRO, RESERVAR MEMÓRIA PARA INSERÇÃO DE DADOS.\n");
		printf("\n         1- Reservar memória para Inserção dos aviões na fila                      \n");
        printf("\n         2- Adiconar/Inserir avião na fila  de espera                               \n");
		printf("\n         3- Listar aviões da fila                                                   \n");
	    printf("\n         4- Listas/Obter numeros/quantidade de avioes aguardando na fila de decolagem\n");
        printf("\n         5- Autorizar decolagem do primeiro avião na fila                             \n");
        printf("\n         6- Obter característica do primeiro avião da fila                             \n");
        printf("\n         7- SAIR                                                                        \n");
        printf("\n ====================================================================\n\n");

		printf("  Digite a opcão: ");
	    scanf("%d", &opcao);

     switch(opcao)
	{
    
 case 1:
      RET = Cria_fila();
      
      break;

 case 2:

     printf(" Digite o numero de avião: ");
     scanf(" %d", &ins.numero_do_aviao);
  
     printf(" Digite o nome do avião: ");
     flush_in();
     scanf(" %[^\n]", ins.nome_do_aviao);

     printf(" Digite a origem do avião: ");
     flush_in();
     scanf(" %[^\n]", ins.origem);

     printf(" Digite o destino do avião: ");
     flush_in();
     scanf("  %[^\n]", ins.destino);

      a = Inserir_aviao_na_fila( RET, ins );
     printf(" Se o valor de retorno for igual a 1 portanto, aviao inserido na fila com SUCESSO. VEJA ----> %d.\n", a);

     break;


 case 3:

     Listar_avioes_da_fila(RET);

     break;

  case 4:

     b = numero_de_avioes_na_fila(RET);
     printf(" O numero de aviães aguardando na fila de decolagem = %d\n", b);

     break;

   case 5:

      c = Autorizar_decolagem_do_primeiro_aviao(RET);
      printf(" Se o valor de retorno for igual a 1 portanto, avião decolou com sucesso. VEJA ----> %d.\n", c);

     break;

 case 6:


     Listar_caracteristica_do_primeiro_aviao_da_fila(RET);

     break;
     default:
     printf(" Valor INVALIDO!!\n");

    }
   
   }while(opcao != 7);
  
    liberar_a_fila(RET);



}









