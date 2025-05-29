#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char itens[MAX];
    int frente, tras, tamanho;
} FilaChar;

typedef struct {
    char itens[MAX];
    int topo;
} PilhaChar;

void inicializarFila(FilaChar *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

void inicializarPilha(PilhaChar *p) {
    p->topo = -1;
}

void enqueue(FilaChar *f, char valor) {
    if (f->tamanho == MAX) return;
    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = valor;
    f->tamanho++;
}

char dequeue(FilaChar *f) {
    if (f->tamanho == 0) return '\0';
    char valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return valor;
}

void push(PilhaChar *p, char valor) {
    if (p->topo == MAX-1) return;
    p->itens[++p->topo] = valor;
}

char pop(PilhaChar *p) {
    if (p->topo == -1) return '\0';
    return p->itens[p->topo--];
}

int eh_palindromo(const char *palavra) {
    PilhaChar pilha;
    FilaChar fila;
    inicializarPilha(&pilha);
    inicializarFila(&fila);
    int n = strlen(palavra);
    for (int i = 0; i < n; i++) {
        char c = tolower(palavra[i]);
        push(&pilha, c);
        enqueue(&fila, c);
    }
    for (int i = 0; i < n; i++) {
        if (pop(&pilha) != dequeue(&fila))
            return 0;
    }
    return 1;
}

int main() {
    char palavra[MAX];
    printf("Digite uma palavra para verificar se é palíndromo: ");
    scanf("%s", palavra);
    if (eh_palindromo(palavra))
        printf("A palavra '%s' é um palíndromo.\n", palavra);
    else
        printf("A palavra '%s' não é um palíndromo.\n", palavra);
    return 0;
}