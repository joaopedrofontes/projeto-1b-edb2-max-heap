#include "max_heap.h"
#include "file-utils.h"
#include "print-utils.h"

void imprimir_opcoes();

int main() {

    char* filename = "voos.csv";

    MaxHeap* heap = criar_heap();

    heap = ler_csv_e_inserir(heap, filename);

    int escolha;

    while(1) {
        imprimir_opcoes();
        scanf("%d", &escolha);
        getchar();

        if(escolha == 1) {
            adicionar_voo(heap);
        }
        else if(escolha == 2) {
            imprimir_todos_voos(heap);
        }
        else if(escolha == 3) {
            imprimir_maior_prioridade(heap);
        }
        else if(escolha == 4) {
            remover_topo(heap);
        }
        else if(escolha == 5) {
            alterar_voo(heap);
        }
        else {
            break;
        }
    }

    liberar_heap(heap);
    
    return 0;
}

void imprimir_opcoes() {
    printf("Escolha uma das seguintes opções:\n");
    printf("(0) - Parar o programa\n");
    printf("(1) - Adicionar Voo\n");
    printf("(2) - Listar todos os voos\n");
    printf("(3) - Listar o voo com maior prioridade\n");
    printf("(4) - Remover voo com maior prioridade\n");
    printf("(5) - Alterar algum voo\n");
    printf("Opção escolhida: ");
}