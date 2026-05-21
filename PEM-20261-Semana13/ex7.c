/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 7            *
*******************************
*/

#include <stdio.h>
int main() {
    // Declarando o array de 8 inteiros
    int numeros[8] = {12, 45, 7, 23, 89, 34, 5, 18};
    
    // Criando o ponteiro que vai apontar para o inicio do array
    int *ptr = numeros;

    // Variaveis para guardar as estatisticas (inicializadas com o primeiro elemento)
    int soma = 0;
    int maior = *ptr; // Comeca valendo o primeiro numero: *(ptr + 0)
    int menor = *ptr; 

    printf("--- PERCURSO DO ARRAY (VIA PONTEIRO) ---\n\n");

    for (int i = 0; i < 8; i++) {
        // Pega o valor atual usando a aritmetica de ponteiros
        int valor_atual = *(ptr + i);
        
        // Pega o endereco do elemento atual
        int *endereco_atual = ptr + i;

        // Imprime o valor e o endereco correspondente na memoria
        printf("Elemento [%d] -> Valor: %2d | Endereco: %p\n", i, valor_atual, (void*)endereco_atual);

        // 1. Acumula a soma
        soma += valor_atual;

        // 2. Descobre o maior valor
        if (valor_atual > maior) {
            maior = valor_atual;
        }

        // 3. Descobre o menor valor
        if (valor_atual < menor) {
            menor = valor_atual;
        }
    }

    // Calcula a media fazendo o cast para float para nao perder as casas decimais
    float media = (float)soma / 8;

    // Exibe os resultados finais
    printf("\n--- RESULTADOS FINAIS ---\n");
    printf("Soma de todos os valores: %d\n", soma);
    printf("Media dos valores:        %.2f\n", media);
    printf("Maior valor encontrado:   %d\n", maior);
    printf("Menor valor encontrado:   %d\n", menor);

    return 0;
}