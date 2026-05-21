/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 08 -                 *
* Gestão de Carga em Logística*
* (Ponteiros e Vetores)       *
*******************************
*/

#include <stdio.h>
// REQ02 e REQ03: Protótipo da função usando ponteiro para o vetor
void processarCarga(float *ptr_vetor, int n);

int main() {
    // REQ01: Declaração e inicialização do vetor de pesos com 10 pacotes (em kg, por exemplo)
    float pesos[10] = {120.5, 95.0, 150.0, 88.2, 110.0, 135.8, 90.0, 145.3, 102.1, 115.4};
    int tamanho = 10;

    // REQ04: Exibir o estado do vetor ANTES do processamento
    printf("--- ESTADO INICIAL DA CARGA ---\n");
    for (int i = 0; i < tamanho; i++) {
        // Exibição usando aritmética de ponteiros para fins didáticos
        printf("Pacote %02d: %.2f kg\n", i + 1, *(pesos + i));
    }
    printf("-------------------------------\n\n");

    // Chamada da função passando o vetor (que decai para um ponteiro)
    processarCarga(pesos, tamanho);

    // REQ04: Exibir o estado do vetor APÓS o processamento
    printf("\n--- ESTADO FINAL DA CARGA (APÓS CALIBRAÇÃO) ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Pacote %02d: %.2f kg\n", i + 1, *(pesos + i));
    }
    printf("-----------------------------------------------\n");

    return 0;
}

// Implementação da função de processamento
void processarCarga(float *ptr_vetor, int n) {
    float soma = 0.0;
    float media = 0.0;

    // a. Calcular a média aritmética usando ponteiros
    for (int i = 0; i < n; i++) {
        soma += *(ptr_vetor + i); // Caminha na memória e soma o valor
    }
    media = soma / n;
    printf("[INFO] Média aritmética do lote: %.2f kg\n", media);
    printf("[INFO] Limite de tolerância (Média + 10%%): %.2f kg\n\n", media * 1.10);

    // b. Localizar pesos que excedam a média em mais de 10%
    for (int i = 0; i < n; i++) {
        // Ponteiro apontando diretamente para a posição atual do vetor
        float *ptr_atual = ptr_vetor + i; 

        if (*ptr_atual > (media * 1.10)) {
            printf("[ALERTA] Pacote %02d (%.2f kg) excedeu o limite!\n", i + 1, *ptr_atual);
            
            // c. Aplicar correção de -5% diretamente no endereço de memória
            *ptr_atual = *ptr_atual * 0.95; // Reduz em 5%
            
            printf("[CORREÇÃO] Novo valor aplicado diretamente na memória: %.2f kg\n", *ptr_atual);
        }
    }
    return 0;
}