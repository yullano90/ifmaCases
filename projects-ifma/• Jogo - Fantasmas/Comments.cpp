#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
//--------------------------------------------------------------------------------------------------------------------
  int main(){
    void play();
    play();
  }
//--------------------------------------------------------------------------------------------------------------------
//Declaração das constantes do nosso jogo, via diretiva de pré-processador.
#define ArenaFacil 1      //Corresponde a uma matriz de 01 fantasma;
#define ArenaDificil 4    //Corresponde a uma matriz de 04 fantasmas;
//--------------------------------------------------------------------------------------------------------------------
//Comparação do nível de dificuldade do usuário com a diretiva correspondente.
  int nivel(void){
      int nivel= 0, dificuldade= 0;
      do{ printf("\n\n\n");
          printf("EM QUAL ARENA DESEJA JOGAR?:\n (1)FACIL (2)DIFICIL\n");
          fflush(stdin);
          scanf("%d",&nivel);
          system("cls");
      } while (nivel!= 1 && nivel!= 2);
      if(nivel==1){dificuldade = ArenaFacil;}
      if(nivel==2){dificuldade = ArenaDificil;}
    return (dificuldade);
  }
//--------------------------------------------------------------------------------------------------------------------
//Apresentação do Splash do nosso jogo.
  void infoI(){
      printf("\n===================================================================");
      printf("\nINSTITUTO FEDERAL DO MARANHAO - SISTEMAS DE INFORMACAO #MELHORCURSO");
      printf("\nPROGRAMADORES: IULANO SANTOS && JAILSON SOARES");
      printf("\nPROF. DRA. EVALDINOLIA MOREIRA GILBERTONI");
      printf("\nDISCIPLINA: LINGUAGEM DE PROGRAMACAO");
      printf("\nBEM VINDO AO FOGE-FOGE, BOA SORTE! :) ");
      printf("\n===================================================================\n\n");
      printf(":. PRESSIONE ENTER PARA AVANCAR .:");
      getchar();
      system("cls");
  }
  //--------------------------------------------------------------------------------------------------------------------
//Apresentação das regras do jogo.
  void infoII(){
      printf("\n===================================================================");
      printf("\n* NOSSO JOGO CONSISTE EM UMA MATRIZ QUE REPRESENTA SEU PASSEIO:");
      printf("\n* DURANTE O PERCURSO VOCE PRECISA ESCAPAR DOS FANTASMAS:");
      printf("\n* SE ALGUM FANTASMA ENCONSTAR EM VOCE = GAMEOVER!!!");
      printf("\n* CUIDADO, OS FANTASMAS ANDAM DE FORMA ALEATORIA");
      printf("\n* MAS CALMA AI! VOCE TEM UM TRUQUE NA MANGA:");
      printf("\n* UMA PILULA MAGICA PARA EXPLODIR TODOS ELES!");
      printf("\n===================================================================\n\n");
      printf(":. PRESSIONE ENTER PARA AVANCAR .:");
      getchar();
      system("cls");
  }
//--------------------------------------------------------------------------------------------------------------------
//Invocada sempre que o herói encontrar a PÍLULA, e assim explodir todos os fantasmas!
  void venceu(){
      printf("\n");
      printf("\n==========================================================");
      printf("\n|                   PARABENS(A)!!!                       |");
      printf("\n|                   VOCE VENCEU!!!                       |");
      printf("\n==========================================================\n");
      printf("\n");
      printf(":. PRESSIONE ENTER PARA AVANCAR .:");
      getchar();
      system("cls");
  }
//--------------------------------------------------------------------------------------------------------------------
//Invocada sempre que algum fantasma tocar no nosso herói.
  void perdeu(){
      printf("\n");
      printf("\n==========================================================");
      printf("\n|                   VOCE PERDEU        :(                |");
      printf("\n|                   TENTE NOVAMENTE!                     |");
      printf("\n==========================================================");
      printf("\n");
      printf(":. PRESSIONE ENTER PARA AVANCAR .:");
      getchar();
      system("cls");
  }
//--------------------------------------------------------------------------------------------------------------------
//Seleção do nivel do jogo e navegação do usuário na arena.
//Aplicação dos conhecimentos em manipulação de arquivos.
  int start(){
      int operador;
      char arena[20][40];
      infoI();
      infoII();
      FILE* f;
      int dificuldade = nivel();
      while (dificuldade!= 1 && dificuldade!= 2);
          if(dificuldade == 1){
              f = fopen("Arena_Facil.txt","r");
              printf("\n\nBEM VINDO A ARENA FACIL, CUIDADO COM O PERSEGUIDOR!\n");
              printf("EVITE SE APROXIMAR DO GUARDIAO E FOCO NA PILULA!\n");
              printf("(C) = VOCE,(F) =  FANTASMA , (O) = PILULA!\n");

              printf("\n");
                  if(f == 0){
                      printf("ERRO NO CARREGAMENTO DA ARENA");
                      exit(1);
                  }
            }
          if(dificuldade == 2){
              f = fopen("Arena_Dificil.txt","r");
              printf("\n\nBEM VINDO A ARENA DIFICL, CUIDADO COM OS OBSTACULOS\n");
              printf("EVITE SE APROXIMAR DO GUARDIAO E FOCO NA PILULA!\n");
              printf("(C) = VOCE,(F) =  FANTASMA , (O) = PILULA!\n");
              printf("\n");
                  if(f == 0){
                      printf("ERRO NO CARREGAMENTO DA ARENA");
                      exit(1);
                  }
            }
      int i, j, a, b;
      while(!feof(f)){
          for( i=0;i<10;i++){
              for( j=0;j<41;j++){
                  fscanf(f,"%c",&arena[i][j]);
              }
          }
      }
      for( a=0;a<10;a++){
          for( b=0;b<41;b++){
              printf("%c",arena[a][b]);
          }
          printf("\n");
      }
    fclose(f);
    printf("\n");
    system("pause");
    system("cls");
    return dificuldade;
  }
//--------------------------------------------------------------------------------------------------------------------
  void Imprime_Arena(int dim, int *Pontos, int jog_x, int jog_y, int fant_x, int fant_y, char **M){
    int i, j;
    /*Recebe posição do jogador*/
    M[jog_y][jog_x] = 'C';
    M[fant_y][fant_x] = 'F';
    system("cls");
    printf("\n  A TECLA CAPSLOOK PRECISA ESTAR DESATIVADA!\n");
    printf("\n  W - CIMA, S - BAIXO, A - ESQUERDA, D - DIREITA.\n");
    for(i = 0; i< dim; i++)
    {
        printf("\n");
        for(j = 0 ; j<dim; j++)
            printf(" %c",M[i][j]);
    }
    printf("\nSCORECARD: %d",(*Pontos));
  }
//--------------------------------------------------------------------------------------------------------------------
//Os parâmetros de posições e de pontos, passamos como referência:
  void movimentos_C(char **M, int *posX, int *posY, char controle, int *Pontos){
    if(controle == 'a' ){
        if(M[(*posY)][(*posX)-1] == '|'){        //Verificando se a posição à esquerda é uma parede;
            /*NAO ACONTECE NADA COM A ARENA*/
        }
        else{
            if(M[(*posY)][(*posX)-1] == '.')    //Verificando se a posição à esquerda é '.'
                (*Pontos)++;                    //Se sim, incrementa 1 ponto no score;
            M[(*posY)][(*posX)] = ' ';
            (*posX) = (*posX) - 1;
            M[(*posY)][(*posX)] = 'C';
        }
    }
    if(controle == 'd' ){
        if(M[(*posY)][(*posX)+1] == '|'){
            /*NAO ACONTECE NADA COM A ARENA*/
        }
        else{
            if(M[(*posY)][(*posX)+1] == '.')
                (*Pontos)++;
            M[(*posY)][(*posX)] = ' ';
            (*posX) = (*posX) + 1;
            M[(*posY)][(*posX)] = 'C';
        }
    }
    if(controle == 'w' ){
        if(M[(*posY)-1][(*posX)] == '|')
        {
            /*NAO ACONTECE NADA COM A ARENA*/
        }
        else
        {
            if(M[(*posY)-1][(*posX)] == '.')
                (*Pontos)++;
            M[(*posY)][(*posX)] = ' ';
            (*posY) = (*posY) - 1;
            M[(*posY)][(*posX)] = 'C';
        }
    }
    if(controle == 's' ){
        if(M[(*posY)+1][(*posX)] == '|')
        {
            /*NAO ACONTECE NADA COM A ARENA*/
        }
        else
        {
            if(M[(*posY)+1][(*posX)] == '.')
                (*Pontos)++;
            M[(*posY)][(*posX)] = ' ';
            (*posY) = (*posY) + 1;
            M[(*posY)][(*posX)] = 'C';
        }
    }
  }
//--------------------------------------------------------------------------------------------------------------------
/*Aplicação dos conhecimentos de Alocação Dinâmica*/
  char** Constroe_Arena(int dim){
    int i, j;
    char **M;
    M = (char**) malloc(dim *sizeof(char*));        //Alocação de uma dimensão da ARENA
    for(i = 0; i < dim; i++){
        M[i] = (char*) malloc(dim *sizeof(char));  //Alocação da segunda dimensão da ARENA
        for(j = 0; j < dim; j++){
            /*Construção da Arena*/
            if(i == 0 || i == (dim-1) || j == 0 || j == (dim-1) )
                M[i][j] = '|';
            else{
                M[i][j] = '.';
            }
        }
    }
    return M;
  }
  //--------------------------------------------------------------------------------------------------------------------
  int Dist_Fant(int X, int Y, int x, int y){
    return int (sqrt(pow(X-x,6) + pow(Y-y,12)));
  }
  //--------------------------------------------------------------------------------------------------------------------
 void movimentos_F(char **M, char *AF, int *PX, int *PY, int *AFX, int *AFY, int *LF){

   /* AF POSICAO ATUAL DO FANTASMA.
      PX POSICAO DO FANTASMA NA HORIZONTAL
      PY POSICAO DO FANTASMA NA VERTICAL
      AFX MOVIMENTO ANTERIOR NA HORIZONTAL
      AFY MOVIMENTO ANTERIOR NA VERTICAL
      LF VIDA DO FANTASMA */

    int i, j, DM;
    int PMX, PMY;

    DM = Dist_Fant((*AFX),(*AFY),(*PX),(*PY));
    PMX = (*AFX) ;
    PMY = (*AFY);
    if((M[(*AFY)][(*AFX) - 1] != '|') && (Dist_Fant(((*AFX)-1),(*AFY),(*PX),(*PY)) < DM)){
        PMX = ((*AFX) - 1) ;
        PMY = (*AFY);
    }
    if((M[(*AFY)][(*AFX) + 1] != '|') && (Dist_Fant(((*AFX)+1),(*AFY),(*PX),(*PY)) < DM)){
        PMX = ((*AFX) + 1) ;
        PMY = (*AFY);
    }
    if((M[((*AFY) - 1)][(*AFX)] != '|') && (Dist_Fant((*AFX),((*AFY)-1),(*PX),(*PY)) < DM)){
        PMX = (*AFX);
        PMY = ((*AFY) - 1);
    }
    if((M[((*AFY) + 1)][(*AFX)] != '|') && (Dist_Fant((*AFX),((*AFY)+1),(*PX),(*PY)) < DM)){
        PMX = (*AFX);
        PMY = ((*AFY) + 1);
    }
    if((*AFX) == PMX && ((*AFY) == PMY)){
        if( pow( ((*AFX)-1) - (*PX) ,2) < pow( ((*AFX) - (*PX)) ,2)  && M[(*AFY)][(*AFX)-1] != '|' )
            PMX = (*AFX)-1;
        else if( pow( ((*AFX)+1) - (*PX), 2) < pow( ((*AFX) - (*PX)), 2) && M[(*AFY)][(*AFX)+1]!= '|' )
            PMX = (*AFX)+1;
        if( pow( ((*AFY)-1) - (*PY) ,2) < pow( ((*AFY) - (*PY)) ,2) && M[(*AFY)-1][(*AFX)]!= '|' )
            PMY = (*AFY)-1;
        else if( pow( ((*AFY)+1) - (*PY), 2) < pow( ((*AFY) - (*PY)), 2) && M[(*AFY)+1][(*AFX)]!= '|' )
            PMY = (*AFY)+1;
    }

    if((*AF) == ' ')
        M[(*AFY)][(*AFX)] = ' ';
    if((*AF) == '.')
        M[(*AFY)][(*AFX)] = '.';
    if((*AF) == '|')
        M[(*AFY)][(*AFX)] = '|';
    (*AFX) = PMX;
    (*AFY) = PMY;
    (*AF) = M[(*AFY)][(*AFX)];
    if((*AFY) == (*PY) && (*AFX)== (*PX))
        (*LF) = 0;


        if(*LF == 0){
            system("cls");
            perdeu();
        }

        if(M[3][3] == 'C'){
        (*LF) = 0;
            if(*LF == 0){
            system("cls");
            venceu();
        }
    }

         if(M[1][2] == 'C'){
        (*LF) = 0;
            if(*LF == 0){
            system("cls");
            perdeu();
        }
    }
}

  //--------------------------------------------------------------------------------------------------------------------
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
      getchar();
  }
  //-------------------------------------------------------------------------------------
  /*Encerra o jogo ou starta uma nova jogada.*/
  void restart(){
      int operador;
      printf("\n\n");
      printf("DESEJA CONTINUAR ?\n1 - SIM  QUALQUER TECLA - NAO\n");
      scanf("%d", &operador);
      if (operador == 1){
          system("cls");
          int main();
              main();
      }
      else{
          system("cls");
          printf("\nOBRIGADO POR UTILIZAR O NOSSO JOGO!!!\n\n");
          ifma();
      }
  }
//--------------------------------------------------------------------------------------------------------------------

  int play (){
    int i, j, dim = 20, Pontos_Maximos = 2, vida = 1, Pontos = 0, nivelcorresp;
    int posX = 1, posY = 18, fantposX = 9, fantposY = 11 ;
    char **M, ant_fant = ' ', controle;
    void obstaculosI(char **M);
    void obstaculosII(char **M);
    M = Constroe_Arena(dim);
    nivelcorresp = start();
    if(nivelcorresp == 1){
    //void obstaculosI(**M);
    obstaculosI(M);}

    if(nivelcorresp == 2){
    //void obstaculosII(**M);
    obstaculosII(M);}

    Imprime_Arena(dim,&Pontos,posX,posY,fantposX,fantposY,M);
    while(vida == 1){
        controle = getch();
        if(controle == 'a' || controle == 'd' || controle == 's' || controle == 'w')
        {
            movimentos_C(M,&posX,&posY,controle,&Pontos);
            movimentos_F(M,&ant_fant,&posX,&posY, &fantposX, &fantposY, &vida);
            Imprime_Arena(dim,&Pontos,posX,posY,fantposX,fantposY,M);
        }
    }
    restart();
  }
  //--------------------------------------------------------------------------------------------------------------------
    void obstaculosI(char **M){

    M[1][2] = 'F'; M[1][18] = '.'; M[11][9] = 'O'; M[11][10] = '.';
    M[3][3] = 'O'; M[3][4] = '.'; M[4][2] = '.'; M[4][3] = '.';
}

  void obstaculosII(char **M){

    M[1][2] = 'F'; M[1][18] = ' '; M[11][9] = 'O'; M[11][10] = ' ';

    M[2][2] = '|'; M[2][3] = '|'; M[2][4] = '|'; M[3][2] = '|';
    M[3][3] = 'O'; M[3][4] = ' '; M[4][2] = '|'; M[4][3] = '.';
    M[4][4] = '|'; M[5][2] = '|'; M[5][3] = '|'; M[5][4] = '|';
    M[2][6] = '|'; M[3][6] = '.'; M[4][6] = '|'; M[5][6] = '|';
    M[2][7] = '|'; M[3][7] = '.'; M[4][7] = '|'; M[5][7] = '|';
    M[2][12] = '|'; M[3][12] = '|'; M[4][12] = '|'; M[5][12] = '|';
    M[2][13] = '|'; M[3][13] = '|'; M[4][13] = '|'; M[5][13] = '|';
    M[2][15] = '|'; M[2][16] = '|'; M[2][17] = '|'; M[3][15] = '|';
    M[3][16] = '.'; M[3][17] = '|'; M[4][15] = '|'; M[4][16] = '.';
    M[4][17] = '|'; M[5][15] = '|'; M[5][16] = '|'; M[5][17] = '|';
    M[1][9] = '|'; M[2][9] = '|'; M[3][9] = '|'; M[4][9] = '|';
    M[5][9] = '|'; M[1][10] = '|'; M[2][10] = '|'; M[3][10] = '|';
    M[4][10] = '|'; M[5][10] = '|'; M[7][1] = '|'; M[7][2] = '|';
    M[7][3] = '|'; M[8][1] = '|'; M[9][3] = '|'; M[10][2] = '|';
    M[10][3] = '|'; M[11][3] = '|'; M[12][1] = '|'; M[13][1] = '|';
    M[13][2] = '|'; M[13][3] = '|'; M[12][7] = '|'; M[12][12] = '|';
    M[7][16] = '|'; M[7][17] = '|'; M[7][18] = '|'; M[8][18] = '|';
    M[9][16] = '|'; M[10][16] = '|'; M[10][17] = '|'; M[11][16] = '|';
    M[12][18] = '|'; M[13][18] = '|'; M[13][17] = '|'; M[13][16] = '|';
    M[7][5] = '|'; M[8][5] = '|'; M[9][5] = '|'; M[10][5] = '|';
    M[11][5] = '|'; M[12][5] = '|'; M[9][6] = '|'; M[9][7] = '|';
    M[10][6] = '|'; M[10][7] = '|'; M[7][14] = '|'; M[8][14] = '|';
    M[9][14] = '|'; M[10][14] = '|'; M[11][14] = '|'; M[12][14] = '|';
    M[9][13] = '|'; M[9][12] = '|'; M[10][13] = '|'; M[10][12] = '|';
    M[7][7] = '|'; M[7][8] = '|'; M[7][9] = '|'; M[7][10] = '|';
    M[7][11] = '|'; M[7][12] = '|'; M[8][9] = '|'; M[8][10] = '|';
    M[9][9] = '|'; M[9][10] = '|'; M[14][7] = '|'; M[14][8] = '|';
    M[14][9] = '|'; M[14][10] = '|'; M[14][11] = '|'; M[14][12] = '|';
    M[13][9] = '|'; M[13][10] = '|'; M[12][9] = '|'; M[12][10] = '|';
    M[15][2] = '|'; M[15][3] = '.'; M[15][4] = '|'; M[16][2] = '|';
    M[16][3] = '.'; M[16][4] = '|'; M[17][2] = '.'; M[17][3] = '|';
    M[17][4] = '|'; M[14][5] = '|'; M[15][5] = '|'; M[16][5] = '.';
    M[17][5] = '|'; M[15][15] = '|'; M[15][16] = '|'; M[15][17] = '|';
    M[16][15] = ' '; M[16][16] = ' '; M[16][17] = '|'; M[17][15] = '|';
    M[17][16] = '|'; M[17][17] = '|'; M[14][14] = '|'; M[15][14] = '|';
    M[16][14] = '|'; M[17][14] = '|'; M[16][7] = '|'; M[17][7] = '|';
    M[16][12] = '|'; M[17][12] = '|'; M[16][9] = '|'; M[17][9] = '|';
    M[18][9] = '|'; M[16][10] = '|'; M[17][10] = '|'; M[18][10] = '|';
}