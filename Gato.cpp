#include "Gato.h"

// Implementação do construtor da classe Gato
Gato::Gato(string nome, int idade, string raca, double peso, string cor,
           string genero, string dono, string endereco, string telefone, string historicoMedico)
    : AnimalDomestico(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico) {}

// Método para exibir os detalhes do gato
void Gato::exibir() const {
    cout << "Gato: " << nome << ", Idade: " << idade << endl;
}

// Método para salvar os dados do gato no arquivo binário corretamente
void Gato::salvar(ofstream &arquivo) const {
    arquivo.write((char*)this, sizeof(Gato));
}

// Método para carregar os dados do gato do arquivo binário corretamente
void Gato::carregar(ifstream &arquivo) {
    arquivo.read((char*)this, sizeof(Gato));
}
