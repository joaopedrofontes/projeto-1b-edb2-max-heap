#include "file-utils.h"

MaxHeap* ler_csv_e_inserir(MaxHeap* heap, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return heap;
    }

    char buffer[1024];
    char id[100];
    int combustivel, horario, tipo, emergencia;

    while (fgets(buffer, sizeof(buffer), file)) {
        char* token = strtok(buffer, ",");
        strcpy(id, token);

        token = strtok(NULL, ",");
        combustivel = atoi(token);

        token = strtok(NULL, ",");
        horario = atoi(token);

        token = strtok(NULL, ",");
        tipo = atoi(token);

        token = strtok(NULL, ",");
        emergencia = atoi(token);

        
        Voo* novo_voo = criar_voo(id, combustivel, horario, tipo, emergencia);
        inserir_elemento(heap, novo_voo);
    }

    fclose(file);
    return heap;
}