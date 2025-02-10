#ifndef GATO_H
#define GATO_H

#include "AnimalDomestico.h"

class Gato : public AnimalDomestico {
private:
    bool ronroneiaComFrequencia;
    bool usaCaixaDeAreia;
    std::string raca;
    std::string tipoPelo;

public:
    Gato(int codigo, std::string nome, int idade, char sexo, float peso, bool ronroneia, bool usaCaixa, std::string raca, std::string pelo, Pessoa* tutor);
    void exibirInfo() const override;
};

#endif
