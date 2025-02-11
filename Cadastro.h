#ifndef CADASTRO_H
#define CADASTRO_H

#include "AnimalDomestico.h"
#include "Pessoa.h"
#include <vector>
#include <string>

class Cadastro {
private:
    std::vector<AnimalDomestico*> animais;  // Vetor de ponteiros para animais

public:
    void adicionarAnimal(AnimalDomestico* animal);
    void listarAnimais() const;
    void removerAnimal(int codigo);
    void atualizarAnimal(int codigo);
    void salvarArquivo(const std::string& filename);
    void carregarArquivo(const std::string& filename);
};

#endif
