
#define ATUALIZADO_COM_SUCESSO 1

struct disciplina{

	
	char Nome[100];
	char Codigo[10];
	int Semestre;
	char professor[100];
	
    struct disciplina *proximo;
    
};

struct aluno{
	
	
	char nome[100];
	int matricula;
	char sexo[3];
	int dia;
	int mes;
	int ano;
	unsigned long long int CPF;  
	struct disciplina DIS;
};


struct professor{

    int matricula;
    char nome[100];
    char sexo[3];
    int dia;
    int mes;
    int ano;
   unsigned long long int cpf;

};

struct guarda{

   struct professor DADOS;
   struct guarda *proximo;

};

struct elemento{
	
	struct aluno dados;
	struct elemento *prox;
	
};



typedef struct elemento *Lista;
typedef struct elemento Elem;

typedef struct guarda *RETORNO;
typedef struct guarda ESTRUTURA;



Lista *cria_lista();
int inserir_inicio(Lista *li, struct aluno al);
void imprmir_alunos_com_dados_completos(Lista *li);
void imprimir_alunos_de_sexo_masculino(Lista *li);
void imprimir_alunos_de_sexo_feminino(Lista *li);
void imprimir_alunos_em_ordem_alfabetica(Lista *li);
int Atualizar_lista_de_alunos(Lista *li, int matricula);
int Excluir_aluno_na_lista(Lista *li, int matricula);
void quantidade_dos_alunos(Lista *li);
void Alunos_aniversariantes_de_um_determinado_mes(Lista *li, int mess);
void libera_memoria_reservada_para_alunos(Lista *li);


struct disciplina *Cria_lista();
struct disciplina *insere_disciplina_na_lista( struct disciplina *ptr, char *nome, char *codigo, int semestre, char *professor);
void imprime(struct disciplina *t);
void imprime_alunos_numa_disciplina(struct disciplina *t, Lista *li, char *discipli);
int Atualizar_lista_de_disciplina( struct disciplina *t, char *codigo);
int Excluir_disciplina_na_lista(struct disciplina *t, char *cod);
void libera_memoria_reservada_para_disciplinas(struct disciplina *t);



RETORNO *CRIA_LISTA();
int INSERIR_PROFESSOR_NA_LISTA(RETORNO *ini, struct professor prof);
void IMPRIMIR_LISTA_DOS_PROFESSORES(RETORNO *ini);
void IMPRIMIR_LISTA_DE_PROFESSORES_DE_SEXO_MASCULINO(RETORNO *ini);
void IMPRIMIR_LISTA_DE_PROFESSORES_DE_SEXO_FEMININO(RETORNO *ini);
void PROFESSORES_ANIVERSARIANTES_DE_UM_DETERMINADO_MES(RETORNO *ini, int mes);
void LIBERA_MEMORIA_RESERVADA_PARA_PROFESSORES(RETORNO *ini);
void IMPRIMIR_POR_ORDEM_ALFABETICA(RETORNO *ini);
int EXCLUIR_PROFESSOR_NA_LISTA(RETORNO *ini, int matricula);
int ATUALIZAR_LISTA_DE_PROFESSORES(RETORNO *li, int matricula);
int QUANTIDADE_DE_PROFESSORES(RETORNO *ini);

