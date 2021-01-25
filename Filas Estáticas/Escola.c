#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Escola.h"

int fila_vazia_de_professores(Guarda *ptr){

    if(ptr == NULL){

		return -1;

	}
	
	else if(ptr->qtdPROFESSOR == 0){

		return FILA_ESTA_VAZIA ;

	}
	
	else{

		return FILA_NAO_ESTA_VAZIA;

	}



}



int fila_cheia_de_professore(Guarda *ptr){


    if(ptr == NULL){
	
	return -1;
	
     }

    else if(ptr->qtdPROFESSOR == MAXPROF){
	
    return FILA_CHEIA;
    
    }
    else{
	
    return 1;
   }



}





int fila_cheia_de_alunos(guarda *fil){
   
   if(fil == NULL){
	
	return -1;
	
     }

    else if(fil->qtdALUNO == MAXalu){
	
    return FILA_CHEIA;
    
    }
    else{
	
    return 1;
   }


}


int fila_vazia_de_alunos(guarda *fil){

     if(fil == NULL){

		return -1;

	}
	
	else if(fil->qtdALUNO == 0){

		return FILA_ESTA_VAZIA ;

	}
	
	else{

		return FILA_NAO_ESTA_VAZIA;

	}
}



int atualizar_lista_dos_professores(Guarda *ptr, int mmmatricula){

    char NOME[100];
	int MATRICULA;
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    unsigned long long int CPF;
    
 
	int valida = 0;
	int val = 0, valS = 0,  valD = 0,  valM = 0,  valA = 0,  valCPF = 0;

	int opcao;
	int i;
	int retorno = 0;

	char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";

	printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf(" 1- Todos os campos; 2- Nome; 3- Sexo; 4- Dia de Nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8- Matricula.\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

	for( i = 0; i < ptr->qtdPROFESSOR; i ++){

		if( ptr->Dados[i].matricula != mmmatricula ){

			valida = 0;

		}else{

              valida = 1;
		}

	}

	if(valida == 0 ){

		return -1;

	}



	else{

	    if(opcao == 1){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

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

		if( CPF < 9999999999 || CPF > 99999999999 ){

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

		for( i = 0; i < ptr->qtdPROFESSOR; i++){

		if( ptr->Dados[i].matricula == mmmatricula ){

			strcpy(ptr->Dados[i].nome, NOME);
			ptr->Dados[i].matricula = MATRICULA;
			strcpy(ptr->Dados[i].sexo, SEXO);
			ptr->Dados[i].dia = DIA;
			ptr->Dados[i].mes = MES;
			ptr->Dados[i].ano = ANO;
			ptr->Dados[i].cpf = CPF;
          

		   }

		 }

		 retorno  = ATUALIZADO_COM_SUCESSO;

	} else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( i = 0; i < ptr->qtdPROFESSOR; i++){

			if( ptr->Dados[i].matricula == mmmatricula ){

				strcpy(ptr->Dados[i].nome, NOME);

			}

		}

		retorno  = ATUALIZADO_COM_SUCESSO;

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

		for( i = 0; i < ptr->qtdPROFESSOR; i ++){

			if( ptr->Dados[i].matricula == mmmatricula ){

				strcpy( ptr->Dados[i].sexo, SEXO );

			}


		}

		retorno  = ATUALIZADO_COM_SUCESSO;

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

		for( i = 0; i < ptr->qtdPROFESSOR; i ++){

			if( ptr->Dados[i].matricula  == mmmatricula ){

				ptr->Dados[i].dia = DIA;

			}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;

	}

	else if(opcao == 5){

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

			for( i = 0; i < ptr->qtdPROFESSOR; i ++){

				if( ptr->Dados[i].matricula == mmmatricula ){

					ptr->Dados[i].mes = MES;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;

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

			for( i = 0; i < ptr->qtdPROFESSOR; i ++){

				if( ptr->Dados[i].matricula == mmmatricula ){

				ptr->Dados[i].ano = ANO;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;



	}else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %lld", &CPF);

		if( CPF < 9999999999 || CPF > 99999999999 ){

			cc = 1;

			while( cc == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %lld", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 ){

			cc = 0;

		   }
	   }

	}
		cc = 0;

		for( i = 0; i < ptr->qtdPROFESSOR; i ++){

				if( ptr->Dados[i].matricula  == mmmatricula ){

				 ptr->Dados[i].cpf = CPF;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;


	}else if( opcao == 8){

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

		for( i = 0; i < ptr->qtdPROFESSOR; i ++){

			if( ptr->Dados[i].matricula == mmmatricula ){

				ptr->Dados[i].matricula = MATRICULA;

				}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		
	}


  }

     return  retorno;
	 return -1;

}




void imprimir_professores_de_sexo_masculino(Guarda *ptr){

   int i;
   char sexo1[3] = "M";
   char sexo2[3] = "m";
   
   printf("\n=============== Lista de professores de sexo masculino ===============\n\n");
   for( i = 0; i < ptr->qtdPROFESSOR; i ++){

      if( strcmp ( ptr->Dados[i].sexo, sexo1) == 0 || strcmp (ptr->Dados[i].sexo, sexo2) == 0){

         printf("Nome: %s\n", ptr->Dados[i].nome);

         }


     }

}


void imprimir_professores_de_sexo_feminino(Guarda *ptr){

   int i;
   char sexo1[3] = "F";
   char sexo2[3] = "f";
   
   printf("\n=============== Lista de professoras (sexo feminino) ===============\n\n");

   for( i = 0; i < ptr->qtdPROFESSOR; i ++){

      if( strcmp ( ptr->Dados[i].sexo, sexo1 ) == 0 || strcmp ( ptr->Dados[i].sexo, sexo2 ) == 0){

         printf("Nome: %s\n", ptr->Dados[i].nome);

         }


     }
}




int quantidade_dos_professores(Guarda *ptr){


    if(ptr == NULL)
	return -1;
	return ptr->qtdPROFESSOR;

}


int excluir_professor_na_lista(Guarda *ptr){

    if( ptr == NULL || ptr->qtdPROFESSOR == 0){
		
	  return FILA_ESTA_VAZIA;
	  
	}
	
	else{
		
		ptr->Inicio = (ptr->Inicio + 1) % MAXPROF;
		ptr->qtdPROFESSOR --;
	}

	return 1;


}



void listar_aniversariantes_de_um_dado_mmes(Guarda *ptr, int mmmes){


      int i;
      printf("\n=============== Lista de aniversariantes de Mes de: %d ===============\n\n", mmmes);
      for( i = 0; i < ptr->qtdPROFESSOR; i ++){

       if(ptr->Dados[i].mes == mmmes){
         
         printf("-------> %s\n", ptr->Dados[i].nome);

         }


     }


}




void imprimir_lista_de_professores(Guarda *ptr){

   int i;

   printf("\n========== Lista de professres com os dados completo ==========\n\n");
   for( i = 0; i < ptr->qtdPROFESSOR; i ++){

       printf(" Nome: %s\n", ptr->Dados[i].nome);
       printf(" Sexo: %s\n", ptr->Dados[i].sexo);
       printf(" Matricula: %d\n", ptr->Dados[i].matricula);
       printf(" Dia: %d\n", ptr->Dados[i].dia);
       printf(" Mes: %d\n", ptr->Dados[i].mes);
       printf(" ANo: %d\n", ptr->Dados[i].ano);
       printf(" CPF: %llu\n", ptr->Dados[i].cpf);

      printf("\n\n");

     }


}


void libera_memoria_reservada_para_professores(Guarda *ptr){


   free(ptr);


}


Guarda *cria_fila_de_professores(){


   Guarda *ptr = (Guarda *) malloc(sizeof(Guarda));

   if(ptr != NULL){

     ptr->Inicio = 0;
     ptr->Fim = 0;
     ptr->qtdPROFESSOR = 0;

    }
 
   return ptr;



}

int insere_professor_na_fila( Guarda *ptr, struct professor el ){

    if( ptr == NULL){
		
	  return -1;
	  
	}
	
	if(ptr->qtdPROFESSOR == MAXPROF){

		return -1;
	}
	
	else{
		
		ptr->Dados[ptr->Fim] = el;
		ptr->Fim = (ptr->Fim + 1) % MAXPROF;
		ptr->qtdPROFESSOR ++;
		
		return 1;
	}

}



int quantidade_dos_alunos(guarda *fil){

    if(fil == NULL)
	return -1;
	return fil->qtdALUNO;


}


int atualizar_lista_dos_alunos( guarda *fil, int mmatricula ){


    char NOME[100];
	int MATRICULA;
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    unsigned long long int CPF;
    char DISCIPLINAA[100];
 
	int valida = 0;
	int val = 0, valS = 0,  valD = 0,  valM = 0,  valA = 0,  valCPF = 0;

	int opcao;
	int i;
	int retorno = 0;

	char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";

	printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf(" 1- Todos os campos; 2- Nome; 3- Sexo; 4- Dia de Nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8- Matricula; 9- Dsiciplina\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

	for( i = 0; i < fil->qtdALUNO; i ++){

		if( fil->dados[i].matricula != mmatricula ){

			valida = 0;

		}else{

              valida = 1;
		}

	}

	if(valida == 0 ){

		return -1;

	}



	else{

	    if(opcao == 1){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

	    printf(" Digite o novo sexo do aluno: ");
		scanf(" %[^\n]", SEXO);
       
       printf(" Digite a nova disciplina do aluno: ");
	   scanf(" %[^\n]", DISCIPLINAA);

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

		if( CPF < 9999999999 || CPF > 99999999999 ){

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

		for( i = 0; i < fil->qtdALUNO; i++){

		if( fil->dados[i].matricula == mmatricula ){

			strcpy(fil->dados[i].nome, NOME);
			fil->dados[i].matricula = MATRICULA;
			strcpy(fil->dados[i].sexo, SEXO);
			fil->dados[i].dia = DIA;
			fil->dados[i].mes = MES;
			fil->dados[i].ano = ANO;
			fil->dados[i].cpf = CPF;
            strcpy ( fil->dados[i].dis.nome_da_disciplina, DISCIPLINAA );

		   }

		 }

		 retorno  = ATUALIZADO_COM_SUCESSO;

	} else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( i = 0; i < fil->qtdALUNO; i++){

			if( fil->dados[i].matricula == mmatricula ){

				strcpy(fil->dados[i].nome, NOME);

			}

		}

		retorno  = ATUALIZADO_COM_SUCESSO;

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

		for( i = 0; i < fil->qtdALUNO; i ++){

			if( fil->dados[i].matricula == mmatricula ){

				strcpy( fil->dados[i].sexo, SEXO );

			}


		}

		retorno  = ATUALIZADO_COM_SUCESSO;

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

		for( i = 0; i < fil->qtdALUNO; i ++){

			if( fil->dados[i].matricula  == mmatricula ){

				fil->dados[i].dia = DIA;

			}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;

	}

	else if(opcao == 5){

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

			for( i = 0; i < fil->qtdALUNO; i ++){

				if( fil->dados[i].matricula == mmatricula ){

					fil->dados[i].mes = MES;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;

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

			for( i = 0; i < fil->qtdALUNO; i ++){

				if( fil->dados[i].matricula == mmatricula ){

				fil->dados[i].ano = ANO;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;



	}else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %lld", &CPF);

		if( CPF < 9999999999 || CPF > 99999999999 ){

			cc = 1;

			while( cc == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %lld", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 ){

			cc = 0;

		   }
	   }

	}
		cc = 0;

		for( i = 0; i < fil->qtdALUNO; i ++){

				if( fil->dados[i].matricula  == mmatricula ){

				 fil->dados[i].cpf = CPF;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;


	}else if( opcao == 8){

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

		for( i = 0; i < fil->qtdALUNO; i ++){

			if( fil->dados[i].matricula == mmatricula ){

				fil->dados[i].matricula = MATRICULA;

				}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		
	}else if(opcao == 9){
    
       
         printf(" Digite a nova disciplina do aluno: ");
	     scanf(" %[^\n]", DISCIPLINAA);

      for( i = 0; i < fil->qtdALUNO; i ++){

			if( fil->dados[i].matricula == mmatricula ){

				strcpy(fil->dados[i].dis.nome_da_disciplina, DISCIPLINAA);

			}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;

    }


  }

     return  retorno;
	 return -1;


}




void listar_disciplinas_e_alunos_matriculados( GUARDA *fil, guarda *fill){

    char DISCIPLINA[100];
    int i;
    int k;

    printf(" Digite a disciplina: ");
    scanf(" %[^\n]", DISCIPLINA);

    printf("\n                 Dados da disciplina de : %s                     \n\n", DISCIPLINA);

    for( i = 0; i < fil->qtd; i ++ )
	{

    	 if( strcmp( fil->DADOS[i].nome_da_disciplina, DISCIPLINA ) == 0 )

		 {

			printf(" Nome da disciplina: %s\n", fil->DADOS[i].nome_da_disciplina);
		    printf(" Codigo da disciplina: %s\n", fil->DADOS[i].codigo);
		    printf(" Semestre: %d\n", fil->DADOS[i].semestre);
		    printf(" Nome do(a) professor(a): %s\n", fil->DADOS[i].professor);

		    printf("\n\n");

		 }
		 else{}

	}

	printf("\n ========== Alunos Matriculados na disciplina de: %s ==========\n", DISCIPLINA);

	for( k = 0; k < fill->qtdALUNO; k++)
	{

		if( strcmp( fill->dados[k].dis.nome_da_disciplina,  DISCIPLINA) == 0 )
		{
			printf(" -----> %s\n", fill->dados[k].nome);

		}
    }

}



void imprimir_lista_de_alunos( guarda *fil ){

    int i;
 
    printf("\n\n==================== Lista dos alunos com dados completos ====================\n");

    for(  i = 0; i < fil->qtdALUNO; i ++ ){

        printf(" Nome: %s\n", fil->dados[i].nome);
        printf(" Sexo: %s\n", fil->dados[i].sexo);
        printf(" Dia: %d\n", fil->dados[i].dia);
        printf(" Mes: %d\n", fil->dados[i].mes);
        printf(" Ano: %d\n", fil->dados[i].ano);
        printf(" CPF: %llu\n", fil->dados[i].cpf);
        printf(" Matricula: %d\n", fil->dados[i].matricula);
        printf(" Disciplina: %s\n", fil->dados[i].dis.nome_da_disciplina);

        printf("\n\n");

     }



}




guarda *cria_fila_de_alunos(){

   guarda *fil = (guarda *) malloc(sizeof(guarda));

          if(fil != NULL){

         fil->INICIO = 0;
         fil->FIM = 0;
         fil->qtdALUNO = 0;

      }
      return fil;

}



int insere_aluno_na_fila( guarda *fil, struct aluno al ){

    if( fil == NULL){
		
	  return -1;
	  
	}
	
	if(fil->qtdALUNO == MAXalu){

		return -1;
	}
	
	else{
		
		fil->dados[fil->FIM] = al;
		fil->FIM = (fil->FIM + 1) % MAXalu;
		fil->qtdALUNO ++;
		
		return 1;
	}


}


GUARDA *cria_fila_das_disciplinas(){
	
	GUARDA *fil;
	fil = (GUARDA *) malloc(sizeof(GUARDA));
	
	if( fil != NULL ){
		
		fil->inicio = 0;
		fil->fim = 0;
		fil->qtd = 0;
		
	}
	
	return fil;
}




int insere_disciplina_na_fila(GUARDA *fil, struct disciplina al){


    if( fil == NULL){
		
	  return -1;
	  
	}
	
	if(fil->qtd == MAXdis){
		return -1;
	}
	
	else{
		
		fil->DADOS[fil->fim] = al;
		fil->fim = (fil->fim + 1) % MAXdis;
		fil->qtd ++;
		
		return 1;
	}


}


int remove_disciplina_na_fila(GUARDA *fil){

   if( fil == NULL || fil->qtd == 0){
		
	  return -1;
	  
	}
	
	else{
		
		fil->inicio = (fil->inicio+1) % MAXdis;
		fil->qtd --;
	}
	return 1;


}

int fila_vazia(GUARDA *fil){

  if(fil == NULL){

		return -1;

	}
	
	else if(fil->qtd == 0){

		return FILA_ESTA_VAZIA ;

	}
	
	else{

		return FILA_NAO_ESTA_VAZIA;

	}

}


int fila_cheia(GUARDA *fil){

   if(fil == NULL){
	
	return -1;
	
     }
    else if(fil->qtd == MAXdis){
	
    return FILA_CHEIA;
    
    }
    else{
	
    return 1;
   }


}

void libera_fila_das_disciplinas(GUARDA *fil){
	
	free(fil); 
	
	
}


void libera_memoria_reservada_para_aluno(guarda *fil){

   free(fil);


}



int quantidade_das_disciplinas_na_fila(GUARDA *fil){

    if(fil == NULL)
	return -1;
	return fil->qtd;



}

void imprimir_lista_das_disciplinas(GUARDA *fil){

    int i;
    printf("\n\n==================== Lista das disciplinas e os dados completos ====================\n\n");
    for( i = 0; i < fil->qtd; i ++ ){

       printf(" Disciplina: %s\n", fil->DADOS[i].nome_da_disciplina);
       printf(" Codigo: %s\n", fil->DADOS[i].codigo);
       printf(" Professor: %s\n", fil->DADOS[i].professor);
       printf(" Semestre: %d\n", fil->DADOS[i].semestre);

       printf("\n");

    }

}



int atualizar_disciplina_na_lista(GUARDA *fil, char codigo[20]){

    char Nome_Da_Disciplina[100];
	char Codigo[20];
	char Professor[100];
	int Semestre;
	int i;
	
	int opcao;
	int retorno = 0;

    printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf(" 1- Todos os campos; 2- Nome da disciplina; 3- Codigo; 4- Nome do(a) professor(a); 5- Semestre.\n\n");

    printf(" Digite opcao: ");
	scanf("%d", &opcao);

    for( i = 0; i < fil->qtd; i ++ ){

       if( strcmp( fil->DADOS[i].codigo, codigo ) != 0 )
      {
          return -1;

         }else{

            if( opcao == 1 ){

			printf(" Digite o novo nome da disciplina: ");
			scanf(" %[^\n]", Nome_Da_Disciplina);

			printf(" Digite o novo Codigo da disciplina: ");
			scanf(" %[^\n]", Codigo);

			printf(" Digite o novo nome do(a) professor(a): ");
			scanf(" %[^\n]", Professor);

			printf(" Digite o novo semestre: ");
			scanf(" %d", &Semestre);



				if( strcmp (fil->DADOS[i].codigo, codigo) == 0 ){

				strcpy(fil->DADOS[i].nome_da_disciplina, Nome_Da_Disciplina);
				strcpy(fil->DADOS[i].codigo, Codigo);
				strcpy(fil->DADOS[i].professor, Professor);
				fil->DADOS[i].semestre = Semestre;

			    retorno = ATUALIZADO_COM_SUCESSO;
                return retorno;
		  }

		} else if( opcao == 2 ){

			printf(" Digite o novo nome da disciplina: ");
			scanf(" %[^\n]", Nome_Da_Disciplina);

				if( strcmp(fil->DADOS[i].codigo, codigo) == 0 ){

				  strcpy(fil->DADOS[i].nome_da_disciplina, Nome_Da_Disciplina);

				  retorno = ATUALIZADO_COM_SUCESSO;

				return retorno;

			}



		}else if(opcao == 3){

		    printf(" Digite o novo Codigo da disciplina: ");
			scanf(" %[^\n]", Codigo);

				if( strcmp(fil->DADOS[i].codigo, codigo) == 0 ){

					strcpy(fil->DADOS[i].codigo, Codigo);

				   retorno = ATUALIZADO_COM_SUCESSO;

				   return retorno;
			}



		}else if( opcao == 4 ){

			printf(" Digite o novo nome do(a) professor(a): ");
			scanf(" %[^\n]", Professor);


			if( strcmp(fil->DADOS[i].codigo, codigo) == 0 ){

			 strcpy(fil->DADOS[i].professor, Professor);

		    retorno = ATUALIZADO_COM_SUCESSO;
		    return retorno;

			}



		}else if(opcao == 5){

		printf(" Digite o novo semestre: ");
		scanf(" %d", &Semestre);

			if( strcmp( fil->DADOS[i].codigo, codigo ) == 0 ){

				fil->DADOS[i].semestre = Semestre;
			    retorno = ATUALIZADO_COM_SUCESSO;

			     return retorno;

			}

       }

     }


   }


}


void imprimir_alunos_de_sexo_masculino(guarda *fil){


    printf("\n\n");

	int i;
	char sexoM[3] = "M";
	char sexom[3] = "m";


	printf("\n ================ Lista de ALUNOS (sexo masculino) ====================\n");


	for( i = 0; i < fil->qtdALUNO; i++ ){

		if(strcmp( fil->dados[i].sexo, sexoM) == 0 || strcmp( fil->dados[i].sexo, sexom) == 0)
		{

			printf(" --------> %s\n", fil->dados[i].nome);

		}


	}

	printf("\n\n");



}


void imprimir_alunos_de_sexo_feminino(guarda *fil){

      printf("\n\n");

	int i;
	char sexoM[3] = "F";
	char sexom[3] = "f";


	printf("\n ================ Lista de ALUNAS (sexo feminino) ====================\n");


	for( i = 0; i < fil->qtdALUNO; i++ ){

		if(strcmp( fil->dados[i].sexo, sexoM) == 0 || strcmp( fil->dados[i].sexo, sexom) == 0)
		{

			printf(" --------> %s\n", fil->dados[i].nome);

		}


	}

	printf("\n\n");



}

int excluir_aluno_na_lista(guarda *fil){

    if( fil == NULL || fil->qtdALUNO == 0){
		
	  return FILA_ESTA_VAZIA;
	  
	}
	
	else{
		
		fil->INICIO = (fil->INICIO+1) % MAXalu;
		fil->qtdALUNO --;
	}
	return 1;


}



void listar_aniversariantes_de_um_dado_mes(guarda *fil, int mmes){

    int i;
    printf("\n=============== Lista de aniversariantes de Mes de: %d ===============\n", mmes);
    for( i = 0; i < fil->qtdALUNO; i ++){

       if(fil->dados[i].mes == mmes){
         
         printf("-------> %s\n", fil->dados[i].nome);

         }


     }


}







