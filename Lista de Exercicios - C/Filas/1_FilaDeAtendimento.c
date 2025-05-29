#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int id;
} Cliente;

typedef struct {
    Cliente fila[MAX];
    int inicio, fim, tamanho;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

void enfileirar(Fila *f, int id) {
    if (f->tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX;
    f->fila[f->fim].id = id;
    f->tamanho++;
    printf("Cliente %d entrou na fila.\n", id);
}

void desenfileirar(Fila *f) {
    if (f->tamanho == 0) {
        printf("Nenhum cliente na fila.\n");
        return;
    }
    Cliente *c = &f->fila[f->inicio];
    printf("Cliente %d foi atendido.\n", c->id);
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
}

void mostrar_fila(Fila *f) {
    if (f->tamanho == 0) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; i < f->tamanho; i++, idx = (idx + 1) % MAX) {
        printf("%d ", f->fila[idx].id);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Fila fila;
    inicializar(&fila);
    int tempo_simulacao = 20, tempo_atual = 0, ultimo_cliente = 0;
    while (tempo_atual < tempo_simulacao) {
        if (rand() % 10 < 3) {
            enfileirar(&fila, ++ultimo_cliente);
        }
        if (rand() % 10 < 5) {
            desenfileirar(&fila);
        }
        tempo_atual++;
    }
    return 0;
}