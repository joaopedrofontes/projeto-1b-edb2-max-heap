#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "voo.h"

#define MAX_TAMANHO 100

typedef struct MaxHeap {
    Voo* elementos[MAX_TAMANHO];
    int tamanho;
} MaxHeap;

MaxHeap* criar_heap();

void trocar(Voo** a, Voo** b);

void subir_elemento(MaxHeap* heap, int index);

void descer_elemento(MaxHeap* heap, int index);

void inserir_elemento(MaxHeap* heap, Voo* novo_voo);

void remover_topo(MaxHeap* heap);

void adicionar_voo(MaxHeap* heap);

void alterar_voo(MaxHeap* heap);

void liberar_heap(MaxHeap* heap);

#endif