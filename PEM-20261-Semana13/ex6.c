/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 6            *
*******************************
*/

#include <stdio.h>
#include <string.h>

// Definindo a estrutura do Produto
struct Produto {
    char nome[40];
    float preco;
    int estoque;
};

int main() {
    // Declarando a instancia e o ponteiro para ela
    struct Produto prod;
    struct Produto *ptr = &prod;

    // 1 - Usando apenas desreferenciacao (*) e ponto (.)
    
    // Preenchendo os dados
    strcpy((*ptr).nome, "Teclado Mecanico");
    (*ptr).preco = 250.50f;
    (*ptr).estoque = 15;

    // Exibindo os dados
    printf("--- EXIBINDO COM (*ptr). ---\n");
    printf("Nome: %s\n", (*ptr).nome);
    printf("Preco: R$ %.2f\n", (*ptr).preco);
    printf("Estoque: %d unidades\n\n", (*ptr).estoque);

    // 2 - Repetindo o processo, mas agora usando o operador
    
    // Atualizando os dados usando a nova sintaxe
    strcpy(ptr->nome, "Mouse Gamer");
    ptr->preco = 180.00f;
    ptr->estoque = 30;

    // Exibindo os dados
    printf("--- EXIBINDO COM ptr-> ---\n");
    printf("Nome: %s\n", ptr->nome);
    printf("Preco: R$ %.2f\n", ptr->preco);
    printf("Estoque: %d unidades\n", ptr->estoque);

    /* 
       COMPARAÇÃO DO CÓDIGO:
       
       A sintaxe `(*ptr).campo` exige o uso de parenteses obrigatoriamente porque o 
       operador de ponto (.) tem prioridade sobre o operador de asterisco (*). Se a gente 
       escrever `*ptr.campo` sem parenteses, o C vai achar que estamos tentando puxar o 
       ponteiro de dentro do campo, gerando um erro de compilacao.
       
       Ja o operador `ptr->campo` funciona exatamente como um "atalho". Ele faz as duas 
       coisas de uma vez só: desreferencia o ponteiro e acessa o campo da estrutura. 
       Isso deixa o codigo muito mais limpo, legivel e facil de digitar, evitando 
       esquecer algum parenteses pelo caminho.
    */

    return 0;
}