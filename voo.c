#include "voo.h"

Voo* criar_voo(char* id, int combustivel, int horario, int tipo, int emergencia) {

    Voo* novo_voo = (Voo*)malloc(sizeof(Voo));
    
    novo_voo->id = (char*)malloc(strlen(id) + 1);
    strcpy(novo_voo->id, id);
    novo_voo->combustivel = combustivel;
    novo_voo->horario = horario;
    novo_voo->tipo = tipo;
    novo_voo->emergencia = emergencia;

    novo_voo->prioridade = (1000 - combustivel) + (1440 - horario) + (500 * tipo) + (5000 * emergencia);

    return novo_voo;
}