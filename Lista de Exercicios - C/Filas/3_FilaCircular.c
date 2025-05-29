#include <stdio.h>
#define MAX 5

typedef struct {
    int itens[MAX];
    int frente, tras, tamanho;
} FilaCircular;

void inicializarFila(FilaCircular *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int estaVazia(FilaCircular *f) {
    return (f->tamanho == 0);
}

int estaCheia(FilaCircular *f) {
    return (f->tamanho == MAX);
}

void enqueue(FilaCircular *f, int valor) {
    if (estaCheia(f)) {
        printf("Erro: A fila está cheia.\n");
        return;
    }
    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = valor;
    f->tamanho++;
    printf("Elemento %d enfileirado.\n", valor);
}

int dequeue(FilaCircular *f) {
    if (estaVazia(f)) {
        printf("Erro: A fila está vazia.\n");
        return -1;
    }
    int valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    printf("Elemento %d desenfileirado.\n", valor);
    return valor;
}

void mostrarFila(FilaCircular *f) {
    printf("Fila: [");
    for (int i = 0, idx = f->frente; i < f->tamanho; i++, idx = (idx + 1) % MAX) {
        printf("%d", f->itens[idx]);
        if (i < f->tamanho - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    FilaCircular fila;
    inicializarFila(&fila);
    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);
    enqueue(&fila, 4);
    enqueue(&fila, 5);
    enqueue(&fila, 6);
    mostrarFila(&fila);
    dequeue(&fila);
    dequeue(&fila);
    mostrarFila(&fila);
    enqueue(&fila, 6);
    enqueue(&fila, 7);
    mostrarFila(&fila);
    return 0;
}
