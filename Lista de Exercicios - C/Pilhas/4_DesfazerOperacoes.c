#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAM_ACAO 50

typedef struct {
    char itens[MAX][TAM_ACAO];
    int topo;
} PilhaStr;

void inicializarPilha(PilhaStr *p) {
    p->topo = -1;
}

int estaVazia(PilhaStr *p) {
    return (p->topo == -1);
}

int estaCheia(PilhaStr *p) {
    return (p->topo == MAX - 1);
}

void push(PilhaStr *p, const char *valor) {
    if (estaCheia(p)) return;
    strcpy(p->itens[++p->topo], valor);
}

void pop(PilhaStr *p, char *dest) {
    if (estaVazia(p)) {
        dest[0] = '\0';
        return;
    }
    strcpy(dest, p->itens[p->topo--]);
}

void listar(PilhaStr *p) {
    printf("Ações realizadas:\n");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d: %s\n", i+1, p->itens[i]);
    }
}

int main() {
    PilhaStr pilha;
    inicializarPilha(&pilha);
    push(&pilha, "Escreveu 'Olá'");
    push(&pilha, "Escreveu 'Mundo'");
    listar(&pilha);
    char acao[TAM_ACAO];
    pop(&pilha, acao);
    if (acao[0] != '\0') printf("Ação desfeita: %s\n", acao);
    listar(&pilha);
    return 0;
}
