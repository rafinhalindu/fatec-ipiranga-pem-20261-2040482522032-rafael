/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 16           *
*******************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Variaveis globais para estatisticas da Busca Recursiva
int chamadas_busca = 0;
int prof_atual_busca = 0;
int prof_max_busca = 0;

// Variaveis globais para estatisticas da Soma Recursiva
int chamadas_soma = 0;
int prof_atual_soma = 0;
int prof_max_soma = 0;

// 1. Funcao de Busca Recursiva (Varredura linear)
int buscaRec(int *v, int n, int chave) {
    chamadas_busca++;
    prof_atual_busca++;
    
    // Atualiza a profundidade maxima atingida na pilha
    if (prof_atual_busca > prof_max_busca) {
        prof_max_busca = prof_atual_busca;
    }

    // --- CASO BASE 1 ---
    // Se o tamanho do vetor chegou a zero, significa que varremos tudo e nao achamos
    if (n <= 0) {
        prof_atual_busca--; // desempilha
        return -1;
    }

    // --- CASO BASE 2 ---
    // Se o elemento da primeira posicao atual (v[0]) for a chave, achamos!
    if (v[0] == chave) {
        prof_atual_busca--; // desempilha
        return 0; // retorna indice 0 relativo a este subvetor
    }

    // --- PASSO RECURSIVO ---
    // Anda com o ponteiro do vetor para frente (v + 1) e diminui o tamanho restante (n - 1)
    int resultado = buscaRec(v + 1, n - 1, chave);

    prof_atual_busca--; // desempilha ao retornar

    // Se a busca mais a frente achou o numero (resultado diferente de -1),
    // precisamos somar 1 ao indice retornado para ajustar a posicao real no vetor original
    if (resultado != -1) {
        return resultado + 1;
    }

    return -1;
}

// 2. Funcao de Soma Recursiva por Divisao e Conquista
int somaRec(int *v, int ini, int fim) {
    chamadas_soma++;
    prof_atual_soma++;

    if (prof_atual_soma > prof_max_soma) {
        prof_max_soma = prof_atual_soma;
    }

    // --- CASO BASE ---
    // Se o inicio for igual ao fim, o intervalo tem apenas 1 elemento. Retorna ele direto.
    if (ini == fim) {
        prof_atual_soma--; // desempilha
        return v[ini];
    }

    // --- PASSO RECURSIVO ---
    // Acha o ponto do meio para quebrar o vetor em duas metades
    int meio = (ini + fim) / 2;

    // Soma recursivamente a metade esquerda (de ini ate meio)
    int soma_esquerda = somaRec(v, ini, meio);

    // Soma recursivamente a metade direita (de meio + 1 ate fim)
    int soma_direita = somaRec(v, meio + 1, fim);

    prof_atual_soma--; // desempilha ao retornar

    // Une os resultados das duas metades
    return soma_esquerda + soma_direita;
}

int main() {
    int vetor[12];
    int i, chave, indice_encontrado, soma_total;

    // Inicializa o gerador de numeros aleatorios com base no tempo atual
    srand(time(NULL));

    // Preenche o vetor com numeros aleatorios entre 1 e 50
    printf("Vetor gerado: [ ");
    for (i = 0; i < 12; i++) {
        vetor[i] = (rand() % 50) + 1;
        printf("%d ", vetor[i]);
    }
    printf("]\n\n");

    // --- Execucao da Soma ---
    soma_total = somaRec(vetor, 0, 11);
    printf("--- Estatisticas da Soma (Divisao e Conquista) ---\n");
    printf("Soma total do vetor: %d\n", soma_total);
    printf("Quantidade total de chamadas: %d\n", chamadas_soma);
    printf("Profundidade maxima atingida: %d\n\n", prof_max_soma);

    // --- Execucao da Busca ---
    printf("Digite um valor para buscar no vetor: ");
    scanf("%d", &chave);

    indice_encontrado = buscaRec(vetor, 12, chave);

    printf("\n--- Estatisticas da Busca Recursiva ---\n");
    if (indice_encontrado != -1) {
        printf("O valor %d foi encontrado no indice: %d\n", chave, indice_encontrado);
    } else {
        printf("O valor %d nao existe no vetor.\n", chave);
    }
    printf("Quantidade total de chamadas: %d\n", chamadas_busca);
    printf("Profundidade maxima atingida: %d\n", prof_max_busca);

    return 0;
}