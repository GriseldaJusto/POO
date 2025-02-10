#ifndef ANIMALDOMESTICO_H
#define ANIMALDOMESTICO_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Classe abstrata representando um animal doméstico
class AnimalDomestico {
protected:
    string nome;
    int idade;
    string raca;
    double peso;
    string cor;
    string genero;
    string dono;
    string endereco;
    string telefone;
    string historicoMedico;

public:
    // Construtor
    AnimalDomestico(string nome = "", int idade = 0, string raca = "", double peso = 0.0, string cor = "", 
                    string genero = "", string dono = "", string endereco = "", string telefone = "", string historicoMedico = "");
    virtual ~AnimalDomestico() {}
    
    // Métodos virtuais puros
    virtual void exibir() const = 0;
    virtual void salvar(ofstream &arquivo) const = 0;
    virtual void carregar(ifstream &arquivo) = 0;
    
    // Métodos de acesso (getters e setters)
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
    string getRaca() const { return raca; }
    double getPeso() const { return peso; }
    
    void setIdade(int novaIdade) { idade = novaIdade; }
    void setRaca(const string &novaRaca) { raca = novaRaca; }
    void setPeso(double novoPeso) { peso = novoPeso; }
};

#endif
