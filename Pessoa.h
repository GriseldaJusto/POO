#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
private:
    std::string nomeTutor;
    std::string endereco;
    std::string telefone;

public:
    Pessoa(std::string nome, std::string endereco, std::string telefone);
    void exibirInfo() const;
};

#endif
