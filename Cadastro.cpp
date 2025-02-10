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
            cout << "Nova idade: ";
            cin >> novaIdade;
            if (novaIdade >= 0) animal->setIdade(novaIdade); // Atualizando a idade

            double novoPeso;
            cout << "Novo peso: ";
            cin >> novoPeso;
            animal->setPeso(novoPeso);  // Atualizando o peso

            if (Cachorro* c = dynamic_cast<Cachorro*>(animal)) {
                string novoHistorico;
                
                // Atualiza o histórico médico para o cachorro
                cout << "Novo histórico médico: ";
                cin.ignore();  // Ignorar o newline residual do cin
                getline(cin, novoHistorico);
                c->setHistoricoMedico(novoHistorico);

            } else if (Gato* g = dynamic_cast<Gato*>(animal)) {
                string novoDono, novoEndereco, novoTelefone;
                
                // Atualiza o dono, endereço e telefone para o gato
                cout << "Novo dono: ";
                cin.ignore();  // Ignorar o newline residual do cin
                getline(cin, novoDono);
                g->setDono(novoDono);

                cout << "Novo endereço: ";
                getline(cin, novoEndereco);
                g->setEndereco(novoEndereco);

                cout << "Novo telefone: ";
                getline(cin, novoTelefone);
                g->setTelefone(novoTelefone);
            }

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
        string tipo;
        if (dynamic_cast<Cachorro*>(animal)) {
            tipo = "Cachorro";
        } else if (dynamic_cast<Gato*>(animal)) {
            tipo = "Gato";
        }

        // Salvar o tipo do animal antes dos dados
        arquivo.write(tipo.c_str(), tipo.size() + 1);

        // Salvar os dados do animal
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
        char tipoBuffer[10] = {0};  // Inicializa o buffer com zeros
        arquivo.read(tipoBuffer, sizeof(tipoBuffer) - 1);  // Lê até 9 caracteres, deixando espaço para '\0'

        string tipo(tipoBuffer);

        if (arquivo.eof()) break;  // Verifica se atingimos o final do arquivo

        if (tipo == "Cachorro") {
            Cachorro* c = new Cachorro();
            c->carregar(arquivo);
            animais.push_back(c);
        } else if (tipo == "Gato") {
            Gato* g = new Gato();
            g->carregar(arquivo);
            animais.push_back(g);
        }
    }

    arquivo.close();
    cout << "Dados carregados com sucesso de " << arquivoNome << endl;
}
