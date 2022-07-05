/*Instituto Federal de Ciência e Tecnologia do Maranhão | IFMA
  Departamento de Computação 
  Curso: Sistemas de Informação 
  Disciplina: Linguagem de Programação 
  Profª. Evaldinolia Gilbertoni Moreira 
========================================================================
"Motive-se, sempre, pois ainda que você não atinja o seu objetivo,
ao olhar para trás verá que no mínimo, realizou coisas extraordinárias!"
========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

/*Lista de declaração das constantes do nosso jogo, feita através da diretiva de pré-processador #define.*/
#define F 10 //Nível Fácil
#define M 6 //Nível Médio
#define D 4 //Nível Difícil

/* Abaixo temos uma sequência de funções (sem retorno) que serão utilizadas durante a execução do programa.
A função "start" é chamada após a entrada do limite da faixa de valores definidos pelo usuário (máximo e mínimo).*/
void start(void){

    printf("\n");
    printf("\n=======================================================");
    printf("\nINSTITUTO FEDERAL DO MARANHÃO - SISTEMAS DE INFORMAÇÃO");
    printf("\nProgramadores: IULANO SANTOS e GABRIEL PORTELA");
    printf("\nModularização de Código e Ganho Computacional");
    printf("\nProfessora Dra. Evaldinolia Gilbertoni");
    printf("\n=======================================================\n\n");

printf("\n");
   printf("      P  /_\\  P \n");
   printf("     /_\\_|_|_/_\\ \n");
   printf(" n_n | ||. .|| | n_n      Bem vindo ao \n");
   printf(" |_|_|nnnn nnnn|_|_|   Jogo de Adivinhação \n");
   printf("|     |  |_|  |     | \n");
   printf("|_____| ' _ ' |_____| \n");
   printf("      \\__|_|__/ \n");
   printf("\n");
}

/*A função "parabens" é chamada assim que as condições de vitória do jogo são satisfeitas.*/
void parabens (){
 printf("\n\n");
 printf("\n\n");
 printf("              00000000000 \n");
                    printf("          0000000000000000000 \n");
                    printf("       000000  000000000  000000 \n");
                    printf("     000000      00000      000000 \n");
                    printf("   00000000  #   00000   #  00000000 \n");
                    printf("  0000000000    0000000    0000000000 \n");
                    printf(" 0000000000000000000000000000000000000 \n");
                    printf(" 0000000000000000000000000000000000000 \n");
                    printf(" 0000  0000000000000000000000000  0000 \n");
                    printf("  0000  00000000000000000000000  0000 \n");
                    printf("   0000  000000000000000000000  0000 \n");
                    printf("     00000  000000000000000  00000 \n");
                    printf("       000000  000000000  000000 \n");
                    printf("          0000000     0000000 \n");
                    printf("\n");
                    printf("       Parabens! Voce venceu o jogo!\n");
                    printf("-----------------------------------------\n");
                    printf("\n");
}

/*A função "gameover" é chamada assim que as condições de perda do jogo são satisfeitas.*/

void gameover(void){
printf("\\|/ _____ \\|/ \n");
printf(" @~/ . . \\~@ \n");
printf("/_( \\___/ )_\\ \n");
printf("   \\__U__/ \n");
printf("Voce Perdeu! Tente Novamente!");
}


/*A função "restart" é chamada se o usuário optar por jogar uma nova partida.
Assim, ela executa novamente todas as instruções da função "main"*/

void restart(int x){
    if(x==1){
    system("cls");
    int d,t,n,ns,x,j,m,mn,c,nc=0;
    float pp=0,pontos=1000.0;
    srand(time(0));
    printf("Deseja Mudar o limite de numeros?\n (1)Sim (2)Nao \n");
    scanf("%d",&c);
    if(c==1){
      printf("Digite os limites minimo e máximo:\n");
      scanf("%d",&mn);
      scanf("%d",&m);
      system("cls");
    }
    if(c==2){
        m=99;
        mn=0;
        system("cls");
    }
    ns= rand() % (m+1-mn)+mn;
    start();
    system("pause");
    printf("Qual o nivel de dificuldade:\n (1)Facil (2)Medio (3)Dificil \n");
    scanf("%d",&d);
    system("cls");
    if(d==1){
        for(t=1;t<=10;t++){
                printf("->Tentativa %d de %d ",t,F);
                printf("Chute um numero:\t");
                scanf("%d",&n);
                pp= abs(n-ns)/2.0;
                pontos= pontos -pp;
                if(n==nc){
                    printf("Voce ja chutou esse numero!\n");
                    t--;
                }
                if (n<ns){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                if(n>ns){
                    printf("Seu chute foi maior que o numero secreto!\n");
                }
                if(n==ns){
                    system("cls");
                    parabens();
                    printf("\n Total de pontos: %.2f pontos. Ate a proxima.\n",pontos);
                    printf("---------------------------------------");
                    system("pause");
                    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
                    scanf("%d",&j);
                    restart(j);
                    return 0;
                }
                nc=n;
        }

    }
    if(d==2){
     for(t=1;t<=6;t++){
                printf("->Tentativa %d de %d ",t,M);
                printf("Chute um numero:\t");
                scanf("%d",&n);
                pp= abs(n-ns)/2.0;
                pontos= pontos -pp;
                if(n==nc){
                    printf("Voce ja chutou esse numero!\n");
                    t--;
                }
                if (n<ns){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                if(n>ns){
                    printf("Seu chute foi maior que o numero secreto!\n");
                }
                if(n==ns){
                    system("cls");
                    parabens();
                    printf("\n Scorecard: %.2f pontos. Ate a proxima.\n",pontos);
                    printf("------------------------------------------------");
                    system("pause");
                    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
                    scanf("%d",&j);
                    restart(j);
                    return 0;
                }
                nc=n;
      }

    }
    if(d==3){
     for(t=1;t<=4;t++){
                printf("->Tentativa %d de %d ",t,D);
                printf("Chute um numero:\t");
                scanf("%d",&n);
                pp= abs(n-ns)/2.0;
                pontos= pontos -pp;
                if(n==nc){
                    printf("Voce ja chutou esse numero!\n");
                    t--;
                }
                if (n<ns){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                if(n>ns){
                    printf("Seu chute foi maior que o numero secreto!\n");
                }
                if(n==ns){
                    system("cls");
                    parabens();
                    printf("\n Voce fez %.2f pontos. Ate a proxima.",pontos);
                    printf("\n");
                    system("pause");
                    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
                    scanf("%d",&j);
                    restart(j);
                    return 0;
                }
                nc=n;
   }
    }
    system("cls");
    gameover();
    printf("\n");
    system("pause");
    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
    scanf("%d",&j);
    restart(j);

    }
    if(x==2){
    system("cls");
    printf("Obrigado por jogar!!!");
    printf("\n ------------------------------------------------\n");
    printf("\n Espero ter ajudado!\n Grande abraço.\n");
    printf("\n Yullano Santos\n\n");
    return 0;
    }
}

int main(){

    setlocale(LC_ALL,"portuguese");
    char nickname[20];
    char acUserName[100];
    int d,t,n,ns,j,m,mn,c,nc; // c = sim ou não no intervalo / d = dificuldade / nc= numerorepetido
    float pp=0,pontos=1000.0; // pp = pontos perdidos

/* Pra deixar nosso jogo mais dinâmico, inserimos a função da API do Windows - GetUserName.
Ela captura o nome do usu1ário logado no Windows.*/

    DWORD nUserName = sizeof(acUserName);
    if (GetUserName(acUserName, &nUserName)) {
    printf("\nOlá %s, tudo bem?\n",acUserName);
    printf("------------------------------\n");
    printf("\nEntre com um nickname para iniciar o jogo: \n");
    scanf("%s",&nickname);
    printf("------------------------------\n");
    start();
    printf("\nO jogo está programado entre 0 e 99! O número secreto está nesse intervalo!");
    printf("\nDeseja diminuir este intervalo, %s? ",nickname);
    printf("\nDigite (1)Sim (2)Nao \n");
}

    scanf("%d",&c);
    srand(time(0));
    if(c==1){
      printf("Digite os limites mínimo e máximo:\n");
      scanf("%d",&mn);
      scanf("%d",&m);
      system("cls");
    }
    if(c==2){
        m=99;
        mn=0;
    }
    ns= rand() % (m+1-mn)+mn;
    printf("Qual o nivel de dificuldade:\n (1)Facil (2)Medio (3)Dificil \n");
    scanf("%d",&d);
    system("cls");
    if(d==1){//Tentativa nível 1 (fácil);
        for(t=1;t<=10;t++){
                printf("->Tentativa %d de %d ",t,F);
                printf("Chute um numero:\t");
                scanf("%d",&n);
                pp= abs(n-ns)/2.0; //pp pontos perdidos = absoluto (chute - numerosorteado)/2
                pontos= pontos -pp;
                if(n==nc){ //n = chute e nc = chute repetido
                    printf("Voce ja chutou esse numero!\n");
                    t--;
                }
                if (n<ns){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                if(n>ns){
                    printf("Seu chute foi maior que o numero secreto!\n");
                }
                if(n==ns){
                    system("cls");
                    parabens();
                    printf("\n Voce fez %.2f pontos. Ate a próxima %s.",pontos,nickname);
                    printf("\n");
                    system("pause");
                    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
                    scanf("%d",&j);
                    restart(j);
                    return 0;
                }
            nc=n;
        }
    }


    if(d==2){
     for(t=1;t<=6;t++){
                printf("->Tentativa %d de %d ",t,M);
                printf("Chute um numero:\t");
                scanf("%d",&n);
                pp= abs(n-ns)/2.0;
                pontos= pontos -pp;
                if(n==nc){
                    printf("Voce ja chutou esse numero!\n");
                    t--;
                }
                if (n<ns){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                if(n>ns){
                    printf("Seu chute foi maior que o numero secreto!\n");
                }
                if(n==ns){
                    system("cls");
                    parabens();
                    printf("\n Voce fez %.2f pontos. Ate a proxima.",pontos);
                    printf("\n");
                    system("pause");
                    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
                    scanf("%d",&j);
                    restart(j);
                    return 0;
                }
                nc=n;
      }

    }


    if(d==3){
     for(t=1;t<=4;t++){
                printf("->Tentativa %d de %d ",t,D);
                printf("Chute um numero:\t");
                scanf("%d",&n);
                pp= abs(n-ns)/2.0;
                pontos= pontos -pp;
                if(n==nc){
                    printf("Voce ja chutou esse numero!\n");
                    t--;
                }
                if (n<ns){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                if(n>ns){
                    printf("Seu chute foi maior que o numero secreto!\n");
                }
                if(n==ns){
                    system("cls");
                    parabens();
                    printf(" Voce fez %.2f pontos. Ate a proxima %s.",pontos,nickname);
                    printf("\n");
                    system("pause");
                    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
                    scanf("%d",&j);
                    restart(j);
                    return 0;
                }
                nc=n;
   }
    }
    system("cls");
    gameover();
    printf("\n");
    system("pause");
    printf("Deseja jogar novamente? \n (1)Sim (2)Nao \n");
    scanf("%d",&j);
    restart(j);

}
