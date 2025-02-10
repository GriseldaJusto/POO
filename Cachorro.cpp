#include "Cachorro.h"

// Implementação do construtor da classe Cachorro
Cachorro::Cachorro(string nome, int idade, string raca, double peso, string cor,
                   string genero, string dono, string endereco, string telefone, string historicoMedico)
    : AnimalDomestico(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico) {}

// Método para exibir os detalhes do cachorro
void Cachorro::exibir() const {
    cout << "Cachorro: " << nome << ", Idade: " << idade << ", Raça: " << raca << ", Peso: " << peso
         << ", Cor: " << cor << ", Gênero: " << genero << ", Dono: " << dono << ", Endereço: " << endereco
         << ", Telefone: " << telefone << ", Histórico Médico: " << historicoMedico << endl;
}

// Método para salvar os dados do cachorro no arquivo binário corretamente
void Cachorro::salvar(ofstream &arquivo) const {
    arquivo.write(nome.c_str(), nome.size() + 1);
    arquivo.write((char*)&idade, sizeof(idade));
    arquivo.write(raca.c_str(), raca.size() + 1);
    arquivo.write((char*)&peso, sizeof(peso));
    arquivo.write(cor.c_str(), cor.size() + 1);
    arquivo.write(genero.c_str(), genero.size() + 1);
    arquivo.write(dono.c_str(), dono.size() + 1);
    arquivo.write(endereco.c_str(), endereco.size() + 1);
    arquivo.write(telefone.c_str(), telefone.size() + 1);
    arquivo.write(historicoMedico.c_str(), historicoMedico.size() + 1);
}

// Método para carregar os dados do cachorro do arquivo binário corretamente
void Cachorro::carregar(ifstream &arquivo) {
    char buffer[100];
    arquivo.getline(buffer, 100, '\0');
    nome = buffer;
    arquivo.read((char*)&idade, sizeof(idade));
    arquivo.getline(buffer, 100, '\0');
    raca = buffer;
    arquivo.read((char*)&peso, sizeof(peso));
    arquivo.getline(buffer, 100, '\0');
    cor = buffer;
    arquivo.getline(buffer, 100, '\0');
    genero = buffer;
    arquivo.getline(buffer, 100, '\0');
    dono = buffer;
    arquivo.getline(buffer, 100, '\0');
    endereco = buffer;
    arquivo.getline(buffer, 100, '\0');
    telefone = buffer;
    arquivo.getline(buffer, 100, '\0');
    historicoMedico = buffer;
}
