#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.h"
#include <time.h>
#include <string.h>

void pegaN(int x,char *n){

    LIVRO A;
    LIVROS = fopen("livros.txt", "rb");
    AUXL = fopen("auxL.txt", "ab");

    while(fread(&A, sizeof(LIVRO), 1, LIVROS)){
        if(A.codigoL==x){
            A.quant--;
            fwrite(&A, sizeof(LIVRO),1,AUXL);
            strcpy(n, A.nLivro);
        }else{
            fwrite(&A, sizeof(LIVRO),1,AUXL);
        }
    }
    fclose(LIVROS);
    fclose(AUXL);
    remove("livros.txt");
    rename("auxL.txt", "livros.txt");
}

void pegaA(char x[D], char *y){
    ALUNO A;
    ALUNOS = fopen("alunos.txt", "rb");

    while(fread(&A, sizeof(ALUNO), 1, ALUNOS)){
        if(strcmp(A.matricula, x) == 0){
            strcpy(y, A.nome);
        }
    }
    fclose(ALUNOS);

}

void aumenta(char x[D]){

    ALUNO A;

    ALUNOS = fopen("alunos.txt", "rb");
    AUXA = fopen("auxA.txt", "ab");

    while(fread(&A, sizeof(ALUNO), 1, ALUNOS)){
        if(strcmp(A.matricula, x) == 0){
            A.Qemp++;
            fwrite(&A, sizeof(ALUNO), 1, AUXA);
        }else{
            fwrite(&A, sizeof(ALUNO), 1, AUXA);
        }
    }
    fclose(ALUNOS);
    fclose(AUXA);
    remove("alunos.txt");
    rename("auxA.txt","alunos.txt");
}


int verificaA(char x[D]){
    int verifica = 0;

    ALUNO A;
    ALUNOS = fopen("alunos.txt","rb");

    while(fread(&A, sizeof(ALUNO), 1,ALUNOS)){
        if(strcmp(A.matricula, x) == 0){
            verifica++;
            if(A.Qemp > 1){
                verifica++;
            }
        }
    }
    fclose(ALUNOS);

    if(verifica == 0){
        return 0;
    }else if(verifica == 2){
        return 2;
    }else{
        return 1;
    }
}

int verificaL(int x){
    int verifica = 0;

    LIVRO L;
    LIVROS = fopen("livros.txt","rb");

    while(fread(&L, sizeof(LIVRO), 1,LIVROS)){
        if(L.codigoL == x){
            verifica++;
        }
    }
    fclose(LIVROS);

    if(verifica == 0){
        return 0;
    }else{
        return 1;
    }
}

void devolveN(int x){
    LIVRO L;
    LIVROS = fopen("livros.txt", "rb");
    AUXL = fopen("auxL.txt", "ab");

    while(fread(&L, sizeof(LIVRO), 1, LIVROS)){
        if(L.codigoL==x){
            L.quant = L.quant + 1;
            fwrite(&L, sizeof(LIVRO),1,AUXL);
        }else{
            fwrite(&L, sizeof(LIVRO),1,AUXL);        }
    }
    fclose(LIVROS);
    fclose(AUXL);
    remove("livros.txt");
    rename("auxL.txt", "livros.txt");
}

void devolveE(char x[D]){

    ALUNO A;
    ALUNOS = fopen("alunos.txt", "rb");
    AUXA = fopen("auxA.txt", "ab");

    while(fread(&A, sizeof(ALUNO), 1, ALUNOS)){
        if(strcmp(A.matricula,x) == 0){
            A.Qemp = A.Qemp - 1;
            fwrite(&A, sizeof(LIVRO),1,AUXA);
        }else{
            fwrite(&A, sizeof(LIVRO),1,AUXA);        }
        }
    fclose(ALUNOS);
    fclose(AUXA);
    remove("alunos.txt");
    rename("auxA.txt", "alunos.txt");

}

void emprestimo(int x, char y[D], char z[D], char h[D]){


    EMPREST ep;

    if((EMP = fopen("emprestimos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
    }

    system("cls");
    Tbiblio();
    ep.EmpID = x;
    strcpy(ep.EmpAluno, y);
    strcpy(ep.EmpNomeL, z);
    strcpy(ep.EmpNomeA, h);
    printf("\tDIGITE A DATA DO EMPRÉSTIMO");
    printf("\n\tDIA:");
    scanf("%d", &ep.EmpDia);
    printf("\tMES:");
    scanf("%d", &ep.EmpMes);
    printf("\tANO:");
    scanf("%d", &ep.EmpAno);
    ep.DevDia = ep.EmpDia + 10;

    if(ep.DevDia > 30){
        ep.DevDia = ep.DevDia - 30;
        ep.DevMes = ep.EmpMes + 1;
    }else{
        ep.DevMes = ep.EmpMes;
    }

    ep.DevAno = ep.EmpAno;
    fwrite(&ep, sizeof(EMPREST),1,EMP);
    fclose(EMP);
    printf("\n\n\tEMPRÉSTIMO FEITO COM SUCESSO");
    sistema();
}

void mostEmpr(){
    system("cls");

    EMPREST ep;
    EMP = fopen("emprestimos.txt", "rb");
    Tbiblio();
    printf("\t===================EMPRÉSTIMOS==================\n\n");
    while(fread(&ep, sizeof(EMPREST), 1,EMP)){
        printf("\tID DO LIVRO:%d\n", ep.EmpID);
        printf("\tNOME DO LIVRO:%s\n",strupr(ep.EmpNomeL));
        printf("\tNOME DO ALUNO:%s\n", strupr(ep.EmpNomeA));
        printf("\tCÓDIGO DO ALUNO:%s\n", strupr(ep.EmpAluno));
        printf("\tDATA DO EMPRÉSTIMO:%d/%d/%d\n", ep.EmpDia, ep.EmpMes, ep.EmpAno);
        printf("\tDATA DA DEVOLUÇAO:%d/%d/%d\n\n", ep.DevDia, ep.DevMes, ep.DevAno);
        printf("\t==============================\n\n");
    }
    fclose(EMP);
    sistema();
}

void Ecancel(int x, char y[D]){
    EMPREST ep;
    EMP = fopen("emprestimos.txt", "rb");
    AUXE = fopen("auxEmp.txt", "ab");

    while(fread(&ep, sizeof(EMPREST), 1, EMP)){
        if(ep.EmpID != x && strcmp(ep.EmpAluno, y) != 0){
            fwrite(&ep, sizeof(EMPREST), 1, AUXE);
        }else if(ep.EmpID == x && strcmp(ep.EmpAluno, y) != 0){
            fwrite(&ep, sizeof(EMPREST), 1, AUXE);
        }else if(ep.EmpID != x && strcmp(ep.EmpAluno, y) == 0){
            fwrite(&ep, sizeof(EMPREST), 1, AUXE);
        }
    }
    fclose(EMP);
    fclose(AUXE);
    remove("emprestimos.txt");
    rename("auxEmp.txt", "emprestimos.txt");
}
