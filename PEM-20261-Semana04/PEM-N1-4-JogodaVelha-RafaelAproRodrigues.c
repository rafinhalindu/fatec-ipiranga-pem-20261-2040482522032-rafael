//Rafael Apro Rodrigues RA: 2040482522032
//Jogo da Velha Semana 4

#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];
char player1[50], player2[50];

void inicializarMatriz(){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }
}

int eValido(char letra){
    if(letra == 'x' || letra == 'o')
        return 1;
    else
        return 0;
}

int coordenadaEhValida(int x, int y){
    if(x >= 0 && x < 3){
        if(y >= 0 && y < 3)
            return 1;
    }
    return 0;
}

int posicaoVazia(int x, int y){
    if(jogo[x][y] != 'x' && jogo[x][y] != 'o')
        return 1;
    return 0;
}

int ganhouLinhas(){
    int i, j, igual = 1;

    for (i = 0 ; i < 3; i++){
        for (j = 0; j < 2; j++){
            if(eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
                igual++;
        }

        if(igual == 3)
            return 1;

        igual = 1;
    }

    return 0;
}

int ganhouColunas(){
    int i, j, igual = 1;

    for (i = 0 ; i < 3; i++){
        for (j = 0; j < 2; j++){
            if(eValido(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
                igual++;
        }

        if(igual == 3)
            return 1;

        igual = 1;
    }

    return 0;
}

int ganhouDiagPrincipal(){

    if(eValido(jogo[0][0]) &&
       jogo[0][0] == jogo[1][1] &&
       jogo[1][1] == jogo[2][2])
        return 1;

    return 0;
}

int ganhouDiagSecundaria(){

    if(eValido(jogo[0][2]) &&
       jogo[0][2] == jogo[1][1] &&
       jogo[1][1] == jogo[2][0])
        return 1;

    return 0;
}

void imprimir(){

    int lin, col;

    printf("\n\t    0   1   2\n");

    for (lin = 0; lin < 3; lin++){

        printf("\t%d ", lin);

        for (col = 0; col < 3; col++){

            if(eValido(jogo[lin][col]))
                printf(" %c ", jogo[lin][col]);
            else
                printf("   ");

            if(col < 2)
                printf("|");
        }

        if(lin < 2)
            printf("\n\t   -----------\n");
    }

    printf("\n");
}

void jogar(){

    int x, y;
    int valida;
    int jogadas = 0;
    int ganhou = 0;
    int ordem = 1;

    do{

        do{

            imprimir();

            printf("\nDigite a coordenada (linha coluna): ");
            scanf("%d %d", &x, &y);

            valida = coordenadaEhValida(x,y);

            if(valida == 1)
                valida += posicaoVazia(x,y);

            if(valida != 2)
                printf("\nPosicao invalida! Tente novamente.\n");

        }while(valida != 2);

        if(ordem == 1){
            jogo[x][y] = 'x';
            printf("\nJogada de %s\n", player1);
        }
        else{
            jogo[x][y] = 'o';
            printf("\nJogada de %s\n", player2);
        }

        jogadas++;

        ordem++;

        if(ordem == 3)
            ordem = 1;

        ganhou += ganhouLinhas();
        ganhou += ganhouColunas();
        ganhou += ganhouDiagPrincipal();
        ganhou += ganhouDiagSecundaria();

    }while(ganhou == 0 && jogadas < 9);

    imprimir();

    if(ganhou != 0){

        if(ordem - 1 == 1)
            printf("\nParabens %s, voce venceu!\n", player1);
        else
            printf("\nParabens %s, voce venceu!\n", player2);

    }
    else{

        printf("\nEmpate! Ninguem venceu.\n");

    }
}

int main(){

    printf("Digite o nome do Jogador 1 (X): ");
    scanf("%s", player1);

    printf("Digite o nome do Jogador 2 (O): ");
    scanf("%s", player2);

    inicializarMatriz();

    jogar();

    return 0;
}