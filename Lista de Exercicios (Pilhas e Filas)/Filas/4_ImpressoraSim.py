from collections import deque

class Impressora:
    
    def __init__(self):
        
        self.fila = deque()

    def adicionar_documento(self, nome, paginas):
        self.fila.append({"nome": nome, "paginas": paginas})
        print(f"Documento '{nome}' com {paginas} páginas adicionado à fila.")

    def imprimir_proximo(self):
        if not self.fila:
            print("Nenhum documento na fila para imprimir.")
            return None

        documento = self.fila.popleft()
        print(f"Imprimindo documento '{documento['nome']}' com {documento['paginas']} páginas.")
        return documento

    def mostrar_fila(self):
        if not self.fila:
            print("A fila de impressão está vazia.")
        else:
            print("Fila de impressão:")
            for i, doc in enumerate(self.fila, start=1):
                print(f"{i}. {doc['nome']} - {doc['paginas']} páginas")


impressora = Impressora()

impressora.adicionar_documento("Trabalho", 10)
impressora.adicionar_documento("Relatório", 5)
impressora.adicionar_documento("Apresentação", 15)

impressora.mostrar_fila()

impressora.imprimir_proximo()
impressora.imprimir_proximo()

impressora.mostrar_fila()

impressora.imprimir_proximo()

impressora.imprimir_proximo()