/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 5            *
*******************************
*/

#include <stdio.h>
int main() {
    // Criando o vetor de 5 posicoes com valores quaisquer
    int vetor[5] = {2, 5, 8, 11, 14};
    
    // Criando o ponteiro. Lembra que o nome do vetor ja e o endereco do primeiro elemento dele!
    int *ptr = vetor; 

    // 1 - Mostrando o vetor antes de mexer nele
    printf("--- VETOR ANTES ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Posicao %d: %d\n", i, vetor[i]); // Aqui usa [] so pra printar normal
    }

    // 2 - Multiplicando cada elemento por 2 usando APENAS ponteiros
    // Reseta o ponteiro pro inicio do vetor (boa pratica)
    ptr = vetor; 
    
    for (int i = 0; i < 5; i++) {
        // *(ptr + i) vai direto na gaveta da memoria de cada posicao
        *(ptr + i) = *(ptr + i) * 2; 
    }

    // 3 - Mostrando o vetor depois da operacao
    printf("\n--- VETOR DEPOIS (MULTIPLICADO POR 2) ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Posicao %d: %d\n", i, vetor[i]);
    }

    return 0;
}