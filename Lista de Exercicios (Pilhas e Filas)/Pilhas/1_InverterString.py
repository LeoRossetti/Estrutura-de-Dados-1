def inverter_string(texto):
    
    pilha = []
    
    for char in texto:
        pilha.append(char)
    
    resultado = ""
    while pilha:
        resultado += pilha.pop()

    return resultado

print(inverter_string("Python"))