#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ATUALIZADO_COM_SUCESSO 1

#include "Escola.h"

int QUANTIDADE_DE_PROFESSORES(RETORNO *ini){

  ESTRUTURA *aux = *ini;
  int cont = 0;

    while(aux != NULL ){

     cont++;
     aux = aux->proximo;

    }

   return cont;

}




int ATUALIZAR_LISTA_DE_PROFESSORES(RETORNO *li, int matricula){

    
	char NOME[100];
	int MATRICULA;
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    unsigned long long int CPF;
    char DISCIPLINA[100];
	int valida = 0;
	int val = 0, valS = 0,  valD = 0,  valM = 0,  valA = 0,  valCPF = 0;

	int opcao;
	int i;
	int retorno = 0;
    ESTRUTURA *aux = *li;

	char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";
    int validaMatricula = 0;




    while( aux != NULL)
    {

     if(  aux->DADOS.matricula  != matricula )
     {
         valida = 0;

     }else{

         valida = 1;
      }

      aux = aux->proximo;

    }

    if( valida == 0 )
	{

		return -1;

	}



   else{

    printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf(" 1- Todos os campos; 2- Nome; 3- Sexo; 4- Dia de Nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8- Matricula\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

    if( opcao == 1 ){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);
       
       if(MATRICULA < 1)
       {
       	validaMatricula = 1;
       	
       	while(validaMatricula == 1)
       	{
       		
       	printf(" Novo numero de matricula INVALIDO!\n");
       	printf(" Digite de novo, o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);
		
		if(MATRICULA > 0)
		{
			
			validaMatricula  = 0;
			
	      }
		
		}
	}
       validaMatricula  = 0;
       
	    printf(" Digite o novo sexo do aluno: ");
		scanf(" %[^\n]", SEXO);

	    if( strcmp( SEXO, sexo1) != 0 && strcmp( SEXO, sexo2) != 0 && strcmp(SEXO, sexo3) != 0 && strcmp(SEXO, sexo4) != 0 && strcmp(SEXO, sexo5) != 0 && strcmp(SEXO, sexo6) != 0)
	    {
	    	val = 1;

	    	while( val == 1)
			{
				printf(" Novo sexo do aluno INVALIDO!!!\n");
	    		printf(" Digite o novo sexo do aluno: ");
		        scanf(" %[^\n]", SEXO);

		if( strcmp( SEXO, sexo1) == 0 || strcmp( SEXO, sexo2) == 0  || strcmp(SEXO, sexo3) == 0  || strcmp(SEXO, sexo4) == 0  || strcmp(SEXO, sexo5) == 0  || strcmp(SEXO, sexo6) == 0)
           {

           		val = 0;

		   }
	    }
	}
	     val = 0;
	     printf(" Digite o novo dia de nascimeto: ");
		 scanf(" %d", &DIA);

		 if( DIA <= 0 || DIA > 31){

		 	valD = 1;

		 	while( valD == 1){

		 	 printf(" Novo dia de nascimeto INVALIDO!\n");
		 	 printf(" Digite o novo dia de nascimeto: ");
		     scanf(" %d", &DIA);

		     if( DIA >= 1 && DIA <= 31){

		     	valD = 0;

			    }
			 }
		 }
	       valD = 0;

		printf(" Digite o novo mes de nascimeto: ");
		scanf(" %d", &MES);

		if( MES <= 0 || MES > 12 ){

			valM = 1;

			while( valM == 1 ){

				printf(" Novo mes de nascimeto INVALIDO!!\n");
				printf(" Digite o novo mes de nascimeto: ");
		        scanf(" %d", &MES);

		        if( MES >=1 && MES <= 12 ){

		        	valM = 0;
				}
			}
		}

		valM = 0;

			printf(" Digite o novo ano de nascimeto: ");
		    scanf(" %d", &ANO);

		    if( ANO <= 0){

		    	valA = 1;

		    	while (valA == 1 ){

		    	printf(" Novo ano de nascimeto INVALIDO\n");
		    	printf(" Digite o novo ano de nascimeto: ");
		    	scanf(" %d", &ANO);

		    	if( ANO > 0){

		    		valA = 0;

				   }
				}
			}

			valA = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &CPF);

		if( CPF <= 9999999999 || CPF > 99999999999 ){

			valCPF = 1;

			while( valCPF == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 ){

			valCPF = 0;

		   }
	   }

	}
		valCPF = 0;
        
		for( aux = *li; aux != NULL; aux = aux->proximo)
        {

		if( aux->DADOS.matricula == matricula)
        {

			strcpy(aux->DADOS.nome, NOME);
			aux->DADOS.matricula = MATRICULA;
			strcpy(aux->DADOS.sexo,SEXO);
			aux->DADOS.dia = DIA;
			aux->DADOS.mes = MES;
			aux->DADOS.ano = ANO;
			aux->DADOS.cpf = CPF;

        }


		 }

		 retorno  = ATUALIZADO_COM_SUCESSO;
         return retorno;

	}else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( aux = *li; aux != NULL; aux = aux->proximo){

			if(  aux->DADOS.matricula == matricula ){

				strcpy(aux->DADOS.nome, NOME);

			}	

		}

		retorno  = ATUALIZADO_COM_SUCESSO;
        return retorno;

	}else if(opcao == 3){

		int SS = 0;

		 printf(" Digite o novo sexo do aluno: ");
		 scanf(" %[^\n]", SEXO);

	    if( strcmp( SEXO, sexo1) != 0 && strcmp( SEXO, sexo2) != 0 && strcmp(SEXO, sexo3) != 0 && strcmp(SEXO, sexo4) != 0 && strcmp(SEXO, sexo5) != 0 && strcmp(SEXO, sexo6) != 0)
	    {
	    	SS = 1;

	    	while( SS == 1)
			{
				printf(" Novo sexo do aluno INVALIDO!!!\n");
	    		printf(" Digite o novo sexo do aluno: ");
		        scanf(" %[^\n]", SEXO);

		if( strcmp( SEXO, sexo1) == 0 || strcmp( SEXO, sexo2) == 0  || strcmp(SEXO, sexo3) == 0  || strcmp(SEXO, sexo4) == 0  || strcmp(SEXO, sexo5) == 0  || strcmp(SEXO, sexo6) == 0)
           {

           		SS = 0;

		   }
	    }
	}
	   SS = 0;

		for( aux = *li; aux != NULL; aux = aux->proximo){

			if(  aux->DADOS.matricula == matricula ){

				strcpy( aux->DADOS.sexo, SEXO );

			}

           
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
        return retorno;

	  }else if( opcao == 4 ){

		int jj = 0;

		printf(" Digite o novo dia de nascimeto: ");
		scanf(" %d", &DIA);

		 if( DIA <= 0 || DIA > 31){

		 	jj = 1;

		 	while( jj == 1){

		 	 printf(" Novo dia de nascimeto INVALIDO!\n");
		 	 printf(" Digite o novo dia de nascimeto: ");
		     scanf(" %d", &DIA);

		     if( DIA >= 1 && DIA <= 31){

		     	jj = 0;

			    }
			 }
		 }

		jj = 0;

		for( aux = *li; aux != NULL; aux = aux->proximo){

			if(  aux->DADOS.matricula == matricula ){

				aux->DADOS.dia = DIA;

			}

			
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
        return retorno;

	  } else if(opcao == 5){

		int kk = 0;

		printf(" Digite o novo mes de nascimeto: ");
		scanf(" %d", &MES);

		if( MES <= 0 || MES > 12 ){

			kk = 1;

			while( kk == 1 ){

				printf(" Novo mes de nascimeto INVALIDO!!\n");
				printf(" Digite o novo mes de nascimeto: ");
		        scanf(" %d", &MES);

		        if( MES >=1 && MES <= 12 ){

		        	kk = 0;
				}
			}
		}

		kk = 0;

			for( aux = *li; aux != NULL; aux = aux->proximo){

				if(  aux->DADOS.matricula == matricula ){

					aux->DADOS.mes = MES;

				}

			
			}


	    	retorno  = ATUALIZADO_COM_SUCESSO;
            return retorno;

	   }else if(opcao == 6){

		  int ii = 0;

			printf(" Digite o novo ano de nascimeto: ");
		    scanf(" %d", &ANO);

		    if( ANO <= 0){

		    	ii = 1;

		    	while (ii == 1 ){

		    	printf(" Novo ano de nascimeto INVALIDO\n");
		    	printf(" Digite o novo ano de nascimeto: ");
		    	scanf(" %d", &ANO);

		    	if( ANO > 0){

		    		ii = 0;

				   }
				}
			}

			ii = 0;

			for( aux = *li; aux != NULL; aux = aux->proximo){

				if( aux->DADOS.matricula == matricula ){

				aux->DADOS.ano = ANO;

				}

				

			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;
            return retorno;


	  }else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &CPF);

		if( CPF <= 9999999999 || CPF > 99999999999 ){

			cc = 1;

			while( cc == 1 )
            {

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 )
        {

			cc = 0;

		   }
	   }

	}
		cc = 0;

		for( aux = *li; aux != NULL; aux = aux->proximo){

				if( aux->DADOS.matricula == matricula ){

				 aux->DADOS.cpf = CPF;

				}
				

			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;
            return retorno;

	   }else if( opcao == 8){
       
       int ww = 0;
		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);
        
        if(matricula < 1)
        {
        	ww = 1;
        	
        	while(ww == 1)
        	{
        		printf(" Novo numero de matricula INVALIDO!\n");
        		printf(" Digite o novo numero de matricula do aluno: ");
		        scanf(" %d", &MATRICULA);
        		
        		if(matricula > 0)
        		{
        			
        				ww = 0;
        			
				}
			}
		}
		
		ww = 0;
		for( aux = *li; aux != NULL; aux = aux->proximo){

			if( aux->DADOS.matricula == matricula ){

				aux->DADOS.matricula = MATRICULA;

				}

				
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;

	   }

    }


}



void libera_memoria_reservada_para_disciplinas(struct disciplina *t){
	
	struct disciplina *aux;

		
		while(t != NULL){
			
			aux = t;
			t = t->proximo;
			free(aux);
		}
		free(t);
	     t = NULL;
	
	
	
}

void libera_memoria_reservada_para_alunos(Lista *li){
	
	Elem *aux;
	
	if(li != NULL){
		
		while((*li) != NULL){
			
			aux = *li;
			*li = (*li)->prox;
			free(aux);
		}
		free(li);
        li = NULL;
	}
	
	
	
	
}


void IMPRIMIR_LISTA_DE_PROFESSORES_DE_SEXO_MASCULINO(RETORNO *ini){


    printf("\n\n");
	printf("\n============ Lista de PROFESSORES de sexo masculino ============\n");
	printf("\n");
    
	ESTRUTURA *aux;
	
	for(aux = *ini; aux != NULL; aux = aux->proximo)
	{
		if(strcmp( aux->DADOS.sexo, "M" ) == 0 || strcmp(aux->DADOS.sexo, "m" ) == 0 )
		{
			printf(" ------> %s\n", aux->DADOS.nome);
		}
	}

}


void IMPRIMIR_LISTA_DE_PROFESSORES_DE_SEXO_FEMININO(RETORNO *ini){

    printf("\n\n");
	printf("\n============ Lista de PROFESSORAS (sexo feminino) ============\n");
	printf("\n");
    
	ESTRUTURA *aux;
	
	for(aux = *ini; aux != NULL; aux = aux->proximo)
	{
		if(strcmp( aux->DADOS.sexo, "F" ) == 0 || strcmp(aux->DADOS.sexo, "f" ) == 0 )
		{
			printf(" ------> %s\n", aux->DADOS.nome);
		}
	}

}



void PROFESSORES_ANIVERSARIANTES_DE_UM_DETERMINADO_MES(RETORNO *ini, int mes){

    printf("\n========== Lista de PROFESSORES aniversariantes do mes de %d ==========\n", mes);
	
	ESTRUTURA *aux = *ini;
	
	while( aux != NULL )
	{
		
		if(aux->DADOS.mes == mes)
		{
			printf("-----> %s\n", aux->DADOS.nome);
			
		}

		aux = aux->proximo;
        printf("\n");
		
	}


}


void IMPRIMIR_POR_ORDEM_ALFABETICA(RETORNO *ini){

   
    printf("\n\n");
	printf("\n============ Lista de todos os PROFESSORES em ordem alfabetica ============\n");
	printf("\n");
    
	ESTRUTURA *aux;
	
	for(aux = *ini; aux != NULL; aux = aux->proximo)
	{
			printf(" ------> %s\n", aux->DADOS.nome);
		
	}
	


}


int EXCLUIR_PROFESSOR_NA_LISTA(RETORNO *ini, int matricula){

    ESTRUTURA *aux = *ini, *ultimo;
	
	while( aux != NULL && aux->DADOS.matricula != matricula )
	{
	
		ultimo = aux;
		aux = aux->proximo;
	}
	
	if( aux ==  NULL)
	{
		
     	return -1;
     	
	 }
	 
	 else if(aux == *ini){ //remove o primeiro
	 
	 *ini = aux->proximo;
	 free(aux);
	 return 1;
	 
	 }else{
	 	
		ultimo->proximo = aux->proximo;
		free(aux);
		
		return 1;
		
	}


}

void LIBERA_MEMORIA_RESERVADA_PARA_PROFESSORES(RETORNO *ini){

     ESTRUTURA *aux;
	
	if(ini != NULL){
		
		while((*ini) != NULL){
			
			aux = *ini;
			*ini = (*ini)->proximo;
			free(aux);
		}
		free(ini);
        ini = NULL;
	}
	


}


RETORNO *CRIA_LISTA(){

  RETORNO *ini = (RETORNO *) malloc(sizeof(RETORNO));

  if( ini != NULL)
    *ini = NULL;
    return ini;


}


int INSERIR_PROFESSOR_NA_LISTA(RETORNO *ini, struct professor prof){

    ESTRUTURA *no;
	no = ( ESTRUTURA *) malloc(sizeof( ESTRUTURA ));
	no->DADOS = prof;
	
	if(ini ==  NULL)
	{
		no->proximo = NULL;
		*ini = no;
		
		return 1;
		
	}
	
	else{
		
		 ESTRUTURA *anterior, *atual = *ini;
		
		while( atual != NULL && strcmp(prof.nome, atual->DADOS.nome ) > 0){
			
			anterior = atual;
			atual = atual->proximo;
				
		}
		if( atual == *ini){
			
			no->proximo = (*ini);
			*ini = no;
			
		}else{
			
			no->proximo = atual;
			anterior->proximo = no;
			
		}
		return 1;
		
	}
	

}

void IMPRIMIR_LISTA_DOS_PROFESSORES(RETORNO *ini){


    printf("\n\n");
	printf("\n============ Lista dos professores com os dados completos ============\n");
	printf("\n");
	
	ESTRUTURA *aux = *ini;
	
	while(aux != NULL ){
		
		printf(" Nomes: %s\n", aux->DADOS.nome);
		printf(" Matricula: %d\n", aux->DADOS.matricula);
		printf(" Sexo: %s\n", aux->DADOS.sexo);
		printf(" Dia: %d\n", aux->DADOS.dia);
		printf(" Mes: %d\n", aux->DADOS.mes);
		printf(" Ano: %d\n", aux->DADOS.ano);
        printf(" CPF: %llu\n", aux->DADOS.cpf);
      
		aux = aux->proximo;
		
		printf("\n");
		
		
	}


}


void Alunos_aniversariantes_de_um_determinado_mes(Lista *li, int mess){
	
	printf("\n========== Lista de alunos aniversariantes do mes de %d ==========\n", mess);
	
	Elem *aux = *li;
	
	while( aux != NULL )
	{
		
		if(aux->dados.mes == mess)
		{
			printf("-----> %s\n", aux->dados.nome);
			
		}
		aux = aux->prox;
	}
	
	
}

int Excluir_disciplina_na_lista(struct disciplina *t, char *cod){
	
	struct disciplina *aux = t, *anterior;
	
	    
	if( t == NULL){
		
		return 0;
		
	}
	
	while(  aux != NULL && strcmp( aux->Codigo, cod ) != 0  )
	{
		anterior = aux;
		
	    aux = aux->proximo;
	}
	
	if( aux == NULL ) {// Nao esta na lista
	  
	  return 0;
	  
     }
     
    if( aux == t ){
		
	    t = aux->proximo;
	    free(aux);
	    
		return 1;
			
	}
	
	
	else{
		
	anterior->proximo = aux->proximo;
	free(aux);
	
	return 1;
	
	}
	
	
}

int Atualizar_lista_de_disciplina( struct disciplina *t, char *codigo){
	
	struct disciplina *aux;
	int retorno;
	int valida = 0;
	int opcao;
	
	
	char nome[100];
	char CODIGO[10];
	int semestre; int val = 0, sem = 0;
	char Professor[100];
	
	
	for( aux = t; aux != NULL; aux = aux->proximo)
	{
		if( strcmp ( aux->Codigo, codigo) != 0 )
		{
			valida = 1;
			
		}
		else{
			
			valida = 0;
			
		}
		
	}
	
	if( valida == 1 ){

		return -1;

	}
	
	else{
		
	printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("\n 1- Todos os campos; 2- Nome da disciplina; 3- Codigo; 4-Semestre; 5-Nome do professor.\n\n");
	
    printf(" Digite opcao: ");
	scanf("%d", &opcao);
		
		if( opcao == 1 )
		{
			
		printf(" Digite o novo nome da disciplina: ");
		scanf(" %[^\n]", nome);
		
		printf(" Digite o novo nome do professor: ");
		scanf(" %[^\n]", Professor);
		
		printf(" Digite o novo codigo da disciplina: ");
		scanf(" %[^\n]", CODIGO);
		
		printf(" Digite o novo semestre: ");
		scanf(" %d", &semestre);
		
		if( semestre < 1 )
		{
			val = 1;
			
			while( val == 1 )
			{
				printf(" Semestre INVALIDO!!\n");
				printf(" Digite de novo o semestre: ");
		        scanf(" %d", &semestre);
		        
		        if( semestre > 0 )
		        {
		        	val = 0;
				}
			}
			
		}
		
		val = 0;
		
		for( aux = t; aux != NULL; aux = aux->proximo)
		{
		
		if( strcmp (aux->Codigo, codigo) == 0)
		{
			strcpy(aux->Nome, nome);
			strcpy(aux->professor, Professor);
			strcpy(aux->Codigo, CODIGO);
			aux->Semestre = semestre;
			
		  }
			
		}
		
		retorno = ATUALIZADO_COM_SUCESSO;
	    return retorno;
	    return -1;
	    
	}else if( opcao == 2 ){
		
		printf(" Digite o novo nome da disciplina: ");
		scanf(" %[^\n]", nome);
		
		for( aux = t; aux != NULL; aux = aux->proximo)
		{
		
		if( strcmp (aux->Codigo, codigo) == 0)
		{
			
			strcpy(aux->Nome, nome);
			
		  }
			
		}
		
		retorno = ATUALIZADO_COM_SUCESSO;
		return retorno;
	    return -1;
		
	}else if( opcao == 3 ){
		
		printf(" Digite o novo codigo da disciplina: ");
		scanf(" %[^\n]", CODIGO);
		
		for( aux = t; aux != NULL; aux = aux->proximo)
		{
		
		if( strcmp (aux->Codigo, codigo) == 0)
		{
			
			strcpy(aux->Codigo, CODIGO);
			
		  }
			
		}
		
			retorno = ATUALIZADO_COM_SUCESSO;
			return retorno;
	        return -1;
		
	}else if( opcao == 4 ){
		
		printf(" Digite o novo semestre: ");
		scanf(" %d", &semestre);
		
		if( semestre < 1 )
		{
			sem = 1;
			
			while( sem == 1 )
			{
				printf(" Semestre INVALIDO!!\n");
				printf(" Digite de novo, o novo semestre: ");
		        scanf(" %d", &semestre);
		        
		        if(semestre > 0)
		        {
		        	sem = 0;
				}
		
			}
		}
		sem = 0;
		
		for( aux = t; aux != NULL; aux = aux->proximo)
		{
		
		if( strcmp ( aux->Codigo, codigo ) == 0)
		{
			
			aux->Semestre = semestre;
			
		  }
			
		}
		
		retorno = ATUALIZADO_COM_SUCESSO;
		return retorno;
	    return -1;
		
	}else if( opcao == 5 ){
		
		printf(" Digite o novo nome do professor: ");
		scanf(" %[^\n]", Professor);
		
		for( aux = t; aux != NULL; aux = aux->proximo)
		{
		
		if( strcmp ( aux->Codigo, codigo ) == 0)
		{
			
			strcpy( aux->professor, Professor );
			
		  }
			
		}
		
		retorno = ATUALIZADO_COM_SUCESSO;
		
		return retorno;
	    return -1;
		
	}
		
	}
	
	
	
}







void imprime_alunos_numa_disciplina(struct disciplina *t, Lista *li, char *discipli){
	
	struct disciplina *aux = t;
	Elem *ax = *li;
	
	printf("\n\n ============== Dados da disciplina %s ==============\n\n", discipli);
	
	while( aux != NULL )
	{
			
		
		if( strcmp ( aux->Nome, discipli ) == 0 )
		{
			
		printf(" Nome da disciplina: %s\n", aux->Nome);
		printf(" Codigo: %s\n", aux->Codigo);
		printf(" Semestre: %d\n", aux->Semestre);
		printf(" Nome do professor: %s\n", aux->professor);
		
		printf("\n\n");
			
		}else{}
		
		aux = aux->proximo;
		
	}
	
	printf("\n========== Alunos Matriculados na disciplina de: %s ==========\n\n", discipli);

		
		while( ax != NULL )
		{
			
		if( strcmp ( ax->dados.DIS.Nome, discipli ) == 0 )
		{
			
			printf(" ---------------->%s\n", ax->dados.nome);
			
		}
		
		ax = ax->prox;
		
		}	
	
}



struct disciplina *Cria_lista(){

	return NULL;
	
}



struct disciplina *insere_disciplina_na_lista(struct disciplina *ptr, char *nome, char *codigo, int semestre, char *professor){
	
	   int retorno = 0;
	   struct disciplina *novo_no;
	   novo_no = ( struct disciplina *) malloc(sizeof(struct disciplina)); 
	   
	     	 strcpy(novo_no->Nome, nome);
	         novo_no->Semestre = semestre;
	         strcpy(novo_no->Codigo, codigo);
			 strcpy(novo_no->professor, professor);
			 
			 novo_no->proximo = ptr;
			 ptr = novo_no;
			
			return (novo_no);
			
} 


void imprime(struct disciplina *t){
	
	
	printf("\n\n Lista de disciplinas com os dados completos.\n\n");
	
	struct disciplina *aux;
	

	
	for( aux = t; aux != NULL;  aux = aux->proximo ){
		
		printf(" Nome da disciplina: %s\n", aux->Nome);
		printf(" Codigo: %s\n", aux->Codigo);
		printf(" Semestre: %d\n", aux->Semestre);
		printf(" Nome do professor: %s\n", aux->professor);
	
		
		printf(" \n");
		
		
	}
	
}



void quantidade_dos_alunos(Lista *li){
	
	printf("\n =============== Totao do alunos =============== \n");
	int cont = 0;
	Elem *aux;
	
	for(aux = *li; aux != NULL; aux = aux->prox)
	{
		cont++;
	}
	
	printf(" Aquantidade dos alunos = %d.\n", cont);
	
}


int Excluir_aluno_na_lista(Lista *li, int matricula){
	
	Elem *aux = *li, *ultimo;
	
	while( aux != NULL && aux->dados.matricula != matricula )
	{
	
		ultimo = aux;
		aux = aux->prox;
	}
	
	if( aux ==  NULL)
	{
		
     	return -1;
     	
	 }
	 
	 else if(aux == *li){ //remove o primeiro
	 
	 *li = aux->prox;
	 free(aux);
	 return 1;
	 
	 }else{
	 	
		ultimo->prox = aux->prox;
		free(aux);
		
		return 1;
		
	}
	
	
}


int Atualizar_lista_de_alunos(Lista *li, int matricula){
	
	char NOME[100];
	int MATRICULA;
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    unsigned long long int CPF;
    char DISCIPLINA[100];
	int valida = 0;
	int val = 0, valS = 0,  valD = 0,  valM = 0,  valA = 0,  valCPF = 0;

	int opcao;
	int i;
	int retorno = 0;
    Elem *aux = *li;

	char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";
    int validaMatricula = 0;




    while( aux != NULL)
    {

     if(  aux->dados.matricula  != matricula )
     {
         valida = 0;

     }else{

         valida = 1;
      }

      aux = aux->prox;

    }

    if( valida == 0 )
	{

		return -1;

	}



   else{

    printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf(" 1- Todos os campos; 2- Nome; 3- Sexo; 4- Dia de Nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8- Matricula, 9-Disciplina\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

    if( opcao == 1 ){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);
       
       if(MATRICULA < 1)
       {
       	validaMatricula = 1;
       	
       	while(validaMatricula == 1)
       	{
       		
       	printf(" Novo numero de matricula INVALIDO!\n");
       	printf(" Digite de novo, o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);
		
		if(MATRICULA > 0)
		{
			
			validaMatricula  = 0;
			
	      }
		
		}
	}
       validaMatricula  = 0;
       
	    printf(" Digite o novo sexo do aluno: ");
		scanf(" %[^\n]", SEXO);

	    if( strcmp( SEXO, sexo1) != 0 && strcmp( SEXO, sexo2) != 0 && strcmp(SEXO, sexo3) != 0 && strcmp(SEXO, sexo4) != 0 && strcmp(SEXO, sexo5) != 0 && strcmp(SEXO, sexo6) != 0)
	    {
	    	val = 1;

	    	while( val == 1)
			{
				printf(" Novo sexo do aluno INVALIDO!!!\n");
	    		printf(" Digite o novo sexo do aluno: ");
		        scanf(" %[^\n]", SEXO);

		if( strcmp( SEXO, sexo1) == 0 || strcmp( SEXO, sexo2) == 0  || strcmp(SEXO, sexo3) == 0  || strcmp(SEXO, sexo4) == 0  || strcmp(SEXO, sexo5) == 0  || strcmp(SEXO, sexo6) == 0)
           {

           		val = 0;

		   }
	    }
	}
	     val = 0;
	     printf(" Digite o novo dia de nascimeto: ");
		 scanf(" %d", &DIA);

		 if( DIA <= 0 || DIA > 31){

		 	valD = 1;

		 	while( valD == 1){

		 	 printf(" Novo dia de nascimeto INVALIDO!\n");
		 	 printf(" Digite o novo dia de nascimeto: ");
		     scanf(" %d", &DIA);

		     if( DIA >= 1 && DIA <= 31){

		     	valD = 0;

			    }
			 }
		 }
	       valD = 0;

		printf(" Digite o novo mes de nascimeto: ");
		scanf(" %d", &MES);

		if( MES <= 0 || MES > 12 ){

			valM = 1;

			while( valM == 1 ){

				printf(" Novo mes de nascimeto INVALIDO!!\n");
				printf(" Digite o novo mes de nascimeto: ");
		        scanf(" %d", &MES);

		        if( MES >=1 && MES <= 12 ){

		        	valM = 0;
				}
			}
		}

		valM = 0;

			printf(" Digite o novo ano de nascimeto: ");
		    scanf(" %d", &ANO);

		    if( ANO <= 0){

		    	valA = 1;

		    	while (valA == 1 ){

		    	printf(" Novo ano de nascimeto INVALIDO\n");
		    	printf(" Digite o novo ano de nascimeto: ");
		    	scanf(" %d", &ANO);

		    	if( ANO > 0){

		    		valA = 0;

				   }
				}
			}

			valA = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &CPF);

		if( CPF <= 9999999999 || CPF > 99999999999 ){

			valCPF = 1;

			while( valCPF == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 ){

			valCPF = 0;

		   }
	   }

	}
		valCPF = 0;
        
		for( aux = *li; aux != NULL; aux = aux->prox)
        {

		if( aux->dados.matricula == matricula)
        {

			strcpy(aux->dados.nome, NOME);
			aux->dados.matricula = MATRICULA;
			strcpy(aux->dados.sexo,SEXO);
			aux->dados.dia = DIA;
			aux->dados.mes = MES;
			aux->dados.ano = ANO;
			aux->dados.CPF = CPF;

        }


		 }

		 retorno  = ATUALIZADO_COM_SUCESSO;
         return retorno;

	}else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( aux = *li; aux != NULL; aux = aux->prox){

			if(  aux->dados.matricula == matricula ){

				strcpy(aux->dados.nome, NOME);

			}	

		}

		retorno  = ATUALIZADO_COM_SUCESSO;
        return retorno;

	}else if(opcao == 3){

		int SS = 0;

		 printf(" Digite o novo sexo do aluno: ");
		 scanf(" %[^\n]", SEXO);

	    if( strcmp( SEXO, sexo1) != 0 && strcmp( SEXO, sexo2) != 0 && strcmp(SEXO, sexo3) != 0 && strcmp(SEXO, sexo4) != 0 && strcmp(SEXO, sexo5) != 0 && strcmp(SEXO, sexo6) != 0)
	    {
	    	SS = 1;

	    	while( SS == 1)
			{
				printf(" Novo sexo do aluno INVALIDO!!!\n");
	    		printf(" Digite o novo sexo do aluno: ");
		        scanf(" %[^\n]", SEXO);

		if( strcmp( SEXO, sexo1) == 0 || strcmp( SEXO, sexo2) == 0  || strcmp(SEXO, sexo3) == 0  || strcmp(SEXO, sexo4) == 0  || strcmp(SEXO, sexo5) == 0  || strcmp(SEXO, sexo6) == 0)
           {

           		SS = 0;

		   }
	    }
	}
	   SS = 0;

		for( aux = *li; aux != NULL; aux = aux->prox){

			if(  aux->dados.matricula == matricula ){

				strcpy( aux->dados.sexo, SEXO );

			}

           
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
        return retorno;

	  }else if( opcao == 4 ){

		int jj = 0;

		printf(" Digite o novo dia de nascimeto: ");
		scanf(" %d", &DIA);

		 if( DIA <= 0 || DIA > 31){

		 	jj = 1;

		 	while( jj == 1){

		 	 printf(" Novo dia de nascimeto INVALIDO!\n");
		 	 printf(" Digite o novo dia de nascimeto: ");
		     scanf(" %d", &DIA);

		     if( DIA >= 1 && DIA <= 31){

		     	jj = 0;

			    }
			 }
		 }

		jj = 0;

		for( aux = *li; aux != NULL; aux = aux->prox){

			if(  aux->dados.matricula == matricula ){

				aux->dados.dia = DIA;

			}

			
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
        return retorno;

	  } else if(opcao == 5){

		int kk = 0;

		printf(" Digite o novo mes de nascimeto: ");
		scanf(" %d", &MES);

		if( MES <= 0 || MES > 12 ){

			kk = 1;

			while( kk == 1 ){

				printf(" Novo mes de nascimeto INVALIDO!!\n");
				printf(" Digite o novo mes de nascimeto: ");
		        scanf(" %d", &MES);

		        if( MES >=1 && MES <= 12 ){

		        	kk = 0;
				}
			}
		}

		kk = 0;

			for( aux = *li; aux != NULL; aux = aux->prox){

				if(  aux->dados.matricula == matricula ){

					aux->dados.mes = MES;

				}

			
			}


	    	retorno  = ATUALIZADO_COM_SUCESSO;
            return retorno;

	   }else if(opcao == 6){

		  int ii = 0;

			printf(" Digite o novo ano de nascimeto: ");
		    scanf(" %d", &ANO);

		    if( ANO <= 0){

		    	ii = 1;

		    	while (ii == 1 ){

		    	printf(" Novo ano de nascimeto INVALIDO\n");
		    	printf(" Digite o novo ano de nascimeto: ");
		    	scanf(" %d", &ANO);

		    	if( ANO > 0){

		    		ii = 0;

				   }
				}
			}

			ii = 0;

			for( aux = *li; aux != NULL; aux = aux->prox){

				if( aux->dados.matricula == matricula ){

				aux->dados.ano = ANO;

				}

				

			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;
            return retorno;


	  }else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &CPF);

		if( CPF <= 9999999999 || CPF > 99999999999 ){

			cc = 1;

			while( cc == 1 )
            {

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 )
        {

			cc = 0;

		   }
	   }

	}
		cc = 0;

		for( aux = *li; aux != NULL; aux = aux->prox){

				if( aux->dados.matricula == matricula ){

				 aux->dados.CPF = CPF;

				}
				

			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;
            return retorno;

	   }else if( opcao == 8){
       
       int ww = 0;
		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);
        
        if(matricula < 1)
        {
        	ww = 1;
        	
        	while(ww == 1)
        	{
        		printf(" Novo numero de matricula INVALIDO!\n");
        		printf(" Digite o novo numero de matricula do aluno: ");
		        scanf(" %d", &MATRICULA);
        		
        		if(matricula > 0)
        		{
        			
        				ww = 0;
        			
				}
			}
		}
		
		ww = 0;
		for( aux = *li; aux != NULL; aux = aux->prox){

			if( aux->dados.matricula == matricula ){

				aux->dados.matricula = MATRICULA;

				}

				
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;

	   }else if( opcao == 9){
	   	
	   	printf(" Digite a nova disciplina: ");
	   	scanf(" %[^\n]", DISCIPLINA);
	   	
	   	for( aux = *li; aux != NULL; aux = aux->prox)//{

			if( aux->dados.matricula == matricula )//{

				strcpy(aux->dados.DIS.Nome, DISCIPLINA);

				//}
	   	
	   }
	   
	    retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;

}



	
}


void imprimir_alunos_em_ordem_alfabetica(Lista *li){
	

	
	printf("\n\n");
	printf("\n============ Lista de todos os alunos em ordem alfabetica ============\n");
	printf("\n");
    
	Elem *aux;
	
	for(aux = *li; aux != NULL; aux = aux->prox)
	{
			printf(" ------> %s\n", aux->dados.nome);
		
	}
	
}

void imprimir_alunos_de_sexo_feminino(Lista *li){
	
    printf("\n\n");
	printf("\n============ Lista de alunos de sexo feminino ============\n");
	printf("\n");
    
	Elem *aux;
	
	for(aux = *li; aux != NULL; aux = aux->prox)
	{
		if(strcmp( aux->dados.sexo, "F" ) == 0 || strcmp(aux->dados.sexo, "f" ) == 0 )
		{
			printf(" ------> %s\n", aux->dados.nome);
		}
	}
	
}

void imprimir_alunos_de_sexo_masculino(Lista *li){
	
    printf("\n\n");
	printf("\n============ Lista de alunos de sexo masculino ============\n");
	printf("\n");
    
	Elem *aux;
	
	for(aux = *li; aux != NULL; aux = aux->prox)
	{
		if(strcmp( aux->dados.sexo, "M" ) == 0 || strcmp(aux->dados.sexo, "m" ) == 0 )
		{
			printf(" ------> %s\n", aux->dados.nome);
		}
	}
	
}

Lista *cria_lista(){
	
	Lista *li = (Lista *) malloc(sizeof(Lista)); 
	if(li != NULL)
	*li = NULL;
	return li;
}


int inserir_inicio(Lista *li, struct aluno al){

	Elem *no;
	no = (Elem *) malloc(sizeof(Elem));
	no->dados = al;
	
	if(li ==  NULL)
	{
		no->prox = NULL;
		*li = no;
		
		return 1;
		
	}
	
	else{
		
		Elem *anterior, *atual = *li;
		
		while( atual != NULL && strcmp(al.nome, atual->dados.nome ) > 0){
			
			anterior = atual;
			atual = atual->prox;
				
		}
		if( atual == *li){
			
			no->prox = (*li);
			*li = no;
			
		}else{
			
			no->prox = atual;
			anterior->prox = no;
			
		}
		return 1;
		
	}
	
   }
	


void imprmir_alunos_com_dados_completos(Lista *li){
	
	printf("\n\n");
	printf("\n============ Lista de alunos com os dados completos ============\n");
	printf("\n");
	
	Elem *aux = *li;
	
	while(aux != NULL ){
		
		printf(" Nomes: %s\n", aux->dados.nome);
		printf(" Matricula: %d\n", aux->dados.matricula);
		printf(" Sexo: %s\n", aux->dados.sexo);
		printf(" Dia: %d\n", aux->dados.dia);
		printf(" Mes: %d\n", aux->dados.mes);
		printf(" Ano: %d\n", aux->dados.ano);
        printf(" CPF: %llu\n", aux->dados.CPF);
        printf(" Disciplna: %s\n", aux->dados.DIS.Nome);

		aux = aux->prox;
		
		printf("\n");
		
		
	}

	
}



