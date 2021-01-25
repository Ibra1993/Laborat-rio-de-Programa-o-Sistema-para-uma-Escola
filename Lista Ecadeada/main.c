#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Escola.h"

int main(){
	
	system("Color a");
	
	Lista *li;
	RETORNO *inicio;
	
	struct aluno g;
	struct disciplina ins;
	struct professor prof;

	int a, b, c, dc;
	int opcao;
	
	
	int dia = 0;
    int mes = 0;
    int ano = 0;
	int teste = 0;  //foi
    int tsexo = 0;
    int tdata = 0;
    int tcpf = 0;
	int matri = 0; // foi
	int cpf = 0;
	
	
	char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";
    
    int Busca_matricula;
    int matricula_do_aluno_a_excluir;
    int validaExcluir = 0;
	int valida_Busca_matricula = 0;
	
	
	char nome[100];
	char Codigo[10];
	int Semestre;
	char professor[100];
	char discipli[100];
	int atua; char codigo[10];
	char CODIGO[10]; 
	int exclui;
	int mess;
	struct disciplina *p;
	int val = 0;
	

    
    int MATRI = 0;
    int TESTE = 0;
    int DIA = 0;
    int MES = 0;
    int ANO = 0;
    int CPF = 0;
    int messs;
    int mat, matt;
   int de, df, dff,  dfff;
	
	do{
		
		printf("\n ====================================================================\n\n");
        printf("\n =============== Menus =========== .\n");
		printf("\n =============== Aconselho-te a cadastrar, primeiro, as disciplinas! =========== .\n");

		printf("\n         1- Cria/reservar memoria para Lista de alunos .                          \n");
        printf("\n         2- Inserir aluno na lista .                                                \n");
		printf("\n         3- Listar alunos com os dados completos                                    \n");
		printf("\n         4- Listar alunos de sexo masculino                                         \n");
		printf("\n         5- Listar alunos de sexo feminino                                          \n");
		printf("\n         6- Listar alunos em ordem alfabetica                                       \n");
		printf("\n         7- Atualizar lista de alunos                                               \n");
		printf("\n         8- Exluir aluno na lista                                                   \n");
		printf("\n         9- Obter quantidade dos alunos na escola                                   \n");
		printf("\n         10- Criar lista de disciplinas                                             \n");
		printf("\n         11- Inserir disciplina na lista                                            \n");
		printf("\n         12- Imprimir lista de disciplinas                                          \n");
		printf("\n         13- Listar disciplina e os alunos matriculados                             \n");
		printf("\n         14- Atualizar dados da disciplina                                          \n");
		printf("\n         15- Excluir disciplina na lista                                            \n");	
		printf("\n         16- Listar alunos  aniversariantes de um dado mes                          \n");
		printf("\n         17- Cria/reservar memoria para Lista de professores                        \n");
		printf("\n         18- Insere professor na lista                                              \n");
		printf("\n         19- Listar Professores                                                     \n");
        printf("\n         20- Listar professores em ordem alfabetica                                 \n");
        printf("\n         21- Listar professores de sexo masculino                                   \n");
        printf("\n         22- Listar professoras (sexo feminino)                                     \n");
        printf("\n         23- Listar professores aniversariantes de um dado mes                      \n");
        printf("\n         24- Excluir professor na lista                                             \n");
        printf("\n         25- Atualizar lista de professores                                         \n"); 
        printf("\n         26- Obter quantidade dos professores na escola                             \n");
        printf("\n         27- Sair                                                                    \n");

		printf("\n ====================================================================\n\n");

		printf("  Digite a opcao: ");
	    scanf("%d", &opcao);
		
	switch(opcao)
	{
		
	case 1:
	
		li = cria_lista();
		//printf(" Se valor for diferente de ZERO  portanto, erro na criacao da lisa. VEJA ---->%d", li);
		break;
	
	case 2:
		
		printf(" Digite o nome do aluno: ");
	    scanf(" %[^\n]", g.nome);
	    
	    printf(" Digite matricula do aluno: ");
	    scanf(" %d", &g.matricula);
	    
	    if(g.matricula < 1)
		{
	    	
	    	matri = 1;
	    	
	    	while(matri == 1)
			{
				
			printf(" Matricula INVALIDA!\n");
			printf(" Digite matricula do aluno: ");
	        scanf(" %d", &g.matricula);
			
			if( g.matricula > 0 )
			{
				matri = 0;
			}
			
		 }
	    	
	}
		matri = 0;
		
	    printf(" Digite o sexo : ");
		scanf(" %[^\n]", g.sexo);
		
		 if( strcmp(g.sexo, sexo1 ) != 0 && strcmp(g.sexo, sexo2) != 0 && strcmp(g.sexo, sexo3 ) != 0 && strcmp(g.sexo, sexo4 ) != 0 && strcmp(g.sexo, sexo5 ) != 0 && strcmp(g.sexo, sexo6 ) != 0 )
	    {
	       	teste = 1;

			while(teste == 1)
			{
		    printf(" Sexo Invalido.\n\n");
			printf(" Digite o sexo : ");
		    scanf(" %[^\n]", g.sexo);


		if( strcmp(g.sexo, sexo1 ) == 0 || strcmp(g.sexo, sexo2 ) == 0 || strcmp(g.sexo, sexo3 ) == 0 || strcmp(g.sexo, sexo4 ) == 0 || strcmp(g.sexo, sexo5 ) == 0 || strcmp(g.sexo, sexo6 ) == 0 )
        {
        	teste = 0;

		  }

	   }
   }
        teste = 0;
        
        printf(" Digite o dia do nascimento: ");
		scanf("%d", &g.dia);
		
		if(g.dia < 1 || g.dia > 31)
		{
			dia = 1;
			
			while(g.dia == 1)
			{
				printf(" Dia INVALIDA!\n");
				printf(" Digite o novo dia do nascimento: ");
		        scanf(" %d", &g.dia);
		        
		        if(g.dia >= 1 && g.dia <= 31)
		        {
		        	dia = 0;
				}
			}
		}
		dia = 0;
		
		printf(" Digite o mes de nascimeto: ");
		scanf(" %d", &g.mes);

		if( g.mes <= 0 || g.mes > 12 ){

			mes = 1;

			while( mes == 1 ){

				printf(" Mes de nascimento INVALIDO!!\n");
				printf(" Digite o novo mes de nascimeto: ");
		        scanf(" %d", &g.mes);

		        if( g.mes >=1 && g.mes <= 12 ){

		        	mes = 0;
				}
			}
		}

		mes = 0;

		printf(" Digite ano de nascimeto: ");
		scanf(" %d", &g.ano);

		    if( g.ano <= 0){

		    	ano = 1;

		    	while (g.ano == 1 ){

		    	printf(" Novo ano de nascimeto INVALIDO\n");
		    	printf(" Digite o novo ano de nascimeto: ");
		    	scanf(" %d", &g.ano);

		    	if( ano > 0){

		    		ano = 0;

				   }
				}
			}

		ano = 0;
		
		
		printf(" Digite o CPF: ");
		scanf(" %llu", &g.CPF);

		if( g.CPF <= 9999999999 || g.CPF > 99999999999 ){

			cpf = 1;

			while( cpf == 1 ){

				printf(" CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &g.CPF);

		if( g.CPF >= 10000000000 && g.CPF <= 99999999999 ){

			cpf = 0;

		   }
	   }

	}
	cpf = 0;
	
	printf(" Digite a disciplina: ");
	scanf(" %[^\n]", g.DIS.Nome);
	
		a = inserir_inicio(li, g);
		printf("Aluno Inserido com suceso se o valor for igual a 1. VEJA ---->%d\n", a);
		
		break;
		
	case 3:
		
		imprmir_alunos_com_dados_completos(li);
		
		break;
		
	case 4: 
	    
	    imprimir_alunos_de_sexo_masculino(li);
	    
	    break;
	    
	case 5:
		
		imprimir_alunos_de_sexo_feminino(li);
		
		break;
	
	case 6:
		
		imprimir_alunos_em_ordem_alfabetica(li);
		break;
	
	case 7:
		
		printf(" Digite o numero de matricula do aluno a ser procurado na lista: ");
		scanf(" %d", &Busca_matricula);
		
		if(Busca_matricula < 1)
		{
			valida_Busca_matricula = 1;
			
			while(valida_Busca_matricula == 1)
			{
				
				printf(" Numero de matricula INVALIDO!\n");
				printf(" Digite o numero de matricula do aluno a ser procurado na lista: ");
				scanf(" %d", &Busca_matricula);
				
				if(Busca_matricula > 0)
				{
				   valida_Busca_matricula = 0;
				   	
				}
				
			}
		}
		valida_Busca_matricula = 0;
		
		b = Atualizar_lista_de_alunos(li, Busca_matricula);
		printf(" Se o valor de retorno for diferente de 1 portanto, INSUCESSO na atualizacao. VEJA ----> %d\n", b);
		
		break;
		
	case 8:
		
		printf(" Digite o numero de matricula do aluno a ser excluido: ");
		scanf(" %d", &matricula_do_aluno_a_excluir);
		
		if(matricula_do_aluno_a_excluir < 1)
		{
			validaExcluir = 1;
			
			while( validaExcluir == 1 )
			{
				printf("O numero de matricula INVALIDO!\n");
				printf(" Digite de novo o numero de matricula do aluno a ser excluido: ");
		        scanf(" %d", &matricula_do_aluno_a_excluir);
		        
		        if(matricula_do_aluno_a_excluir > 0 )
		        {
		        	validaExcluir = 0;
				}
				
			}
		}
		validaExcluir = 0;
		
		c = Excluir_aluno_na_lista(li, matricula_do_aluno_a_excluir);
		printf(" Se o valor de retorno for diferente de 1 portanto, INSUCESSO na exclusao. VEJA ----> %d\n", c);
       
	    break;
        
    case 9:
    	
    	quantidade_dos_alunos(li);
        break;
        
		case 10:  
    
        	p = Cria_lista();
		   // printf(" Memoria criada com sucesso = %d ", *p);
		break;
		
	case 11:
		
		printf(" Digite o nome da disciplina: ");
		scanf(" %[^\n]", nome);
		
		printf(" Digite o nome do professor: ");
		scanf(" %[^\n]", professor);
		
		printf(" Digite o codigo da disciplina: ");
		scanf(" %[^\n]", Codigo);
		
		printf(" Digite o semestre: ");
		scanf(" %d", &Semestre);
		
		if( Semestre < 1 )
		{
			val = 1;
			
			while(val == 1 )
			{
				printf(" Semestre INVALIDO!!\n");
				printf(" Digite de novo o semestre: ");
		        scanf(" %d", &Semestre);
		        
		        if(Semestre > 0)
		        {
		        	val = 0;
				}
			}
			
		}
		
		val = 0;
		
		p = insere_disciplina_na_lista( p, nome, Codigo, Semestre, professor );
		
		break;
		
	case 12:
		
		imprime(p); 
	
	    break;
	
	case 13:
		
		printf("Digite o nome da disciplina na qual deseja ver os nomes dos alunos(as) matriculados: ");
		scanf(" %[^\n]", discipli);
		
		imprime_alunos_numa_disciplina( p, li, discipli );
	
		break;
		
	case 14:
		
	    printf("Digite o codigo da disciplina a ser atualizado: ");
		scanf(" %[^\n]", codigo);
		
	    atua = Atualizar_lista_de_disciplina( p, codigo);
	    printf(" Se o valor for diferente de 1 portanto, INSUCESSO na atualizacao. VEJA ----->%d.\n", atua);
	    
	    break;
	
	case 15:
		
		printf(" Digite o codigo da disciplina que deseja exluir: ");
		scanf(" %[^\n]", CODIGO);
	
		
		exclui = Excluir_disciplina_na_lista( p, CODIGO);
		printf(" Se o valor for diferente de 1 portanto, INSUCESSO na exclusao. VEJA ----->%d.\n", exclui);
		break;
		
    case 16:
    	
    	printf(" Digite o mes na qual quer saber a lista de aniversariantes: ");
    	scanf(" %d", &mess);
    	Alunos_aniversariantes_de_um_determinado_mes(li, mess);
	    break;
	
	case 17:

		inicio = CRIA_LISTA();
        
		
	    break;
	    
	case 18:
		

        printf(" Digite o nome do aluno: ");
	    scanf(" %[^\n]", prof.nome);
	    
	    printf(" Digite matricula do aluno: ");
	    scanf(" %d", &prof.matricula);
	    
	    if(prof.matricula < 1)
		{
	    	
	    	MATRI = 1;
	    	
	    	while(MATRI == 1)
			{
				
			printf(" Matricula INVALIDA!\n");
			printf(" Digite matricula do aluno: ");
	        scanf(" %d", &prof.matricula);
			
			if( prof.matricula > 0 )
			{
				MATRI = 0;
			}
			
		 }
	    	
	}
		MATRI = 0;
		
	    printf(" Digite o sexo : ");
		scanf(" %[^\n]", prof.sexo);
		
		 if( strcmp(prof.sexo, sexo1 ) != 0 && strcmp(prof.sexo, sexo2) != 0 && strcmp(prof.sexo, sexo3 ) != 0 && strcmp(prof.sexo, sexo4 ) != 0 && strcmp(prof.sexo, sexo5 ) != 0 && strcmp(prof.sexo, sexo6 ) != 0 )
	    {
	       	TESTE = 1;

			while(TESTE == 1)
			{
		    printf(" Sexo Invalido.\n\n");
			printf(" Digite o sexo : ");
		    scanf(" %[^\n]", prof.sexo);


		if( strcmp(prof.sexo, sexo1 ) == 0 || strcmp(prof.sexo, sexo2 ) == 0 || strcmp(prof.sexo, sexo3 ) == 0 || strcmp(prof.sexo, sexo4 ) == 0 || strcmp(prof.sexo, sexo5 ) == 0 || strcmp(prof.sexo, sexo6 ) == 0 )
        {
        	TESTE = 0;

		  }

	   }
   }
        TESTE = 0;
        
        printf(" Digite o dia do nascimento: ");
		scanf("%d", &prof.dia);
		
		if(prof.dia < 1 || prof.dia > 31)
		{
			DIA = 1;
			
			while(DIA == 1)
			{
				printf(" Dia INVALIDA!\n");
				printf(" Digite o novo dia do nascimento: ");
		        scanf(" %d", &prof.dia);
		        
		        if(prof.dia >= 1 && prof.dia <= 31)
		        {
		        	DIA = 0;
				}
			}
		}
		DIA = 0;
		
		printf(" Digite o mes de nascimeto: ");
		scanf(" %d", &prof.mes);

		if( prof.mes <= 0 || prof.mes > 12 ){

			MES = 1;

			while( MES == 1 ){

				printf(" Mes de nascimento INVALIDO!!\n");
				printf(" Digite o novo mes de nascimeto: ");
		        scanf(" %d", &prof.mes);

		        if( prof.mes >=1 && prof.mes <= 12 ){

		        	MES = 0;
				}
			}
		}

		MES = 0;

		printf(" Digite ano de nascimeto: ");
		scanf(" %d", &prof.ano);

		    if( prof.ano <= 0 ){

		    	ANO = 1;

		    	while ( ANO == 1 ){

		    	printf(" Novo ano de nascimeto INVALIDO\n");
		    	printf(" Digite o novo ano de nascimeto: ");
		    	scanf(" %d", &prof.ano);

		    	if( prof.ano > 0){

		    		ANO = 0;

				   }
				}
			}

		ANO = 0;
		
		
		printf(" Digite o CPF: ");
		scanf(" %llu", &prof.cpf);

		if( prof.cpf <= 9999999999 || prof.cpf > 99999999999 ){

			CPF = 1;

			while( CPF == 1 ){

				printf(" CPF INVALIDO!!\n");
				printf(" Digite o novo CPF: ");
		        scanf(" %llu", &prof.cpf);

		if( prof.cpf >= 10000000000 && prof.cpf <= 99999999999 ){

			CPF = 0;

		   }
	   }

	}

	CPF = 0;   
 
		de = INSERIR_PROFESSOR_NA_LISTA( inicio, prof);
        printf(" Se o valor for diferente de 1 portanto, INSUCESSO na insercao. VEJA-----> %d.\n", de);

	    break;

    case 19:
        
        IMPRIMIR_LISTA_DOS_PROFESSORES(inicio);

        break;

    case 20:

         IMPRIMIR_POR_ORDEM_ALFABETICA(inicio);

         break;
   
   case 21:

         IMPRIMIR_LISTA_DE_PROFESSORES_DE_SEXO_MASCULINO(inicio);
    
        break;

    case 22:

        IMPRIMIR_LISTA_DE_PROFESSORES_DE_SEXO_FEMININO(inicio);
       
        break;
    
     case 23:

        printf(" Digite o mes na qual quer saber a lista dos aniversariantes: ");
    	scanf(" %d", &messs);
        PROFESSORES_ANIVERSARIANTES_DE_UM_DETERMINADO_MES(inicio, messs);
    
        break;

     case 24:

        printf(" Digite o numero de matricula do(a) professor(a) que quer EXCLUIR na lista: ");
    	scanf(" %d", &mat);
        dff = EXCLUIR_PROFESSOR_NA_LISTA(inicio, mat);
        printf(" Se o valor de retorno for diferente de 1 portanto, INSUCESSO  na exclusao. VEJA ----->%d\n", dff);

        break;

    case 25:
        
        printf(" Digite o numero de matricula do(a) professor(a) que quer ATUALIZAR na lista: ");
    	scanf(" %d", &matt);
        dff = ATUALIZAR_LISTA_DE_PROFESSORES(inicio, matt);
        printf(" Se o valor de retorno for diferente de 1 portanto, INSUCESSO  na atualizacao. VEJA ----->%d\n", dff);

        break;

    case 26:

        dfff = QUANTIDADE_DE_PROFESSORES(inicio);
        printf(" QUntidade dos professores = %d\n", dfff);
        break;
		default:
		printf(" opcao INVALIDO!\n");
		
   }
   
   }while(opcao != 27);
   
    libera_memoria_reservada_para_alunos(li);
    libera_memoria_reservada_para_disciplinas(p);
    LIBERA_MEMORIA_RESERVADA_PARA_PROFESSORES(inicio);

	return 0;
	
}
