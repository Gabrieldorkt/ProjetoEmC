#ifndef FUNCTION-STRUCTS_H_INCLUDED
#define FUNCTION-STRUCTS_H_INCLUDED
#define D 50
#define C 25

//FUNÇÔES DE IMPRESSÃO DE TELAS NO PROGRAMA
void Tbiblio();
int Tinicio();
int Tacervo();
int Taluno();
int Temprestimo();
//end

//função de limpar a tela
void sistema();
//end

//ARQUIVOS
FILE *LIVROS;
FILE *AUXL;
FILE *ALUNOS;
FILE *AUXA;

FILE *EMP;
FILE *AUXE;
//END

//STRUCTS
typedef struct{
    int codigoL;
    char nLivro[D];
    char nAutor[D];
    int quant;
    char conhec[D];
}LIVRO;

typedef struct{
    char matricula[C];
    char nome[D];
    char cpf[C];
    int Qemp;
}ALUNO;

typedef struct{
    int EmpID;
    char EmpAluno[D];
    char EmpNomeL[D];
    char EmpNomeA[D];
    int EmpDia;
    int EmpMes;
    int EmpAno;
    int DevDia;
    int DevMes;
    int DevAno;
}EMPREST;
//FIM DAS STRUCTS

//FUNÇÃO ENVOLVENDO DADOS DE ALUNOS E LIVROS
void cadLivro();
int remoLivro();
int editLivro();
void mostrarL();

void cadAluno();
int editAluno();
int remoAluno();
void mostrarA();
//END


//FUNÇÕES DE EMPRESTIMO
void emprestimo();
void mostEmpr();
void pegaN();
void Ecancel();
void devolveN();
int verificaL();
int verificaA();
void aumenta();
void pegaA();
void aumenta();


#endif // FUNCTION-STRUCTS_H_INCLUDED
