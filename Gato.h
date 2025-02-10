#ifndef GATO_H
#define GATO_H

#include "AnimalDomestico.h"

// Classe concreta Gato
class Gato : public AnimalDomestico {
public:
    Gato(string nome = "", int idade = 0, string raca = "", double peso = 0.0, string cor = "", 
         string genero = "", string dono = "", string endereco = "", string telefone = "", string historicoMedico = "");
    void exibir() const override;
    void salvar(ofstream &arquivo) const override;
    void carregar(ifstream &arquivo) override;
};

#endif
