#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Escola.h"


int main(){

   printf("\n\n");

   GUARDA *ptr;
   guarda *paluno;
   Guarda *ponteiro;

   struct disciplina dd;
   struct aluno al;
   struct professor el; 


   
   int opcao;
   int a, b, c, d, e, f, aa, bb, mmes, cc, mmatricula, cd, ka, kb;
   char cod[20];


    int valMatricula = 0;
    char sexo1[3] = "M";
    char sexo2[3] = "m";
    char sexo3[3] = "F";
    char sexo4[3] = "f";
    char sexo5[3] = "O";
    char sexo6[3] = "o";
    int valida = 0;
    int teste = 0;
    int tdata = 0;

    int validaa = 0;
    int testee = 0;
    int valMatriculaa = 0;
    int fe, fee, feee, feeee, mmmes, mmmatricula;
    int ss, sss;

   do{
     
    printf("\n ====================================================================\n\n");
    printf("\n =============== Menus =========== .\n");
    printf("\n\n OBS: ANTES DE CADASTRAR ALUNO NUMA DISCIPLINA, PRIMEIRO, A DISCIPLINA PRECISA SER CADASTRADA!!!\n\n");
    printf("\n 1- Reservar memória para fila das disciplinas .\n");
    printf("\n 2- Inserir disciplina na fila .                  \n");
    printf("\n 3- Remover disciplina na fila.                    \n");
    printf("\n 4- Obter quantidade das disciplinas na fila .      \n");
    printf("\n 5- Consultar se a fila das disciplinas está CHEIA ou NÃO\n");
    printf("\n 6- Consultar se a fila das disciplinas está VAZIA ou NÃO\n");
    printf("\n 7- Listar disciplinas .                               \n");
    printf("\n 8- Atualizar lista de disciplinas                      \n");
    printf("\n 9- Reservar memoria para alunos.                        \n");
    printf("\n 10- Inserir aluno na fila.                               \n");
    printf("\n 11- Listar alunos                                         \n");
    printf("\n 12- Listar disciplina e os alunos matriculados nessa disciplina.\n");
    printf("\n 13- Listar alunos de sexo masculino.                       \n");
    printf("\n 14- Listar alunos de sexo feminino                          \n");
    printf("\n 15- Listar aniversariantes de um dado mes.                   \n");
    printf("\n 16- Excluir aluno na lista.                                   \n"); 
    printf("\n 17- Aualizar lista dos alunos.                                 \n");
    printf("\n 18 Obter quantidade dos alunos na fila .                        \n");
    printf("\n 19- Reservar memoria para fila de profesores.                    \n");
    printf("\n 20- Inserir professor na fila .                                   \n");
    printf("\n 21- Listar professores.                                            \n");
    printf("\n 22- Obter quantidade dos professores na fila.                       \n");
    printf("\n 23- Excluir professor na fila .                                      \n");
    printf("\n 24- Listar professor(s) aniversariante(s) de um dado mês.             \n");
    printf("\n 25- Listar professor(s) de sexo masculino                              \n");
    printf("\n 26- Listar professoras (sexo feminino)                                  \n");
    printf("\n 27- Atualizar lista dos professores.                                      \n");
    printf("\n 28- Verificar se a fila dos alunos está VAZIA ou NÃO                      \n");
    printf("\n 29- Verificar se a fila dos alunos está CHEIA ou NÃO                       \n");
    printf("\n 30- Verificar se a fila dos professores está VAZIA ou NÃO                    \n");
    printf("\n 31- Verificar se a fila dos professores está CHEIA ou NÃO                     \n");
    printf("\n 32- SAIR.                                                                \n");
    printf("\n ====================================================================\n\n");

    printf("  Digite a opcao: ");
	scanf("%d", &opcao);

    printf("\n\n");

    switch( opcao )
    {

    case 1:
         
         ptr = cria_fila_das_disciplinas();
         break;

    case 2:
    
        printf(" Digite nome da disciplina: ");
    	scanf(" %[^\n]", dd.nome_da_disciplina);

    	printf(" Digite codigo da disciplina: ");
    	scanf(" %[^\n]", dd.codigo);

    	printf(" Digite o semestre: ");
    	scanf(" %d", &dd.semestre);

    	printf(" Digite nome do(a) professor(a): ");
    	scanf(" %[^\n]", dd.professor);
     
        a = insere_disciplina_na_fila( ptr, dd);
        printf(" Se o valor de retorno for diferente de 1 portanto, INSUCESSO na inserção na Fila. VEJA ---->%d\n ", a);
        
        break;
     
     case 3:


        b = remove_disciplina_na_fila(ptr);
        printf(" Se o valor de retorno for diferente de 1 portanto, INSUCESSO na remoçao na Fila. VEJA ---->%d\n ", b);
        
        break;
   
     case 4:

        c = quantidade_das_disciplinas_na_fila(ptr);
        printf(" Quantidade das disciplinas cadastradas = %d\n ", c);

        break;
 
    case 5:

        d = fila_vazia(ptr);
        printf(" Se o valor de retorno for igual 2 portanto, fila nao está vazio. VEJA ----->%d\n ", d);

        break;

     case 6:

        e = fila_cheia(ptr);
        printf(" Se o valor de retorno for igual 1 portanto, fila NAO está cheia. VEJA ----->%d\n ", e);
        break;
    
     case 7:


        imprimir_lista_das_disciplinas(ptr);
        break;

     case 8:

        printf("Digite o codigo da disciplina que vc quer atualizar na lista: ");
        scanf(" %[^\n]", cod);

        f = atualizar_disciplina_na_lista(ptr, cod);
        printf(" Se o valor de retorno for igual 1 portanto, ATUALIZADO com sucesso. VEJA ----->%d\n ", f);

        break;

     case 9:

        paluno = cria_fila_de_alunos();
        break;

     case 10:


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
       

        aa = insere_aluno_na_fila( paluno, al );
        printf (" Se o valor de retorno for igual a 1 portanto, SUCESSO na insercao. VEJA ---->%d\n", aa);

        break;

     case 11:

        imprimir_lista_de_alunos(paluno);

        break;
      
     case 12:

        
        listar_disciplinas_e_alunos_matriculados( ptr, paluno);
        break;

     case 13:
       
         imprimir_alunos_de_sexo_masculino(paluno);

        break;

     case 14:
        

        imprimir_alunos_de_sexo_feminino(paluno);

        break;
  
    case 15:
       
        printf("Digite o mes na qual quer saber aniversariantes deste: ");
        scanf("%d", &mmes);

        listar_aniversariantes_de_um_dado_mes(paluno, mmes);

        break;
    case 16:
       
        bb = excluir_aluno_na_lista(paluno);
        printf("Se o valor de retorno for igual a 1 portanto, SUCESSO na exclusao. VEJA-----> %d\n", bb);
        
        break;

    case 17:
        
        printf("Digite o numero de matricula do aluno a ser atualizado: ");
        scanf("%d", &mmatricula);

        cc = atualizar_lista_dos_alunos( paluno, mmatricula );
        printf("Se o valor de retorno for igual a 1 portanto, SUCESSO na atualizacao. VEJA-----> %d\n", cc);

        break;

     case 18:
  
         cd = quantidade_dos_alunos(paluno);
         printf(" Quantidade dos alunos-----> %d\n", cd);

        break;

    case 19:

        ponteiro = cria_fila_de_professores();

        break;

    case 20:


        printf(" Digite o nome: ");
	     scanf(" %[^\n]", el.nome);

	    printf(" Digite o sexo : ");
		scanf(" %[^\n]", el.sexo);

	    if( strcmp(el.sexo, sexo1 ) != 0 && strcmp(el.sexo, sexo2) != 0 && strcmp(el.sexo, sexo3 ) != 0 && strcmp(el.sexo, sexo4 ) != 0 && strcmp(el.sexo, sexo5 ) != 0 && strcmp(el.sexo, sexo6 ) != 0 )
	    {
	       	testee = 1;

			while(testee == 1)
			{
		    printf("\nSexo Invalido.\n\n");
			printf(" Digite o sexo : ");
		    scanf(" %[^\n]", el.sexo);


		if( strcmp(el.sexo, sexo1 ) == 0 || strcmp(el.sexo, sexo2 ) == 0 || strcmp(el.sexo, sexo3 ) == 0 || strcmp(el.sexo, sexo4 ) == 0 || strcmp(el.sexo, sexo5 ) == 0 || strcmp(el.sexo, sexo6 ) == 0 )
        {
        	testee = 0;

		  }

	   }
   }
        testee = 0;

	    printf(" Digite o numero da matricula: ");
	    scanf(" %d", &el.matricula);
		
		if(el.matricula <= 0){
			
			valMatriculaa = 1;
			
			while(valMatriculaa == 1){
				
				printf(" Numero de matricula INVALIDO!\n ");
				printf(" Digite de novo o numero de matricula: ");
	            scanf(" %d", &el.matricula);
	            
	            if(el.matricula > 0){
	            	
	            	valMatriculaa = 0;
	            	
				}
			}
		}
		valMatriculaa = 0;
		
		

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &el.dia);

        printf(" Digite o mes do nascimento: ");
		scanf(" %d", &el.mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &el.ano);

		if( el.dia < 1 || el.dia > 31 || el.mes <= 0 || el.mes > 12 || el.ano <= 0 ){

			validaa = 1;


		while(validaa == 1)
		{

		printf(" DATA INVALIDA\n! ");

		printf(" Digite o dia do nascimento: ");
		scanf(" %d", &el.dia);

		printf(" Digite o mes do nascimento: ");
		scanf(" %d", &el.mes);

		printf(" Digite o ano do nascimento: ");
		scanf(" %d", &el.ano);

		if( el.dia > 0 && el.dia <= 31 && el.mes > 0 && el.mes <= 12 && el.ano > 0 ){

			validaa = 0;

		   }

		}
	 }
		validaa = 0;


		printf(" Digite o CPF: ");
		scanf(" %llu", &el.cpf);
		
		if( el.cpf < 9999999999 || el.cpf > 99999999999 )
		{

		validaa = 1;

		while( validaa == 1 )
		{
			printf(" CPF invalido!!\n");
			printf(" Digite de novo o CPF: ");
			scanf(" %llu", &el.cpf);

			if( el.cpf >= 10000000000 && el.cpf <= 99999999999){
			   	validaa = 0;

			   }
			}
		}

		validaa = 0;
       

        fe = insere_professor_na_fila( ponteiro, el );
        printf("Se o valor de retorno for igual a 1 portanto, SUCESSO na inserção. VEJA-----> %d\n", fe);
        
        break;

  case 21:

        imprimir_lista_de_professores(ponteiro);

        break;

  case 22:

     fee = quantidade_dos_professores(ponteiro);
     printf ("Quantidade dos professor = %d\n", fee);

     break;

 case 23:

     feee = excluir_professor_na_lista(ponteiro);
     printf ("Se o valor de retorno for igual a 1 portanto, SUCESSO na exclusão. VEJA ----> %d\n", feee); 

     break;

 case 24:

     printf("Digite o mes na qual quer ver os aniversariantes deste: ");
     scanf("%d", &mmmes);

     listar_aniversariantes_de_um_dado_mmes(ponteiro, mmmes);

     break;

 case 25:

     imprimir_professores_de_sexo_masculino(ponteiro);

     break;


 case 26:

     imprimir_professores_de_sexo_feminino(ponteiro);
    
     break;

  case 27:

     
     printf(" Digite o numero de matricula do(a) professor(a) que quer atualizar: ");
     scanf("%d", &mmmatricula);

     feeee = atualizar_lista_dos_professores( ponteiro, mmmatricula);
     printf(" Se o valor de retorno for igual a 1 portanto, SUCESSO na atualizacao. VEJA ----> %d\n", feeee);

     break;

  case 28:

     ss = fila_vazia_de_alunos(paluno);
     printf ("Se o valor de retorno for igual a 2 portanto, a fila nao está vazio. VEJA ----->%d\n", ss);

     break;

  case 29:

     sss = fila_cheia_de_alunos(paluno);
     printf ("Se o valor de retorno for igual a 1 portanto, a fila nao está cheia. VEJA ----->%d\n", sss);
    
     break;

  case 30:

     ka = fila_vazia_de_professores(ponteiro);
     printf ("Se o valor de retorno for igual a 2 portanto, a fila não está cheia. VEJA ----->%d\n", ka);

     break;


  case 31:
     
     kb = fila_cheia_de_professore(ponteiro);
     printf ("Se o valor de retorno for igual a 1 portanto, a fila não está cheia. VEJA ----->%d\n", kb);

     break;
     default :
     printf ("VALOR INVÁLIDO!\n");
     
     }

  }while(opcao != 32);

     libera_fila_das_disciplinas(ptr);
     libera_memoria_reservada_para_aluno(paluno);
     libera_memoria_reservada_para_professores(ponteiro);

     return 0;

}


