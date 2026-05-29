/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 3            *
*******************************
*/

#include <stdio.h>
int main() {
    double peso, altura, imc;

    printf("Digite o peso (kg): ");
    scanf("%lf", &peso);

    printf("Digite a altura (m): ");
    scanf("%lf", &altura);

    // Tratando as entradas invalidas antes de fazer a conta
    if (peso <= 0 || altura <= 0) {
        printf("Erro: Peso e altura devem ser maiores que zero!\n");
    } else {
        // Conta do IMC: peso dividido pela altura ao quadrado
        imc = peso / (altura * altura);

        printf("\nIMC: %.2lf\n", imc);

        // Classificacao usando if encadeado
        if (imc < 18.5) {
            printf("Classificacao: Abaixo do peso\n");
        } 
        else if (imc < 25.0) { // nao precisa testar >= 18.5 porque o if de cima ja barrou
            printf("Classificacao: Peso normal\n");
        } 
        else if (imc < 30.0) { // mesma lógica, se chegou aqui e porque e maior ou igual a 25.0
            printf("Classificacao: Sobrepeso\n");
        } 
        else { // se nao caiu em nenhuma das anteriores, so pode ser maior ou igual a 30.0
            printf("Classificacao: Obesidade\n");
        }
    }

    return 0;
}