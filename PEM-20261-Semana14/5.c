/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 5            *
*******************************
*/

#include <stdio.h>
int main() {
    int i, j;
    char opcao;

    // Do-while externo para controlar se o usuario quer continuar ou nao
    do {
        
        // Laco externo 'for' controlando qual tabuada estamos multiplicando (de 1 a 10)
        for (i = 1; i <= 10; i++) {
            printf("\n--- TABUADA DO %d ---\n", i);
            
            // O laco interno precisa ser 'while', entao reiniciamos o contador 'j' aqui
            j = 1;
            while (j <= 10) {
                // O \t serve como um "Tab" para deixar o texto alinhado em colunas
                printf("%d x %d = %d\t", i, j, i * j);
                j++; // nao esquecer de incrementar o j para nao dar loop infinito
            }
            printf("\n"); // quebra de linha quando termina uma tabuada inteira
        }

        // Extensao: perguntando se deseja continuar
        printf("\nDeseja ver a tabuada de novo? (S/N): ");
        // O espaco antes do %c serve para limpar o 'enter' (\n) que ficou no buffer do teclado
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's'); // aceita S maiusculo ou minusculo

    printf("\nPrograma finalizado. Ate logo!\n");

    return 0;
}