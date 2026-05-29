/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 7            *
*******************************
*/

#include <stdio.h>
int main() {
    float vetor[10];
    float soma = 0, media = 0;
    float maior, menor;
    float soma_acima_media = 0;
    int i;

    // Loop unico para leitura e calculos
    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);

        // vai somando os valores para a media no final
        soma = soma + vetor[i];

        // Se for o primeiro elemento, ele e o maior e o menor ao mesmo tempo
        if (i == 0) {
            maior = vetor[i];
            menor = vetor[i];
        } else {
            // checando o maior e o menor
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
            if (vetor[i] < menor) {
                menor = vetor[i];
            }
        }

        // Como o enunciado exige um LOOP UNICO para tudo, calculamos a media parcial 
        // até este momento para decidir se o numero atual entra na soma dos "acima da media"
        media = soma / (i + 1);

        if (vetor[i] > media) {
            soma_acima_media = soma_acima_media + vetor[i];
        }
    }

    // A variavel 'media' termina o loop guardando a media total correta (soma / 10)

    // Exibindo os resultados formatados
    printf("\n--- ESTATISTICAS ---\n");
    printf("Media aritmetica: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Soma dos valores acima da media (parcial): %.2f\n", soma_acima_media);

    return 0;
}