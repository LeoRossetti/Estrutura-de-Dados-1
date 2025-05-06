def decimal_para_binario(numero):
    
    pilha = []
    
    while numero > 0:
        resto = numero % 2
        pilha.append(resto)
        numero //= 2

    binario = ""
    while pilha:
        binario += str(pilha.pop())

    return binario


print(decimal_para_binario(10))