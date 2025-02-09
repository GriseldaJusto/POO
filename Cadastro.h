#ifndef CADASTRO_H
#define CADASTRO_H

#include "Cachorro.h"
#include "Gato.h"
#include <vector>

// Classe responsável por gerenciar o CRUD dos animais
class Cadastro {
private:
    vector<AnimalDomestico*> animais; // Lista de ponteiros para animais
public:
    ~Cadastro(); // Destrutor adequado para liberar memória
    void adicionar(AnimalDomestico* animal);
    void listar() const;
    void atualizar(const string& nome);
    void remover(const string& nome);
    void salvarArquivo(const string &arquivoNome) const;
    void carregarArquivo(const string &arquivoNome);
};

#endif