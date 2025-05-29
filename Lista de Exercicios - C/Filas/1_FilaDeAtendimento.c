#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int frente, tras, tamanho;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int estaVazia(Fila *f) {
    return (f->tamanho == 0);
}

int estaCheia(Fila *f) {
    return (f->tamanho == MAX);
}

void enqueue(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = valor;
    f->tamanho++;
    printf("Cliente %d entrou na fila.\n", valor);
}

int dequeue(Fila *f) {
    if (estaVazia(f)) {
        printf("Nenhum cliente na fila.\n");
        return -1;
    }
    int valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    printf("Cliente %d foi atendido.\n", valor);
    return valor;
}

void mostrarFila(Fila *f) {
    if (estaVazia(f)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0, idx = f->frente; i < f->tamanho; i++, idx = (idx + 1) % MAX) {
        printf("%d ", f->itens[idx]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Fila fila;
    inicializarFila(&fila);
    int tempo_simulacao = 20, tempo_atual = 0, ultimo_cliente = 0;
    while (tempo_atual < tempo_simulacao) {
        if (rand() % 10 < 3) {
            enqueue(&fila, ++ultimo_cliente);
        }
        if (rand() % 10 < 5) {
            dequeue(&fila);
        }
        tempo_atual++;
    }
    return 0;
}