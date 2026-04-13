#include <stdio.h>
#include <string.h>
#include "requisicao.h"

Requisicao cria_requisicao(const char *nome, int inscricao, const char *proc) {
    Requisicao req;

    strncpy(req.nome_paciente, nome, TAM_NOME - 1);
    req.nome_paciente[TAM_NOME - 1] = '\0';

    req.codigo_inscricao = inscricao;

    strncpy(req.codigo_procedimento, proc, TAM_PROCEDIMENTO - 1);
    req.codigo_procedimento[TAM_PROCEDIMENTO - 1] = '\0';

    return req;
}

void exibe_requisicao(const Requisicao *req) {
    printf("  Paciente    : %s\n", req->nome_paciente);
    printf("  Inscrição   : %d\n", req->codigo_inscricao);
    printf("  Procedimento: %s\n", req->codigo_procedimento);
}
