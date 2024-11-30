#include "print-utils.h"

void imprimir_todos_voos(MaxHeap* heap) {
    if(heap->tamanho  < 1) {
        printf("Não há elementos\n");
        return;
    }
    for (int i = 0; i < heap->tamanho; i++) {
        printf("Voo ID: %s | Prioridade: %d\n", heap->elementos[i]->id, heap->elementos[i]->prioridade);
    }
}

void imprimir_maior_prioridade(MaxHeap* heap){
    if(heap->tamanho  < 1) {
        printf("Não há elementos\n");
        return;
    }
    printf("Voo com maior prioridade atualmente:\n ");
    printf("Voo ID: %s | Prioridade: %d\n", heap->elementos[0]->id, heap->elementos[0]->prioridade);
}
