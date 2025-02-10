#include "Cachorro.h"

// Implementação do construtor da classe Cachorro
Cachorro::Cachorro(string nome, int idade, string raca, double peso, string cor,
                   string genero, string dono, string endereco, string telefone, string historicoMedico)
    : AnimalDomestico(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico) {}

// Método para exibir os detalhes do cachorro
void Cachorro::exibir() const {
    cout << "Cachorro: " << nome << ", Idade: " << idade << endl;
}

// Método para salvar os dados do cachorro no arquivo binário corretamente
void Cachorro::salvar(ofstream &arquivo) const {
    char tipo = 'C';  // Identificador para Cachorro
    arquivo.write(&tipo, sizeof(tipo));

    // Serializa os atributos da classe base
    int nomeSize = nome.size();
    arquivo.write(reinterpret_cast<const char*>(&nomeSize), sizeof(nomeSize));
    arquivo.write(nome.c_str(), nomeSize);

    arquivo.write(reinterpret_cast<const char*>(&idade), sizeof(idade));
    arquivo.write(reinterpret_cast<const char*>(&peso), sizeof(peso));

    int racaSize = raca.size();
    arquivo.write(reinterpret_cast<const char*>(&racaSize), sizeof(racaSize));
    arquivo.write(raca.c_str(), racaSize);

    int corSize = cor.size();
    arquivo.write(reinterpret_cast<const char*>(&corSize), sizeof(corSize));
    arquivo.write(cor.c_str(), corSize);

    int generoSize = genero.size();
    arquivo.write(reinterpret_cast<const char*>(&generoSize), sizeof(generoSize));
    arquivo.write(genero.c_str(), generoSize);

    int donoSize = dono.size();
    arquivo.write(reinterpret_cast<const char*>(&donoSize), sizeof(donoSize));
    arquivo.write(dono.c_str(), donoSize);

    int enderecoSize = endereco.size();
    arquivo.write(reinterpret_cast<const char*>(&enderecoSize), sizeof(enderecoSize));
    arquivo.write(endereco.c_str(), enderecoSize);

    int telefoneSize = telefone.size();
    arquivo.write(reinterpret_cast<const char*>(&telefoneSize), sizeof(telefoneSize));
    arquivo.write(telefone.c_str(), telefoneSize);

    int historicoSize = historicoMedico.size();
    arquivo.write(reinterpret_cast<const char*>(&historicoSize), sizeof(historicoSize));
    arquivo.write(historicoMedico.c_str(), historicoSize);
}


// Método para carregar os dados do cachorro do arquivo binário corretamente
void Cachorro::carregar(ifstream &arquivo) {
    int nomeSize;
    arquivo.read(reinterpret_cast<char*>(&nomeSize), sizeof(nomeSize));
    nome.resize(nomeSize);
    arquivo.read(&nome[0], nomeSize);

    arquivo.read(reinterpret_cast<char*>(&idade), sizeof(idade));
    arquivo.read(reinterpret_cast<char*>(&peso), sizeof(peso));

    int racaSize;
    arquivo.read(reinterpret_cast<char*>(&racaSize), sizeof(racaSize));
    raca.resize(racaSize);
    arquivo.read(&raca[0], racaSize);

    int corSize;
    arquivo.read(reinterpret_cast<char*>(&corSize), sizeof(corSize));
    cor.resize(corSize);
    arquivo.read(&cor[0], corSize);

    int generoSize;
    arquivo.read(reinterpret_cast<char*>(&generoSize), sizeof(generoSize));
    genero.resize(generoSize);
    arquivo.read(&genero[0], generoSize);

    int donoSize;
    arquivo.read(reinterpret_cast<char*>(&donoSize), sizeof(donoSize));
    dono.resize(donoSize);
    arquivo.read(&dono[0], donoSize);

    int enderecoSize;
    arquivo.read(reinterpret_cast<char*>(&enderecoSize), sizeof(enderecoSize));
    endereco.resize(enderecoSize);
    arquivo.read(&endereco[0], enderecoSize);

    int telefoneSize;
    arquivo.read(reinterpret_cast<char*>(&telefoneSize), sizeof(telefoneSize));
    telefone.resize(telefoneSize);
    arquivo.read(&telefone[0], telefoneSize);

    int historicoSize;
    arquivo.read(reinterpret_cast<char*>(&historicoSize), sizeof(historicoSize));
    historicoMedico.resize(historicoSize);
    arquivo.read(&historicoMedico[0], historicoSize);
}

