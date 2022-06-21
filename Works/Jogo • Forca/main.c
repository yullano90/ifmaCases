/*Instituto Federal de Ciência e Tecnologia do Maranhão | IFMA
  Departamento de Computação
  Curso: Sistemas de Informação
  Disciplina: Linguagem de Programação
  Profª. Evaldinolia Gilbertoni Moreira
===================================================================
Nunca deixe ninguém dizer que você não pode fazer alguma coisa.
Se você tem um sonho, você deve protegê-lo e correr atrás,
As pessoas que não conseguem vencer, dirão que você também não vai vencer.
Se quer alguma coisa, corre atrás e ponto!!!
===================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
/*==================================================================================
/*Declaração das constantes do nosso jogo, via diretiva de pré-processador.*/
#define Facil 4 //Nível Fácil
#define Medio 3//Nível Médio
#define Dificil 2 //Nível Difícil
//==================================================================================
/*Apresentação do Splash do nosso jogo.*/
void start(){
    printf("\n");
    printf("\n=======================================================");
    printf("\nINSTITUTO FEDERAL DO MARANHAO - SISTEMAS DE INFORMACAO");
    printf("\nPROGRAMADORES: IULANO SANTOS && JAILSON SOARES ");
    printf("\nPROF. DRA. EVALDINOLIA MOREIRA GILBERTONI");
    printf("\nDISCIPLINA: LINGUAGEM DE PROGRAMACAO");
    printf("\nBEM VINDO AO JOGO DA FORCA, BOA SORTE! :) ");
    printf("\n=======================================================\n\n");
}
//==================================================================================
/*Comparação do nível de dificuldade do usuário com a diretiva correspondente.*/
int level(void){
    int level= 0, difficulty= 0;
    do{ printf("\n\n\n");
        printf("Qual o nivel de dificuldade:\n (1)Facil (2)Medio (3)Dificil?\n");
        fflush(stdin);
        scanf("%d",&level);
        system("cls");
    } while (level!= 1 && level!= 2 && level!= 3);
    if(level==1){difficulty = Facil;}
    if(level==2){difficulty = Medio;}
    if(level==3){difficulty = Dificil;}
    return (difficulty);
}
//==================================================================================
/*Nesta função usuário pode colaborar adicionando novas strings nos arquivos.*/
void admin(){
    int op, arquivo;
    char palavra[46]; //Tam 46 pois é a maior palavra do mundo!!!
    do{ printf("\n\n\n");
        printf("\nDeseja colaborar adicionando uma palavra na forca?\n1 - SIM  2 - NAO\n");
        scanf("%d", &op);
        system("cls");

    } while (op!= 1 && op!= 2);
    if (op == 1){
        do{ printf("Digite a palavra: ");
            scanf("%s",&palavra);
            printf("\nEsta palavra sera adicionada na lista que escolher agora: \n");
            printf("\n==========================================================");
            printf("\n|          Digite uma opcao para prosseguir:             |");
            printf("\n|                     1 = ALUNOS                         |");
            printf("\n|                     2 = DISCIPLINAS                    |");
            printf("\n|                     3 = MESTRES                        |");
            printf("\n==========================================================\n");
            scanf("%d",&arquivo);
            system("cls");
        } while (arquivo!= 1 && arquivo!= 2 && arquivo!= 3);

        if(arquivo == 1){
            FILE *p_alunos;  //Ponteiro do arquivo "ALUNOS".
            p_alunos = fopen("ALUNOS.txt", "a+");//Leitura e alterações.
            if(p_alunos == NULL){
                printf("Arquivo nao pode ser aberto\n");
          }
            fprintf(p_alunos,"\n%s",palavra); //Adiciona a palavra no arquivo.
            printf("\n\nPalavra gravada com sucesso na lista: ALUNOS!\n\n\n");
            system("pause");
            fclose(p_alunos);
        }
        //-------------------------------------------------------------------
        if(arquivo == 2){
            FILE *p_disciplinas;  //Ponteiro do arquivo "DISCIPLINAS".
            p_disciplinas = fopen("DISCIPLINAS.txt", "a+");//Leitura e alterações.
            if(p_disciplinas == NULL){
                printf("Arquivo nao pode ser aberto\n");
          }
            fprintf(p_disciplinas,"\n%s",palavra); //Adiciona a palavra no arquivo.
            printf("\n\nPalavra gravada com sucesso na lista: DISCIPLINAS!\n\n\n");
            system("pause");
            fclose(p_disciplinas);
        }
        //-------------------------------------------------------------------
        if(arquivo == 3){
            FILE *p_mestres;  //Ponteiro do arquivo "MESTRES".
            p_mestres = fopen("MESTRES.txt", "a+");//Leitura e alterações.
            if(p_mestres == NULL){
                printf("Arquivo nao pode ser aberto\n");
          }
            fprintf(p_mestres,"\n%s",palavra); //Adiciona a palavra no arquivo.
            printf("\n\nPalavra gravada com sucesso na lista: MESTRES!\n\n\n");
            system("pause");
            fclose(p_mestres);
        }
        //-------------------------------------------------------------------
    }
    if(op == 2){
        printf("\nTudo bem, voce quem manda!!!\n");
        printf("Muito obrigado por utilizar o nosso jogo!!!\n\n\n");
        system("pause");
        system("cls");
    }
}
//==================================================================================
void victory(){
    printf("\n");
    printf("\n==========================================================");
    printf("\n|                   PARABENS(A)!!!                       |");
    printf("\n|                   VOCE VENCEU!!!                       |");
    printf("\n==========================================================\n");
    printf("\n");
}
//==================================================================================
void gameover(){
    printf("\n");
    printf("\n==========================================================");
    printf("\n|                   VOCE PERDEU        :(                |");
    printf("\n|                   TENTE NOVAMENTE!                     |");
    printf("\n==========================================================");
    printf("\n");
}
//==================================================================================
/*A função ifma será chamada sempre que o jogo for encerrado pelo usuário.*/
void ifma(){
    printf("\n");
    printf("___00__000000000__00000_________00000___0000000___\n");
    printf("___00__000000000__00_00_________00_00__000000000__\n");
    printf("___00__00_________00__00_______00__00__00_____00__\n");
    printf("___00__000000_____00___00_____00___00__000000000__\n");
    printf("___00__000000_____00____00___00____00__000000000__\n");
    printf("___00__00_________00_____00_00_____00__00_____00__\n");
    printf("___00__00_________00______000______00__00_____00__\n");
    printf("___00__00_________00_______________00__00_____00__\n");
    printf("\n");
    printf("======== #SISTEMASDEINFORMACAO #IFMA ==========\n");
    printf("======== #MELHORCURSO #MELHORPROFESSORA ========\n\n");
}
//==================================================================================
/*Esta função sorteia a string secreta e testa as entradas do usuário*/
void play(){
    char palavraSecreta[46], palavraDigitada [46], chute, enter;
    int numeroDeChutes = 0, limiteDeChutes = 0, contaCorretas = 0, chuteRestante = 0;
    int dificuldade, fimJogo = 0, i, j, cont = 0;

    start();
    system("pause");
    system("cls");

    int arquivo;

    do {
        printf("\nEscolha um tema para sortear a palavra secreta: \n");
        printf("\n==========================================================");
        printf("\n|          Digite uma opcao para prosseguir:             |");
        printf("\n|                     1 = ALUNOS                         |");
        printf("\n|                     2 = DISCIPLINAS                    |");
        printf("\n|                     3 = MESTRES                        |");
        printf("\n==========================================================\n");
        scanf("%d", &arquivo);
        system("cls");
    } while (arquivo != 1 && arquivo != 2 && arquivo != 3);

    int aux, numeroDeLinhas = 0, numeroAleatorio = 0;

    if(arquivo == 1){
        FILE *p_alunos = fopen("ALUNOS.txt","r");

        do {
            aux = fgetc(p_alunos);//caracater por caracter até o \n

            if(aux == '\n')
                numeroDeLinhas++;
        } while (aux != EOF);

        fclose(p_alunos);

        p_alunos = fopen("ALUNOS.txt","r");
        srand(time(NULL));

        numeroAleatorio = 1+(rand()%numeroDeLinhas);

        for(i=0; i<= numeroAleatorio; i++)
            fgets(palavraSecreta, 46, p_alunos);//pegar uma string de uma linha;

        fclose(p_alunos);
    }

    if(arquivo == 2){
        FILE *p_disciplinas = fopen("DISCIPLINAS.txt","r");

        do {
            aux = fgetc(p_disciplinas);//caracater por caracter até o \n

            if(aux == '\n')
                numeroDeLinhas++;
        } while(aux != EOF);

        fclose(p_disciplinas);

        p_disciplinas = fopen("DISCIPLINAS.txt","r");
        srand(time(NULL));

        numeroAleatorio = 1+(rand()%numeroDeLinhas);

        for(i=0; i<= numeroAleatorio; i++)
            fgets(palavraSecreta, 46, p_disciplinas);//pegar uma string de uma linha;

        fclose(p_disciplinas);
    }

    if(arquivo == 3){
        FILE *p_mestres = fopen("MESTRES.txt","r");

        do {
            aux = fgetc(p_mestres);//caracater por caracter até o \n

            if(aux == '\n')
                numeroDeLinhas++;
        } while(aux != EOF);

        fclose(p_mestres);

        p_mestres = fopen("MESTRES.txt","r");
        srand(time(NULL));

        numeroAleatorio = 1+(rand()%numeroDeLinhas);

        for(i=0; i<= numeroAleatorio; i++)
            fgets(palavraSecreta, 46, p_mestres);//pegar uma string de uma linha;

        fclose(p_mestres);
    }

    dificuldade = level();


    int tamanhoSecreta = strlen(palavraSecreta)-1;
    limiteDeChutes = dificuldade + tamanhoSecreta;

    //GABARITO:
    printf("GABARITO: %s", palavraSecreta);

    for(i=0; i<tamanhoSecreta; i++)
        palavraDigitada[i] = '*';

    do {
        for(i=0; i<tamanhoSecreta; i++){
            printf("\n");

            //CONTADORES NA TELA:
            chuteRestante = limiteDeChutes-cont;

            printf("\n===========================================================\n");
            printf("                   Qtde de Letras: %d\n", tamanhoSecreta);
            printf("                   Limite de Erros: %d\n", dificuldade);
            printf("                   Tent. Restantes: %d            ", chuteRestante);
            printf("\n                   Acertos: %d               ", contaCorretas);
            printf("\n===========================================================\n");
            printf("\n");

            //LETRAS JÁ ENCONTRADAS
            for(i=0; i<tamanhoSecreta; i++)
                printf("[ %c ] ", palavraDigitada[i]);

            printf("\n\n");

            // TESTAR AS RESPOSTAS DO USUÁRIO
            printf("\nDigite uma letra ou (** para encerrar) :\n");
            scanf("%s", &chute);

            for(j=0; j<tamanhoSecreta; j++){
                if(toupper(chute) == palavraSecreta[j]){
                    palavraDigitada[j] = chute;
                    contaCorretas++;
                }
            }

            if (chuteRestante == 4 || contaCorretas == tamanhoSecreta)
                fimJogo = 1;

            cont++;
        }

        system("cls");

    } while(fimJogo == 0);
      system ("cls");

    //Condições de saída do jogo por perda:
    if(contaCorretas < tamanhoSecreta) {
        gameover();
        printf("\n==========================================================");
        printf("\n           A PALAVRA SECRETA ERA:    %s       \n", palavraSecreta);
        printf("==========================================================\n\n");
        system("pause");
        system("cls");
    } else if(chute!= '*') {
        victory();
        system("pause");
        system("cls");
    }

    admin();
    system("cls");
}
void restart(){
    play();
    system("pause");
    system("cls");
}
//==================================================================================
/*Encerra o jogo ou starta uma nova jogada.*/
void decision(){
    int op;
    printf("\n\n");
    printf("Voce deseja continuar ?\n1 - SIM  QUALQUER TECLA - NAO\n");
    scanf("%d", &op);
    if (op == 1){
        system("cls");
        restart();
    }
    else{
        printf("\nObrigado por utilizar nosso jogo!!!\n\n");
    }
}
//==================================================================================
int main(){
    play();
    decision();
    ifma();
}
