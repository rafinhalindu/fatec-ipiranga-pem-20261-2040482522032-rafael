/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 10           *
*******************************
*/

#include <stdio.h>
// Função 1: Apenas imprime o tabuleiro como uma grade/tabela
void exibirTabuleiro(int matriz[4][4]) {
    int i, j;
    printf("\n--- TABULEIRO (4x4) ---\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n"); // quebra de linha ao fim de cada fileira
    }
}

// Função 2: Calcula e mostra as duas diagonais
void mostrarDiagonais(int matriz[4][4]) {
    int i;
    
    printf("\nDiagonal Principal: ");
    for (i = 0; i < 4; i++) {
        // Na principal, a linha e igual a coluna (0,0), (1,1)...
        printf("%d ", matriz[i][i]);
    }
    
    printf("\nDiagonal Secundaria: ");
    for (i = 0; i < 4; i++) {
        // Na secundaria, a coluna faz o caminho inverso: (0,3), (1,2), (2,1), (3,0)
        printf("%d ", matriz[i][3 - i]);
    }
    printf("\n");
}

// Função 3: Verifica se a matriz é simétrica (matriz transposta é igual a original)
int verificarSimetria(int matriz[4][4]) {
    int i, j;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            // Se o elemento da linha X coluna Y for diferente de coluna Y linha X, nao e simetrico
            if (matriz[i][j] != matriz[j][i]) {
                return 0; // Retorna falso (0) imediatamente e sai da funcao
            }
        }
    }
    return 1; // Se testou tudo e nao achou erro, retorna verdadeiro (1)
}

int main() {
    // Tabuleiro preenchido manualmente de forma simetrica para teste
    // Repare que o par do '2' em (0,1) esta em (1,0), o do '5' em (0,2) esta em (2,0)...
    int tabuleiro[4][4] = {
        {1, 2, 5, 6},
        {2, 3, 4, 7},
        {5, 4, 8, 8},
        {6, 7, 8, 1}
    };

    // Chamando as funcoes criadas
    exibirTabuleiro(tabuleiro);
    mostrarDiagonais(tabuleiro);

    // Verificando a simetria com base no retorno da funcao
    if (verificarSimetria(tabuleiro) == 1) {
        printf("\nResultado: Todos os pares estao em posicoes simetricas em relacao a diagonal principal!\n");
    } else {
        printf("\nResultado: Os pares NAO estao em posicoes simetricas.\n");
    }

    return 0;
}