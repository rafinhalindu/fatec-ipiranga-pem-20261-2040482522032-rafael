//Rafael Apro Rodrigues RA:2040482522032

#include <stdio.h>
int main(){

#define TAM 10

int idProduto [TAM];
int i = 0, opcao;
int id, encontrado;

for(i = 0; i < TAM; i++){
    idProduto[i] = -1;
}

do{
    printf("\n===== MENU =====\n");
    printf("1 - Inclusao\n");
    printf("2 - Consulta\n");
    printf("3 - Alteracao\n");
    printf("4 - Exclusao\n");
    printf("5 - Listar todos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);

switch (opcao)
{
case 1: //Inclusão
                printf("Digite o ID do produto: ");
                scanf("%d", &id);

                for(i = 0; i < TAM; i++) {
                    if(idProduto[i] == -1) {
                        idProduto[i] = id;
                        printf("Produto cadastrado na posicao %d\n", i);
                        break;
                    }
                }

                if(i == TAM) {
                    printf("Lista cheia!\n");
                }
                break;

case 2: //Consulta
                printf("Digite o ID do produto para buscar: ");
                scanf("%d", &id);

                encontrado = 0;

                for(i = 0; i < TAM; i++) {
                    if(idProduto[i] == id) {
                        printf("Produto encontrado na posicao %d\n", i);
                        encontrado = 1;
                        break;
                    }
                }

                if(!encontrado) {
                    printf("Produto nao encontrado.\n");
                }
                break;

case 3: //Alteração
                printf("Digite o ID do produto que deseja alterar: ");
                scanf("%d", &id);

                encontrado = 0;

                for(i = 0; i < TAM; i++) {
                    if(idProduto[i] == id) {
                        printf("Digite o novo ID do produto: ");
                        scanf("%d", &idProduto[i]);
                        printf("Produto alterado com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if(!encontrado) {
                    printf("Produto nao encontrado.\n");
                }
                break;

case 4: //Exclusão
                printf("Digite o ID do produto que deseja excluir: ");
                scanf("%d", &id);

                encontrado = 0;

                for(i = 0; i < TAM; i++) {
                    if(idProduto[i] == id) {
                        idProduto[i] = -1;
                        printf("Produto removido com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if(!encontrado) {
                    printf("Produto nao encontrado.\n");
                }
                break;

case 5: //Listar
                printf("\nLista de produtos cadastrados:\n");

                for(i = 0; i < TAM; i++) {
                    if(idProduto[i] != -1) {
                        printf("Posicao %d: ID %d\n", i, idProduto[i]);
                    }
                }
                break;

case 0: //Sair

                break;

            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

return 0;
}
