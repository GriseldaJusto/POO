#ifndef PEIXE_H
#define PEIXE_H

#include "AnimalDomestico.h"

class Peixe : public AnimalDomestico {
private:
    std::string escamas;
    std::string temperatura;
    std::string especie;

public:
    Peixe(int codigo, std::string nome, int idade, char sexo, float peso, std::string escamas, std::string temperatura, std::string especie, Pessoa* tutor);
    void exibirInfo() const override;
};

#endif
