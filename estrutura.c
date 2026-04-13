#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void fila_inicializar(Fila *fila) {
    fila->head    = NULL;
    fila->tail    = NULL;
    fila->tamanho = 0;
}

int fila_inserir(Fila *fila, Requisicao req) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        fprintf(stderr, "[ERRO] fila_inserir: falha ao alocar memoria.\n");
        return 0;
    }

    novo->dados   = req;
    novo->proximo = NULL;

    if (fila->tail == NULL) {
        fila->head = novo;
        fila->tail = novo;
    } else {
        fila->tail->proximo = novo;
        fila->tail          = novo;
    }

    fila->tamanho++;
    return 1;
}

int fila_remover(Fila *fila, Requisicao *destino) {
    if (fila->head == NULL) {
        fprintf(stderr, "[AVISO] fila_remover: fila vazia.\n");
        return 0;
    }

    No *removido = fila->head;

    if (destino != NULL) {
        *destino = removido->dados;
    }

    fila->head = removido->proximo;

    if (fila->head == NULL) {
        fila->tail = NULL;
    }

    free(removido);
    fila->tamanho--;
    return 1;
}

int fila_tamanho(const Fila *fila) {
    return fila->tamanho;
}

int fila_esta_vazia(const Fila *fila) {
    return (fila->tamanho == 0);
}

void fila_destruir(Fila *fila) {
    No *atual = fila->head;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    fila->head    = NULL;
    fila->tail    = NULL;
    fila->tamanho = 0;
}
