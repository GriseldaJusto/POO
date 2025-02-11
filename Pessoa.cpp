#include "Pessoa.h"

Pessoa::Pessoa(std::string nome, std::string endereco, std::string telefone)
    : nome(nome), endereco(endereco), telefone(telefone) {}

std::string Pessoa::getNome() const {
    return nome;
}

std::string Pessoa::getEndereco() const {
    return endereco;
}

std::string Pessoa::getTelefone() const {
    return telefone;
}

void Pessoa::exibirInfo() const {
    std::cout << "Nome do Tutor: " << nome << "\n";
    std::cout << "Endereco: " << endereco << "\n";
    std::cout << "Telefone: " << telefone << "\n";
}
