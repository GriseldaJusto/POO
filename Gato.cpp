#include "Gato.h"
#include <iostream>

Gato::Gato(int codigo, std::string nome, int idade, char sexo, float peso, bool ronroneia, bool usaCaixa, std::string raca, std::string pelo, Pessoa* tutor)
    : AnimalDomestico(codigo, nome, idade, sexo, peso, tutor), ronroneiaComFrequencia(ronroneia), usaCaixaDeAreia(usaCaixa), raca(raca), tipoPelo(pelo) {}

void Gato::exibirInfo() const {
    std::cout << "Gato: " << nomeAnimal << ", Idade: " << idade << " anos, Peso: " << peso << "kg\n";
    std::cout << "Ronroneia com frequencia: " << (ronroneiaComFrequencia ? "Sim" : "Nao") << "\n";
    std::cout << "Usa caixa de areia: " << (usaCaixaDeAreia ? "Sim" : "Nao") << "\n";
    std::cout << "Raca: " << raca << "\n";
    std::cout << "Tipo de pelo: " << tipoPelo << "\n";
    
    if (tutor != nullptr) {
        tutor->exibirInfo();  // Exibe as informações do tutor
    }
}
