#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Funcoes.h"
#include <ctype.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int aux = 0;
    int carregando = 0;
    int id = 0;
    char mat[C];
    int verifica;
    char nome[D];
    char nomeA[D];

    //variaveis que ser�o aplicadas nos switch cases
    int op;
    setlocale(LC_ALL, "Portuguese");

    do{
        op = Tinicio(&carregando);

        switch(op){
            case 1:{
                aux = Tacervo();
                switch(aux){
                    case 1:
                        cadLivro();
                        break;
                    case 2:
                        printf("\n\tDIGITE O N�MERO DE ID DE QUAL LIVRO DESEJA ALTERAR:");
                        scanf("%d", &id);
                        verifica = editLivro(id);
                        if(verifica == 0){
                            printf("\tID DE LIVRO NAO ENCONTRADO");
                            sistema();
                        }
                        break;
                    case 3:
                        printf("\n\tDIGITE O ID DO LIVRO QUE DESEJA REMOVER:");
                        scanf("%d", &id);
                        verifica = remoLivro(id);
                        if(verifica == 0){
                            printf("\tLIVRO NAO ENCONTRADO");
                            sistema();
                        }
                        break;
                    case 4:
                        mostrarL();
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\tOP�AO INVALIDA");
                        sistema();
                        break;
                }
                break;
            }
            case 2:{
                aux = Taluno();
                switch(aux){
                    case 1:
                        cadAluno();
                        break;
                    case 2:
                        printf("\n\tDIGITE O N�MERO DA MATRICULA DO ALUNO QUE DESEJA ALTERAR:");
                        setbuf(stdin,NULL);
                        gets(mat);
                        verifica = editAluno(mat);
                        if(verifica == 1){
                            printf("\n\tALUNO NAO ENCONTRADO, RETORNANDO A TELA PRINCIPAL");
                            sistema();
                        }else{
                            printf("\n\tEDI��O FEITA COM SUCESSO!");
                            sistema();
                        }
                        break;
                    case 3:
                        printf("\n\tDIGITE A MATRICULA DO ALUNO QUE DESEJA REMOVER:");
                        setbuf(stdin,NULL);
                        gets(mat);
                        verifica = remoAluno(mat);
                        if(verifica == 0){
                            printf("\n\tALUNO NAO ENCONTRADO!");
                            sistema();
                        }else{
                            printf("\n\tALUNO DE MATRICULA:%s, REMOVIDO COM SUCESSO!", mat);
                            sistema();
                        }
                        break;
                    case 4:
                        mostrarA();
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\tOP�AO INVALIDA");
                        sistema();
                        break;
                }
                break;
            }
            case 3:{
                aux = Temprestimo();
                switch(aux){
                    case 1:
                        printf("\n\tDIGITE O ID DO LIVRO QUE DESEJA FAZER EMPR�STIMO:");
                        scanf("%d", &id);
                        verifica = verificaL(id);
                        if(verifica == 0){
                            system("cls");
                            Tbiblio();
                            printf("\tLIVRO NAO ENCONTRADO, RETORNANDO A TELA PRINCIPAL");
                            sistema();
                        }else{
                            printf("\tDIGITE A MATRICULA DO ALUNO QUE FAR� O EMPR�STIMO:");
                            setbuf(stdin,NULL);
                            gets(mat);
                            verifica = verificaA(mat);
                            if(verifica == 0){
                                printf("\n\tALUNO N�O ENCONTRADO, RETORNANDO A TELA PRINCIPAL");
                                sistema();
                            }else if(verifica == 2){
                                printf("\n\tO ALUNO NAO PODE REALIZAR MAIS EMPR�STIMOS, POIS ATINGIU O LIMITE DE 2");
                                sistema();
                            }else{
                                pegaN(id, &nome);
                                pegaA(mat, &nomeA);
                                emprestimo(id, mat, nome, nomeA);
                                aumenta(mat);
                            }
                        }
                        break;
                    case 2:
                        printf("\n\tDIGITE O ID DO LIVRO QUE SER� DEVOLVIDO:");
                        scanf("%d", &id);
                        printf("\tDIGITE A MATRICULA DO ALUNO QUE DESEJA FAZER A DEVOLU�AO:");
                        setbuf(stdin,NULL);
                        gets(mat);
                        Ecancel(id, mat);
                        devolveN(id);
                        devolveE(mat);
                        printf("\n\tDEVOLU�AO FEITA COM SUCESSO!");
                        sistema();
                        break;
                    case 3:
                        printf("\n\tDigite o ID DO LIVRO QUE DESEJA CANCELAR O EMPR�STIMO:");
                        scanf("%d", &id);
                        printf("\tDIGITE A MATRICULA DO ALUNO QUE SER� CANCELADO O EMPR�STIMO:");
                        setbuf(stdin,NULL);
                        gets(mat);
                        Ecancel(id, mat);
                        devolveN(id);
                        devolveE(mat);
                        printf("\tCANCELAMENTO FEITO COM SUCESSO");
                        sistema();
                        break;
                    case 4:
                        mostEmpr();
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\tOP�AO INVALIDA");
                        sistema();
                        break;
                }
                break;
            }
            case 4:{
                break;
            }default:{
                printf("\n\tOP�AO INVALIDA");
                sistema();
                break;
            }
        }
    }while(op != 4);

    return 0;
}
