#include <stdio.h>
#include "requisicao.h"
#include "estrutura.h"

#define LIMIAR_ALERTA 3

static void separador(void) {
    printf("\n--------------------------------------------\n");
}

int main(void) {
    Fila fila_atendimento;
    fila_inicializar(&fila_atendimento);

    printf("==============================================\n");
    printf("  Sistema de Gerenciamento de Saude — SA1    \n");
    printf("==============================================\n");

    separador();
    printf("FASE 1 — Chegada de pacientes\n");
    separador();

    Requisicao pacientes[] = {
        cria_requisicao("Ana Paula Ferreira",  1001, "CARD-01"),
        cria_requisicao("Bruno Souza Lima",    1002, "ORTO-03"),
        cria_requisicao("Carla Mendes Rocha",  1003, "NEUR-07"),
        cria_requisicao("Diego Alves Neto",    1004, "DERM-02"),
        cria_requisicao("Eliane Costa Pinto",  1005, "ONCO-11"),
    };

    int n = (int)(sizeof(pacientes) / sizeof(pacientes[0]));

    for (int i = 0; i < n; i++) {
        if (fila_inserir(&fila_atendimento, pacientes[i])) {
            printf("[INSERIDO] %s | Inscricao: %d\n",
                   pacientes[i].nome_paciente,
                   pacientes[i].codigo_inscricao);
        }
    }

    separador();
    printf("FASE 2 — Monitoramento da fila\n");
    separador();

    int em_espera = fila_tamanho(&fila_atendimento);
    printf("Pacientes em espera: %d\n", em_espera);

    if (em_espera > LIMIAR_ALERTA) {
        printf("[ALERTA] Acionar instituicao parceira!\n");
    }

    separador();
    printf("FASE 3 — Atendimento (FIFO)\n");
    separador();

    for (int i = 0; i < 3; i++) {
        Requisicao atendido;
        if (fila_remover(&fila_atendimento, &atendido)) {
            printf("[ATENDIDO]\n");
            exibe_requisicao(&atendido);
            printf("  Fila restante: %d\n\n", fila_tamanho(&fila_atendimento));
        }
    }

    separador();
    printf("FASE 4 — Reavaliacao\n");
    separador();

    em_espera = fila_tamanho(&fila_atendimento);
    printf("Pacientes em espera: %d\n", em_espera);

    if (em_espera <= LIMIAR_ALERTA) {
        printf("[OK] Fila dentro do limite.\n");
    }

    separador();
    printf("FASE 5 — Esvaziando a fila\n");
    separador();

    while (!fila_esta_vazia(&fila_atendimento)) {
        Requisicao atendido;
        fila_remover(&fila_atendimento, &atendido);
        printf("[ATENDIDO] %s (inscricao %d)\n",
               atendido.nome_paciente, atendido.codigo_inscricao);
    }

    printf("\nTentando remover de fila vazia:\n");
    fila_remover(&fila_atendimento, NULL);

    fila_destruir(&fila_atendimento);

    separador();
    printf("Memoria liberada. Sistema encerrado.\n");
    printf("==============================================\n\n");

    return 0;
}
