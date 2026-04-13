#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct No {
    Requisicao  dados;
    struct No  *proximo;
} No;

typedef struct {
    No  *head;
    No  *tail;
    int  tamanho;
} Fila;

void fila_inicializar(Fila *fila);
int  fila_inserir(Fila *fila, Requisicao req);
int  fila_remover(Fila *fila, Requisicao *destino);
int  fila_tamanho(const Fila *fila);
int  fila_esta_vazia(const Fila *fila);
void fila_destruir(Fila *fila);

#endif
