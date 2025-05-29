#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char itens[MAX];
    int topo;
} PilhaChar;

void inicializarPilha(PilhaChar *p) {
    p->topo = -1;
}

int estaVazia(PilhaChar *p) {
    return (p->topo == -1);
}

int estaCheia(PilhaChar *p) {
    return (p->topo == MAX - 1);
}

void push(PilhaChar *p, char valor) {
    if (estaCheia(p)) return;
    p->itens[++p->topo] = valor;
}

char pop(PilhaChar *p) {
    if (estaVazia(p)) return '\0';
    return p->itens[p->topo--];
}

int verifica_balanceamento(const char *expressao) {
    PilhaChar pilha;
    inicializarPilha(&pilha);
    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&pilha, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char topo = pop(&pilha);
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return 0;
            }
        }
    }
    return estaVazia(&pilha);
}

int main() {
    char expressao[MAX];
    printf("Digite a expressão: ");
    scanf("%s", expressao);
    if (verifica_balanceamento(expressao))
        printf("Expressão balanceada.\n");
    else
        printf("Expressão não balanceada.\n");
    return 0;
}
