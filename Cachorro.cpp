#include "Cachorro.h"

// Implementação do construtor da classe Cachorro
Cachorro::Cachorro(string nome, int idade, string raca, double peso, 
    string cor, string genero, string HistoricoMedico)
: AnimalDomestico(nome, idade, raca, peso), cor(cor), genero(genero), historicoMedico(HistoricoMedico) {}

// Método para exibir os detalhes do cachorro
void Cachorro::exibir() const {
    cout << "Cachorro: " << nome << ", Idade: " << idade << ", Raça: " << raca << ", Peso: " << peso
         << ", Cor: " << cor << ", Genero: " << genero << ", Historico medico: " << historicoMedico << endl;
}

// Método para salvar os dados do cachorro no arquivo binário 
void Cachorro::salvar(ofstream &arquivo) const {
    arquivo.write(nome.c_str(), nome.size() + 1);
    arquivo.write((char*)&idade, sizeof(idade));
    arquivo.write(raca.c_str(), raca.size() + 1);
    arquivo.write((char*)&peso, sizeof(peso));
    arquivo.write(cor.c_str(), cor.size() + 1);
    arquivo.write(genero.c_str(), genero.size() + 1);
    arquivo.write(historicoMedico.c_str(), historicoMedico.size() + 1);
}


// Método para carregar os dados do gato do arquivo binário 

void Cachorro::carregar(ifstream &arquivo) {
    char buffer[100];
    arquivo.getline(buffer, sizeof(buffer), '\0');
    nome = buffer;
    arquivo.read((char*)&idade, sizeof(idade));
    arquivo.getline(buffer, sizeof(buffer), '\0');
    raca = buffer;
    arquivo.read((char*)&peso, sizeof(peso));
    arquivo.getline(buffer, sizeof(buffer), '\0');
    cor = buffer;
    arquivo.getline(buffer, sizeof(buffer), '\0');
    genero = buffer;
    arquivo.getline(buffer, sizeof(buffer), '\0');
    historicoMedico = buffer;
}

