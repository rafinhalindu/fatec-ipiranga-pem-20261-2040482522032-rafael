/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 13           *
*******************************
*/

#include "stringutil.h"
#include <string.h> // Apenas liberado o uso do strlen

// Funcao 1: Conta as vogais ignorando se e maiuscula ou minuscula
int contaVogais(char *s) {
    int i = 0;
    int contador = 0;

    // Em C, toda string termina com o caractere nulo '\0'
    while (s[i] != '\0') {
        char c = s[i];
        
        // Testa todas as possibilidades de vogais
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            contador++;
        }
        i++;
    }
    return contador;
}

// Funcao 2: Inverte a string alterando ela direto na memoria (in-place)
void inverteCString(char *s) {
    int i;
    int tam = strlen(s);
    char aux;

    // Vamos andar com o 'i' ate a metade da string, trocando as pontas
    for (i = 0; i < tam / 2; i++) {
        aux = s[i];
        s[i] = s[tam - 1 - i]; // joga o caractere do fim para o comeco
        s[tam - 1 - i] = aux;  // joga o caractere do comeco para o fim
    }
}

// Funcao 3: Retorna 1 se for palindromo e 0 se nao for
int ePalindromo(char *s) {
    int i;
    int tam = strlen(s);

    // Compara o primeiro com o ultimo, o segundo com o penultimo, etc.
    for (i = 0; i < tam / 2; i++) {
        if (s[i] != s[tam - 1 - i]) {
            return 0; // Se encontrar qualquer diferenca, ja nao e palindromo
        }
    }
    return 1; // Se o loop terminar sem achar erros, e palindromo
}