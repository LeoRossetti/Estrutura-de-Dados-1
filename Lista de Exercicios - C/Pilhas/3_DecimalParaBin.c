#include <stdio.h>

#define MAX 32

void decimal_para_binario(int numero) {
    int pilha[MAX];
    int topo = -1;
    if (numero == 0) {
        printf("0\n");
        return;
    }
    while (numero > 0) {
        pilha[++topo] = numero % 2;
        numero /= 2;
    }
    printf("Binário: ");
    while (topo >= 0) {
        printf("%d", pilha[topo--]);
    }
    printf("\n");
}

int main() {
    int numero;
    printf("Digite um número decimal: ");
    scanf("%d", &numero);
    decimal_para_binario(numero);
    return 0;
}
