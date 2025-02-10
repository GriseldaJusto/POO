#include "AnimalDomestico.h"
#include <iostream>

AnimalDomestico::AnimalDomestico(int codigo, std::string nome, int idade, char sexo, float peso, Pessoa* tutor)
    : codigoRegistro(codigo), nomeAnimal(nome), idade(idade), sexo(sexo), peso(peso), tutor(tutor) {}

int AnimalDomestico::getCodigoRegistro() const {
    return codigoRegistro;
}

void AnimalDomestico::setIdade(int idade) {
    this->idade = idade;
}

void AnimalDomestico::setPeso(float peso) {
    this->peso = peso;
}

Pessoa* AnimalDomestico::getTutor() const {
    return tutor;
}

void AnimalDomestico::setTutor(Pessoa* novoTutor) {
    tutor = novoTutor;
}
