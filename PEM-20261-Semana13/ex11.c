/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 11           *
*******************************
*/

#include <stdio.h>
// Funcao que calcula tudo e joga os resultados direto nos ponteiros
void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor) {
    // Inicializa a soma zerada
    *soma = 0;
    
    // Inicializa o maior e o menor com o primeiro elemento do array (*v e o mesmo que v[0])
    *maior = *v;
    *menor = *v;

    // Percorre o array para calcular os dados
    for (int i = 0; i < n; i++) {
        int valor_atual = *(v + i); // Usando aritmetica de ponteiros para pegar o valor

        // Somando o valor atual
        *soma += valor_atual;

        // Atualizando o maior valor, se necessario
        if (valor_atual > *maior) {
            *maior = valor_atual;
        }

        // Atualizando o menor valor, se necessario
        if (valor_atual < *menor) {
            *menor = valor_atual;
        }
    }

    // Calcula a media jogando o resultado dentro do ponteiro da media
    // O (float) serve para nao perder as casas decimais na divisao
    *media = (float)(*soma) / n;
}

int main() {
    // Array de 6 elementos como o enunciado pediu
    int dados[6] = {15, 42, 8, 23, 91, 16};
    int tamanho = 6;

    // Variaveis normais na main que vao receber os resultados da funcao
    int minha_soma;
    float minha_media;
    int meu_maior;
    int meu_menor;

    // Chamando a funcao e passando o '&' para ela saber onde alterar na memoria
    estatisticas(dados, tamanho, &minha_soma, &minha_media, &meu_maior, &meu_menor);

    // Mostrando os resultados finais obtidos
    printf("--- RESULTADOS DAS ESTATISTICAS ---\n");
    printf("Soma total: %d\n", minha_soma);
    printf("Media:      %.2f\n", minha_media);
    printf("Maior:      %d\n", meu_maior);
    printf("Menor:      %d\n", meu_menor);

    return 0;
}