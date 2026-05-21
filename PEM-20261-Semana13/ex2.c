/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 2            *
*******************************
*/

#include <stdio.h>
int main() {
    // Pegando o tamanho de cada tipo de ponteiro com o sizeof
    printf("Tamanho do ponteiro para int: %lu bytes\n", sizeof(int*));
    printf("Tamanho do ponteiro para float: %lu bytes\n", sizeof(float*));
    printf("Tamanho do ponteiro para double: %lu bytes\n", sizeof(double*));
    printf("Tamanho do ponteiro para char: %lu bytes\n\n", sizeof(char*));

    /* 
       RESPOSTA DA QUESTÃO:
       Nao, o tamanho do ponteiro nao varia com o tipo apontado. 
       
       Por que? Porque um ponteiro nao guarda o valor da variavel (ele nao guarda 
       o int ou o char), ele guarda apenas o ENDERECO de memoria onde esse valor esta.
       
       Como os enderecos de memoria no mesmo computador sempre tem o mesmo tamanho 
       (geralmente 8 bytes em sistemas de 64 bits, ou 4 bytes em sistemas de 32 bits), 
       todos os ponteiros vao ter exatamente o mesmo tamanho, nao importa se estao 
       apontando para um char (que ocupa 1 byte) ou para um double (que ocupa 8 bytes).
    */

    return 0;
}