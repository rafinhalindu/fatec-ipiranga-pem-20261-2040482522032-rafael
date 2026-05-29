/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 8            *
*******************************
*/

#include <stdio.h>
// Definindo o tamanho do vetor como pedido pelo enunciado
#define N 8

int main() {
    int vetor[N];
    int vetor_inverso[N];
    int i;
    
    // Variáveis para maior/menor e seus índices
    int maior, indice_maior;
    int menor, indice_menor;
    
    // Contadores
    int pares = 0, impares = 0;
    
    // Variáveis para a busca linear
    int valor_busca, achou = 0;

    // 1. Leitura dos dados do vetor
    printf("Digite %d numeros inteiros:\n", N);
    for (i = 0; i < N; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    // 2. Exibindo o vetor original
    printf("\nVetor original: [ ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");

    // 3. Procurando Maior, Menor, Indices e contando Pares/Impares
    // Inicializamos o maior e o menor com o primeiro elemento do vetor
    maior = vetor[0];
    indice_maior = 0;
    menor = vetor[0];
    indice_menor = 0;

    for (i = 0; i < N; i++) {
        // Testando maior
        if (vetor[i] > maior) {
            maior = vetor[i];
            indice_maior = i;
        }
        // Testando menor
        if (vetor[i] < menor) {
            menor = vetor[i];
            indice_menor = i;
        }

        // Contando pares e impares
        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    // Exibindo os resultados da analise
    printf("\nMaior valor: %d (no indice %d)", maior, indice_maior);
    printf("\nMenor valor: %d (no indice %d)", menor, indice_menor);
    printf("\nQuantidade de numeros pares: %d", pares);
    printf("\nQuantidade de numeros impares: %d\n", impares);

    // 4. Gerando o vetor em ordem inversa
    // O indice do vetor original vai de 0 ate N-1, o do inverso faz o caminho oposto
    for (i = 0; i < N; i++) {
        vetor_inverso[i] = vetor[(N - 1) - i];
    }

    // Exibindo o vetor inverso
    printf("\nVetor invertido: [ ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor_inverso[i]);
    }
    printf("]\n");

    // 5. Busca Linear
    printf("\nDigite um valor para buscar no vetor original: ");
    scanf("%d", &valor_busca);

    for (i = 0; i < N; i++) {
        if (vetor[i] == valor_busca) {
            printf("O valor %d foi encontrado no indice %d.\n", valor_busca, i);
            achou = 1; // variavel flag para avisar que encontrou
            break;     // pode parar o loop ja que achou o numero
        }
    }

    // Se passou pelo loop inteiro e a flag continuou 0, e porque nao existe
    if (achou == 0) {
        printf("O valor %d nao existe no vetor.\n", valor_busca);
    }

    return 0;
}