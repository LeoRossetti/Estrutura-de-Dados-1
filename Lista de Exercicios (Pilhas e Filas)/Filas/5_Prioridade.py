import heapq

class FilaPrioridade:
    def __init__(self):
        self.fila = []
        self.indice = 0

    def inserir(self, item, prioridade):
        heapq.heappush(self.fila, (prioridade, item))
        self.indice += 1
        print(f"Tarefa '{item}' com prioridade {prioridade} adicionada à fila.")

    def remover(self):
        if self.fila:
            prioridade, item = heapq.heappop(self.fila)
            print(f"Tarefa '{item}' com prioridade {prioridade} removida da fila.")
        else:
            print("A fila de prioridade está vazia.")



fila = FilaPrioridade()

fila.inserir("Tarefa A", 3)
fila.inserir("Tarefa B", 1)
fila.inserir("Tarefa C", 2)

fila.remover()
fila.remover()
fila.remover()

fila.remover()