/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 3            *
*******************************
*/

#include <stdio.h>
// Funcao que recebe os enderecos de memoria das variaveis
void trocar(int *a, int *b) {
    int temp; // Variavel temporaria para nao perder o valor durante a troca

    temp = *a; // temp guarda o valor de onde 'a' aponta
    *a = *b;   // o lugar onde 'a' aponta recebe o valor de onde 'b' aponta
    *b = temp; // o lugar onde 'b' aponta recebe o valor que estava salvo em temp
}

int main() {
    int x = 10;
    int y = 20;

    printf("--- ANTES DA TROCA ---\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    // Chamando a funcao e usando o operador '&' para passar o ENDERECO delas
    trocar(&x, &y);

    printf("\n--- DEPOIS DA TROCA ---\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}