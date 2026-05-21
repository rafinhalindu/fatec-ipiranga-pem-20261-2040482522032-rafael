/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 1            *
*******************************
*/

#include <stdio.h>
int main() {

// 1: CRIANDO AS VARIÁVEIS
// Aqui a gente só cria as variáveis e guarda um valor nelas (int, float e char)
    int idade = 21;
    float nota = 7.5;
    char letra = 'X';

// 2: CRIANDO OS PONTEIROS ---
// O asterisco (*) diz que a variável é um ponteiro (ela só guarda endereços)
// O "e comercial" (&) serve para pegar o endereço de memória da variável normal

    // p_idade aponta para onde a idade tá guardada
    int *p_idade = &idade;   
    // p_nota aponta para onde a nota tá guardada
    float *p_nota = &nota;   
    // p_letra aponta para onde a letra tá guardada
    char *p_letra = &letra;  

// 3: MOSTRANDO OS RESULTADOS DO INT
    printf("--- TESTANDO O INT ---\n");
    // Mostra o valor normal que tá na variável
    printf("Idade: %d\n", idade);
    // O &idade descobre o endereço real dessa variável na memória do PC
    printf("Onde esta na memoria: %p\n", (void*)&idade);
    // Mostra o endereço que o ponteiro p_idade guardou (vai dar igual ao de cima)
    printf("Endereco no ponteiro: %p\n", (void*)p_idade);
    // O asterisco antes do ponteiro (*p_idade) serve para ir lá no endereço e pegar o valor
    printf("Valor puxado pelo ponteiro: %d\n\n", *p_idade);

// 4: MOSTRANDO OS RESULTADOS DO FLOAT
    printf("--- TESTANDO O FLOAT ---\n");
    printf("Nota: %.1f\n", nota);
    printf("Onde esta na memoria: %p\n", (void*)&nota);
    printf("Endereco no ponteiro: %p\n", (void*)p_nota);
    printf("Valor puxado pelo ponteiro: %.1f\n\n", *p_nota);

// 5: MOSTRANDO OS RESULTADOS DO CHAR
    printf("--- TESTANDO O CHAR ---\n");
    printf("Letra: %c\n", letra);
    printf("Onde esta na memoria: %p\n", (void*)&letra);
    printf("Endereco no ponteiro: %p\n", (void*)p_letra);
    printf("Valor puxado pelo ponteiro: %c\n\n", *p_letra);

    return 0;
}