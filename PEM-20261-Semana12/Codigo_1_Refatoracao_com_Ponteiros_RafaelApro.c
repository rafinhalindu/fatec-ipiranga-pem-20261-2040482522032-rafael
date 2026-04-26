/*------------------------------------------------------------*
 *                  FATEC Ipiranga                            *
 * Disciplina: Programação Estruturada e Modular              *
 *                  Prof. Veríssimo                           *
 *------------------------------------------------------------*
 * Objetivo do Programa: Busca em profundidade (Recursividade)*
 *                       CÓDIGO NOVO 1 — Refatoração          *
 *                       com Ponteiros                        *
 * Data - 24/04/2026                                          *
 * Refatorado por Rafael Apro Rodrigues RA: 2040482522032     *
 *------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PASTAS      50
#define LIMITE_ALERTA   300.0

typedef struct {
    char  nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int   subpastas_indices[10];
    int   qtd_sub;
} Pasta;

/* Banco de dados simulado */
Pasta drive[MAX_PASTAS];

/*
 * processarHierarquia — versão com ponteiros
 *
 * Parâmetros:
 *   pasta_ptr        : ponteiro direto para a Pasta corrente
 *   drive_ptr        : ponteiro para o início do vetor (base)
 *   nivel_atual      : profundidade corrente da recursão
 *   limite_prof      : profundidade máxima permitida
 *
 * Retorna: tamanho_total acumulado da pasta (float)
 */
float processarHierarquia(Pasta *pasta_ptr,
                          Pasta *drive_ptr,
                          int    nivel_atual,
                          int    limite_prof)
{
    /* Caso base: ponteiro inválido ou profundidade excedida */
    if (pasta_ptr == NULL || nivel_atual > limite_prof)
        return 0.0f;

    /* Inicializa o total com o tamanho próprio da pasta */
    pasta_ptr->tamanho_total = pasta_ptr->tamanho_proprio;

    /* Mergulho recursivo: acessa cada filho via ponteiro aritmético */
    for (int i = 0; i < pasta_ptr->qtd_sub; i++) {
        int    filho_idx = pasta_ptr->subpastas_indices[i];
        Pasta *filho_ptr = drive_ptr + filho_idx;   /* aritmética de ponteiros */

        pasta_ptr->tamanho_total +=
            processarHierarquia(filho_ptr,
                                drive_ptr,
                                nivel_atual + 1,
                                limite_prof);
    }

    /* Impressão com indentação */
    for (int i = 0; i < nivel_atual; i++)
        printf("  ");

    printf("|-- %s [%.2f GB]", pasta_ptr->nome, pasta_ptr->tamanho_total);

    if (pasta_ptr->tamanho_total > LIMITE_ALERTA)
        printf(" [!] ALERTA: GARGALO DETECTADO");

    printf("\n");

    return pasta_ptr->tamanho_total;
}

int main(void)
{
    /* ── 1. Configuração da árvore ── */

    /* RAIZ (índice 0) */
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio      = 10.0f;
    drive[0].qtd_sub              = 2;
    drive[0].subpastas_indices[0] = 1;   /* → Projetos_TI  */
    drive[0].subpastas_indices[1] = 2;   /* → Backups_Antigos */

    /* Projetos_TI (índice 1) */
    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio      = 50.0f;
    drive[1].qtd_sub              = 1;
    drive[1].subpastas_indices[0] = 3;   /* → Videos_Aulas */

    /* Backups_Antigos (índice 2) */
    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0f;   /* já excede o limite */
    drive[2].qtd_sub         = 0;

    /* Videos_Aulas (índice 3) */
    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0f;
    drive[3].qtd_sub         = 0;

    /* ── 2. Execução ── */

    int    limite;
    Pasta *raiz_ptr = drive;   /* ponteiro aponta para drive[0] */

    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    processarHierarquia(raiz_ptr, drive, 0, limite);
    printf("-------------------------------------------\n");

    return 0;
}