/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 11           *
*******************************
*/

#include <stdio.h>
int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int *p = vetor; // aponta para o primeiro elemento (vetor[0])
    int i;
    int soma = 0;

    printf("--- 1. Imprimindo Elementos e Enderecos ---\n");
    for (i = 0; i < 6; i++) {
        // *(p + i) acessa o valor e (p + i) acessa o endereco de memoria
        printf("Elemento: %d\tEndereco: %p\n", *(p + i), (void*)(p + i));
    }

    printf("\n--- 2. Calculando a Soma ---\n");
    for (i = 0; i < 6; i++) {
        soma = soma + *(p + i); // acumula o valor apontado
    }
    printf("Soma total dos elementos: %d\n", soma);

    printf("\n--- 3. Dobrando os Valores In-Place ---\n");
    for (i = 0; i < 6; i++) {
        // altera o valor direto na memoria usando a desreferenciacao
        *(p + i) = *(p + i) * 2;
    }
    
    // Mostrando o vetor alterado para provar que funcionou
    printf("Vetor apos dobrar os valores:\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    printf("\n--- 4. Confirmando a diferenca de sizeof(int) ---\n");
    // Mostrando a diferenca pratica pegando o endereco do segundo elemento menos o primeiro
    printf("Endereco do elemento 0: %p\n", (void*)(p));
    printf("Endereco do elemento 1: %p\n", (void*)(p + 1));
    printf("Tamanho de um int neste sistema (sizeof): %lu bytes\n", sizeof(int));
    printf("Nota: Na aritmetica de ponteiros, fazer 'p + 1' desloca o ponteiro em exatamente %lu bytes na memoria!\n", sizeof(int));

    return 0;
}