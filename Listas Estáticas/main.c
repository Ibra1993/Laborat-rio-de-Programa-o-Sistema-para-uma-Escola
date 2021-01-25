#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Escola.h"

int main(){


   
	printf("\n\n");

	ALUNO p;
	DIS ppt;
	PROF pro;

	int op = 0;
	int a, b, c, d, e, f, g, h, k, dfff;
	struct aluno al;
	struct disciplina eel;
	struct professor in;
	int t;
    int y;
    int valida = 0;
    int teste = 0;
    int tsexo = 0;
    int tdata = 0;
    long long int tcpf = 0;
    int ret;
    char letras[10];
    int mes;
    int validaMes = 0;
    int r;
    int valMatricula = 0;
    char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";
    char Nome_da_Disciplina[100];
    char DISCIPLINA[100];
    char NOME[100];
    char NomeAtualiza[100];
    char CODIGO[20];
    char nomedeprofessor[100];

    do{

    printf("\n ====================================================================\n\n");
    printf("\n =============== Menus =========== .\n");
    printf("\n\nATENCAO, ANTES DE CADASTRAR ALUNO NUMA DISCIPLINA, PRIMEIRO, A DISCIPLINA PRECISA SER CADASTRADA!!!\n\n");
    printf("\n        1-  Cria Lista dos alunos .                                                          *\n");
	printf("\n        2-  Insere aluno na Lista.                                                           *\n");
	printf("\n        3-  Obter quantidade dos alunos.                                                     *\n");
	printf("\n        4-  Ecluir aluno da disciplina.                                                      *\n");
	printf("\n        5-  Imprimir a Lista  de alunos                                                      *\n");
	printf("\n        6-  Imprimir alunos de sexo masculino                                                *\n");
	printf("\n        7-  Imprimir alunos de sexo feminino                                                 *\n");
    printf("\n        8-  Listar por ordem alfabetica dos alunos                                           *\n");
    printf("\n        9-  Listar alunos por ordem de nascimento                                            *\n");
    printf("\n        10- Listar alunos atraves de string de busca! NAO ACESSAR!!!!!!!                    *\n");
    printf("\n        11- Criar/reservar memoria para Lista de disciplinas                                *\n");
	printf("\n        12- Cadastrar disciplinas                                                           *\n");
	printf("\n        13- Listar dados da disciplinas sem alunos  				                          *\n");
    printf("\n        14- Listar uma disciplina (dados da disciplina e os alunos matriculados)  		  *\n");
    printf("\n        15- Criar Lista de professores                                                      *\n");
	printf("\n        16- Inserir professor na lista                                                      *\n");
	printf("\n        17- Listar professores                                                              *\n");
	printf("\n        18- Listar professores de sexo Masculino                                            *\n");
    printf("\n        19- Listar professores de sexo Feminino                                             *\n");
    printf("\n        20- Listar professores por ordem de nomes                                            *\n");
	printf("\n        21- Listar professores por ordem de nascimento                                      *\n");
    printf("\n        22- Professores aniversariantes de um determinado mes!                              *\n");
	printf("\n        23- Excluir Disciplina na lista                                                     *\n");
	printf("\n        24- Excluir professor(a) na Lista                                                   *\n");
	printf("\n        25- Atualizar dados dos(as) alunos(as)                                              *\n");
    printf("\n        26- Atualizar dados das disciplinas                                                 *\n");
	printf("\n        27- Atualizar dados dos professores                                                 *\n");
    printf("\n        28- Obter quantidade dos professores                                                *\n");	
    printf("\n        29- SAIR                                                                            *\n");
                                                                           
	printf("\n ====================================================================\n\n");

    printf("  Digite a opcao: ");
	scanf("%d", &op);

    switch( op )
	{
	case 1:

		a = Cria_lista(&p);
        printf(" Memoria reservado para Lista de alunos com sucesso = %d\n", a);
         break;

	case 2:

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
	            scanf("%d", &al.matricula);
	            
	            if(al.matricula > 0){
	            	
	            	valMatricula = 0;
	            	
				}
			}
		}
		valMatricula = 0;
		
		printf(" Digite o nome da disciplina: ");
	    scanf(" %[^\n]", al.dis.nome_da_disciplina); //nome_da_disciplina

		printf(" Digite o dia do nascimento: ");
		scanf("%d", &al.dia);

        printf(" Digite o mes do nascimento: ");
		scanf("%d", &al.mes);

		printf(" Digite o ano do nascimento: ");
		scanf("%d", &al.ano);

		if( al.dia < 1 || al.dia > 31 || al.mes <= 0 || al.mes > 12 || al.ano <= 0 ){

			valida = 1;


		while(valida == 1)
		{

		printf(" DATA INVALIDA\n! ");

		printf(" Digite o dia do nascimento: ");
		scanf("%d", &al.dia);

		printf(" Digite o mes do nascimento: ");
		scanf("%d", &al.mes);

		printf(" Digite o ano do nascimento: ");
		scanf("%d", &al.ano);

		if( al.dia > 0 && al.dia <= 31 && al.mes > 0 && al.mes <= 12 && al.ano > 0 ){

			valida = 0;

		   }

		}
	 }
		valida = 0;


		printf(" Digite o CPF: ");
		scanf(" %lld", &al.cpf);
		

		if( al.cpf < 9999999999 || al.cpf > 99999999999 )
		{

		valida = 1;

		while( valida == 1 )
		{
			printf(" CPF invalido!!\n");
			printf(" Digite o CPF: ");
			scanf(" %lld", &al.cpf);

			if( al.cpf >= 10000000000 && al.cpf <= 99999999999){
			   	valida = 0;

			   }
			}
		}

		valida = 0;

	    y = insere(&p, al);
		printf(" Inserido = %d\n", y);
		break;

	case 3:


		t = Tamanho_da_lista(&p);

		printf("\n==============================\n");
		printf("\n\n");

        printf(" Tamanho da lista = %d\n", t);

        printf("\n\n");
        printf("\n==============================\n");


         break;

    case 4:

    	printf("Digite o nome da disciplina que quer excluir o aluno: ");
	    scanf(" %[^\n]", Nome_da_Disciplina);
    	ret = Excluir_aluno_de_uma_disciplina(&p, Nome_da_Disciplina);
    	printf("Se o valor for diferente de 4 entao nao foi escluido! VEJA o valor = %d.\n", ret);
    	break;

    case 5:

	    imprimir(&p);
	    break;

    case 6:
    	Lista_de_sexo_masculino_alunos(&p);
    	break;

    case 7:

    	Lista_de_sexo_feminino_alunas(&p);
    	break;

    case 8:

    	Listar_por_ordem_alfabetica_os_alunos(&p);
    	break;

    case 9:

    	Listar_por_ordem_de_nascimento(&p);
    	break;

    case 10:

    Listar_alunos_string_de_busca(&p);

		break;

	case 11:

		b = Cria_lista_de_disciplinas(&ppt);
    	printf("Memoria reservado para disciplinas com sucesso = %d\n", b);
    	break;

    case 12:

    	printf(" Digite nome da disciplina: ");
    	scanf(" %[^\n]", eel.nome_da_disciplina);

    	printf(" Digite codigo da disciplina: ");
    	fflush(stdin);
    	scanf(" %[^\n]", eel.codigo);

    	printf(" Digite o semestre: ");
    	scanf(" %d", &eel.semestre);

    	printf(" Digite nome do(a) professor(a): ");
    	scanf(" %[^\n]", eel.professor);

    	//printf(" Digite nome do(a) aluno(a): ");
    	//fflush(stdin);
    	//scanf("%[^\n]", eel.nome_do_aluno);

    	 r = Cadastrar_disciplinas( &ppt, eel );
    	printf("Se valor for igual a 1 ENTAO, disciplina cadastrado com sucesso. Veja ---> %d", r);
		break;

	case 13:

		listar_dados_da_disciplinas_sem_alunos( &ppt);
		break;

	case 14:

		listar_disciplinas_e_alunos_matriculados( &ppt, &p);
		break;

	case 15:

		c = Cria_lista_de_profesores(&pro);
		printf("Memoria reservado para professores com sucesso  = %d\n", c);

		break;

	case 16:

		printf(" Digite o nome do(a) professor(a): ");
		scanf(" %[^\n]", in.Nome);

		printf(" Digite o numero de Matricula: ");
		scanf(" %d", &in.Matricula);

		printf(" Digite o sexo do(a) professor(a): ");
		scanf(" %[^\n]", in.Sexo);

		if( strcmp(in.Sexo, sexo1 ) != 0 && strcmp(in.Sexo, sexo2) != 0 && strcmp(in.Sexo, sexo3 ) != 0 && strcmp(in.Sexo, sexo4 ) != 0 && strcmp(in.Sexo, sexo5 ) != 0 && strcmp(in.Sexo, sexo6 ) != 0 )
	    {
	       	tsexo = 1;

			while(tsexo == 1)
			{
		    printf("\nSexo Invalido.\n\n");
			printf(" Digite o sexo : ");
		    scanf(" %[^\n]", in.Sexo);


		if( strcmp(in.Sexo, sexo1 ) == 0 || strcmp(in.Sexo, sexo2 ) == 0 || strcmp(in.Sexo, sexo3 ) == 0 || strcmp(in.Sexo, sexo4 ) == 0 || strcmp(in.Sexo, sexo5 ) == 0 || strcmp(in.Sexo, sexo6 ) == 0 )
        {
        	tsexo = 0;

		  }

	   }
   }
        tsexo = 0;

        printf(" Digite o dia do nascimento: ");
		scanf(" %d", &in.Dia);

        printf(" Digite o mes do nascimento: ");
		scanf(" %d", &in.Mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &in.Ano);

		if( in.Dia < 1 || in.Dia > 31 || in.Mes <= 0 || in.Mes > 12 || in.Ano <= 0 ){

			tdata = 1;


		while( tdata == 1)
		{

		printf(" DATA INVALIDA\n! ");

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &in.Dia);

		printf(" Digite o mes do nascimento: ");
		scanf(" %d", &in.Mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &in.Ano);

		if( in.Dia > 0 && in.Dia <= 31 && in.Mes > 0 && in.Mes <= 12 && in.Ano > 0 ){

			tdata = 0;

		   }

		}
	 }
		tdata = 0;

		printf(" Digite o CPF: ");
		scanf(" %lld", &in.CPF);
		
		if( in.CPF < 9999999999 || in.CPF > 99999999999 )
		{

		tcpf = 1;

		while( tcpf  == 1 )
		{
			printf(" CPF invalido!!\n");
			printf(" Digite o CPF: ");
			scanf(" %lld", &in.CPF);

			if( in.CPF >= 10000000000 && in.CPF <= 99999999999){
			   	tcpf = 0;

			   }
			}
		}

		tcpf = 0;
		d = Inserir_professor(&pro, in);
		printf (" Inserido com sucesso = %d\n", d);

		break;

	case 17:

		listar_professores(&pro);
		break;

	case 18:

		listar_professores_por_sexo_masculino(&pro);

		break;

	case 19:

		listar_professores_por_sexo_feminino(&pro);
		break;

	case 20:

		Ordenar_professores_por_nome(&pro);
		break;

	case 21:

		listar_professores_por_ordem_de_nascimento(&pro);
		break;

	case 22:
		printf(" Digite o mes para achar professores aniversariantes desse mes: ");
	    scanf(" %d", &mes);


	if( mes < 1 ||  mes > 12){

		validaMes = 1;

	while(validaMes == 1){

		printf(" MES INVALIDO!!!\\n");

		printf(" Digite o mes para achar professores aniversariantes desse mes: ");
	    scanf(" %d", &mes);

	if( mes >= 1 && mes <= 12){

		validaMes = 0;

	    }
	 }
  }
    validaMes = 0;

		aniversariantes_do_mes(&pro, mes);
	    break;

	case 23:

		printf(" Digite a disciplina que quer excluir: ");
		scanf(" %[^\n]", DISCIPLINA);

		e = Excluir_Disciplina_na_Lista( &ppt, DISCIPLINA);
		printf (" Se valor for diferente de 4 erro na exclusao! Veja ----> %d\n", e);

		break;

	case 24:

		printf("Digite o nome que quer excluir: ");
		scanf(" %[^\n]", NOME);
		f = Excluir_professor_na_lista(&pro, NOME);
		printf (" Se valor for diferente de 4 erro na exclusao! Veja ----> %d\n", f);

		break;

	case 25:

		printf(" Digite o nome do aluno a ser atualizado: ");
		scanf(" %[^\n]", NomeAtualiza);

	    g =  atualizar_dados_dos_alunos(&p, NomeAtualiza);
		printf(" Se o valor for diferente de 5, portanto, NAO FOI ATUALIZADO!!. Veja -----> %d\n", g);

		break;

	case 26:

		printf(" Digite o codigo da disciplina na qual quer atualizar: ");
		scanf(" %[^\n]", CODIGO);

		h = Atualizar_dados_da_disciplina( &ppt, CODIGO);
		printf("Se o valor for diferente de 5, portanto, NAO FOI ATUALIZADO!!. Veja -----> %d\n", h);

        break;

	case 27:

		printf(" Digite o nome de professor na qual voce quer atualizar: ");
		scanf(" %[^\n]", nomedeprofessor);

		k = Atualizar_lista_de_professores( &pro, nomedeprofessor);
		printf("Se o valor for diferente de 5, portanto, NAO FOI ATUALIZADO!!. Veja -----> %d\n", k);

		break;

	    case 28:
		
		dfff = quantidade_dos_professores(&pro);
	    printf(" Quantidade dos professores = %d\n", dfff);
	    
	    break;
	    default :
        printf ("Valor invalido!\n");
	}

	}while(op != 29);

    destroi_lista_alunos(&p);
    destroi_lista_disciplinas(&ppt);
    destroi_lista_professores(&pro);

    return 0;

}

