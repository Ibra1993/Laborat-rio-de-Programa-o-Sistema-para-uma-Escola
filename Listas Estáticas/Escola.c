#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Escola.h"

int quantidade_dos_professores(PROF *prof){


    if(prof == NULL)
	return -1;
	else
	return prof->qtdProf;

}

void destroi_lista_alunos(ALUNO *ptr){
	
	free(ptr);
	ptr = NULL;

}

void destroi_lista_disciplinas(DIS *pt){
	
	free(pt);
	pt = NULL;

}

void destroi_lista_professores(PROF *prof){
	
	free(prof);
	prof = NULL;

}

int Atualizar_lista_de_professores( PROF *prof, char nome[100] ){


	int MATRICULA;
	char NOME[100];
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    unsigned long long int Cpf;

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
	printf(" 1- Todos os campos; 2- Nome de professor; 3- Sexo; 4-Dia de nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8-  Matricula; \n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

	for( i = 0; i < prof->qtdProf; i ++){

		if( strcmp(prof->VET[i].Nome, nome ) != 0){

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

		printf(" Digite o novo nome de professor: ");
		scanf(" %[^\n]", NOME);

		printf(" Digite o novo numero de matricula de professor: ");
		scanf(" %d", &MATRICULA);
		
        if( MATRICULA < 1){
        	
        	valS = 1;
        	
        	while(valS == 1){
        		
        		printf(" Numero de matricula INVALIDO!!!\n");
        		printf(" Digite de novo o numero de matricula de professor: ");
		        scanf(" %d", &MATRICULA);
		        
		        if(MATRICULA > 0){
		        	valS = 0;
				}
			}
		}
		valS = 0;
		
	    printf(" Digite o novo sexo de professor: ");
		scanf(" %[^\n]", SEXO);

	    if( strcmp( SEXO, sexo1) != 0 && strcmp( SEXO, sexo2) != 0 && strcmp(SEXO, sexo3) != 0 && strcmp(SEXO, sexo4) != 0 && strcmp(SEXO, sexo5) != 0 && strcmp(SEXO, sexo6) != 0)
	    {
	    	val = 1;

	    	while( val == 1)
			{
				printf(" Novo sexo de professor INVALIDO!!!\n");
	    		printf(" Digite o novo sexo de professor: ");
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
		scanf(" %llu", &Cpf);

		if( Cpf < 9999999999 || Cpf > 99999999999 ){

			valCPF = 1;

			while( valCPF == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &Cpf);

		if( Cpf >= 10000000000 && Cpf <= 99999999999 ){

			valCPF = 0;

		   }
	   }

	}
		valCPF = 0;

		for( i = 0; i < prof->qtdProf; i++){

		if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

			strcpy(prof->VET[i].Nome, NOME);
			prof->VET[i].Matricula = MATRICULA;
			strcpy(prof->VET[i].Sexo, SEXO);
			prof->VET[i].Dia = DIA;
			prof->VET[i].Mes = MES;
			prof->VET[i].Ano = ANO;
			prof->VET[i].CPF = Cpf;

		   }

		 }
		  retorno  = ATUALIZADO_COM_SUCESSO;
		  return retorno;

	} else if(opcao == 2){

		printf(" Digite o novo nome de professor: ");
		scanf(" %[^\n]", NOME);

		for( i = 0; i < prof->qtdProf; i++){

			if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

				strcpy(prof->VET[i].Nome, NOME);

			}

		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;

	}else if(opcao == 3){

		int SS = 0;

		 printf(" Digite o novo sexo de professor: ");
		 scanf(" %[^\n]", SEXO);

	    if( strcmp( SEXO, sexo1) != 0 && strcmp( SEXO, sexo2) != 0 && strcmp(SEXO, sexo3) != 0 && strcmp(SEXO, sexo4) != 0 && strcmp(SEXO, sexo5) != 0 && strcmp(SEXO, sexo6) != 0)
	    {
	    	SS = 1;

	    	while( SS == 1)
			{
				printf(" Novo sexo de professor INVALIDO!!!\n");
	    		printf(" Digite o novo sexo de professor: ");
		        scanf(" %[^\n]", SEXO);

		if( strcmp( SEXO, sexo1) == 0 || strcmp( SEXO, sexo2) == 0  || strcmp(SEXO, sexo3) == 0  || strcmp(SEXO, sexo4) == 0  || strcmp(SEXO, sexo5) == 0  || strcmp(SEXO, sexo6) == 0)
           {

           		SS = 0;

		   }
	    }
	}
	   SS = 0;

		for( i = 0; i < prof->qtdProf; i ++){

			if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

				strcpy( prof->VET[i].Sexo, SEXO );

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

		for( i = 0; i < prof->qtdProf; i ++){

			if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

				prof->VET[i].Dia = DIA;

			}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		 return retorno;
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

			for( i = 0; i < prof->qtdProf; i ++){

				if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

					prof->VET[i].Mes = MES;

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

			for( i = 0; i < prof->qtdProf; i ++){

				if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

				prof->VET[i].Ano = ANO;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;
			 return retorno;


	}else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &Cpf);

		if( Cpf < 9999999999 || Cpf > 99999999999 ){

			cc = 1;

			while( cc == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &Cpf);

		if( Cpf >= 10000000000 && Cpf <= 99999999999 ){

			cc = 0;

		   }
	   }

	}
		cc = 0;

		for( i = 0; i < prof->qtdProf; i ++){

				if( strcmp ( prof->VET[i].Nome, nome ) == 0 ){

				 prof->VET[i].CPF = Cpf;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;
	        return retorno;

	}else if(opcao == 8){

		printf(" Digite o novo numero de matricula de professor: ");
		scanf(" %d", &MATRICULA);

		for( i = 0; i < prof->qtdProf; i ++){

			prof->VET[i].Matricula = MATRICULA;

		}

		retorno  = ATUALIZADO_COM_SUCESSO;
	    return retorno;

	}


  }


}




int Atualizar_dados_da_disciplina(DIS *pt, char CODIGO[20]){

	char Nome_Da_Disciplina[100];
	char Codigo[20];
	char Professor[100];
	int Semestre;
	int i;
	//int valida;
	int opcao;
	int retorno = 0;

	printf("\n--------------------------------------------------------------------------------\n");
    printf("                           OPCOES DE ATUALIZACAO\n");
	printf("--------------------------------------------------------------------------------\n");
	printf(" 1- Todos os campos; 2- Nome da disciplina; 3- Codigo; 4- Nome do(a) professor(a); 5- Semestre.\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);


	for( i = 0; pt->qtdDisciplinas; i ++){

		if( strcmp ( pt->vet[i].codigo, CODIGO ) != 0 ){

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



				if( strcmp(pt->vet[i].codigo, CODIGO) == 0 ){

				strcpy(pt->vet[i].nome_da_disciplina, Nome_Da_Disciplina);
				strcpy(pt->vet[i].codigo, Codigo);
				strcpy(pt->vet[i].professor, Professor);
				pt->vet[i].semestre = Semestre;

			 retorno = ATUALIZADO_COM_SUCESSO;
		  }

		} else if( opcao == 2 ){

			printf(" Digite o novo nome da disciplina: ");
			scanf(" %[^\n]", Nome_Da_Disciplina);

				if( strcmp(pt->vet[i].codigo, CODIGO) == 0 ){

				  strcpy(pt->vet[i].nome_da_disciplina, Nome_Da_Disciplina);

				retorno = ATUALIZADO_COM_SUCESSO;
				return retorno;
			}



		}else if(opcao == 3){

		    printf(" Digite o novo Codigo da disciplina: ");
			scanf(" %[^\n]", Codigo);

				if( strcmp(pt->vet[i].codigo, CODIGO) == 0 ){

					strcpy(pt->vet[i].codigo, Codigo);

				   retorno = ATUALIZADO_COM_SUCESSO;
				   return retorno;
			}



		}else if(opcao == 4){

			printf(" Digite o novo nome do(a) professor(a): ");
			scanf(" %[^\n]", Professor);


			if( strcmp(pt->vet[i].codigo, CODIGO) == 0 ){

			 strcpy(pt->vet[i].professor, Professor);

		    retorno = ATUALIZADO_COM_SUCESSO;
		    return retorno;

			}



		}else if(opcao == 5){

		printf(" Digite o novo semestre: ");
		scanf(" %d", &Semestre);

			if( strcmp(pt->vet[i].codigo, CODIGO) == 0 ){

					pt->vet[i].semestre = Semestre;



			retorno = ATUALIZADO_COM_SUCESSO;
			return retorno;
			}


		}

 	  }
	}



}


int atualizar_dados_dos_alunos(ALUNO *ptr, char Nome[100]){

	char NOME[100];
	int MATRICULA;
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    long long int CPF;
    //char disciplinaa[100];
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
	printf(" 1- Todos os campos; 2- Nome; 3- Sexo; 4- Dia de Nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8- Matricula\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

	for( i = 0; i < ptr->qtd; i ++){

		if(strcmp(ptr->array[i].nome, Nome) != 0){

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
		scanf(" %lld", &CPF);

		if( CPF < 9999999999 || CPF > 99999999999 ){

			valCPF = 1;

			while( valCPF == 1 ){

				printf("Novo CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %lld", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 ){

			valCPF = 0;

		   }
	   }

	}
		valCPF = 0;

		for( i = 0; i < ptr->qtd; i++){

		if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

			strcpy(ptr->array[i].nome, NOME);
			ptr->array[i].matricula = MATRICULA;
			strcpy(ptr->array[i].sexo, SEXO);
			ptr->array[i].dia = DIA;
			ptr->array[i].mes = MES;
			ptr->array[i].ano = ANO;
			ptr->array[i].cpf = CPF;

		   }

		 }
		 retorno  = ATUALIZADO_COM_SUCESSO;

	} else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( i = 0; i < ptr->qtd; i++){

			if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

				strcpy(ptr->array[i].nome, NOME);

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

		for( i = 0; i < ptr->qtd; i ++){

			if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

				strcpy( ptr->array[i].sexo, SEXO );

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

		for( i = 0; i < ptr->qtd; i ++){

			if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

				ptr->array[i].dia = DIA;

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

			for( i = 0; i < ptr->qtd; i ++){

				if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

					ptr->array[i].mes = MES;

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

			for( i = 0; i < ptr->qtd; i ++){

				if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

				ptr->array[i].ano = ANO;

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
		        scanf(" %llu", &CPF);

		if( CPF >= 10000000000 && CPF <= 99999999999 ){

			cc = 0;

		   }
	   }

	}
		cc = 0;

		for( i = 0; i < ptr->qtd; i ++){

				if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

				 ptr->array[i].cpf = CPF;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;


	}else if( opcao == 8){

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

		for( i = 0; i < ptr->qtd; i ++){

			if( strcmp ( ptr->array[i].nome, Nome ) == 0 ){

				ptr->array[i].matricula = MATRICULA;

				}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;
	}


  }

     return  retorno;
	 return -1;

}


int Cria_lista_de_profesores(PROF *prof){

 	prof = (PROF *) malloc(sizeof(PROF));

 	if(prof != NULL)
	 {

 		prof->qtdProf = 0;

	 }

	 return 1;
	 return -1;

 }

int Inserir_professor(PROF *prof, struct professor ins){

	if(prof->qtdProf == MAXPROF){

		return LISTA_CHEIA;

	}

	prof->VET[prof->qtdProf] = ins;
	prof->qtdProf ++;

	return INSERIDO_COM_SUCESSO;
	return -1;
}

void listar_professores(PROF *prof){

	int i;
	struct professor impr;
	printf("\n\n ============= Lista de Professores com os dados completos =============\n\n");

	for( i = 0; i < prof->qtdProf; i++)
	{

		impr = prof->VET[i];

		printf(" Nome do(a) professor(a): %s\n", impr.Nome);
		printf(" Matricula: %d\n", impr.Matricula);
		printf(" Sexo: %s\n", impr.Sexo);
		printf(" Dia de nascimento: %d\n", impr.Dia);
		printf(" Mes de nascimento: %d\n", impr.Mes);
		printf(" Ano de nascimento: %d\n", impr.Ano);
		printf(" CPF: %lld\n", impr.CPF);

			printf("\n");
	}



}

void listar_professores_por_sexo_masculino(PROF *prof){

	int indice;
	char sexoM[3] = "M";
	char sexom[3] = "m";

	printf("\n ========== Lista de professores Masculinos ==========\n");

	for( indice = 0; indice < prof->qtdProf; indice++)
	{

		if( strcmp( prof->VET[indice].Sexo, sexom) == 0 || strcmp(prof->VET[indice].Sexo, sexoM) == 0 )
		{

			printf(" ------> %s\n", prof->VET[indice].Nome);


		}

	}
	printf("\n\n");

}

void listar_professores_por_sexo_feminino(PROF *prof){

	int indice;
	char sexoF[3] = "F";
	char sexof[3] = "f";

	printf("\n ========== Lista de professores Femininos ==========\n");

	for( indice = 0; indice < prof->qtdProf; indice++)
	{

		if( strcmp( prof->VET[indice].Sexo, sexof) == 0 || strcmp(prof->VET[indice].Sexo, sexoF) == 0 )
		{

			printf(" ------> %s\n", prof->VET[indice].Nome);


		}

	}
	printf("\n\n");

}

int compara_nomes(const void *pa, const void *pb){

 	return strcmp(((struct professor *)pa)->Nome, ((struct professor*)pb)->Nome);



}


void Ordenar_professores_por_nome(PROF *prof){

	int i;
	int j;
    struct professor item[prof->qtdProf];

	printf("\n============= Lista de professores Ordenados por Nome =============\n\n");

	for (i = 0; i < prof->qtdProf; i++)
	{

     strcpy(item[i].Nome, prof->VET[i].Nome);

    }
	qsort(item, prof->qtdProf, sizeof(struct professor), compara_nomes);


	for(j = 0; j < prof->qtdProf; j++){

	  printf(" ------> %s\n", item[j].Nome);

	}


}

void listar_professores_por_ordem_de_nascimento(PROF *prof){

	int i;
	int j;
	struct professor tem[prof->qtdProf];


	for( i = 0; i < prof->qtdProf; i++){
		for( j = i + 1; j < prof->qtdProf; j++){


			if( prof->VET[i].Ano < prof->VET[j].Ano ){

				tem[i] = prof->VET[j];
				prof->VET[j] = prof->VET[i];
				prof->VET[i] = tem[i];

			}

			 if( prof->VET[i].Ano == prof->VET[j].Ano && prof->VET[i].Mes < prof->VET[j].Mes ){

				tem[i] = prof->VET[j];
				prof->VET[j] = prof->VET[i];
				prof->VET[i] = tem[i];

			}

			if( prof->VET[i].Ano == prof->VET[j].Ano && prof->VET[i].Mes == prof->VET[j].Mes && prof->VET[i].Dia < prof->VET[j].Dia){

				tem[i] = prof->VET[j];
				prof->VET[j] = prof->VET[j];
				prof->VET[i] = tem[i];

			}
		}

	}

	//int k;
	printf(" ==================== Lista de professores por Idade   ===========================\n\n");
	for( i = 0; i < prof->qtdProf; i++){

		printf(" -------> %s\n",prof->VET[i].Nome);

	}


}

void aniversariantes_do_mes(PROF *prof, int mes){


	int s;


	for( s = 0; s < prof->qtdProf; s ++ )
	{

		if( mes == prof->VET[s].Mes )
		{

			printf(" ------> %s\n", prof->VET[s].Nome);

		}

		else{}

	}

}

int Excluir_professor_na_lista(PROF *prof, char NOME[]){

	if( prof->qtdProf == 0 )
	return LISTA_VAZIA;

	int i = 0;
	int j;

	while( i < prof->qtdProf &&  strcmp(prof->VET[i].Nome, NOME) != 0 )
	    i ++;
	if( i == prof->qtdProf)
	return DISCIPLINA_NAO_ESTA_NA_LISTA;

	for( j = i; j < prof->qtdProf-1; j ++)
	prof->VET[j] = prof->VET[j+1];
	prof->qtdProf --;

	return EXCLUIDO_COM_SUCESSO;
	return NAO_FOI_EXCLUIDO_COM_SUCESSO;

}

int Cria_lista_de_disciplinas(DIS *pt){

	pt = (DIS *) malloc (sizeof(DIS));

	if( pt != NULL )
	{

		pt->qtdDisciplinas = 0;

	}

	return 1;
	return -1;
}

int Cadastrar_disciplinas(DIS *pt, struct disciplina el){

	int retorno;

	if(pt->qtdDisciplinas == MAXdis)
	{

		 retorno = LISTA_CHEIA;

	}

	pt->vet[pt->qtdDisciplinas] = el;
	pt->qtdDisciplinas ++;
	retorno = INSERIDO_COM_SUCESSO;

	return retorno;

}

void listar_dados_da_disciplinas_sem_alunos(DIS *pt){

	int i;
	struct disciplina ell;

	printf("\n ================== Dados da disciplina  =======================\n\n");

	for( i = 0; i < pt->qtdDisciplinas; i++){

		ell = pt->vet[i];

		printf(" Nome da disciplina: %s\n", ell.nome_da_disciplina);
	    printf(" Codigo da disciplina: %s\n", ell.codigo);
	    printf(" Semestre: %d\n", ell.semestre);
	    printf(" Nome do(a) professor(a): %s\n", ell.professor);

	    printf("\n\n");
	}



}

void listar_disciplinas_e_alunos_matriculados( DIS *pt, ALUNO *p){


    char DISCIPLINA[100];
    int i;
    int k;


    printf(" Digite a disciplina: ");
    scanf(" %[^\n]", DISCIPLINA);

    printf("\n========== Dados da disciplina de : %s ========== \n\n", DISCIPLINA);

    for( i = 0; i < pt->qtdDisciplinas; i++ )
	{

    	 if( strcmp( pt->vet[i].nome_da_disciplina, DISCIPLINA ) == 0 )

		 {

			printf(" Nome da disciplina: %s\n", pt->vet[i].nome_da_disciplina);
		    printf(" Codigo da disciplina: %s\n", pt->vet[i].codigo);
		    printf(" Semestre: %d\n", pt->vet[i].semestre);
		    printf(" Nome do(a) professor(a): %s\n", pt->vet[i].professor);

		    printf("\n\n");

		 }
		 //else{}

	}

	printf("\n                            Alunos Matriculados na disciplina de: %s                       \n\n", DISCIPLINA);

	for( k = 0; k < p->qtd; k++)
	{

		if( strcmp( p->array[k].dis.nome_da_disciplina,  DISCIPLINA) == 0 )
		{
			printf(" -----> %s\n", p->array[k].nome);

		}
    }



}

int Excluir_Disciplina_na_Lista(DIS *pt, char DISCIPLINA[]){

	if(pt->qtdDisciplinas == 0)
	return LISTA_VAZIA;

	int i = 0;
	int j;

	while( i < pt->qtdDisciplinas &&  strcmp(pt->vet[i].nome_da_disciplina, DISCIPLINA) != 0 )
	    i ++;
	if( i == pt->qtdDisciplinas)
	return DISCIPLINA_NAO_ESTA_NA_LISTA;

	for( j = i; j < pt->qtdDisciplinas-1; j ++)
	pt->vet[j] = pt->vet[j+1];
	pt->qtdDisciplinas --;

	return EXCLUIDO_COM_SUCESSO;
	return NAO_FOI_EXCLUIDO_COM_SUCESSO;


}



int Cria_lista(ALUNO *ptr){


	ptr = (ALUNO *) malloc(sizeof(ALUNO));

	if( ptr != NULL ){

		 ptr->qtd = 0;

	}

	return 1;
	return -1;
}

int insere(ALUNO *p, struct aluno al){

     int retorno;
     if(p->qtd == MAX){

     retorno = LISTA_CHEIA;
	 }

     p->array[p->qtd] = al;
     p->qtd ++;

     retorno = INSERIDO_COM_SUCESSO;


    return retorno;

}

int Tamanho_da_lista(ALUNO *p){

	if(p == NULL)
	return -1;
	else
	return p->qtd;

}

int Excluir_aluno_de_uma_disciplina(ALUNO *p, char disci[]){

	if(p->qtd == 0)
	return LISTA_VAZIA;

	int i = 0;
	int j;

	while( i < p->qtd  &&  strcmp( p->array[i].dis.nome_da_disciplina, disci) != 0 )
	    i ++;
	if( i == p->qtd)
	return DISCIPLINA_NAO_ESTA_NA_LISTA;

	for( j = i; j < p->qtd-1; j ++)
	p->array[j] = p->array[j+1];
	p->qtd --;

	return EXCLUIDO_COM_SUCESSO;
	return NAO_FOI_EXCLUIDO_COM_SUCESSO;
}

void Lista_de_sexo_masculino_alunos(ALUNO *p){

	printf("\n\n");

	int i;
	char sexoM[3] = "M";
	char sexom[3] = "m";


	printf(" ====================================\n\n");
	printf(" Lista de ALUNOS.\n");

	for( i = 0; i < p->qtd; i++ ){

		if(strcmp( p->array[i].sexo, sexoM) == 0 || strcmp( p->array[i].sexo, sexom) == 0)
		{

			printf(" --------> %s\n", p->array[i].nome);

		}


	}
	printf("\n\n");
}

void Lista_de_sexo_feminino_alunas(ALUNO *p){

		printf("\n\n");

	int i;
	char sexoM[3] = "F";
	char sexom[3] = "f";


	printf(" ====================================\n\n");
	printf(" Lista de ALUNAS.\n");

	for( i = 0; i < p->qtd; i++ ){

		if(strcmp( p->array[i].sexo, sexoM) == 0 || strcmp( p->array[i].sexo, sexom) == 0)
		{

			printf(" --------> %s\n", p->array[i].nome);

		}


	}
	printf("\n\n");


}

int compara_nomesAlunos(const void *paa, const void *pbb){



 	return strcmp(((struct aluno *)paa)->nome,((struct aluno *)pbb)->nome);

}

void Listar_por_ordem_alfabetica_os_alunos(ALUNO *p){

	int k;
	int j;
	struct aluno vet[p->qtd];

	printf("\n============= Lista de alunos Ordenados por Nome =============\n\n");
	for (k = 0; k < p->qtd; k++)
	{

     strcpy(vet[k].nome, p->array[k].nome);

    }

	qsort( vet, p->qtd, sizeof(struct aluno), compara_nomesAlunos);

	for(j = 0; j < p->qtd; j ++){

	  printf(" --------> %s\n", vet[j].nome);

	}


}


void Listar_por_ordem_de_nascimento(ALUNO *p){

	int i;
	int j;
	struct aluno tem[p->qtd];


	for( i = 0; i < p->qtd; i++){
		for( j = i+1; j < p->qtd; j++){


			if( p->array[i].ano < p->array[j].ano ){

				tem[i] = p->array[j];
				p->array[j] = p->array[i];
				p->array[i] = tem[i];

			}

			 if( p->array[i].ano == p->array[j].ano && p->array[i].mes < p->array[j].mes ){

				tem[i] = p->array[j];
				p->array[j] = p->array[i];
				p->array[i] = tem[i];

			}

			if( p->array[i].ano == p->array[j].ano && p->array[i].mes == p->array[j].mes && p->array[i].dia < p->array[j].dia){

				tem[i] = p->array[j];
				p->array[j] = p->array[i];
				p->array[i] = tem[i];

			}
		}

	}


	printf("\n==================== Lista de Alunos por Idade   ===========================\n\n");
	for( i = 0; i < p->qtd; i ++){

		printf(" --------> %s\n", p->array[i].nome);

	}

}

void Listar_alunos_string_de_busca(ALUNO *pp){

	int i, j;
	char let[100];
	char p;
	char s;
	char t;


	printf(" \n================== Os nomes que tem aqueles tres letras ============================\n\n");

	printf("Insira as letras (Minimo 3) do aluno: ");
    scanf(" %[^\n]", let);

    p = let[0];
    s = let[1];
    t = let[2];
	int cont = 0;


	for( i = 0; i < pp->qtd; i++)
	{
	    for( j = 0; j < strlen(pp->array[i].nome); j++){


	  	if( pp->array[i].nome[j] == p && pp->array[i].nome[j] == s && pp->array[i].nome[j] == t )
	  	{
		  	cont ++;

		  	if( cont > 0 )

	  		printf(" %s\n", pp->array[i].nome);


	    	}

	     }

	  }

  }




void imprimir(ALUNO *p){

	printf("\n\n");

	int i;
	struct aluno al;


	printf("========== Lista dos dados dos alunos.==========\n\n");

	for( i = 0; i < p->qtd; i++){

		al = p->array[i];

		printf(" Nome : %s\n", al.nome);
		printf(" Matricula : %d\n", al.matricula);
	    printf(" Nome da disciplina: %s\n", al.dis.nome_da_disciplina);
		printf(" Dia de nascimento: %d\n", al.dia);
		printf(" Mes de nascimento: %d\n", al.mes);
		printf(" Ano de nascimento: %d\n", al.ano);
		printf(" Sexo : %s\n", al.sexo);
		printf(" CPF : %lld\n", al.cpf);



	    printf("\n\n");



}
    	printf("==========================================================\n\n");


}


