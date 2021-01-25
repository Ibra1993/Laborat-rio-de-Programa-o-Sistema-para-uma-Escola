#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "Escola.h"


int main(){


    PILHA *pdisci;
    struct disciplina dis;
    Pilha *pAluno;
    struct aluno al;
    PI *PROF;
    struct professor ins;

    int opcao;
    int pd, pdd, pddd, pdddd, pddddd;
    char  codigo_da_disciplina[20];
    int pa, paa, mmes, paaa, paaaa, paaaaa, paaaaaa,  paaaaaaa, mmmes, TR, TRT, TRS, TRF, mmmatricula;
    int mmatricula;

    int pb; 
    int Valida = 0;
    int Teste = 0;
    int ValMatricula = 0;



    char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";
    int valida = 0;
    int teste = 0;
    int valMatricula = 0;

   do{
   
    printf("\n ====================================================================\n\n");
    printf("\n =============== Menus =========== .\n");
    printf("\n\nATENCAO, ANTES DE CADASTRAR ALUNO NUMA DISCIPLINA, PRIMEIRO, A DISCIPLINA PRECISA SER CADASTRADA!!!\n\n");
 
    printf("\n        1- Criar/reservar ESPAÇO de memoria para Lista de disciplinas                     \n");
	printf("\n        2- Cadastrar disciplinas                                                           \n");
	printf("\n        3- Listar dados da disciplinas sem alunos  				                         \n");
    printf("\n        4- Excluir Disciplina na lista                                                     \n");
    printf("\n        5- Atualizar dados das disciplinas                                                 \n");
    printf("\n        6- Verificar se a lista (PILHA) das disciplinas está CHEIA ou NÃO   		         \n");
    printf("\n        7- Verificar se a lista(PILHA) das disciplinas está VAZIA ou NÃO                    \n");
    printf("\n        8- Reservar memória para lista(PILHA) de alunos                                      \n");
    printf("\n        9- Inserir aluno na lista(PILHA)                                                     \n");
    printf("\n       10- Listar alunos                                                                 \n");
    printf("\n       11- Acessar o TOPO da lista (PILHA) da disciplina                                  \n");
    printf("\n       12- Listar uma disciplina, dados da disciplina e os alunos matriculados nessa disciplina\n");
    printf("\n       13- Listar alunos de sexo masculino                                                  \n");
    printf("\n       14- Listar alunos de sexo feminino                                                    \n");
    printf("\n       15- Acessar o TOPO da lista (PILHA) dos alunos                                       \n");
    printf("\n       16- Excluir aluno na lista (PILHA)                                                   \n");
    printf("\n       17- Listar alunos aniversariantes  de um determinado mes                             \n");
    printf("\n       18- Obter quantidade dos alunos na lista (PILHA)                                     \n");
    printf("\n       19- Verificar se a lista(PILHA) dos alunos está VAZIA ou NÃO                          \n");
    printf("\n       20- Verificar se a lista (PILHA) dos alunos está CHEIA ou NÃO                        \n");
    printf("\n       21- Atualizar lista de alunos                                                        \n");
    printf("\n       22- Reservar/Criar ESPAÇO de memória para lista de professores                     \n");
    printf("\n       23- Cadastrar professor na lista (PILHA)                                            \n");
    printf("\n       24- Listar professores                                                              \n");
    printf("\n       25- Listar professores de Sexo Masculino                                            \n");
    printf("\n       26- Listar professoras  (sexo) Feminino                                             \n");
    printf("\n       27- Acessar o TOPO da lista(PILHA)                                                  \n");
    printf("\n       28- Excluir professor na lista (PILHA)                                                \n");
    printf("\n       29- Listar professor(es) aniversariantes de um dado mês                               \n");
    printf("\n       30- Obter quantidade dos profesores                                                  \n");
    printf("\n       31- Verificar se a lista(PILHA) dos professores está VAZIA ou NÃO                    \n");
    printf("\n       32- Verificar se a lista (PILHA) dos professores está CHEIA ou NÃO                   \n");
    printf("\n       33- Atualizar a lista(PILHA) dos professores                                          \n");
    printf("\n       34- SAIR                                                                             \n");
    printf("\n ====================================================================\n\n");
 
    printf("  Digite a opcao: ");
    scanf("%d", &opcao);
    
   switch(opcao)
   {
   
  case 1:

       pdisci = cria_pilha_disciplina();
   
       break;

  case 2:

       printf(" Digite o nome da disciplina: ");
       scanf(" %[^\n]", dis.nome_da_disciplina);
      
       printf(" Digite o codigo da disciplina: ");
       scanf(" %[^\n]", dis.codigo);

       printf(" Digite o semestre: ");
       scanf(" %d", &dis.semestre);
 
       printf(" Digite o nome do(a) professor(a): ");
       scanf(" %[^\n]", dis.professor);
       

       pd = insere_elemento_disciplina( pdisci, dis);
       printf(" SE o valor de retorno for nigual a 1 portanto, inserido com SUCESSO. VEJA --->%d\n", pd);

       break;

   case 3:

       listar_disciplinas(pdisci);

       break;


   case 4:

       pdd = remove_pilha_disciplina(pdisci);
       printf ("Se o valor de retorno for igual a 1 portanto, removido com SUCESSO. VEJA --->%d\n", pdd);

       break;

   case 5:

       printf(" Digite  codigo da disciplina que quer atualizar: ");
       scanf(" %[^\n]", codigo_da_disciplina );

       pddd = atualizar_dados_da_disciplina( pdisci,  codigo_da_disciplina );
       printf ("Se o valor de retorno for igual a 1 portanto, ATUALIADO com SUCESSO. VEJA --->%d\n", pddd);

       break;

   case 6:


      pdddd = pilha_cheia_disciplina(pdisci);
      printf ("Se o valor de retorno for igual a ZERO (0) portanto, fila NÃO está cheia. VEJA --->%d\n", pddd);
 
      break;

   case 7:

       pddddd = pilha_vazia_disciplina(pdisci);
       printf ("Se o valor de retorno for igual a ZERO (0) portanto, fila NÃO está vazia. VEJA --->%d\n", pdddd);

       break;


   case 8:

       pAluno = cria_pilha_de_alunos();

       break;

   case 9:

        printf(" Digite o nome: ");
	     scanf(" %[^\n]", al.nome);

	    printf(" Digite o sexo : ");
		scanf(" %[^\n]", al.sexo);

	    if( strcmp(al.sexo, sexo1 ) != 0 && strcmp(al.sexo, sexo2) != 0 && strcmp(al.sexo, sexo3 ) != 0 && strcmp(al.sexo, sexo4 ) != 0 && strcmp(al.sexo, sexo5 ) != 0 && strcmp(al.sexo, sexo6 ) != 0 )
	    {
	       	teste = 1;

			while(teste == 1)
			{
		    printf("\nSexo Invalido.\n\n");
			printf(" Digite o sexo : ");
		    scanf(" %[^\n]", al.sexo);


		if( strcmp(al.sexo, sexo1 ) == 0 || strcmp(al.sexo, sexo2 ) == 0 || strcmp(al.sexo, sexo3 ) == 0 || strcmp(al.sexo, sexo4 ) == 0 || strcmp(al.sexo, sexo5 ) == 0 || strcmp(al.sexo, sexo6 ) == 0 )
        {
        	teste = 0;

		  }

	   }
   }
        teste = 0;

	    printf(" Digite o numero da matricula: ");
	    scanf("%d", &al.matricula);
		
		if(al.matricula < 1){
			
			valMatricula = 1;
			
			while(valMatricula == 1){
				
				printf(" Numero de matricula INVALIDO!\n ");
				printf(" Digite de novo o numero de matricula: ");
	            scanf(" %d", &al.matricula);
	            
	            if(al.matricula > 0){
	            	
	            	valMatricula = 0;
	            	
				}
			}
		}
		valMatricula = 0;
		
		printf(" Digite o nome da disciplina: ");
	    scanf(" %[^\n]", al.dis.nome_da_disciplina); //nome_da_disciplina

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &al.dia);

        printf(" Digite o mes do nascimento: ");
		scanf(" %d", &al.mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &al.ano);

		if( al.dia < 1 || al.dia > 31 || al.mes <= 0 || al.mes > 12 || al.ano <= 0 ){

			valida = 1;


		while(valida == 1)
		{

		printf(" DATA INVALIDA\n! ");

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &al.dia);

		printf(" Digite o mes do nascimento: ");
		scanf(" %d", &al.mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &al.ano);

		if( al.dia > 0 && al.dia <= 31 && al.mes > 0 && al.mes <= 12 && al.ano > 0 ){

			valida = 0;

		   }

		}
	 }
		valida = 0;


		printf(" Digite o CPF: ");
		scanf(" %llu", &al.cpf);
		
		if( al.cpf < 9999999999 || al.cpf > 99999999999 )
		{

		valida = 1;

		while( valida == 1 )
		{
			printf(" CPF invalido!!\n");
			printf(" Digite de novo o CPF: ");
			scanf(" %llu", &al.cpf);

			if( al.cpf >= 10000000000 && al.cpf <= 99999999999){
			   	valida = 0;

			   }
			}
		}

		valida = 0;
       

       pa = insere_aluno_na_pilha( pAluno, al );

       printf(" Se o valor de retorno for igual a 1 portanto, inserido com SUCESSO. VEJA --->%d\n", pa);

       break;

   case 10:

       imprimir_lista_de_alunos( pAluno);

       break;

    case 11:

       acessa_topo_da_pilha(pdisci);

       break;

   case 12:

       listar_disciplinas_e_alunos_matriculados( pdisci, pAluno);

       break;

   case 13:

        imprimir_alunos_de_sexo_masculino(pAluno);
        
        break;

   case 14:

        imprimir_alunos_de_sexo_feminino(pAluno);
       
       break;

   case 15:

        acessa_topo_da_pilha_aluno(pAluno);

       break;

   case 16:

       paa = excluir_aluno_na_lista(pAluno);
       printf ("Se o valor de retorno for igual a 1 portanto, removido com SUCESSO. VEJA --->%d\n", paa);

       break;

    case 17:

      printf(" Digite o mes para saber quem são aniversariantes deste: ");
      scanf(" %d", &mmes);

       listar_aniversariantes_de_um_dado_mes( pAluno, mmes);

       break;


    case 18:


       paaa = quantidade_dos_alunos( pAluno);
       printf("Quantidade dos alunos = %d\n", paaa);

       break;

   case 19:
     
       paaaa = pilha_vazia_de_alunos(pAluno);
       printf ("Se o valor de retorno for igual a ZERO (0) portanto, fila NÃO está vazia. VEJA --->%d\n", paaaa);

       break;

   case 20:

       paaaaa = pilha_cheia_de_alunos(pAluno);
       printf ("Se o valor de retorno for igual a ZERO (0) portanto, fila NÃO está cheia. VEJA --->%d\n", paaaaa);

       break;

   case 21:
       
       printf(" Digite o numero de matricula do aluno que quer atualizar: ");
       scanf(" %d", &mmatricula);
       paaaaaa = atualizar_lista_dos_alunos( pAluno, mmatricula );
       printf ("Se o valor de retorno for igual a 1 portanto, ATUALIADO com SUCESSO. VEJA --->%d\n", paaaaaa);

       break;

  case 22:
       
       PROF = cria_pilha_de_professor();

       break;

  case 23:
 
        printf(" Digite o nome: ");
	     scanf(" %[^\n]", ins.Nome);

	    printf(" Digite o sexo : ");
		scanf(" %[^\n]", ins.Sexo);

	    if( strcmp(ins.Sexo, sexo1 ) != 0 && strcmp(ins.Sexo, sexo2) != 0 && strcmp(ins.Sexo, sexo3 ) != 0 && strcmp(ins.Sexo, sexo4 ) != 0 && strcmp(ins.Sexo, sexo5 ) != 0 && strcmp(ins.Sexo, sexo6 ) != 0 )
	    {
	       	Teste = 1;

			while(Teste == 1)
			{
		    printf("\nSexo Invalido.\n\n");
			printf(" Digite o sexo : ");
		    scanf(" %[^\n]", ins.Sexo);


		if( strcmp( ins.Sexo, sexo1 ) == 0 || strcmp(ins.Sexo, sexo2 ) == 0 || strcmp(ins.Sexo, sexo3 ) == 0 || strcmp(ins.Sexo, sexo4 ) == 0 || strcmp(ins.Sexo, sexo5 ) == 0 || strcmp(ins.Sexo, sexo6 ) == 0 )
        {
        	Teste = 0;

		  }

	   }
   }
        Teste = 0;

	    printf(" Digite o numero da matricula: ");
	    scanf("%d", &ins.Matricula);
		
		if(ins.Matricula < 1){
			
			ValMatricula = 1;
			
			while(ValMatricula == 1){
				
				printf(" Numero de matricula INVALIDO!\n ");
				printf(" Digite de novo o numero de matricula: ");
	            scanf(" %d", &ins.Matricula);
	            
	            if(ins.Matricula > 0){
	            	
	            	ValMatricula = 0;
	            	
				}
			}
		}
		ValMatricula = 0;
		
		//printf(" Digite o nome da disciplina: ");
	    //scanf(" %[^\n]", al.dis.nome_da_disciplina); //nome_da_disciplina

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &ins.Dia);

        printf(" Digite o mes do nascimento: ");
		scanf(" %d", &ins.Mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &ins.Ano);

		if( ins.Dia < 1 || ins.Dia > 31 || ins.Mes <= 0 || ins.Mes > 12 || ins.Ano <= 0 ){

			Valida = 1;


		while(Valida == 1)
		{

		printf(" DATA INVALIDA\n! ");

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &ins.Dia);

		printf(" Digite o mes do nascimento: ");
		scanf(" %d", &ins.Mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &ins.Ano);

		if( ins.Dia > 0 && ins.Dia <= 31 && ins.Mes > 0 && ins.Mes <= 12 && ins.Ano > 0 ){

			Valida = 0;

		   }

		}
	 }
		Valida = 0;


		printf(" Digite o CPF: ");
		scanf(" %llu", &ins.CPF);
		
		if( ins.CPF < 9999999999 || ins.CPF > 99999999999 )
		{

		Valida = 1;

		while( Valida == 1 )
		{
			printf(" CPF invalido!!\n");
			printf(" Digite de novo o CPF: ");
			scanf(" %llu", &ins.CPF);

			if( ins.CPF >= 10000000000 && ins.CPF <= 99999999999){
			   	Valida = 0;

			   }
			}
		}

		Valida = 0;
       

      
       pb = insere_professor_na_pilha( PROF, ins );
       printf(" Se o valor de retorno for igual a 1 portanto, inserido com SUCESSO. VEJA --->%d\n", pb);

       break;


   case 24:

       imprimir_lista_de_professor( PROF);

       break;

  case 25:

       imprimir_professor_de_sexo_masculino(PROF);
      
       break;


  case 26:

       imprimir_professor_de_sexo_feminino(PROF);

       break;  

  case 27:

       acessa_topo_da_pilha_professor(PROF);
      
       break;  

   case 28:

       paaaaaaa = excluir_professor_na_lista(PROF);
       printf ("Se o valor de retorno for igual a 1 portanto, removido com SUCESSO. VEJA --->%d\n", paaaaaaa);

       break;

  case 29:

       printf(" Digite o mes para saber quem são aniversariantes deste: ");
       scanf(" %d", &mmmes);

       listar_aniversariantes_de_um_dado_mes_professor(PROF, mmmes);

       break;


  case 30:

       TR = quantidade_dos_professor(PROF);
       printf(" Quantidade  dos professores = %d\n", TR);
     

       break;

   case 31:

      TRT = pilha_vazia_de_professor(PROF);
      printf ("Se o valor de retorno for igual a ZERO (0) portanto, fila NÃO está vazia. VEJA --->%d\n", TRT);

      break;

   case 32:

      TRS = pilha_cheia_de_professor(PROF);
      printf ("Se o valor de retorno for igual a ZERO (0) portanto, fila NÃO está cheia. VEJA --->%d\n", TRS);

       break;


  case 33:

       printf(" Digite o numero de matricula do aluno que quer atualizar: ");
       scanf(" %d", &mmmatricula);

       TRF = atualizar_lista_dos_professor( PROF, mmmatricula );
       printf("Se o valor de retorno for igual a 1 portanto, ATUALIADO com SUCESSO. VEJA --->%d\n", TRF);
      
       break;
	   default :

       printf ("VALOR INVÁLIDO!\n");

      }

    }while( opcao != 34 );

   libera_pilha_disciplina(pdisci);
   libera_memoria_reservada_para_aluno(pAluno);
   libera_memoria_reservada_para_professor(PROF);

  return 0;

}



