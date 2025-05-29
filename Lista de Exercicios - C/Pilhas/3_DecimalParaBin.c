#include <stdio.h>
#define MAX 32

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
    if (estaVazia(p)) return -1;
    return p->itens[p->topo--];
}

void decimal_para_binario(int numero) {
    PilhaInt pilha;
    inicializarPilha(&pilha);
    if (numero == 0) {
        printf("0\n");
        return;
    }
    while (numero > 0) {
        push(&pilha, numero % 2);
        numero /= 2;
    }
    printf("Binário: ");
    while (!estaVazia(&pilha)) {
        printf("%d", pop(&pilha));
    }
    printf("\n");
}

int main() {
    int numero;
    printf("Digite um número decimal: ");
    scanf("%d", &numero);
    decimal_para_binario(numero);
    return 0;
}
