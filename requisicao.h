#ifndef REQUISICAO_H
#define REQUISICAO_H

#define TAM_NOME        40
#define TAM_PROCEDIMENTO 10

typedef struct {
    char nome_paciente[TAM_NOME];
    int  codigo_inscricao;
    char codigo_procedimento[TAM_PROCEDIMENTO];
} Requisicao;

Requisicao cria_requisicao(const char *nome, int inscricao, const char *proc);
void       exibe_requisicao(const Requisicao *req);

#endif
