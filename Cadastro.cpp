#include "Cadastro.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void Cadastro::adicionarAnimal(AnimalDomestico* animal) {
    animais.push_back(animal);
}

void Cadastro::listarAnimais() const {
    for (const auto& animal : animais) {
        animal->exibirInfo();
        std::cout << "--------------------\n";
    }
}

void Cadastro::removerAnimal(int codigo) {
    auto it = std::remove_if(animais.begin(), animais.end(),
                             [codigo](AnimalDomestico* animal) { return animal->getCodigoRegistro() == codigo; });
    for (auto i = it; i != animais.end(); ++i) {
        delete *i;
    }
    animais.erase(it, animais.end());
}

void Cadastro::atualizarAnimal(int codigo) {
    for (auto& animal : animais) {
        if (animal->getCodigoRegistro() == codigo) {
            int novaIdade;
            float novoPeso;
            std::cout << "Nova idade: ";
            std::cin >> novaIdade;
            std::cout << "Novo peso: ";
            std::cin >> novoPeso;

            animal->setIdade(novaIdade);
            animal->setPeso(novoPeso);

            // Atualiza o tutor
            std::string nomeTutor, endereco, telefone;
            std::cout << "Novo nome do tutor: ";
            std::cin.ignore();  // Limpar o buffer de entrada
            std::getline(std::cin, nomeTutor);
            std::cout << "Novo endereco do tutor: ";
            std::getline(std::cin, endereco);
            std::cout << "Novo telefone do tutor: ";
            std::getline(std::cin, telefone);

            Pessoa* novoTutor = new Pessoa(nomeTutor, endereco, telefone);
            animal->setTutor(novoTutor);

            std::cout << "Animal e tutor atualizados!\n";
            return;
        }
    }
    std::cout << "Animal nao encontrado!\n";
}

void Cadastro::salvarArquivo(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo para salvar.\n";
        return;
    }
    for (auto& animal : animais) {
        file.write(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));
    }
    file.close();
}

void Cadastro::carregarArquivo(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo para carregar.\n";
        return;
    }
    // Implementação da leitura dos animais do arquivo
    file.close();
}
