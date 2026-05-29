/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 15           *
*******************************
*/

#include <stdio.h>
// Variavel global para contar os movimentos (fácil de acessar em qualquer lugar)
int total_movimentos = 0;

// Funcao recursiva para resolver a Torre de Hanoi
void hanoi(int n, char origem, char destino, char auxiliar) {
    
    // --- CASO BASE ---
    // Se so restar 1 disco, basta mover direto da origem para o destino
    if (n == 1) {
        printf("Mova disco 1 de %c para %c\n", origem, destino);
        total_movimentos++;
        return; // encerra esta chamada na pilha
    }

    // --- PASSO RECURSIVO ---
    // 1. Move os n-1 discos de cima da Origem para o Auxiliar (usando o Destino como apoio)
    hanoi(n - 1, origem, auxiliar, destino);

    // 2. Move o disco maior (o que sobrou) da Origem para o Destino
    printf("Mova disco %d de %c para %c\n", n, origem, destino);
    total_movimentos++;

    // 3. Move os n-1 discos que estavam no Auxiliar para o Destino (usando a Origem como apoio)
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;
    int formula_calculada = 1;
    int i;

    printf("Digite o numero de discos (1 a 10): ");
    scanf("%d", &n);

    // Validacao de entrada simples como o enunciado pediu
    if (n < 1 || n > 10) {
        printf("Erro: Numero de discos invalido. Digite um valor entre 1 e 10.\n");
    } else {
        printf("\n--- Passos para resolver a Torre de Hanoi ---\n");
        
        // Chamada inicial da funcao passando as torres como caracteres 'A', 'C' e 'B'
        hanoi(n, 'A', 'C', 'B');

        // Calculando 2^n - 1 de forma manual (sem usar a math.h)
        for (i = 0; i < n; i++) {
            formula_calculada = formula_calculada * 2;
        }
        formula_calculada = formula_calculada - 1;

        // Analise obrigatoria dos resultados
        printf("\n--- Analise Final ---\n");
        printf("Total de movimentos realizados na pratica: %d\n", total_movimentos);
        printf("Resultado previsto pela formula (2^n - 1): %d\n", formula_calculada);

        if (total_movimentos == formula_calculada) {
            printf("Sucesso: O numero de movimentos coincide perfeitamente com a teoria!\n");
        } else {
            printf("Aviso: Houve alguma divergencia no calculo.\n");
        }
    }

    return 0;
}