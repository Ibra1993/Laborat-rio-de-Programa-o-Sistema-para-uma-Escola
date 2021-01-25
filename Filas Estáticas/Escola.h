#define MAXalu 500
#define MAXdis 500
#define MAXPROF 500
#define FILA_NAO_ESTA_VAZIA 2
#define FILA_ESTA_VAZIA -2
#define FILA_CHEIA -3;
#define ATUALIZADO_COM_SUCESSO 1


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

	int matricula;
	char nome[100];
	char sexo[3];
	int dia;
	int mes;
	int ano;
	unsigned long long int cpf;


};


struct GuardaProfessor{

    int Inicio;
	int Fim;
	int qtdPROFESSOR;
   struct professor Dados[MAXPROF];

};


struct GuardaDisciplina{
	
	int inicio;
	int fim;
	int qtd;
	struct disciplina DADOS[MAXdis];
	
};

struct GuardaALUNO{
	
	int INICIO;
	int FIM;
	int qtdALUNO;
	struct aluno dados[MAXalu];
	
};


typedef struct GuardaDisciplina GUARDA;
typedef struct GuardaALUNO guarda;
typedef struct GuardaProfessor Guarda;


GUARDA *cria_fila_das_disciplinas();
void libera_fila_das_disciplinas(GUARDA *fil);
int consulta_fila_das_disciplinas(GUARDA *fil, struct disciplina *al);
int insere_disciplina_na_fila(GUARDA *fil, struct disciplina al);
int remove_disciplina_na_fila(GUARDA *fil);
int quantidade_das_disciplinas_na_fila(GUARDA *fil);
int fila_vazia(GUARDA *fil);
int fila_cheia(GUARDA *fil);
void libera_fila_das_disciplinas(GUARDA *fil);
void imprimir_lista_das_disciplinas(GUARDA *fil);
int atualizar_disciplina_na_lista(GUARDA *fil, char codigo[20]);
void listar_disciplinas_e_alunos_matriculados( GUARDA *fil, guarda *fill);




guarda *cria_fila_de_alunos();
int insere_aluno_na_fila( guarda *fil, struct aluno al );
void imprimir_lista_de_alunos(guarda *fil);
void libera_memoria_reservada_para_aluno(guarda *fil);
void listar_disciplinas_e_alunos_matriculados( GUARDA *fil, guarda *fill);
void imprimir_alunos_de_sexo_masculino(guarda *fil);
void imprimir_alunos_de_sexo_feminino(guarda *fil);
int excluir_aluno_na_lista(guarda *fil);
void listar_aniversariantes_de_um_dado_mes(guarda *fil, int mmes);
int atualizar_lista_dos_alunos( guarda *fil, int mmatricula );
int quantidade_dos_alunos(guarda *fil);
int fila_vazia_de_alunos(guarda *fil);
int fila_cheia_de_alunos(guarda *fil);


Guarda *cria_fila_de_professores();
int insere_professor_na_fila( Guarda *ptr, struct professor el );
void imprimir_lista_de_professores(Guarda *ptr);
void libera_memoria_reservada_para_professores(Guarda *ptr);
int quantidade_dos_professores(Guarda *ptr);
int excluir_professor_na_lista(Guarda *ptr);
void listar_aniversariantes_de_um_dado_mmes(Guarda *ptr, int mmmes);
void imprimir_professores_de_sexo_masculino(Guarda *ptr);
void imprimir_professores_de_sexo_feminino(Guarda *ptr);
int atualizar_lista_dos_professores(Guarda *ptr, int mmmatricula);
int fila_vazia_de_professores(Guarda *ptr);
int fila_cheia_de_professore(Guarda *ptr);





