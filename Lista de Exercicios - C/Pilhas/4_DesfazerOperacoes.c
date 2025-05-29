#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAM_ACAO 50

typedef struct {
    char acoes[MAX][TAM_ACAO];
    int topo;
} PilhaAcoes;

void adicionar_acao(PilhaAcoes *p, const char *acao) {
    if (p->topo < MAX - 1) {
        strcpy(p->acoes[++p->topo], acao);
        printf("Ação adicionada: %s\n", acao);
    }
}

void desfazer_acao(PilhaAcoes *p) {
    if (p->topo < 0) {
        printf("Nenhuma ação para desfazer.\n");
        return;
    }
    printf("Ação desfeita: %s\n", p->acoes[p->topo--]);
}

void listar_acoes(PilhaAcoes *p) {
    printf("Ações realizadas:\n");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d: %s\n", i+1, p->acoes[i]);
    }
}

int main() {
    PilhaAcoes editor = {.topo = -1};
    adicionar_acao(&editor, "Escreveu 'Olá'");
    adicionar_acao(&editor, "Escreveu 'Mundo'");
    listar_acoes(&editor);
    desfazer_acao(&editor);
    listar_acoes(&editor);
    return 0;
}
