#include <stdio.h>
#include <string.h>

#define MAX 100

void inverter_string(char *texto) {
    char pilha[MAX];
    int topo = -1;
    int i = 0;
    while (texto[i] != '\0') {
        pilha[++topo] = texto[i];
        i++;
    }
    printf("Invertido: ");
    while (topo >= 0) {
        printf("%c", pilha[topo--]);
    }
    printf("\n");
}

int main() {
    char texto[MAX];
    printf("Digite uma palavra: ");
    scanf("%s", texto);
    inverter_string(texto);
    return 0;
}
