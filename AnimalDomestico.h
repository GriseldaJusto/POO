#ifndef ANIMALDOMESTICO_H
#define ANIMALDOMESTICO_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AnimalDomestico {
    protected:
        string nome;
        int idade;
        string raca;
        double peso;
    public:
        AnimalDomestico(string nome = "", int idade = 0, string raca = "", double peso = 0.0);
        virtual ~AnimalDomestico() {}
    
        virtual void exibir() const = 0;
        virtual void salvar(ofstream &arquivo) const = 0;
        virtual void carregar(ifstream &arquivo) = 0;
    
        // Métodos de acesso
        string getNome() const { return nome; }
        int getIdade() const { return idade; }
        string getRaca() const { return raca; }
        double getPeso() const { return peso; }

        //Adicionando o setter 
        void setIdade(int novaIdade) { idade = novaIdade; }
        void setPeso(int novoPeso) { peso = novoPeso; }
    };
    
#endif
