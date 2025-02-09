
#ifndef CADASTRO_H
#define CADASTRO_H

#include "Cachorro.h"
#include "Gato.h"
#include <vector>

class Cadastro {
private:
    vector<AnimalDomestico*> animais;
public:
    void adicionar(AnimalDomestico* animal);
    void listar() const;
    void atualizar(const string& nome);
    void remover(const string& nome);
    void salvarArquivo(const string &arquivoNome) const;
    void carregarArquivo(const string &arquivoNome);
};

#endif
