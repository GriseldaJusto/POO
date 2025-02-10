#include "Gato.h"

// Implementação do construtor da classe Gato
Gato::Gato(string nome, int idade, string raca, double peso, 
    string dono, string endereco, string telefone)
: AnimalDomestico(nome, idade, raca, peso), dono(dono), endereco(endereco), telefone(telefone) {}

// Método para exibir os detalhes do gato
void Gato::exibir() const {
    cout << "Gato: " << nome << ", Idade: " << idade << ", Raça: " << raca << ", Peso: " << peso
         << ", Dono: " << dono << ", Endereço: " << endereco << ", Telefone: " << telefone << endl;
}

// Método para salvar os dados do gato no arquivo binário 
void Gato::salvar(ofstream &arquivo) const {
    arquivo.write(nome.c_str(), nome.size() + 1);
    arquivo.write((char*)&idade, sizeof(idade));
    arquivo.write(raca.c_str(), raca.size() + 1);
    arquivo.write((char*)&peso, sizeof(peso));
    arquivo.write(dono.c_str(), dono.size() + 1);
    arquivo.write(endereco.c_str(), endereco.size() + 1);
    arquivo.write(telefone.c_str(), telefone.size() + 1);
}


// Método para carregar os dados do gato do arquivo binário 

void Gato::carregar(ifstream &arquivo) {
    char buffer[100];
    arquivo.getline(buffer, sizeof(buffer), '\0');
    nome = buffer;
    arquivo.read((char*)&idade, sizeof(idade));
    arquivo.getline(buffer, sizeof(buffer), '\0');
    raca = buffer;
    arquivo.read((char*)&peso, sizeof(peso));
    arquivo.getline(buffer, sizeof(buffer), '\0');
    dono = buffer;
    arquivo.getline(buffer, sizeof(buffer), '\0');
    endereco = buffer;
    arquivo.getline(buffer, sizeof(buffer), '\0');
    telefone = buffer;
}





