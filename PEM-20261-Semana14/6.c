/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 6            *
*******************************
*/

#include <stdio.h>
int main() {
    int n;
    int passos = 0; // contador de passos, começa em zero

    // Controle de entrada: fica preso no loop se o numero for menor ou igual a zero
    printf("Digite um inteiro positivo para iniciar a Sequencia de Collatz: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Erro: O valor deve ser um inteiro positivo maior que zero!\n");
    } else {
        printf("\nSequencia gerada: %d", n);

        // O laco continua ate o numero virar 1, como diz a conjectura
        while (n != 1) {
            
            // se o resto da divisao por 2 for zero, ele e par
            if (n % 2 == 0) {
                n = n / 2;
            } 
            // se nao, e impar
            else {
                n = 3 * n + 1;
            }

            // imprime o proximo numero da sequencia na mesma linha
            printf(" -> %d", n);
            
            // conta que mais um passo foi dado
            passos++;
        }

        // mostra o total de passos que demorou para chegar no 1
        printf("\n\nNumero de passos necessarios: %d\n", passos);
    }

    return 0;
}