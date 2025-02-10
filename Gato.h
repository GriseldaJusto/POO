#ifndef GATO_H
#define GATO_H

#include "AnimalDomestico.h"

// Classe concreta Gato
class Gato : public AnimalDomestico {
    private:
        string dono;
        string endereco;
        string telefone;
    public:
        Gato(string nome = "", int idade = 0, string raca = "", double peso = 0.0, 
             string dono = "", string endereco = "", string telefone = "");
        
        void exibir() const override;
        void salvar(ofstream &arquivo) const override;
        void carregar(ifstream &arquivo) override;

        //Adicionando os setters
        void setDono(const string &novoDono) { dono = novoDono; }
        void setEndereco(const string &novoEndereco) { endereco = novoEndereco; }
        void setTelefone(const string &novoTelefone) { telefone = novoTelefone; }
    
        //Adicionando os getters para facilitar
        string getDono() const { return dono; }
        string getEndereco() const { return endereco; }
        string getTelefone() const { return telefone; }
};

#endif