#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int avaliar_posfixa(const char *expressao) {
    int pilha[MAX];
    int topo = -1;
    char token[MAX];
    int i = 0, j = 0;
    while (1) {
        if (expressao[i] == ' ' || expressao[i] == '\0') {
            if (j > 0) {
                token[j] = '\0';
                if (isdigit(token[0])) {
                    pilha[++topo] = atoi(token);
                } else {
                    int b = pilha[topo--];
                    int a = pilha[topo--];
                    switch (token[0]) {
                        case '+': pilha[++topo] = a + b; break;
                        case '-': pilha[++topo] = a - b; break;
                        case '*': pilha[++topo] = a * b; break;
                        case '/': pilha[++topo] = a / b; break;
                    }
                }
                j = 0;
            }
            if (expressao[i] == '\0') break;
        } else {
            token[j++] = expressao[i];
        }
        i++;
    }
    return pilha[topo];
}

int main() {
    char expressao[MAX];
    printf("Digite a expressão pós-fixa: ");
    fgets(expressao, MAX, stdin);
    expressao[strcspn(expressao, "\n")] = 0;
    printf("Resultado: %d\n", avaliar_posfixa(expressao));
    return 0;
}
