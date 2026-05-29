/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 2            *
*******************************
*/

#include <stdio.h>
int main() {
    // Escolhi 'int' porque o enunciado pede um maximo de 2.147.483.647, que e exatamente o limite do int de 32 bits
    int centimetros;
    
    // 'float' aqui e suficiente porque metros nao precisam de tanta precisao extrema
    float metros;
    
    // 'double' para km e milhas porque divisoes sucessivas e conversao de milhas exigem maior precisao decimal
    double quilometros, milhas;

    printf("Digite a distancia em centimetros: ");
    scanf("%d", &centimetros);

    // Desafio: verificando se o valor e positivo antes de calcular
    if (centimetros < 0) {
        printf("Erro: O valor informado nao pode ser negativo!\n");
    } else {
        // Realizando as conversoes
        metros = centimetros / 100.0; // usando 100.0 para forcar a divisao de float
        quilometros = metros / 1000.0;
        milhas = quilometros / 1.60934;

        // Exibindo os resultados com duas casas decimais
        printf("\n--- Resultados ---\n");
        printf("Metros: %.2f m\n", metros);
        printf("Quilometros: %.2lf km\n", quilometros);
        printf("Milhas: %.2lf mi\n", milhas);
    }

    return 0;
}