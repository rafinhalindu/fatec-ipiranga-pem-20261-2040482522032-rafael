/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 8            *
*******************************
*/

#include <stdio.h>
int main() {
    // Criando o array de double com 10 elementos
    double notas[10] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};

    // Inicializando os dois ponteiros
    // Lembrando: o 3.º elemento fica no indice 2 e o 8.º elemento no indice 7
    double *ptr_inicio = &notas[2]; 
    double *ptr_fim = &notas[7];

    // Calculando a diferenca direta entre eles
    long diferenca = ptr_fim - ptr_inicio;

    printf("--- DISTANCIA ENTRE PONTEIROS ---\n");
    printf("Endereco do 3.o elemento (ptr_inicio): %p\n", (void*)ptr_inicio);
    printf("Endereco do 8.o elemento (ptr_fim):    %p\n", (void*)ptr_fim);
    printf("Resultado da subtracao (ptr_fim - ptr_inicio): %ld\n\n", diferenca);

    /* 
       EXPLICAÇÃO DE COMO O COMPILADOR REALIZA ESSE CÁLCULO:
       
       Se voce olhar os enderecos em hexadecimal, a diferenca real de bytes na memoria 
       seria de 40 bytes (ja que cada double ocupa 8 bytes e 7 - 2 = 5 elementos; 5 * 8 = 40).
       
       Porem, quando subtraimos dois ponteiros do mesmo tipo em C, o compilador nao devolve 
       a distancia em bytes. Ele pega a diferenca em bytes e divide pelo tamanho do tipo 
       apontado (sizeof(double), que e 8).
       
       Ou seja: (40 bytes de diferenca) / (8 bytes por double) = 5.
       
       Portanto, o resultado da subtracao e a distancia em NUMERO DE ELEMENTOS entre os 
       dois ponteiros, e nao em bytes. O tipo desse resultado e o 'ptrdiff_t' (um tipo inteiro).
    */

    // Percorrendo o intervalo entre os dois ponteiros (inclusive os limites)
    printf("--- IMPRIMINDO O INTERVALO ---\n");
    
    // Criamos um ponteiro auxiliar para caminhar do inicio ate o fim
    double *p = ptr_inicio;
    int contador = 3; // apenas para organizar o print do "o elemento"

    while (p <= ptr_fim) {
        printf("%d.o elemento: %.1f (no endereco %p)\n", contador, *p, (void*)p);
        p++; // Avança para o proximo double na memoria
        contador++;
    }

    return 0;
}