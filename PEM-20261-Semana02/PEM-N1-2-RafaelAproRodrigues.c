/*Atividade Semana 02
  Rafael Apro Rodrigues
  ADS Vespertino 2º
  PEM 2026 1
*/

#include <stdio.h>
#include <string.h>

int main() {
    //cria um vetor de 100 caracteres para guardar a frase
    char frase[100];

    //pede para o usuário digitar a frase
    printf("Digite a frase completa: ");

    //lê a frase completa e salva valor em frase
    fgets(frase, 100, stdin);

    //conta quantos caracteres a frase tem
    int tamanho = strlen(frase);

    //variável para o loop
    int i;

    //começa em 1 pois a primeira palavra não tem espaço antes
    int contadorPalavras = 1;

    //percorre cada caractere da frase
    for (i = 0; i < tamanho; i++) {

        //verifica se o caractere atual é um espaço
        if (frase[i] == ' ') {

            //verifica se o próximo caractere não é espaço
            if (frase[i + 1] != ' ') {
                //encontrou uma nova palavra, adiciona 1
                contadorPalavras = contadorPalavras + 1;
            }
        }
    }

    //exibe o resultado final
    printf("Numero de palavras: %d\n", contadorPalavras);

return 0;
}