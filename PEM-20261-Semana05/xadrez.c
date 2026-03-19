#include <stdio.h>
#include <string.h>

#define TAM 8

char tabuleiro[TAM][TAM][5];

void inicializarTabuleiro() {
    int i, j;

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            strcpy(tabuleiro[i][j], " ");
        }
    }

    // pretas
    strcpy(tabuleiro[0][0], "TP");
    strcpy(tabuleiro[0][1], "CP");
    strcpy(tabuleiro[0][2], "BP");
    strcpy(tabuleiro[0][3], "DP");
    strcpy(tabuleiro[0][4], "RP");
    strcpy(tabuleiro[0][5], "BP");
    strcpy(tabuleiro[0][6], "CP");
    strcpy(tabuleiro[0][7], "TP");

    for(int j = 0; j < TAM; j++)
        strcpy(tabuleiro[1][j], "PP");

    // brancas
    strcpy(tabuleiro[7][0], "TB");
    strcpy(tabuleiro[7][1], "CB");
    strcpy(tabuleiro[7][2], "BB");
    strcpy(tabuleiro[7][3], "DB");
    strcpy(tabuleiro[7][4], "RB");
    strcpy(tabuleiro[7][5], "BB");
    strcpy(tabuleiro[7][6], "CB");
    strcpy(tabuleiro[7][7], "TB");

    for(int j = 0; j < TAM; j++)
        strcpy(tabuleiro[6][j], "PB");
}

void mostrarTabuleiro() {
    int i, j;

    printf("\n   a    b    c    d    e    f    g    h\n");
    for(i = 0; i < TAM; i++) {
        printf("%d ", 8 - i);
        for(j = 0; j < TAM; j++) {
            printf("[%3s]", tabuleiro[i][j]);
        }
        printf(" %d\n", 8 - i);
    }
    printf("   a    b    c    d    e    f    g    h\n\n");
}

void moverPeca(int li, int ci, int lf, int cf) {
    char temp[5];

    strcpy(temp, tabuleiro[li][ci]);
    strcpy(tabuleiro[li][ci], "...");
    strcpy(tabuleiro[lf][cf], temp);
}

void limparRastro() {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if(strcmp(tabuleiro[i][j], "...") == 0) {
                strcpy(tabuleiro[i][j], " ");
            }
        }
    }
}

int main() {

    inicializarTabuleiro();

    printf("=== POSICAO INICIAL ===\n");
    mostrarTabuleiro();


    printf("=== JOGADA 1 ===\n");

    moverPeca(6, 4, 4, 4);
    mostrarTabuleiro();
    limparRastro();

    moverPeca(1, 4, 3, 4);
    mostrarTabuleiro();
    limparRastro();


    printf("=== JOGADA 2 ===\n");

    moverPeca(7, 5, 4, 2);
    mostrarTabuleiro();
    limparRastro();

    moverPeca(0, 1, 2, 2);
    mostrarTabuleiro();
    limparRastro();


    printf("=== JOGADA 3 ===\n");

    moverPeca(7, 3, 3, 7);
    mostrarTabuleiro();
    limparRastro();

    moverPeca(0, 6, 2, 5);
    mostrarTabuleiro();
    limparRastro();


    printf("=== JOGADA FINAL (XEQUE MATE) ===\n");

    moverPeca(3, 7, 1, 5);
    mostrarTabuleiro();

    return 0;
}