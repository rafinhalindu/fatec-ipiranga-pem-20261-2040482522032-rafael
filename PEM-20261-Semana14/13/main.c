/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 13           *
*******************************
*/

#include <stdio.h>
#include "stringutil.h"
int main() {
    // Casos de teste para as funcoes
    char str1[] = "Algoritmos";
    char str2[] = "Fatec";
    
    char str3[] = "arara";
    char str4[] = "cadeira";

    // --- Teste 1: Conta Vogais ---
    printf("--- Teste: contaVogais ---\n");
    printf("A string '%s' tem %d vogais.\n", str1, contaVogais(str1));
    printf("A string '%s' tem %d vogais.\n", str2, contaVogais(str2));

    // --- Teste 2: Palindromo ---
    printf("\n--- Teste: ePalindromo ---\n");
    printf("A palavra '%s' e palindromo? %s\n", str3, ePalindromo(str3) ? "Sim (1)" : "Nao (0)");
    printf("A palavra '%s' e palindromo? %s\n", str4, ePalindromo(str4) ? "Sim (1)" : "Nao (0)");

    // --- Teste 3: Inverte String ---
    printf("\n--- Teste: inverteCString ---\n");
    printf("Original 1: %s -> ", str1);
    inverteCString(str1);
    printf("Invertida: %s\n", str1);

    printf("Original 2: %s -> ", str2);
    inverteCString(str2);
    printf("Invertida: %s\n", str2);

    return 0;
}