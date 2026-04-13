# SA1 — Gerenciamento de Requisições de Saúde
 
Implementação de um TAD Fila em linguagem C para gerenciar o fluxo de atendimento de pacientes em uma organização de saúde de grande porte.
 
## Estrutura de Arquivos
 
```
SA1_Gerenciamento_Saude/
├── requisicao.h     # Definição da entidade Requisição (paciente)
├── requisicao.c     # Implementação das funções da entidade
├── estrutura.h      # Contrato do TAD Fila (assinaturas)
├── estrutura.c      # Implementação da lógica da fila
└── main.c           # Código cliente para validação do fluxo
```
 
## TAD Fila
 
A fila é implementada com **lista encadeada** com ponteiros para o início (`head`) e o fim (`tail`), garantindo complexidade constante nas operações principais.
 
| Operação | Complexidade |
|---|---|
| `fila_inserir` | O(1) |
| `fila_remover` | O(1) |
| `fila_tamanho` | O(1) |
| `fila_destruir` | O(n) |
 
## Dados da Requisição
 
Cada requisição armazena:
- **Nome do Paciente** — string de até 40 caracteres
- **Código de Inscrição** — inteiro único
- **Código do Procedimento** — string de até 10 caracteres
 
## Como Compilar e Executar
 
```bash
gcc -Wall -Wextra -o sa1 requisicao.c estrutura.c main.c
./sa1
```
 
## Boas Práticas Aplicadas
 
- Verificação do retorno de `malloc` antes de manipular ponteiros
- Uso de `sizeof` para portabilidade
- `free()` em toda remoção e `fila_destruir()` ao encerrar, evitando memory leaks
- `strncpy` com limite explícito para prevenir buffer overflow
- Separação clara entre contrato (`estrutura.h`) e implementação (`estrutura.c`)
