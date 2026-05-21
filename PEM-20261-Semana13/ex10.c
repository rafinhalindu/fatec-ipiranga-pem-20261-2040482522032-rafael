/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 10           *
*******************************
*/

#include <stdio.h>

// Funcao que inverte o array usando dois ponteiros que se aproximam
void inverter(int *arr, int n) {
    // Ponteiro 'inicio' aponta para o primeiro elemento (indice 0)
    int *inicio = arr;
    
    // Ponteiro 'fim' aponta para o ultimo elemento (indice n - 1)
    int *fim = arr + (n - 1);
    
    int temp; // Variavel auxiliar para fazer a troca de valores

    // O laco roda enquanto os ponteiros nao se cruzarem no meio do array
    while (inicio < fim) {
        // Troca os valores apontados por 'inicio' e 'fim'
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        // Move os ponteiros: 'inicio' vai pra frente e 'fim' vai pra tras
        inicio++;
        fim--;
    }
}

int main() {
    // Criando o array de 7 elementos solicitado
    int meu_array[7] = {10, 20, 30, 40, 50, 60, 70};
    int tamanho = 7;

    // 1. Mostra o array original
    printf("--- ANTES DA INVERSAO ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", meu_array[i]);
    }
    printf("\n\n");

    // Chama a funcao passando o array e o tamanho dele
    inverter(meu_array, tamanho);

    // 2. Mostra o array modificado
    printf("--- DEPOIS DA INVERSAO ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", meu_array[i]);
    }
    printf("\n");

    return 0;
}