class EditorTexto:
    def __init__(self):
        self.pilha_acoes = []

    def adicionar_acao(self, acao):
        self.pilha_acoes.append(acao)
        print(f"Ação adicionada: {acao}")

    def desfazer_acao(self):
        if not self.pilha_acoes:
            print("Nenhuma ação para desfazer.")
            return None
        ultima_acao = self.pilha_acoes.pop()
        print(f"Ação desfeita: {ultima_acao}")
        return ultima_acao

    def listar_acoes(self):
        print("Ações realizadas:", self.pilha_acoes)


editor = EditorTexto()
editor.adicionar_acao("Escreveu 'Olá'")
editor.adicionar_acao("Escreveu 'Mundo'")
editor.listar_acoes()
editor.desfazer_acao()
editor.listar_acoes()