#include <stdio.h>
#include <string.h>

#define MAX 100

int verifica_balanceamento(const char *expressao) {
    char pilha[MAX];
    int topo = -1;
    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha[++topo] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (topo < 0) return 0;
            char topo_pilha = pilha[topo--];
            if ((c == ')' && topo_pilha != '(') ||
                (c == ']' && topo_pilha != '[') ||
                (c == '}' && topo_pilha != '{')) {
                return 0;
            }
        }
    }
    return topo == -1;
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
