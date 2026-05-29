/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 4            *
*******************************
*/

#include <stdio.h>
int main() {
    double a, b, c;
    double a2, b2, c2; // variaveis para guardar os lados ao quadrado

    printf("Digite o lado A: ");
    scanf("%lf", &a);

    printf("Digite o lado B: ");
    scanf("%lf", &b);

    printf("Digite o lado C: ");
    scanf("%lf", &c);

    // 1. Verificando a desigualdade triangular (um lado nao pode ser maior que a soma dos outros dois)
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Erro: Os lados informados nao formam um triangulo valido.\n");
    } 
    else {
        printf("\nTriangulo valido!\n");

        // 2. Classificacao quanto aos lados (if encadeado basico)
        if (a == b && b == c) {
            // todos os lados iguais
            printf("Classificacao dos lados: Equilatero\n");
        } 
        else if (a == b || a == c || b == c) {
            // se nao sao todos iguais, mas caiu aqui, pelo menos dois sao iguais
            printf("Classificacao dos lados: Isosceles\n");
        } 
        else {
            // se nao e nenhum dos de cima, todos sao diferentes
            printf("Classificacao dos lados: Escaleno\n");
        }

        // 3. Classificacao quanto aos angulos (usando o quadrado dos lados)
        // Primeiro calculamos os quadrados para facilitar as formulas
        a2 = a * a;
        b2 = b * b;
        c2 = c * c;

        // Precisamos testar as relacoes para os tres lados, ja que nao sabemos qual e o maior
        if ((a2 == b2 + c2) || (b2 == a2 + c2) || (c2 == a2 + b2)) {
            // se o quadrado de um for igual a soma dos outros, e retangulo (Teorema de Pitagoras)
            printf("Classificacao dos angulos: Retangulo\n");
        } 
        else if ((a2 > b2 + c2) || (b2 > a2 + c2) || (c2 > a2 + b2)) {
            // se o quadrado de um for maior que a soma dos outros, o angulo e aberto (maior que 90)
            printf("Classificacao dos angulos: Obtusangulo\n");
        } 
        else {
            // se nao e reto nem aberto, so pode ser fechado (todos menores que 90)
            printf("Classificacao dos angulos: Acutangulo\n");
        }
    }

    return 0;
}