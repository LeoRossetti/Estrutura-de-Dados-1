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
    if (estaCheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = valor;
}

char pop(PilhaChar *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return '\0';
    }
    return p->itens[p->topo--];
}

void inverter_string(const char *texto) {
    PilhaChar p;
    inicializarPilha(&p);
    int i = 0;
    while (texto[i] != '\0') {
        push(&p, texto[i]);
        i++;
    }
    printf("Invertido: ");
    while (!estaVazia(&p)) {
        printf("%c", pop(&p));
    }
    printf("\n");
}

int main() {
    char texto[MAX];
    printf("Digite uma palavra: ");
    scanf("%s", texto);
    inverter_string(texto);
    return 0;
}
