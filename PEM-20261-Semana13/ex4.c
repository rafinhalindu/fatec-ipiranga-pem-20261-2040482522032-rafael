/*
*******************************
* Nome: Rafael Apro Rodrigues *
* RA: 2040482522032           *
*                             *
* Prof: Veríssimo             *
* Semana 13 - ex 4            *
*******************************
*/

#include <stdio.h>
// Definindo a estrutura do Aluno
struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

int main() {
    // Criando uma instancia do struct e populando com alguns dados
    struct Aluno aluno1 = {"Rodrigo", 202601, 8.5f};

    printf("--- ENDERECOS DE MEMORIA DO STRUCT ---\n");
    // O (void*) serve para o printf mostrar o endereco certinho com %p
    printf("Endereco do Aluno (Struct inteiro): %p\n\n", (void*)&aluno1);
    
    printf("Endereco do campo 'nome':      %p\n", (void*)&aluno1.nome);
    printf("Endereco do campo 'matricula': %p\n", (void*)&aluno1.matricula);
    printf("Endereco do campo 'media':     %p\n", (void*)&aluno1.media);

    /* 
       EXPLICACAO DOS ENDERECOS:
       
       Sim, os enderecos sao consecutivos (eles aparecem em sequencia na memoria), 
       mas eles dao uns "saltos" de tamanho dependendo do tipo de dado de cada campo.
       
       O campo 'nome' comeca exatamente no inicio do struct e ocupa 50 bytes (porque 
       cada char vale 1 byte). 
       
       Logo em seguida, deveria comecar a 'matricula' (um int de 4 bytes). Mas o computador 
       as vezes deixa um espacinho em branco invisivel entre os campos para facilitar a 
       leitura do processador. Esse truque do sistema operacional se chama "Alinhamento de Memoria" (ou Memory Padding).
       
       Por isso, quando voce olha os numeros hexadecimais que o %p mostra na tela, 
       voce consegue ver claramente que eles crescem em fila, um logo apos o termino do outro!
    */

    return 0;
}