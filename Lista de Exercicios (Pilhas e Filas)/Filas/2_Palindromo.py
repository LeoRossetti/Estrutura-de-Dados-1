from collections import deque

def verificar_palindromo(palavra):

    palavra = palavra.lower()

    pilha = []
    fila = deque()


    for char in palavra:
        pilha.append(char)
        fila.append(char)


    while pilha:
        if pilha.pop() != fila.popleft():
            return False

    return True


palavra = input("Digite uma palavra para verificar se é palíndromo: ")
if verificar_palindromo(palavra):
    print(f"A palavra '{palavra}' é um palíndromo.")
else:
    print(f"A palavra '{palavra}' não é um palíndromo.")