#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int eh_palindromo(const char *palavra) {
    int i = 0, j = strlen(palavra) - 1;
    while (i < j) {
        if (tolower(palavra[i]) != tolower(palavra[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    char palavra[MAX];
    printf("Digite uma palavra para verificar se é palíndromo: ");
    scanf("%s", palavra);
    if (eh_palindromo(palavra))
        printf("A palavra '%s' é um palíndromo.\n", palavra);
    else
        printf("A palavra '%s' não é um palíndromo.\n", palavra);
    return 0;
}