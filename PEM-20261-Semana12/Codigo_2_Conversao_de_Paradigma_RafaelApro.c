/*------------------------------------------------------------*
 *                  FATEC Ipiranga                            *
 * Disciplina: Programação Estruturada e Modular              *
 *                  Prof. Veríssimo                           *
 *------------------------------------------------------------*
 * Objetivo do Programa: Busca em profundidade (Iterativo)    *
 *                       CÓDIGO NOVO 2 - Conversão de         *
 *                                       Paradigma            *
 * Data - 24/04/2026                                          *
 * Refatorado por Rafael Apro Rodrigues RA: 2040482522032     *
 *------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
 
#define MAX_PASTAS    50
#define LIMITE_ALERTA 300.0
 
/* Dados de cada pasta */
typedef struct {
    char  nome[50];
    float tamanho_proprio; /* tamanho só desta pasta        */
    float tamanho_total;   /* tamanho dela + todas as filhas */
    int   subpastas_indices[10];
    int   qtd_sub;
} Pasta;
 
/* Vetor global que armazena todas as pastas */
Pasta drive[MAX_PASTAS];
 
/*
 * Item da pilha manual.
 * Como não usamos recursão, precisamos guardar
 * o "estado" de cada pasta enquanto processamos as filhas.
 *   index        -> qual pasta é esta
 *   nivel        -> profundidade na árvore (0 = raiz)
 *   fase         -> 0 = acabou de entrar, 1 = já está processando filhas
 *   filho_cursor -> qual filha processar agora
 */
typedef struct {
    int index;
    int nivel;
    int fase;
    int filho_cursor;
} ItemPilha;
 
#define MAX_PILHA 200
 
ItemPilha pilha[MAX_PILHA];
int topo = -1; /* pilha começa vazia */
 
/* Adiciona um item no topo da pilha */
void empilhar(int index, int nivel, int fase, int cursor) {
    if (topo < MAX_PILHA - 1) {
        topo++;
        pilha[topo].index        = index;
        pilha[topo].nivel        = nivel;
        pilha[topo].fase         = fase;
        pilha[topo].filho_cursor = cursor;
    }
}
 
/*
 * Percorre a árvore de pastas de forma iterativa.
 * Usa a pilha acima para simular o que a recursão fazia.
 *
 * Ideia geral do loop:
 *   - fase 0: "entrei na pasta" -> inicializa o tamanho total
 *   - fase 1: "estou processando as filhas"
 *       * se ainda tem filha -> empilha a próxima filha
 *       * se não tem mais    -> imprime esta pasta e volta para a mãe
 */
float processarHierarquia_iterativo(int raiz, int limite_profundidade) {
 
    if (raiz == -1) return 0;
 
    topo = -1;
    empilhar(raiz, 0, 0, 0); /* começa pela raiz */
 
    float resultado_raiz = 0;
 
    while (topo >= 0) {
 
        /* Olha o item do topo sem tirar da pilha */
        ItemPilha *cur = &pilha[topo];
        int idx   = cur->index;
        int nivel = cur->nivel;
 
        /* FASE 0: primeira vez que visitamos esta pasta */
        if (cur->fase == 0) {
            drive[idx].tamanho_total = drive[idx].tamanho_proprio;
            cur->fase = 1;         /* próxima vez cai no else */
            cur->filho_cursor = 0; /* começa pela primeira filha */
        }
 
        /* FASE 1: já inicializamos, agora processamos as filhas */
        else {
            int cursor = cur->filho_cursor;
 
            /* Ainda tem filha para processar? */
            if (cursor < drive[idx].qtd_sub) {
                int filho_idx = drive[idx].subpastas_indices[cursor];
                cur->filho_cursor++; /* avança para a próxima filha */
 
                /* Só desce se não ultrapassou o limite de profundidade */
                if (nivel + 1 <= limite_profundidade && filho_idx != -1) {
                    empilhar(filho_idx, nivel + 1, 0, 0);
                }
 
            } else {
                /* Todas as filhas foram processadas: hora de imprimir */
 
                for (int i = 0; i < nivel; i++) printf("  "); /* indentação */
 
                printf("|-- %s [%.2f GB]",
                       drive[idx].nome,
                       drive[idx].tamanho_total);
 
                if (drive[idx].tamanho_total > LIMITE_ALERTA)
                    printf(" [!] ALERTA: GARGALO DETECTADO");
 
                printf("\n");
 
                float retorno = drive[idx].tamanho_total;
                topo--; /* remove esta pasta da pilha */
 
                /* Soma o tamanho desta pasta na pasta mãe */
                if (topo >= 0) {
                    int mae_idx = pilha[topo].index;
                    drive[mae_idx].tamanho_total += retorno;
                } else {
                    resultado_raiz = retorno; /* era a raiz, guarda o total */
                }
            }
        }
    }
 
    return resultado_raiz;
}
 
int main() {
 
    /* Monta a árvore de pastas */
 
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio      = 10.0;
    drive[0].qtd_sub              = 2;
    drive[0].subpastas_indices[0] = 1; /* Projetos_TI     */
    drive[0].subpastas_indices[1] = 2; /* Backups_Antigos */
 
    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio      = 50.0;
    drive[1].qtd_sub              = 1;
    drive[1].subpastas_indices[0] = 3; /* Videos_Aulas */
 
    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0; /* já ultrapassa o limite de alerta */
    drive[2].qtd_sub         = 0;
 
    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub         = 0;
 
    /* Lê o limite de profundidade e exibe o relatório */
    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);
 
    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    processarHierarquia_iterativo(0, limite);
    printf("-------------------------------------------\n");
 
    return 0;
}