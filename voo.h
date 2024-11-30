#ifndef VOO_H
#define VOO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Voo {
    char* id;
    int combustivel;
    int horario;
    int tipo;
    int emergencia;
    int prioridade;
 } Voo;

Voo* criar_voo(char* id, int combustivel, int horario, int tipo, int emergencia);

#endif