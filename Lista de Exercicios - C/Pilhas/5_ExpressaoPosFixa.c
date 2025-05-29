#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} PilhaInt;

void inicializarPilha(PilhaInt *p) {
    p->topo = -1;
}

int estaVazia(PilhaInt *p) {
    return (p->topo == -1);
}

int estaCheia(PilhaInt *p) {
    return (p->topo == MAX - 1);
}

void push(PilhaInt *p, int valor) {
    if (estaCheia(p)) return;
    p->itens[++p->topo] = valor;
}

int pop(PilhaInt *p) {
    if (estaVazia(p)) return 0;
    return p->itens[p->topo--];
}

int avaliar_posfixa(const char *expressao) {
    PilhaInt pilha;
    inicializarPilha(&pilha);
    char token[MAX];
    int i = 0, j = 0;
    while (1) {
        if (expressao[i] == ' ' || expressao[i] == '\0') {
            if (j > 0) {
                token[j] = '\0';
                if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                    push(&pilha, atoi(token));
                } else {
                    int b = pop(&pilha);
                    int a = pop(&pilha);
                    switch (token[0]) {
                        case '+': push(&pilha, a + b); break;
                        case '-': push(&pilha, a - b); break;
                        case '*': push(&pilha, a * b); break;
                        case '/': push(&pilha, a / b); break;
                    }
                }
                j = 0;
            }
            if (expressao[i] == '\0') break;
        } else {
            token[j++] = expressao[i];
        }
        i++;
    }
    return pop(&pilha);
}

int main() {
    char expressao[MAX];
    printf("Digite a expressão pós-fixa: ");
    fgets(expressao, MAX, stdin);
    expressao[strcspn(expressao, "\n")] = 0;
    printf("Resultado: %d\n", avaliar_posfixa(expressao));
    return 0;
}
