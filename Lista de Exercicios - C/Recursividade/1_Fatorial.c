#include <stdio.h>

// Função recursiva para calcular o fatorial de um número inteiro positivo n
int fatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    printf("Fatorial de %d = %d\n", n, fatorial(n));
    return 0;
}
