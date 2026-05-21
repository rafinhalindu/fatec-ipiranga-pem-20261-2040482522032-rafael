/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 12           *
*******************************
*/

#include <stdio.h>
// Funcao auxiliar para trocar os valores de lugar usando ponteiros
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao para imprimir o array usando apenas ponteiros
void imprimirArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Algoritmo Selection Sort puramente com aritmetica de ponteiros
void selectionSort(int *arr, int n) {
    int contador_trocas = 1;

    // O primeiro laco vai ate o penultimo elemento
    for (int i = 0; i < n - 1; i++) {
        // Assume que o menor elemento atual esta na posicao 'i'
        int *p_menor = arr + i; 

        // O segundo laco procura se existe alguem menor ainda para a frente
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *p_menor) {
                p_menor = arr + j; // Atualiza o ponteiro do menor encontrado
            }
        }

        // Se o menor elemento nao for o que ja estava na posicao 'i', faz a troca
        if (p_menor != (arr + i)) {
            trocar(arr + i, p_menor);
            
            // Mostra o estado do array durante a ordenacao (a cada troca)
            printf("Troca %d: ", contador_trocas++);
            imprimirArray(arr, n);
        }
    }
}

int main() {
    // Array de 8 inteiros desordenados
    int dados[8] = {45, 7, 23, 89, 12, 5, 34, 18};
    int tamanho = 8;

    printf("--- ESTADO INICIAL (ANTES) ---\n");
    imprimirArray(dados, tamanho);
    printf("\n");

    printf("--- DURANTE A ORDENACAO (A CADA TROCA) ---\n");
    selectionSort(dados, tamanho);
    printf("\n");

    printf("--- ESTADO FINAL (DEPOIS) ---\n");
    imprimirArray(dados, tamanho);

    return 0;
}