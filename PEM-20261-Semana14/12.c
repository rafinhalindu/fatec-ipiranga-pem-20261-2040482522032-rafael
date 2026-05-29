/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 12           *
*******************************
*/

#include <stdio.h>
// Função 1: Troca os valores de duas variaveis usando uma variavel auxiliar
void troca(int *a, int *b) {
    int aux;
    aux = *a;  // guarda o valor de quem 'a' esta apontando
    *a = *b;   // 'a' recebe o valor de quem 'b' esta apontando
    *b = aux;  // 'b' recebe o valor guardado na auxiliar
}

// Função 2: Encontra o menor e o maior elemento de um vetor
// 'min' e 'max' sao ponteiros para podermos "retornar" dois valores ao mesmo tempo
void minMax(int *v, int n, int *min, int *max) {
    int i;
    
    // Inicializa o min e o max com o primeiro elemento do vetor
    *min = *v; // equivale a v[0]
    *max = *v;
    
    for (i = 1; i < n; i++) {
        if (*(v + i) > *max) {
            *max = *(v + i); // atualiza o maior valor na memoria original
        }
        if (*(v + i) < *min) {
            *min = *(v + i); // atualiza o menor valor na memoria original
        }
    }
}

// Função 3: Divide cada elemento do vetor pelo maior elemento dele
void normalizaVetor(float *v, int n) {
    int i;
    float maior = *v; // comeca assumindo que v[0] e o maior
    
    // Primeiro passo: achar o maior valor (precisa ser float)
    for (i = 1; i < n; i++) {
        if (*(v + i) > maior) {
            maior = *(v + i);
        }
    }
    
    // Segundo passo: dividir todo mundo pelo maior se ele for diferente de zero
    if (maior > 0) {
        for (i = 0; i < n; i++) {
            *(v + i) = *(v + i) / maior;
        }
    }
}

int main() {
    int i;

    // --- Testando a Função troca ---
    int x = 10, y = 20;
    printf("--- Teste da Funcao troca ---\n");
    printf("Antes: x = %d, y = %d\n", x, y);
    troca(&x, &y); // passamos o endereco (&) das variaveis
    printf("Depois: x = %d, y = %d\n", x, y);


    // --- Testando a Função minMax ---
    int vetor_int[5] = {35, 12, 89, 4, 50};
    int menor_val, maior_val;
    
    printf("\n--- Teste da Funcao minMax ---\n");
    printf("Vetor: ");
    for (i = 0; i < 5; i++) printf("%d ", vetor_int[i]);
    
    // Passamos o vetor (que ja e um ponteiro) e os enderecos de menor_val e maior_val
    minMax(vetor_int, 5, &menor_val, &maior_val);
    printf("\nDepois da funcao -> Menor: %d, Maior: %d\n", menor_val, maior_val);


    // --- Testando a Função normalizaVetor ---
    float vetor_float[4] = {2.0, 5.0, 10.0, 8.0};
    
    printf("\n--- Teste da Funcao normalizaVetor ---\n");
    printf("Antes: ");
    for (i = 0; i < 4; i++) printf("%.1f ", vetor_float[i]);
    
    normalizaVetor(vetor_float, 4);
    
    printf("\nDepois (Normalizado): ");
    for (i = 0; i < 4; i++) printf("%.2f ", vetor_float[i]);
    printf("\n");

    return 0;
}