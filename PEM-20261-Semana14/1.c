/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 1            *
*******************************
*/

#include <stdio.h>
int main() {
    // declarando as variaveis que o enunciado pediu
    double n1, n2, n3;
    int p1, p2, p3;
    double media;

    // lendo as notas e os pesos na sequencia
    printf("Digite a nota 1 e o peso 1: ");
    scanf("%lf %d", &n1, &p1);

    printf("Digite a nota 2 e o peso 2: ");
    scanf("%lf %d", &n2, &p2);

    printf("Digite a nota 3 e o peso 3: ");
    scanf("%lf %d", &n3, &p3);

    // conta da media ponderada (multiplica nota pelo peso e divide pela soma dos pesos)
    media = (n1*p1 + n2*p2 + n3*p3) / (p1 + p2 + p3);

    // .2lf serve para travar em duas casas decimais
    printf("\nMedia: %.2lf\n", media);

    // mostrando os bytes usando o sizeof
    printf("Tamanho double: %d bytes\n", sizeof(double));
    printf("Tamanho int: %d bytes\n", sizeof(int));

    return 0;
}