#include "Cadastro.h"

Cadastro::~Cadastro() {
    for (auto& animal : animais) {
        delete animal;
    }
    animais.clear();
}

void Cadastro::adicionar(AnimalDomestico* animal) {
    animais.push_back(animal);
    cout << "O animal foi adicionado com sucesso!" << endl;  // Mensagem de sucesso
}

void Cadastro::listar() const {
    if (animais.empty()) {
        cout << "Não existe nenhum cadastro" << endl;
    } else {
        for (const auto& animal : animais) {
            animal->exibir();
        }
    }
}

void Cadastro::atualizar(const string& nome) {
    for (auto& animal : animais) {
        if (animal->getNome() == nome) {
            cout << "Atualizando dados de " << nome << "..." << endl;
            
            int novaIdade;
            cout << "Nova idade (não pode ser negativa): ";
            cin >> novaIdade;
            if (novaIdade >= 0) animal->setIdade(novaIdade);
            
            string novoDono;
            cout << "Novo dono: ";
            cin.ignore();
            getline(cin, novoDono);
            animal->setDono(novoDono);

            string novoEndereco;
            cout << "Novo endereço: ";
            getline(cin, novoEndereco);
            animal->setEndereco(novoEndereco);

            string novoTelefone;
            cout << "Novo telefone: ";
            getline(cin, novoTelefone);
            animal->setTelefone(novoTelefone);

            string novoHistorico;
            cout << "Novo histórico médico: ";
            getline(cin, novoHistorico);
            animal->setHistoricoMedico(novoHistorico);

            cout << "Os dados do animal foram atualizados com sucesso!" << endl;  // Mensagem de sucesso
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
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    for (const auto& animal : animais) {
        animal->salvar(arquivo);
    }
    arquivo.close();
    cout << "Dados salvos com sucesso em " << arquivoNome << endl;  // Mensagem de sucesso
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
    cout << "Dados carregados com sucesso de " << arquivoNome << endl;  // Mensagem de sucesso
}
