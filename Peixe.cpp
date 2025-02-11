#include "Peixe.h"
#include <iostream>

Peixe::Peixe(int codigo, std::string nome, int idade, char sexo, float peso, std::string escamas, std::string temperatura, std::string especie, Pessoa* tutor)
    : AnimalDomestico(codigo, nome, idade, sexo, peso, tutor), escamas(escamas), temperatura(temperatura), especie(especie) {}

void Peixe::exibirInfo() const {
    std::cout << "Peixe: " << nomeAnimal << ", Idade: " << idade << " anos, Peso: " << peso << "kg\n";
    std::cout << "Escamas: " << escamas << "\n";
    std::cout << "Temperatura da agua: " << temperatura << "\n";
    std::cout << "Especie: " << especie << "\n";
    
    if (tutor != nullptr) {
        tutor->exibirInfo();  // Exibe as informações do tutor
    }
}
