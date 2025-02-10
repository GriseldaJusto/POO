#ifndef ANIMALDOMESTICO_H
#define ANIMALDOMESTICO_H

#include <string>
#include "Pessoa.h"  // Importa a classe Pessoa

class AnimalDomestico {
protected:
    int codigoRegistro;
    std::string nomeAnimal;
    int idade;
    char sexo;
    float peso;
    Pessoa* tutor;  // Ponteiro para o tutor

public:
    AnimalDomestico(int codigo, std::string nome, int idade, char sexo, float peso, Pessoa* tutor = nullptr);
    virtual ~AnimalDomestico() = default;

    virtual void exibirInfo() const = 0;
    int getCodigoRegistro() const;
    void setIdade(int idade);
    void setPeso(float peso);
    Pessoa* getTutor() const;  // Getter do tutor
    void setTutor(Pessoa* novoTutor);  // Setter do tutor
};

#endif
