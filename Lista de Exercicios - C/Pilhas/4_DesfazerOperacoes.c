#include <stdio.h>      // Inclui a biblioteca padrão de entrada e saída
#include <string.h>     // Inclui a biblioteca para manipulação de strings

#define MAX 100         // Define o tamanho máximo da pilha
#define TAM_ACAO 50     // Define o tamanho máximo de cada ação (string)

typedef struct {
    char itens[MAX][TAM_ACAO]; // Vetor de strings para armazenar as ações
    int topo;                  // Índice do topo da pilha
} PilhaStr;

// Inicializa a pilha, definindo o topo como -1 (pilha vazia)
void inicializarPilha(PilhaStr *p) {
    p->topo = -1;
}

// Retorna 1 se a pilha está vazia, 0 caso contrário
int estaVazia(PilhaStr *p) {
    return (p->topo == -1);
}

// Retorna 1 se a pilha está cheia, 0 caso contrário
int estaCheia(PilhaStr *p) {
    return (p->topo == MAX - 1);
}

// Adiciona uma nova ação ao topo da pilha
void push(PilhaStr *p, const char *valor) {
    if (estaCheia(p)) return;                  // Não faz nada se a pilha estiver cheia
    strcpy(p->itens[++p->topo], valor);        // Incrementa o topo e copia a ação para a pilha
}

// Remove a ação do topo da pilha e armazena em 'dest'
void pop(PilhaStr *p, char *dest) {
    if (estaVazia(p)) {                        // Se a pilha estiver vazia
        dest[0] = '\0';                        // Retorna string vazia
        return;
    }
    strcpy(dest, p->itens[p->topo--]);         // Copia a ação do topo para 'dest'
}

// Lista todas as ações presentes na pilha
void listar(PilhaStr *p) {
    printf("Ações realizadas:\n");
    for (int i = 0; i <= p->topo; i++) {       // Percorre do início até o topo da pilha
        printf("%d: %s\n", i+1, p->itens[i]);  // Imprime o índice e a ação
    }
}

int main() {
    PilhaStr pilha;                            // Declara uma variável do tipo PilhaStr
    inicializarPilha(&pilha);                  // Inicializa a pilha

    push(&pilha, "Escreveu 'Olá'");            // Adiciona a ação "Escreveu 'Olá'" à pilha
    push(&pilha, "Escreveu 'Mundo'");          // Adiciona a ação "Escreveu 'Mundo'" à pilha

    listar(&pilha);                            // Lista todas as ações realizadas

    char acao[TAM_ACAO];                       // Declara uma string para armazenar a ação desfeita
    pop(&pilha, acao);                         // Desfaz a última ação (remove do topo da pilha)
    if (acao[0] != '\0')                       // Se alguma ação foi desfeita
        printf("Ação desfeita: %s\n", acao);   // Imprime a ação desfeita

    listar(&pilha);                            // Lista novamente as ações

    return 0;                                  
}
