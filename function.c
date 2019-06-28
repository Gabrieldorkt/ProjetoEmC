#include <stdio.h>
#include <windows.h>
#include <locale.h>


//T serve de referência para a palavra "TELA"

void sistema(){
    printf("\n\t");
    system("pause");
    system("cls");
}

void Tbiblio(){
    system("color 1F");
    printf("********************************************************************************");
    printf("********************************************************************************\n");
    printf("                 BIBLIOTECA DA UNIVERSIDADE ESTADUAL DA PARAíBA \n\n");
    printf("********************************************************************************");
    printf("********************************************************************************\n");
}

int Tinicio(int *j){
    int a;
    int opcao;
    system("cls");
    Tbiblio();
    for(a = *j; a<3; a++){
            if(a == 0){
                printf("CARREGANDO");
            }
            Sleep(500);
            printf(".");
            Sleep(500);
    }
    *j = 3;
    printf("\n\n      OPÇOES DO SISTEMA:\n\n");
    printf("\t\t   1 - ARCEVO \t 3 - EMPRÉSTIMOS\n\n");
    printf("\t\t   2 - ALUNOS \t 4 - SAIR DO PROGRAMA\n\n");
    printf("\t\tOPÇAO:");
    scanf("%d", &opcao);
    return opcao;
}

int Tacervo(){
    int opcao;
    system("cls");
    Tbiblio();
    printf("\n\n      OPÇOES DE ACERVO:\n\n");
    printf("\t\t   1 - CADASTRAR LIVRO \t 3 - REMOVER LIVRO\n\n");
    printf("\t\t   2 - EDITAR LIVRO \t 4 - LISTAR LIVROS CADASTRADOS\n\n");
    printf("\t\t\t 5 - RETORNAR A TELA ANTERIOR\n\n");
    printf("\t\tOPÇÃO:");
    scanf("%d", &opcao);
    return opcao;
}

int Taluno(){
    int opcao;
    system("cls");
    Tbiblio();
    printf("\n\n      OPÇOES DE ALUNOS:\n\n");
    printf("\t\t   1 - CADASTRAR ALUNO \t 3 - REMOVER ALUNO\n\n");
    printf("\t\t   2 - EDITAR ALUNO \t 4 - LISTAR ALUNOS CADASTRADOS\n\n");
    printf("\t\t\t 5 - RETORNAR A TELA ANTERIOR\n\n");
    printf("\t\tOPÇAO:");
    scanf("%d", &opcao);
    return opcao;
}

int Temprestimo(){
    int opcao;
    system("cls");
    Tbiblio();
    printf("\n\n      OPÇOES DE EMPRÉSTIMO:\n\n");
    printf("\t\t   1 - NOVO EMPRÉSTIMO \t 3 - CANCELAR EMPRÉSTIMO\n\n");
    printf("\t\t2 - CONFIRMAR DEVOLUÇÃO   4 - LISTAR EMPRÉSTIMOS\n\n");
    printf("\t\t\t 5 - RETORNAR A TELA ANTERIOR\n\n");
    printf("\t\tOPÇAO:");
    scanf("%d", &opcao);
    return opcao;
}




