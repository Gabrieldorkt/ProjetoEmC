#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.h"
#include <time.h>
#include <string.h>


void cadLivro(){

    int i=0;
	int opc;

    LIVRO Lcad;

    if ((LIVROS = fopen("livros.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        Lcad.codigoL = 1+(rand()% 300);
        Tbiblio();
        printf("\tCADASTRO DO LIVRO:\n\n");
        printf("\t\tNOME DO LIVRO:");
        setbuf(stdin,NULL);
        gets(Lcad.nLivro);
        printf("\t\tNOME DO AUTOR PRINCIPAL:");
        setbuf(stdin,NULL);
        gets(Lcad.nAutor);
        printf("\t\tQUANTIDADE DE EXEMPLARES:");
        setbuf(stdin,NULL);
        scanf("%d", &Lcad.quant);
        printf("\t\tAREA DO CONHECIMENTO:");
        setbuf(stdin,NULL);
        gets(Lcad.conhec);
        fwrite(&Lcad, sizeof(LIVRO),1,LIVROS);
        fclose(LIVROS);
        printf("\n\n\tCADASTRO FEITO COM SUCESSO");
        sistema();

        Tbiblio();
        printf ("\n\n\t\t=====================================\n");
        printf ("\t\t|                                   |\n");
        printf("\t\t|                                   |\n");
        printf("\t\t| DESEJA FAZER UM NOVO CADASTRO?   |\n");
        printf("\t\t|                                   |\n");
        printf ("\t\t|                                   |\n");
        printf ("\t\t=====================================\n");
        printf ("\n\n");
        printf("\n\t\t\t    1-SIM\t2-NAO");
        printf("\n\n\t\t        SELECIONE UMA OPCAO: ");
        scanf("%d", &opc);
        if(opc == 1){
            cadLivro();
        }
}

int editLivro(int x){

     int verifica = 0;

     int auxN;
     char aux[D];
     int opcao;

     system("cls");
     Tbiblio();
     LIVRO Ledit;
     LIVRO novo;
     LIVROS = fopen("livros.txt","rb");
     AUXL = fopen("auxL.txt","ab");

     while(fread(&Ledit, sizeof(LIVRO), 1,LIVROS)){
        if(Ledit.codigoL==x){
             puts("\tESCCOLHA QUAL CAMPO DO LIVRO DESEJA ALTERAR");
             puts("\t1 - NOME DO LIVRO");
             puts("\t2 - NOME DO AUTOR PRINCIPAL");
             puts("\t3 - QUANTIDADE DE EXEMPLARES");
             puts("\t4 - AREA DO CONHECIMENTO");
             puts("\t5 - RETORNAR A TELA ANTERIOR");
             printf("\tOPÇAO:");
             scanf("%d", &opcao);
             system("cls");
             Tbiblio();
             printf("\n\tDIGITE O NOVO CAMPO:");

                switch(opcao){
                    case 1:
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(Ledit.nLivro,aux);
                        break;
                    case 2:
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(Ledit.nAutor,aux);
                        break;
                    case 3:
                        scanf("%d", &auxN);
                        Ledit.quant = auxN;
                        break;
                    case 4:
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(Ledit.conhec,aux);
                        break;
                    case 5:
                        return;
                        break;
                    default:{
                        printf("opção inválida");
                        break;
                    }
                }
                fwrite(&Ledit, sizeof(LIVRO),1,AUXL);
                verifica++;
        }else{
            fwrite(&Ledit, sizeof(LIVRO),1,AUXL);
        }
    }

    fclose(LIVROS);
    fclose(AUXL);
    remove("livros.txt");
    rename("auxL.txt","livros.txt");

    if(verifica == 0){
        return 0;
    }else{
        return 1;
    }
}


int remoLivro(int x){

    int verificador = 0;

     LIVRO Lremo;
     LIVRO novo;
     LIVROS = fopen("livros.txt","rb");
     AUXL = fopen("auxL.txt","ab");

     while(fread(&Lremo, sizeof(LIVRO), 1,LIVROS)){

        if(Lremo.codigoL == x){
            verificador ++;
        }

        if(Lremo.codigoL!=x){
            fwrite(&Lremo, sizeof(LIVRO),1,AUXL);
        }
    }

    fclose(LIVROS);
    fclose(AUXL);
    remove("livros.txt");
    rename("auxL.txt","livros.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\tLIVRO DE ID:%d, REMOVIDO COM SUCESSO!", x);
        sistema();
        return 1;
    }
}


void mostrarL(){
        system("cls");
        LIVRO Lmost;
        LIVROS = fopen("livros.txt", "rb");
        Tbiblio();
        printf("\t====================LIVROS====================\n\n");
        while (fread(&Lmost, sizeof(LIVRO), 1,LIVROS)){
            printf("\tCODIGO DO LIVRO:%d\n", Lmost.codigoL);
            printf("\tNOME DO LIVRO:%s\n", strupr(Lmost.nLivro));
            printf("\tNOME DO AUTOR PRINCIPAL:%s\n", strupr(Lmost.nAutor));
            printf("\tQUANTIDADE DE EXEMPLARES:%d\n", Lmost.quant);
            printf("\tAREA DO CONHECIMENTO:%s\n\n", strupr(Lmost.conhec));
            printf("\t==============================\n\n");
        }
        fclose(LIVROS);
		sistema();
}


//////////////////////////////////////////////////////////////////////////////////////////ALUNOS//////////////////////////////////////////////////////
void cadAluno(){

    int opc;

    ALUNO Acad;
    system("cls");
    Tbiblio();
    if ((ALUNOS = fopen("alunos.txt", "ab")) == NULL){
        fprintf(stderr, "Arquivo de armazenamento inexistente.\n");
        exit(EXIT_FAILURE);
    }
        printf("\tCADASTRO DO ALUNO:\n");
        printf("\tNOME:");
        setbuf(stdin,NULL);
        gets(Acad.nome);
        printf("\tMATRICULA:");
        setbuf(stdin,NULL);
        gets(Acad.matricula);
        printf("\tCPF:");
        setbuf(stdin,NULL);
        gets(Acad.cpf);
        Acad.Qemp = 0;
        fwrite(&Acad, sizeof(ALUNO),1,ALUNOS);
        fclose(ALUNOS);

        printf("\n\n\tCADASTRO FEITO COM SUCESSO");
        sistema();
        Tbiblio();
        printf ("\n\n\t\t=====================================\n");
        printf ("\t\t|                                   |\n");
        printf("\t\t|                                   |\n");
        printf("\t\t| DESEJA FAZER UM NOVO CADASTRO?    |\n");
        printf("\t\t|                                   |\n");
        printf ("\t\t|                                   |\n");
        printf ("\t\t=====================================\n");
        printf ("\n\n");
        printf("\n\t\t\t    1-SIM\t2-NAO");
        printf("\n\n\t\t        SELECIONE UMA OPCAO: ");
        scanf("%d", &opc);
        if(opc == 1){
            cadAluno();
        }
}


int editAluno(char x[C]){

     int verifica = 0;

     int opcao;
     char aux[D];
     ALUNO Aedit;
     ALUNOS = fopen("alunos.txt", "rb");
     AUXA = fopen("auxA.txt", "ab");

     system("cls");
     Tbiblio();

      while(fread(&Aedit, sizeof(ALUNO), 1, ALUNOS)){
        if(strcmp(Aedit.matricula, x) == 0){
             puts("\tESCOLHA QUAL CAMPO DO ALUNO DESEJA MUDAR\n");
             puts("\t1 - NOME DO ALUNO\n");
             puts("\t2 - MATRÍCULA DO ALUNO\n");
             puts("\t3 - CPF DO ALUNO\n");
             puts("\t4 - RETORNAR A TELA PRINCIPAL");
             printf("\tOPÇÃO:");
             scanf("%d", &opcao);
             system("cls");
             Tbiblio();
             printf("\n\tDIGITE O NOVO CAMPO:");

                    switch(opcao){
                        case 1:
                            setbuf(stdin,NULL);
                            gets(aux);
                            strcpy(Aedit.nome,aux);
                            break;
                        case 2:
                            setbuf(stdin,NULL);
                            gets(aux);
                            strcpy(Aedit.matricula,aux);
                            break;
                        case 3:
                            setbuf(stdin,NULL);
                            gets(aux);
                            strcpy(Aedit.cpf,aux);
                            break;
                        case 4:
                            break;
                        default:{
                            printf("opção inválida");
                            break;
                        }
                    }
                    fwrite(&Aedit, sizeof(ALUNO),1,AUXA);
                    verifica++;
            }else{
                fwrite(&Aedit, sizeof(ALUNO),1,AUXA);
            }
        }
    fclose(ALUNOS);
    fclose(AUXA);
    remove("alunos.txt");
    rename("auxA.txt","alunos.txt");
    if(verifica == 1){
        return 0;
    }else{
        return 1;
    }
}

int remoAluno(char x[C]){

     int verifica = 0;
     ALUNO Aedit;
     ALUNOS = fopen("alunos.txt","rb");
     AUXA = fopen("auxA.txt","ab");

     while(fread(&Aedit, sizeof(ALUNO), 1,ALUNOS)){

        if(strcmp(Aedit.matricula,x)==0){
            verifica++;
        }

        if(strcmp(Aedit.matricula,x)!=0){
            fwrite(&Aedit, sizeof(ALUNO),1, AUXL);
        }
    }
    fclose(ALUNOS);
    fclose(AUXA);
    remove("alunos.txt");
    rename("auxA.txt","alunos.txt");
    if(verifica == 0){
        return 0;
    }else{
        return 1;
    }
}

void mostrarA(LIVRO *u, int *p){

        system("cls");
        ALUNO Amost;
        ALUNOS = fopen("alunos.txt", "rb");
        Tbiblio();
        printf("\t====================ALUNOS====================\n\n");
        while (fread(&Amost, sizeof(ALUNO), 1,ALUNOS)){
            printf("\tNOME DO ALUNO:%s\n", strupr(Amost.nome));
            printf("\tMATRICULA DO ALUNO:%s\n", strupr(Amost.matricula));
            printf("\tCPF DO ALUNO:%s\n", strupr(Amost.cpf));
            printf("\tQUANTIDADE DE EMPRÉSTIMO FEITOS:%d\n\n", Amost.Qemp);
            printf("\t==============================\n\n");
        }
        fclose(ALUNOS);
		sistema();
}

