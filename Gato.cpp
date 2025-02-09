
#include "Gato.h"

Gato::Gato(string nome, int idade, string raca, double peso, string cor,
           string genero, string dono, string endereco, string telefone, string historicoMedico)
    : AnimalDomestico(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico) {}

void Gato::exibir() const {
    cout << "Gato: " << nome << ", Idade: " << idade << endl;
}

void Gato::salvar(ofstream &arquivo) const {
    arquivo.write((char*)this, sizeof(Gato));
}

void Gato::carregar(ifstream &arquivo) {
    arquivo.read((char*)this, sizeof(Gato));
}