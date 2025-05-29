#include <stdio.h>
#define MAX 10

typedef struct {
    int fila[MAX];
    int inicio, fim, tamanho;
} FilaCircular;

void inicializar(FilaCircular *f, int capacidade) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int esta_cheia(FilaCircular *f, int capacidade) {
    return f->tamanho == capacidade;
}

int esta_vazia(FilaCircular *f) {
    return f->tamanho == 0;
}

int enfileirar(FilaCircular *f, int elemento, int capacidade) {
    if (esta_cheia(f, capacidade)) {
        printf("Erro: A fila está cheia.\n");
        return 0;
    }
    f->fim = (f->fim + 1) % capacidade;
    f->fila[f->fim] = elemento;
    f->tamanho++;
    printf("Elemento %d enfileirado.\n", elemento);
    return 1;
}

int desenfileirar(FilaCircular *f, int capacidade) {
    if (esta_vazia(f)) {
        printf("Erro: A fila está vazia.\n");
        return -1;
    }
    int elemento = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % capacidade;
    f->tamanho--;
    printf("Elemento %d desenfileirado.\n", elemento);
    return elemento;
}

void mostrar_fila(FilaCircular *f, int capacidade) {
    printf("Fila: [");
    for (int i = 0, idx = f->inicio; i < f->tamanho; i++, idx = (idx + 1) % capacidade) {
        printf("%d", f->fila[idx]);
        if (i < f->tamanho - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int capacidade = 5;
    FilaCircular fila;
    inicializar(&fila, capacidade);
    enfileirar(&fila, 1, capacidade);
    enfileirar(&fila, 2, capacidade);
    enfileirar(&fila, 3, capacidade);
    enfileirar(&fila, 4, capacidade);
    enfileirar(&fila, 5, capacidade);
    enfileirar(&fila, 6, capacidade);
    mostrar_fila(&fila, capacidade);
    desenfileirar(&fila, capacidade);
    desenfileirar(&fila, capacidade);
    mostrar_fila(&fila, capacidade);
    enfileirar(&fila, 6, capacidade);
    enfileirar(&fila, 7, capacidade);
    mostrar_fila(&fila, capacidade);
    return 0;
}
