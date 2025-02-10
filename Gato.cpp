#include "Gato.h"
#include <iostream>

Gato::Gato(int codigo, std::string nome, int idade, char sexo, float peso, bool ronroneia, bool usaCaixa, std::string raca, std::string pelo, Pessoa* tutor)
    : AnimalDomestico(codigo, nome, idade, sexo, peso, tutor), ronroneiaComFrequencia(ronroneia), usaCaixaDeAreia(usaCaixa), raca(raca), tipoPelo(pelo) {}

void Gato::exibirInfo() const {
    std::cout << "Gato: " << nomeAnimal << ", Idade: " << idade << " anos, Peso: " << peso << "kg\n";
    if (tutor != nullptr) {
        tutor->exibirInfo();  // Exibe as informações do tutor
    }
}
