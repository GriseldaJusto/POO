#include "Cadastro.h"
#include "Gato.h"
#include "Peixe.h"
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

    size_t numAnimais = animais.size();
    file.write(reinterpret_cast<char*>(&numAnimais), sizeof(numAnimais));

    for (auto& animal : animais) {
        file.write(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));  // Salvar os dados de cada animal
    }
    file.close();
    std::cout << "Dados salvos com sucesso no arquivo!\n";
}

void Cadastro::carregarArquivo(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo para carregar.\n";
        return;
    }

    size_t numAnimais;
    file.read(reinterpret_cast<char*>(&numAnimais), sizeof(numAnimais));

    for (size_t i = 0; i < numAnimais; ++i) {
        int codigo, idade;
        float peso;
        char sexo;
        std::string nome;
        file.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
        file.read(reinterpret_cast<char*>(&idade), sizeof(idade));
        file.read(reinterpret_cast<char*>(&peso), sizeof(peso));
        file.read(&sexo, sizeof(sexo));

        std::getline(file, nome, '\0');

        std::string nomeTutor, endereco, telefone;
        std::getline(file, nomeTutor, '\0');
        std::getline(file, endereco, '\0');
        std::getline(file, telefone, '\0');
        Pessoa* tutor = new Pessoa(nomeTutor, endereco, telefone);

        int tipoAnimal;
        file.read(reinterpret_cast<char*>(&tipoAnimal), sizeof(tipoAnimal));

        if (tipoAnimal == 1) {  // Gato
            bool ronroneia, usaCaixa;
            std::string raca, pelo;
            file.read(reinterpret_cast<char*>(&ronroneia), sizeof(ronroneia));
            file.read(reinterpret_cast<char*>(&usaCaixa), sizeof(usaCaixa));

            std::getline(file, raca, '\0');
            std::getline(file, pelo, '\0');

            Gato* gato = new Gato(codigo, nome, idade, sexo, peso, ronroneia, usaCaixa, raca, pelo, tutor);
            animais.push_back(gato);  
        } else if (tipoAnimal == 2) {  // Peixe
            std::string escamas, temperatura, especie;
            std::getline(file, escamas, '\0');
            std::getline(file, temperatura, '\0');
            std::getline(file, especie, '\0');

            Peixe* peixe = new Peixe(codigo, nome, idade, sexo, peso, escamas, temperatura, especie, tutor);
            animais.push_back(peixe);  
        }
    }
    file.close();
    std::cout << "Dados carregados com sucesso!\n";
}
