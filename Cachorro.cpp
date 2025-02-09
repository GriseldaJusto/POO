
#include "Cachorro.h"

Cachorro::Cachorro(string nome, int idade, string raca, double peso, string cor,
                   string genero, string dono, string endereco, string telefone, string historicoMedico)
    : AnimalDomestico(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico) {}

void Cachorro::exibir() const {
    cout << "Cachorro: " << nome << ", Idade: " << idade << endl;
}

void Cachorro::salvar(ofstream &arquivo) const {
    arquivo.write((char*)this, sizeof(Cachorro));
}

void Cachorro::carregar(ifstream &arquivo) {
    arquivo.read((char*)this, sizeof(Cachorro));
}
