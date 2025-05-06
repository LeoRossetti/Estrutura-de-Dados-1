def verifica_balanceamento(expressao):

    pilha = []
    pares = {')': '(', ']': '[', '}': '{'}

    for char in expressao:
        if char in '([{':
            pilha.append(char)
        elif char in ')]}':
            if not pilha or pilha[-1] != pares[char]:
                return False
            pilha.pop()

    return len(pilha) == 0

expressao = "{[()]}"
print(verifica_balanceamento(expressao))