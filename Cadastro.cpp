
#include "Cadastro.h"

void Cadastro::adicionar(AnimalDomestico* animal) {
    animais.push_back(animal);
}

void Cadastro::listar() const {
    for (const auto& animal : animais) {
        animal->exibir();
    }
}

void Cadastro::atualizar(const string& nome) {
    for (auto& animal : animais) {
        if (animal->getNome() == nome) {
            cout << "Atualizando dados de " << nome << "..." << endl;
            animal->exibir();
            return;
        }
    }
    cout << "Animal não encontrado!" << endl;
}

void Cadastro::remover(const string& nome) {
    for (auto it = animais.begin(); it != animais.end(); ++it) {
        if ((*it)->getNome() == nome) {
            delete *it;
            animais.erase(it);
            cout << "Animal " << nome << " removido com sucesso!" << endl;
            return;
        }
    }
    cout << "Animal não encontrado!" << endl;
}

void Cadastro::salvarArquivo(const string &arquivoNome) const {
    ofstream arquivo(arquivoNome, ios::binary);
    for (const auto& animal : animais) {
        animal->salvar(arquivo);
    }
    arquivo.close();
}

void Cadastro::carregarArquivo(const string &arquivoNome) {
    ifstream arquivo(arquivoNome, ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    while (!arquivo.eof()) {
        Cachorro* c = new Cachorro();
        c->carregar(arquivo);
        if (arquivo.eof()) break;
        animais.push_back(c);
    }
    arquivo.close();
}
