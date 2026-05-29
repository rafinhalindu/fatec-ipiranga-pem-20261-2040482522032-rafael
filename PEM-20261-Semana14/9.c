/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 9            *
*******************************
*/

#include <stdio.h>
int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;

    // 1. Leitura da Matriz A
    printf("Digite os elementos da Matriz A (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // 2. Leitura da Matriz B
    printf("\nDigite os elementos da Matriz B (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // 3. Cálculo do Produto Matricial (C = A x B)
    // O loop triplo funciona exatamente como a definicao algebrica:
    // 'i' representa a linha atual da Matriz A e da Matriz C
    for (i = 0; i < 3; i++) {
        // 'j' representa a coluna atual da Matriz B e da Matriz C
        for (j = 0; j < 3; j++) {
            
            // Antes de somar as multiplicacoes, precisamos zerar a posicao atual de C
            C[i][j] = 0;
            
            // 'k' e o indice do somatorio (o "meio" da operacao). 
            // Ele caminha pelas colunas de A enquanto caminha pelas linhas de B ao mesmo tempo
            for (k = 0; k < 3; k++) {
                // Algebricamente: C[i][j] = soma de (A[i][k] * B[k][j])
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }

    // 4. Exibindo os resultados de forma alinhada com \t
    printf("\n--- MATRIZ A ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\n--- MATRIZ B ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    printf("\n--- MATRIZ C (A x B) ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}