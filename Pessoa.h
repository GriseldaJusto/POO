#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string endereco;
    std::string telefone;

public:
    Pessoa(std::string nome, std::string endereco, std::string telefone);
    
    std::string getNome() const;
    std::string getEndereco() const;
    std::string getTelefone() const;
    
    void exibirInfo() const;
};

#endif
