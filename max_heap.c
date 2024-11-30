#include "max_heap.h"

MaxHeap* criar_heap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->tamanho = 0;
    return heap;
}

void trocar(Voo** a, Voo** b) {
    Voo* temp = *a;
    *a = *b;
    *b = temp;
}

//usado após inserir elemento
void subir_elemento(MaxHeap* heap, int index) {
    while (index > 0) {
        int pai = (index - 1) / 2;
        if (heap->elementos[index]->prioridade > heap->elementos[pai]->prioridade) {
            trocar(&heap->elementos[index], &heap->elementos[pai]);
            index = pai;
        } else {
            break;
        }
    }
}

//heapify: chamado após remover o topo
void descer_elemento(MaxHeap* heap, int index) {
    int maior = index;
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;

    if (esquerda < heap->tamanho && heap->elementos[esquerda]->prioridade > heap->elementos[maior]->prioridade) {
        maior = esquerda;
    }
    if (direita < heap->tamanho && heap->elementos[direita]->prioridade > heap->elementos[maior]->prioridade) {
        maior = direita;
    }
    if (maior != index) {
        trocar(&heap->elementos[index], &heap->elementos[maior]);
        descer_elemento(heap, maior);
    }
}

//inserir no fim e chamar a função subir_elemento
void inserir_elemento(MaxHeap* heap, Voo* novo_voo){
    heap->elementos[heap->tamanho] = novo_voo;
    subir_elemento(heap, heap->tamanho);
    heap->tamanho++;
}

void remover_topo(MaxHeap* heap) {
    if(heap->tamanho  < 1) {
        printf("Não há elementos\n");
        return;
    }
    Voo* topo = heap->elementos[0];
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    descer_elemento(heap, 0);
}

void adicionar_voo(MaxHeap* heap) {
    char id[100];
    int combustivel, horario, tipo, emergencia;

    printf("Digite o ID do voo: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    //verificar se id ja existe
    for(int i = 0; i < heap->tamanho; i++){
        if(strcmp(heap->elementos[i]->id, id) == 0) {
            printf("Essse Id já existe.\n");
            return;
        }
    }

    printf("Digite a quantidade de combustível do voo: ");
    scanf("%d", &combustivel);
    getchar();

    printf("Digite o horário do voo: ");
    scanf("%d", &horario);
    getchar();

    printf("Digite o tipo do voo(1/0): ");
    scanf("%d", &tipo);
    getchar();

    printf("Digite se o voo é de emergência(1/0): ");
    scanf("%d", &emergencia);
    getchar();

    printf("\nVoo ID: %s\nCombustível: %d\nHorário: %d\nTipo: %d\nEmergência: %d\n", id, combustivel, horario, tipo, emergencia);

    Voo* novo_voo = criar_voo(id, combustivel, horario, tipo, emergencia);
    inserir_elemento(heap, novo_voo);
}

void alterar_voo(MaxHeap* heap) {
    if(heap->tamanho  < 1) {
        printf("Não há elementos\n");
        return;
    }
    char id_voo[100];
    printf("Digite o id do voo a ser alterado: ");
    fgets(id_voo, sizeof(id_voo), stdin);
    id_voo[strcspn(id_voo, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < heap->tamanho; i++) {
        if (strcmp(heap->elementos[i]->id, id_voo) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Voo com ID %s não encontrado na heap.\n", id_voo);
        return;
    }

    int combustivel, horario, tipo, emergencia;
    printf("Combustível atual: %d\n", heap->elementos[index]->combustivel);
    printf("Digite a nova quantidade de combustível do voo %s: ", id_voo);
    scanf("%d", &combustivel);
    getchar();

    printf("Horario atual: %d\n", heap->elementos[index]->horario);
    printf("Digite o novo horário do voo %s: ", id_voo);
    scanf("%d", &horario);
    getchar();

    printf("Tipo autal: %d\n", heap->elementos[index]->tipo);
    printf("Digite o novo tipo do voo(1/0)%s: ", id_voo);
    scanf("%d", &tipo);
    getchar();

    printf("Emergencia atual: %d\n", heap->elementos[index]->emergencia);
    printf("Digite se o voo é de emergência(1/0)%s: ", id_voo);
    scanf("%d", &emergencia);
    getchar();

    heap->elementos[index]->combustivel = combustivel;
    heap->elementos[index]->horario = horario;
    heap->elementos[index]->tipo = tipo;
    heap->elementos[index]->emergencia = emergencia;

    heap->elementos[index]->prioridade = (1000 - combustivel) + (1440 - horario) + (500 * tipo) + (5000 * emergencia);

    subir_elemento(heap, index);

    descer_elemento(heap, index);

    printf("Voo com ID %s atualizado com sucesso!\n", id_voo);
}

void liberar_heap(MaxHeap* heap) {

    for (int i = 0; i < heap->tamanho; i++) {
        if (heap->elementos[i]->id) {
            free(heap->elementos[i]->id);
        }
        free(heap->elementos[i]);
    }

    free(heap);
}