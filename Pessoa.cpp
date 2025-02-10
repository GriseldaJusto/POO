#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(std::string nome, std::string endereco, std::string telefone)
    : nomeTutor(nome), endereco(endereco), telefone(telefone) {}

void Pessoa::exibirInfo() const {
    std::cout << "Tutor: " << nomeTutor << ", Endereco: " << endereco << ", Telefone: " << telefone << "\n";
}
