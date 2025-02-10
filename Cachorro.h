#ifndef CACHORRO_H
#define CACHORRO_H

#include "AnimalDomestico.h"

// Classe concreta Cachorro
class Cachorro : public AnimalDomestico {
    private:
        string cor;
        string genero;
        string historicoMedico;
    public:
        Cachorro(string nome = "", int idade = 0, string raca = "", double peso = 0.0, 
                 string cor = "", string genero = "", string historicoMedico = "");
        
        void exibir() const override;
        void salvar(ofstream &arquivo) const override;
        void carregar(ifstream &arquivo) override;
        //Adicionando os setters
        void setCor(const string &novaCor) { cor = novaCor; }
        void setGenero(const string &novoGenero) { genero = novoGenero; }
        void setHistoricoMedico(const string &novoHistorico) { historicoMedico = novoHistorico; }
    
        //Adicionando os getters para facilitar
        string getCor() const { return cor; }
        string getGenero() const { return genero; }
        string getHistoricoMedico() const { return historicoMedico; }
};
#endif
