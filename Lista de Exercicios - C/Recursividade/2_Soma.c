#include <stdio.h>

// Função recursiva para somar os elementos de um vetor
int soma_lista(int v[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return v[n-1] + soma_lista(v, n-1);
    }
}

int main() {
    int n, i;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
    int v[n];
    printf("Digite os %d elementos:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    printf("Soma dos elementos = %d\n", soma_lista(v, n));
    return 0;
}
