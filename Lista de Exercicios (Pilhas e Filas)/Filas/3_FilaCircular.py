class FilaCircular:
    
    def __init__(self, capacidade):

        self.capacidade = capacidade
        self.fila = [None] * capacidade
        self.inicio = 0
        self.fim = -1
        self.tamanho = 0

    def enfileirar(self, elemento):
        if self.esta_cheia():
            print("Erro: A fila está cheia.")
            return False

        self.fim = (self.fim + 1) % self.capacidade
        self.fila[self.fim] = elemento
        self.tamanho += 1
        print(f"Elemento {elemento} enfileirado.")
        return True

    def desenfileirar(self):
        if self.esta_vazia():
            print("Erro: A fila está vazia.")
            return None

        elemento = self.fila[self.inicio]
        self.fila[self.inicio] = None  # Limpa o espaço
        self.inicio = (self.inicio + 1) % self.capacidade
        self.tamanho -= 1
        print(f"Elemento {elemento} desenfileirado.")
        return elemento

    def esta_cheia(self):
        return self.tamanho == self.capacidade

    def esta_vazia(self):
        return self.tamanho == 0

    def mostrar_fila(self):
        print("Fila:", self.fila)


fila = FilaCircular(5)

fila.enfileirar(1)
fila.enfileirar(2)
fila.enfileirar(3)
fila.enfileirar(4)
fila.enfileirar(5)

fila.enfileirar(6)

fila.mostrar_fila()

fila.desenfileirar()
fila.desenfileirar() 

fila.mostrar_fila()

fila.enfileirar(6)
fila.enfileirar(7)

fila.mostrar_fila()