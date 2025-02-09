#ifndef CACHORRO_H
#define CACHORRO_H

#include "AnimalDomestico.h"

// Classe concreta Cachorro
class Cachorro : public AnimalDomestico {
public:
    Cachorro(string nome = "", int idade = 0, string raca = "", double peso = 0.0, string cor = "", 
             string genero = "", string dono = "", string endereco = "", string telefone = "", string historicoMedico = "");
    void exibir() const override;
    void salvar(ofstream &arquivo) const override;
    void carregar(ifstream &arquivo) override;
};

#endif
