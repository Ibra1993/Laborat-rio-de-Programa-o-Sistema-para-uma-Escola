#define MAX 500
#define MAXdis 500
#define MAXPROF 500

#define LISTA_CHEIA -1
#define INSERIDO_COM_SUCESSO 1
#define LISTA_VAZIA -2
#define DISCIPLINA_NAO_ESTA_NA_LISTA -3
#define EXCLUIDO_COM_SUCESSO 4
#define NAO_FOI_EXCLUIDO_COM_SUCESSO -4
#define ATUALIZADO_COM_SUCESSO 5
#define NAO_ATUALIZADO_COM_SUCESSO 6

struct disciplina{

	char nome_da_disciplina[100];
	char codigo[20];
	char professor[100];
	int semestre;


};

struct aluno{

	int matricula;
	char nome[100];
	char sexo[3];
	int dia;
	int mes;
	int ano;
	unsigned long long int cpf;

	struct disciplina dis;

};

struct professor{

	int Matricula;
	char Nome[100];
	char Sexo[3];
	int Dia;
	int Mes;
	int Ano;
	unsigned long long int CPF;

};

struct guardaprofessores{

	int qtdProf;
	struct professor VET[MAXPROF];

};

struct guarda{

	int qtd;
	struct aluno array[MAX];

};

struct guardaDisciplinas{

	struct disciplina vet[MAX];
	int qtdDisciplinas;

};

typedef struct guarda ALUNO;
typedef struct guardaDisciplinas DIS;
typedef struct guardaprofessores PROF;


	int Cria_lista(ALUNO *ptr);
	void imprimir(ALUNO *p);
	int insere(ALUNO *p, struct aluno al);
    int Tamanho_da_lista(ALUNO *p);
    int Excluir_aluno_de_uma_disciplina(ALUNO *p, char disci[]);
    void Lista_de_sexo_masculino_alunos(ALUNO *p);
    void Lista_de_sexo_feminino_alunas(ALUNO *p);
    void Listar_por_ordem_alfabetica_os_alunos(ALUNO *p);
    void Listar_por_ordem_de_nascimento(ALUNO *p);
    void Listar_alunos_string_de_busca(ALUNO *p);
    int compara_nomesAlunos(const void *paa, const void *pbb);
    int atualizar_dados_dos_alunos(ALUNO *ptr, char Nome[100]);

    int Cria_lista_de_disciplinas(DIS *pt);
    int Cadastrar_disciplinas(DIS *pt, struct disciplina el);
    void listar_dados_da_disciplinas_sem_alunos(DIS *pt);
    void listar_disciplinas_e_alunos_matriculados( DIS *pt, ALUNO *p);
    int Excluir_Disciplina_na_Lista(DIS *pt, char DISCIPLINA[]);
    int Atualizar_dados_da_disciplina(DIS *pt, char CODIGO[20]);

    


    int Cria_lista_de_profesores(PROF *prof);
    int Inserir_professor(PROF *prof, struct professor ins);
    void listar_professores(PROF *prof);
    void listar_professores_por_sexo_masculino(PROF *prof);
    void listar_professores_por_sexo_feminino(PROF *prof);
    void Ordenar_professores_por_nome(PROF *prof);
    void listar_professores_por_ordem_de_nascimento(PROF *prof);
    int compara_nomes(const void *pa, const void *pb);
    void aniversariantes_do_mes(PROF *prof, int mes);
    int Excluir_professor_na_lista(PROF *prof, char NOME[]);
    int Atualizar_lista_de_professores(PROF *prof, char nome[100]);
    int quantidade_dos_professores(PROF *prof);


   void destroi_lista_alunos(ALUNO *ptr);
   void destroi_lista_disciplinas(DIS *pt);
   void destroi_lista_professores(PROF *prof);
   
