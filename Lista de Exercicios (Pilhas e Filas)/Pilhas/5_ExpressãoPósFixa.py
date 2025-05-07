def avaliar_posfixa(expressao):
    
    pilha = []
    tokens = expressao.split()

    for token in tokens:
        if token.isdigit():
            pilha.append(int(token))
        elif token in "+-*/":
            if len(pilha) < 2:
                raise ValueError("Expressão inválida.")
            b = pilha.pop()
            a = pilha.pop()
            if token == "+":
                pilha.append(a + b)
            elif token == "-":
                pilha.append(a - b)
            elif token == "*":
                pilha.append(a * b)
            elif token == "/":
                pilha.append(a / b)
        else:
            raise ValueError(f"Token inválido: {token}")

    if len(pilha) != 1:
        raise ValueError("Expressão inválida.")
    return pilha.pop()


expressao = "2 3 +"
print(avaliar_posfixa(expressao))