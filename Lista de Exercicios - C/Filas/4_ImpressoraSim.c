#include <stdio.h>
#include <string.h>

#define MAX 10
#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int paginas;
} Documento;

typedef struct {
    Documento fila[MAX];
    int inicio, fim, tamanho;
} Impressora;

void inicializar(Impressora *imp) {
    imp->inicio = 0;
    imp->fim = -1;
    imp->tamanho = 0;
}

void adicionar_documento(Impressora *imp, const char *nome, int paginas) {
    if (imp->tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    imp->fim = (imp->fim + 1) % MAX;
    strcpy(imp->fila[imp->fim].nome, nome);
    imp->fila[imp->fim].paginas = paginas;
    imp->tamanho++;
    printf("Documento '%s' com %d páginas adicionado à fila.\n", nome, paginas);
}

void imprimir_proximo(Impressora *imp) {
    if (imp->tamanho == 0) {
        printf("Nenhum documento na fila para imprimir.\n");
        return;
    }
    Documento *doc = &imp->fila[imp->inicio];
    printf("Imprimindo documento '%s' com %d páginas.\n", doc->nome, doc->paginas);
    imp->inicio = (imp->inicio + 1) % MAX;
    imp->tamanho--;
}

void mostrar_fila(Impressora *imp) {
    if (imp->tamanho == 0) {
        printf("A fila de impressão está vazia.\n");
        return;
    }
    printf("Fila de impressão:\n");
    int i, idx;
    for (i = 0, idx = imp->inicio; i < imp->tamanho; i++, idx = (idx + 1) % MAX) {
        printf("%d. %s - %d páginas\n", i+1, imp->fila[idx].nome, imp->fila[idx].paginas);
    }
}

int main() {
    Impressora impressora;
    inicializar(&impressora);
    adicionar_documento(&impressora, "Trabalho", 10);
    adicionar_documento(&impressora, "Relatório", 5);
    adicionar_documento(&impressora, "Apresentação", 15);
    mostrar_fila(&impressora);
    imprimir_proximo(&impressora);
    imprimir_proximo(&impressora);
    mostrar_fila(&impressora);
    imprimir_proximo(&impressora);
    imprimir_proximo(&impressora);
    return 0;
}