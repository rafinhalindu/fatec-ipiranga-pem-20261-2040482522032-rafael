/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 14 - ex 14           *
*******************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- DECLARAÇÃO DOS PROTÓTIPOS DAS FUNÇÕES ---
int calcularMDC(int a, int b);
long calcularPotencia(int base, int expoente);
int verificarPrimo(int n);
void decimalParaBinario(int n, char *resultado);

// --- FUNÇÃO MAIN (MENU INTERATIVO) ---
int main() {
    int opcao;
    int n1, n2;
    int base, exp;
    int num_primo;
    int num_dec;
    char binario[33]; // 32 bits + '\0' para cobrir o tamanho de um int comum

    do {
        printf("\n======= CALCULADORA MODULAR =======");
        printf("\n1 - Maximo Divisor Comum (MDC)");
        printf("\n2 - Potencia Inteira");
        printf("\n3 - Verificar Numero Primo");
        printf("\n4 - Conversao Decimal -> Binario");
        printf("\n0 - Sair do Programa");
        printf("\n===================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n--- Maximo Divisor Comum (Euclides) ---\n");
                printf("Digite o primeiro valor: ");
                scanf("%d", &n1);
                printf("Digite o segundo valor: ");
                scanf("%d", &n2);
                if (n1 < 0 || n2 < 0) {
                    printf("Por favor, digite apenas numeros positivos.\n");
                } else {
                    printf("MDC(%d, %d) = %d\n", n1, n2, calcularMDC(n1, n2));
                }
                break;

            case 2:
                printf("\n--- Potencia Inteira ---\n");
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente (positivo): ");
                scanf("%d", &exp);
                if (exp < 0) {
                    printf("Erro: Este programa nao calcula expoente negativo.\n");
                } else {
                    printf("%d elevado a %d = %ld\n", base, exp, calcularPotencia(base, exp));
                }
                break;

            case 3:
                printf("\n--- Verificador de Numero Primo ---\n");
                printf("Digite um numero inteiro: ");
                scanf("%d", &num_primo);
                if (verificarPrimo(num_primo) == 1) {
                    printf("O numero %d e PRIMO.\n", num_primo);
                } else {
                    printf("O numero %d NAO e primo.\n", num_primo);
                }
                break;

            case 4:
                printf("\n--- Conversao Decimal para Binario ---\n");
                printf("Digite um numero inteiro positivo: ");
                scanf("%d", &num_dec);
                if (num_dec < 0) {
                    printf("Erro: Digite apenas numeros positivos.\n");
                } else {
                    decimalParaBinario(num_dec, binario);
                    printf("O numero %d em binario e: %s\n", num_dec, binario);
                }
                break;

            case 0:
                printf("\nFinalizando o programa. Ate mais!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES COM DOCUMENTAÇÃO ---

/**
 * @brief Calcula o Maximo Divisor Comum usando o Algoritmo de Euclides (divisoes sucessivas)
 * @param a Primeiro número inteiro positivo
 * @param b Segundo número inteiro positivo
 * @return int O valor do MDC entre a e b
 * @complexity O(log(min(a, b))) - Diminui muito rapido a cada resto de divisao
 */
int calcularMDC(int a, int b) {
    int resto;
    // O algoritmo de Euclides joga o divisor pro dividendo e o resto pro divisor ate zerar
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

/**
 * @brief Calcula a potencia de uma base inteira elevada a um expoente inteiro positivo
 * @param base Numero inteiro a ser multiplicado
 * @param expoente Quantidade de vezes que a base se multiplica
 * @return long O resultado da potenciacao (usando long para evitar estouro rapido)
 * @complexity O(n) - Onde n e o valor do expoente (roda n vezes o laco)
 */
long calcularPotencia(int base, int expoente) {
    long resultado = 1;
    int i;
    
    // Todo numero elevado a 0 e 1, o laco nao vai rodar e vai retornar 1 correto
    for (i = 0; i < expoente; i++) {
        resultado = resultado * base;
    }
    return resultado;
}

/**
 * @brief Verifica se um numero inteiro e primo
 * @param n Numero inteiro a ser testado
 * @return int Retorna 1 se for primo, 0 se nao for
 * @complexity O(sqrt(n)) - Testamos apenas ate a raiz quadrada de n, o que economiza muito processamento
 */
int verificarPrimo(int n) {
    int i;
    
    if (n <= 1) return 0; // numeros menores ou iguais a 1 nao sao primos
    if (n == 2) return 1; // 2 e o unico primo par
    if (n % 2 == 0) return 0; // elimina todos os outros pares direto

    // Comeca do 3 e pula de 2 em 2 para testar so os impares ate a raiz quadrada de n
    // i * i <= n substitui o uso da funcao sqrt() da math.h de forma inteligente
    for (i = 3; i * i <= n; i = i + 2) {
        if (n % i == 0) {
            return 0; // achou um divisor, nao e primo
        }
    }
    return 1; // nao achou nenhum divisor, e primo
}

/**
 * @brief Converte um numero decimal positivo para string representativa em binario
 * @param n Numero inteiro decimal a ser convertido
 * @param resultado Ponteiro para o array de char onde a string final sera guardada
 * @return void As alteracoes ocorrem direto na string passada por parametro
 * @complexity O(log n) - Como dividimos o numero por 2 a cada passo, o numero de operacoes e logaritmico
 */
void decimalParaBinario(int n, char *resultado) {
    char aux[33];
    int i = 0;
    int j = 0;

    // Caso especial para o numero zero
    if (n == 0) {
        resultado[0] = '0';
        resultado[1] = '\0';
        return;
    }

    // Vai guardando os restos da divisao por 2 (que sao os bits) na variavel auxiliar
    while (n > 0) {
        aux[i] = (n % 2) + '0'; // Converte o resto 0 ou 1 para o caractere '0' ou '1'
        n = n / 2;
        i++;
    }
    aux[i] = '\0'; // fecha a string auxiliar

    // Como os restos sao gerados de tras para frente, precisamos inverter na string final
    // 'i - 1' e a ultima posicao valida antes do '\0'
    for (j = 0; j < i; j++) {
        resultado[j] = aux[i - 1 - j];
    }
    resultado[j] = '\0'; // fecha a string de resultado final

    return 0;
}