
#define MAXdis 500
#define MAXprof 500
#define MAXalu 500

#define ERRO_NA_CRIACAO_DE_PILHA -1
#define PILHA_CHEIA -2
#define INSERIDO_COM_SUCESSO 1
#define REMOVIDO_COM_SUCESSO 1
#define PILHA_VAZIA -4
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

	int Matricula;
	char Nome[100];
	char Sexo[3];
	int Dia;
	int Mes;
	int Ano;
	unsigned long long int CPF;

};

struct pilhaDisciplina{
	
	int qtdDISCIPLINA;
    struct disciplina DADOS[MAXdis];
    
};


struct pilhaAluno{
	
	int qtdALUNO;
    struct aluno Dados[MAXalu];
    
};



struct pilhaProfessor{
	
	int qtdPROFESSOR;
    struct professor dados[MAXprof];
    
};

typedef struct pilhaDisciplina PILHA;
typedef struct pilhaAluno Pilha;
typedef struct pilhaProfessor PI;


PILHA *cria_pilha_disciplina();
void libera_pilha_disciplina(PILHA *pi);
//int tamanho_pilha_disciplina(PILHA *pi);
int pilha_cheia_disciplina(PILHA *pi);
int pilha_vazia_disciplina(PILHA *pi);
int insere_elemento_disciplina(PILHA *pi, struct disciplina valor);
int remove_pilha_disciplina(PILHA *pi);
int acessa_topo_disciplina(PILHA *pi, struct disciplina *valor);
void listar_disciplinas(PILHA *pi);
int atualizar_dados_da_disciplina(PILHA *pi, char codigo_da_disciplina[20]);
void acessa_topo_da_pilha(PILHA *pi);



Pilha *cria_pilha_de_alunos();
int insere_aluno_na_pilha( Pilha *pi, struct aluno al );
void imprimir_lista_de_alunos( Pilha *pi);
void libera_memoria_reservada_para_aluno(Pilha *pi);
void listar_disciplinas_e_alunos_matriculados( PILHA *pi, Pilha *paluno);
void imprimir_alunos_de_sexo_masculino(Pilha *pi);
void imprimir_alunos_de_sexo_feminino(Pilha *pi);
void acessa_topo_da_pilha_aluno(Pilha *pi);
int excluir_aluno_na_lista(Pilha *pi);
void listar_aniversariantes_de_um_dado_mes(Pilha *pi, int mmes);
int quantidade_dos_alunos(Pilha *pi);
int pilha_vazia_de_alunos(Pilha *pi);
int pilha_cheia_de_alunos(Pilha *pi);
int atualizar_lista_dos_alunos( Pilha *pi, int mmatricula );



PI *cria_pilha_de_professor();
int insere_professor_na_pilha( PI *pi, struct professor al );
void imprimir_lista_de_professor( PI *pi);
void libera_memoria_reservada_para_professor(PI *pi);
//void listar_disciplinas_e_alunos_matriculados( PILHA *pi, Pilha *paluno);
void imprimir_professor_de_sexo_masculino(PI *pi);
void imprimir_professor_de_sexo_feminino(PI *pi);
void acessa_topo_da_pilha_professor(PI*pi);
int excluir_professor_na_lista(PI *pi);
void listar_aniversariantes_de_um_dado_mes_professor(PI *pi, int mmmes);
int quantidade_dos_professor(PI *pi);
int pilha_vazia_de_professor(PI *pi);
int pilha_cheia_de_professor(PI *pi);


int atualizar_lista_dos_professor( PI *pi, int mmatricula );







