#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "Escola.h"


int atualizar_lista_dos_professor( PI *pi, int mmatricula ){

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
	printf(" 1- Todos os campos; 2- Nome; 3- Sexo; 4- Dia de Nascimento; 5- Mes de Nascimento; 6- Ano de Nascimento; 7- CPF; 8- Matricula\n\n");

    printf(" Digite opcao: ");
	scanf(" %d", &opcao);

	for( i = 0; i < pi->qtdPROFESSOR; i ++){

		if( pi->dados[i].Matricula != mmatricula ){

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

		for( i = 0; i < pi->qtdPROFESSOR; i++){

		if( pi->dados[i].Matricula == mmatricula ){

			strcpy(pi->dados[i].Nome, NOME);
			pi->dados[i].Matricula = MATRICULA;
			strcpy(pi->dados[i].Sexo, SEXO);
			pi->dados[i].Dia = DIA;
			pi->dados[i].Mes = MES;
			pi->dados[i].Ano = ANO;
			pi->dados[i].CPF = CPF;

		   }

		 }

		 retorno  = ATUALIZADO_COM_SUCESSO;

	} else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( i = 0; i < pi->qtdPROFESSOR; i++){

			if( pi->dados[i].Matricula == mmatricula ){

				strcpy(pi->dados[i].Nome, NOME);

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

		for( i = 0; i < pi->qtdPROFESSOR; i ++){

			if( pi->dados[i].Matricula ==  mmatricula ){

				strcpy( pi->dados[i].Sexo, SEXO );

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

		for( i = 0; i < pi->qtdPROFESSOR; i ++){

			if( pi->dados[i].Matricula == mmatricula ){

				pi->dados[i].Dia = DIA;

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

			for( i = 0; i < pi->qtdPROFESSOR; i ++){

				if( pi->dados[i].Matricula == mmatricula ){

					pi->dados[i].Mes = MES;

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

			for( i = 0; i < pi->qtdPROFESSOR; i ++){

				if( pi->dados[i].Matricula == mmatricula ){

				pi->dados[i].Ano = ANO;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;



	}else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &CPF);

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

		for( i = 0; i < pi->qtdPROFESSOR; i ++){

				if( pi->dados[i].Matricula == mmatricula ){

				 pi->dados[i].CPF = CPF;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;


	}else if( opcao == 8){

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

		for( i = 0; i < pi->qtdPROFESSOR; i ++){

			if( pi->dados[i].Matricula == mmatricula ){

				pi->dados[i].Matricula = MATRICULA;

				}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;
	}


  }

     return  retorno;
	 return -1;


}




PI *cria_pilha_de_professor(){

   PI *pi = (PI *) malloc(sizeof(PI));
      if( pi != NULL )
        pi->qtdPROFESSOR = 0;
        return pi;

}



int insere_professor_na_pilha( PI *pi, struct professor al ){


    if(pi == NULL)
	return ERRO_NA_CRIACAO_DE_PILHA;

	if(pi->qtdPROFESSOR == MAXalu)
	return PILHA_CHEIA;
	
	else
	pi->dados[pi->qtdPROFESSOR] = al;
	pi->qtdPROFESSOR ++;
	
	return INSERIDO_COM_SUCESSO;

}



void imprimir_lista_de_professor( PI *pi){

   int i;

   printf("\n ========== Lista dos alunos com os dados completos ==========\n\n");

   for( i = 0; i < pi->qtdPROFESSOR; i ++){

      printf("Nome: %s\n", pi->dados[i].Nome);
      printf("Sexo: %s\n", pi->dados[i].Sexo);
      printf("Dia de Nascimento: %d\n", pi->dados[i].Dia);
      printf("Mes de Nascimento: %d\n", pi->dados[i].Mes);
      printf("Ano de Nascimento: %d\n", pi->dados[i].Ano);
      printf("CPF: %llu\n", pi->dados[i].CPF);
      printf("Matricula: %d\n", pi->dados[i].Matricula);
     

      printf("\n\n");

  }


}


void imprimir_professor_de_sexo_masculino(PI *pi){

      int i;
   
   char sexo1[3] = "M";
   char sexo2[3] = "m";

   printf("\n ============ Lista de alunos (sexo masculino) ============\n\n");

   for( i = 0; i < pi->qtdPROFESSOR; i ++){

      if( strcmp (pi->dados[i].Sexo, sexo1) == 0 || strcmp (pi->dados[i].Sexo, sexo2) == 0){

       printf("-----> %s\n", pi->dados[i].Nome);

       }


    }


}


void imprimir_professor_de_sexo_feminino(PI *pi){

   int i;

   char sexo1[3] = "F";
   char sexo2[3] = "f";

   printf("\n ============ Lista de professoras (sexo feminino) ============\n\n");

   for( i = 0; i < pi->qtdPROFESSOR; i ++){
      
        if( strcmp ( pi->dados[i].Sexo, sexo1 ) == 0 || strcmp ( pi->dados[i].Sexo, sexo2 ) == 0){

         printf("-----> %s\n", pi->dados[i].Nome);

       }

    }




}

void libera_memoria_reservada_para_professor(PI *pi){


   free(pi);


}



void libera_memoria_reservada_para_aluno(Pilha *pi){

    free(pi);


}

void imprimir_lista_de_alunos( Pilha *pi){

   int i;

   printf("\n ========== Lista dos alunos com os dados completos ==========\n\n");

   for( i = 0; i < pi->qtdALUNO; i ++){

      printf("Nome: %s\n", pi->Dados[i].nome);
      printf("Sexo: %s\n", pi->Dados[i].sexo);
      printf("Dia de Nascimento: %d\n", pi->Dados[i].dia);
      printf("Mes de Nascimento: %d\n", pi->Dados[i].mes);
      printf("Ano de Nascimento: %d\n", pi->Dados[i].ano);
      printf("CPF: %llu\n", pi->Dados[i].cpf);
      printf("Matricula: %d\n", pi->Dados[i].matricula);
      printf("Sexo: %s\n", pi->Dados[i].dis.nome_da_disciplina);


      printf("\n\n");
  }


}


void acessa_topo_da_pilha(PILHA *pi){
	
	if(pi == NULL || pi->qtdDISCIPLINA == 0)
	 printf("PILHA VAZIA\n\n");;
	
	 int i;

    printf("\n ========== Elemento do TOPO da pilha ==========\n\n");

   for( i = pi->qtdDISCIPLINA-1; i <= pi->qtdDISCIPLINA-1; i ++){

     printf("Disciplina: %s\n", pi->DADOS[i].nome_da_disciplina);
     printf("Codigo: %s\n", pi->DADOS[i].codigo);
     printf("Semestre: %d\n", pi->DADOS[i].semestre);
     printf("Professor: %s\n", pi->DADOS[i].professor);

      printf("\n\n");
  }

	
}


Pilha *cria_pilha_de_alunos(){


  Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
  if(pi != NULL)
  pi->qtdALUNO = 0;

  return pi;

}



int insere_aluno_na_pilha( Pilha *pi, struct aluno al ){


    if(pi == NULL)
	return ERRO_NA_CRIACAO_DE_PILHA;

	if(pi->qtdALUNO == MAXalu)
	return PILHA_CHEIA;
	
	else
	pi->Dados[pi->qtdALUNO] = al;
	pi->qtdALUNO ++;
	
	return INSERIDO_COM_SUCESSO;



}


PILHA *cria_pilha_disciplina(){

   PILHA *pi = (PILHA *) malloc(sizeof(PILHA));
	
	if( pi != NULL)
	pi->qtdDISCIPLINA = 0;
	
	return pi;

}

int insere_elemento_disciplina(PILHA *pi, struct disciplina valor){

    if(pi == NULL)
	return ERRO_NA_CRIACAO_DE_PILHA;

	if(pi->qtdDISCIPLINA == MAXdis)
	return PILHA_CHEIA;
	
	else
	pi->DADOS[pi->qtdDISCIPLINA] = valor;
	pi->qtdDISCIPLINA ++;
	
	return INSERIDO_COM_SUCESSO;
    
}


void listar_disciplinas(PILHA *pi){

    int i;

    printf("\n ========== Lista das disciplinas com os dados completos ==========\n\n");

    for( i = 0; i < pi->qtdDISCIPLINA; i ++){
 
     printf("Disciplina: %s\n", pi->DADOS[i].nome_da_disciplina);
     printf("Codigo: %s\n", pi->DADOS[i].codigo);
     printf("Semestre: %d\n", pi->DADOS[i].semestre);
     printf("Professor: %s\n", pi->DADOS[i].professor);

     printf("\n\n");
    
    }

}


void libera_pilha_disciplina(PILHA *pi){

   free(pi);

}



int remove_pilha_disciplina(PILHA *pi){


    if( pi == NULL || pi->qtdDISCIPLINA == 0 )
	return PILHA_VAZIA;
	else
	pi->qtdDISCIPLINA --;
	return REMOVIDO_COM_SUCESSO;

}


int atualizar_dados_da_disciplina( PILHA *pi, char codigo_da_disciplina[20] ){

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
	scanf(" %d", &opcao);
    printf("\n");

	for( i = 0; pi->qtdDISCIPLINA; i ++){

		if( strcmp( pi->DADOS[i].codigo, codigo_da_disciplina ) != 0 ){

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



				if( strcmp(pi->DADOS[i].codigo, codigo_da_disciplina) == 0 ){

				strcpy(pi->DADOS[i].nome_da_disciplina, Nome_Da_Disciplina);
				strcpy(pi->DADOS[i].codigo, Codigo);
				strcpy(pi->DADOS[i].professor, Professor);
				pi->DADOS[i].semestre = Semestre;

			 retorno = ATUALIZADO_COM_SUCESSO;
		  }

		} else if( opcao == 2 ){

			printf(" Digite o novo nome da disciplina: ");
			scanf(" %[^\n]", Nome_Da_Disciplina);

				if( strcmp(pi->DADOS[i].codigo, codigo_da_disciplina) == 0 ){

				  strcpy(pi->DADOS[i].nome_da_disciplina, Nome_Da_Disciplina);

				retorno = ATUALIZADO_COM_SUCESSO;
				return retorno;
			}



		}else if(opcao == 3){

		    printf(" Digite o novo Codigo da disciplina: ");
			scanf(" %[^\n]", Codigo);

				if( strcmp(pi->DADOS[i].codigo, codigo_da_disciplina) == 0 ){

					strcpy(pi->DADOS[i].codigo, Codigo);

				   retorno = ATUALIZADO_COM_SUCESSO;
				   return retorno;
			}



		}else if(opcao == 4){

			printf(" Digite o novo nome do(a) professor(a): ");
			scanf(" %[^\n]", Professor);


			if( strcmp(pi->DADOS[i].codigo, codigo_da_disciplina) == 0 ){

			 strcpy(pi->DADOS[i].professor, Professor);

		    retorno = ATUALIZADO_COM_SUCESSO;
		    return retorno;

			}



		}else if(opcao == 5){

		printf(" Digite o novo semestre: ");
		scanf(" %d", &Semestre);

      

			if( strcmp(pi->DADOS[i].codigo, codigo_da_disciplina) == 0 ){

					pi->DADOS[i].semestre = Semestre;



			retorno = ATUALIZADO_COM_SUCESSO;
			return retorno;
			}


		}

 	  }
	}

}



int pilha_cheia_disciplina(PILHA *pi){

    if(pi == NULL)
	return ERRO_NA_CRIACAO_DE_PILHA;
	return pi->qtdDISCIPLINA == MAXdis; // retorna zero sempre que a pilha NÃO estiver cheia

}



int pilha_vazia_disciplina(PILHA *pi){

    if(pi == NULL)
	return ERRO_NA_CRIACAO_DE_PILHA;
	return pi->qtdDISCIPLINA == 0; //retorna 1 sempre que estiver vazia SENÃO retorna zero indicando que não está vazia.


}


void listar_disciplinas_e_alunos_matriculados( PILHA *pi, Pilha *paluno){

  int i, k;
  char DISCIPLINA[100];

  printf(" Digite a disciplina: ");
  scanf(" %[^\n]", DISCIPLINA);


  printf("n\n =========== Dados da disciplina %s ==========\n", DISCIPLINA);

  for( i = 0; i < pi->qtdDISCIPLINA; i ++){
     
    if( strcmp ( pi->DADOS[i].nome_da_disciplina, DISCIPLINA ) == 0)
     {

     printf("Disciplina: %s\n", pi->DADOS[i].nome_da_disciplina);
     printf("Codigo: %s\n", pi->DADOS[i].codigo);
     printf("Semestre: %d\n", pi->DADOS[i].semestre);
     printf("Professor: %s\n", pi->DADOS[i].professor);

     printf("\n");

    }


   }


    printf("\n========== Alunos Matriculados na disciplina de: %s ========== \n", DISCIPLINA);

	for( k = 0; k < paluno->qtdALUNO; k++)
	{

		if( strcmp( paluno->Dados[k].dis.nome_da_disciplina,  DISCIPLINA) == 0 )
		{
			printf(" -----> %s\n", paluno->Dados[k].nome);

		}

       

    }


}



void imprimir_alunos_de_sexo_masculino(Pilha *pi){

   int i;
   
   char sexo1[3] = "M";
   char sexo2[3] = "m";

   printf("\n ============ Lista de alunos (sexo masculino) ============\n\n");

   for( i = 0; i < pi->qtdALUNO; i ++){

      if( strcmp (pi->Dados[i].sexo, sexo1) == 0 || strcmp (pi->Dados[i].sexo, sexo2) == 0){

       printf("-----> %s\n", pi->Dados[i].nome);

       }


    }


}


void imprimir_alunos_de_sexo_feminino(Pilha *pi){

    int i;

   char sexo1[3] = "F";
   char sexo2[3] = "f";

   printf("\n ============ Lista de alunas (sexo feminino) ============\n\n");

   for( i = 0; i < pi->qtdALUNO; i ++){
      
        if( strcmp ( pi->Dados[i].sexo, sexo1 ) == 0 || strcmp ( pi->Dados[i].sexo, sexo2 ) == 0){

         printf("-----> %s\n", pi->Dados[i].nome);

       }

    }


}




void acessa_topo_da_pilha_aluno(Pilha *pi){


   if(pi == NULL || pi->qtdALUNO == 0)
	 printf("PILHA VAZIA\n\n");;
	
	 int i;

    printf("\n ========== Elemento do TOPO da pilha ==========\n\n");

   for( i = pi->qtdALUNO-1; i <=pi->qtdALUNO-1; i ++){

      printf("Nome: %s\n", pi->Dados[i].nome);
      printf("Sexo: %s\n", pi->Dados[i].sexo);
      printf("Dia de Nascimento: %d\n", pi->Dados[i].dia);
      printf("Mes de Nascimento: %d\n", pi->Dados[i].mes);
      printf("Ano de Nascimento: %d\n", pi->Dados[i].ano);
      printf("CPF: %llu\n", pi->Dados[i].cpf);
      printf("Matricula: %d\n", pi->Dados[i].matricula);
      printf("Disciplina: %s\n", pi->Dados[i].dis.nome_da_disciplina);

      printf("\n\n");
  }

}


int excluir_aluno_na_lista(Pilha *pi){

    if( pi == NULL || pi->qtdALUNO == 0 )
	return PILHA_VAZIA;
	else
	pi->qtdALUNO --;
	return REMOVIDO_COM_SUCESSO;


}


void listar_aniversariantes_de_um_dado_mes(Pilha *pi, int mmes){

     int i;

     printf("\n ========== Aniversariantes do mes de: %d ==========\n", mmes);

     for( i = 0; i < pi->qtdALUNO; i ++ ){

        if( pi->Dados[i].mes == mmes){

         printf("-----> %s\n", pi->Dados[i].nome);

        }

    }
 
}


int quantidade_dos_alunos(Pilha *pi){

      

      if(pi == NULL )
      return -1;
      else
      return pi->qtdALUNO;

}




int pilha_vazia_de_alunos(Pilha *pi){

    if( pi == NULL )
	return ERRO_NA_CRIACAO_DE_PILHA;
	return pi->qtdALUNO == MAXalu; // retorna zero sempre que a pilha NÃO estiver cheia
   
}


int pilha_cheia_de_alunos(Pilha *pi){

    if( pi == NULL )
	return ERRO_NA_CRIACAO_DE_PILHA;
	return pi->qtdALUNO == MAXalu; // retorna zero sempre que a pilha NÃO estiver cheia

}



int atualizar_lista_dos_alunos( Pilha *pi, int mmatricula ){

    char NOME[100];
	int MATRICULA;
	char SEXO[3];
	int DIA;
	int MES;
	int ANO;
    unsigned long long int CPF;
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

	for( i = 0; i < pi->qtdALUNO; i ++){

		if( pi->Dados[i].matricula != mmatricula ){

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

		for( i = 0; i < pi->qtdALUNO; i++){

		if( pi->Dados[i].matricula == mmatricula ){

			strcpy(pi->Dados[i].nome, NOME);
			pi->Dados[i].matricula = MATRICULA;
			strcpy(pi->Dados[i].sexo, SEXO);
			pi->Dados[i].dia = DIA;
			pi->Dados[i].mes = MES;
			pi->Dados[i].ano = ANO;
			pi->Dados[i].cpf = CPF;

		   }

		 }

		 retorno  = ATUALIZADO_COM_SUCESSO;

	} else if(opcao == 2){

		printf(" Digite o novo nome do aluno: ");
		scanf(" %[^\n]", NOME);

		for( i = 0; i < pi->qtdALUNO; i++){

			if( pi->Dados[i].matricula == mmatricula ){

				strcpy(pi->Dados[i].nome, NOME);

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

		for( i = 0; i < pi->qtdALUNO; i ++){

			if( pi->Dados[i].matricula ==  mmatricula ){

				strcpy( pi->Dados[i].sexo, SEXO );

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

		for( i = 0; i < pi->qtdALUNO; i ++){

			if( pi->Dados[i].matricula == mmatricula ){

				pi->Dados[i].dia = DIA;

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

			for( i = 0; i < pi->qtdALUNO; i ++){

				if( pi->Dados[i].matricula == mmatricula ){

					pi->Dados[i].mes = MES;

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

			for( i = 0; i < pi->qtdALUNO; i ++){

				if( pi->Dados[i].matricula == mmatricula ){

				pi->Dados[i].ano = ANO;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;



	}else if(opcao == 7){

		int cc = 0;

		printf(" Digite o novo CPF: ");
		scanf(" %llu", &CPF);

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

		for( i = 0; i < pi->qtdALUNO; i ++){

				if( pi->Dados[i].matricula == mmatricula ){

				 pi->Dados[i].cpf = CPF;

				}
			}

	    	retorno  = ATUALIZADO_COM_SUCESSO;


	}else if( opcao == 8){

		printf(" Digite o novo numero de matricula do aluno: ");
		scanf(" %d", &MATRICULA);

		for( i = 0; i < pi->qtdALUNO; i ++){

			if( pi->Dados[i].matricula == mmatricula ){

				pi->Dados[i].matricula = MATRICULA;

				}
		}

		retorno  = ATUALIZADO_COM_SUCESSO;
		return retorno;
	}


  }

     return  retorno;
	 return -1;




}

void acessa_topo_da_pilha_professor(PI*pi){

    if(pi == NULL || pi->qtdPROFESSOR == 0)
	 printf("PILHA VAZIA\n\n");;
	
	 int i;

    printf("\n ========== Elemento do TOPO da pilha ==========\n\n");

   for( i = pi->qtdPROFESSOR-1; i <=pi->qtdPROFESSOR-1; i ++){

      printf("Nome: %s\n", pi->dados[i].Nome);
      printf("Sexo: %s\n", pi->dados[i].Sexo);
      printf("Dia de Nascimento: %d\n", pi->dados[i].Dia);
      printf("Mes de Nascimento: %d\n", pi->dados[i].Mes);
      printf("Ano de Nascimento: %d\n", pi->dados[i].Ano);
      printf("CPF: %llu\n", pi->dados[i].CPF);
      printf("Matricula: %d\n", pi->dados[i].Matricula);
      

      printf("\n\n");
  }
  

}


int excluir_professor_na_lista(PI *pi){


    if( pi == NULL || pi->qtdPROFESSOR == 0 )
	return PILHA_VAZIA;
	else
	pi->qtdPROFESSOR --;
	return REMOVIDO_COM_SUCESSO;

}



void listar_aniversariantes_de_um_dado_mes_professor(PI *pi, int mmmes){

      int i;

     printf("\n ========== Aniversariantes do mes de: %d ==========\n", mmmes);

     for( i = 0; i < pi->qtdPROFESSOR; i ++ ){

        if( pi->dados[i].Mes == mmmes){

         printf("-----> %s\n", pi->dados[i].Nome);

        }

    }
 
}


int quantidade_dos_professor(PI *pi){

      if(pi == NULL )
      return -1;
      else
      return pi->qtdPROFESSOR;

}


int pilha_vazia_de_professor(PI *pi){

    if( pi == NULL )
	return ERRO_NA_CRIACAO_DE_PILHA;
	return pi->qtdPROFESSOR == MAXprof; // retorna zero sempre que a pilha NÃO estiver cheia


}


int pilha_cheia_de_professor(PI *pi){

    if( pi == NULL )
	return ERRO_NA_CRIACAO_DE_PILHA;
	return pi->qtdPROFESSOR == MAXprof; // retorna zero sempre que a pilha NÃO estiver cheia


}








