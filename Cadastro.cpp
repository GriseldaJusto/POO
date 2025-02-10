#include "Cadastro.h"

// Destrutor para liberar memória alocada dinamicamente
Cadastro::~Cadastro() {
    for (auto& animal : animais) {
        delete animal;
    }
    animais.clear();
}

void Cadastro::adicionar(AnimalDomestico* animal) {
    animais.push_back(animal);
}

//modificado o parametro da funcao
//LISTA TODOS OS ANIMAIS CADASTRADOS 
//LEITURA DIRETAMENTE DO ARQUIVO BINARIO
void Cadastro::listar(const string &arquivoNome) const {
    ifstream arquivo(arquivoNome, ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    while (arquivo.peek() != EOF) { 
        char tipo;
        arquivo.read(&tipo, sizeof(tipo));

        AnimalDomestico* animal = nullptr;
        if (tipo == 'C') {
            animal = new Cachorro();
        } else if (tipo == 'G') {
            animal = new Gato();
        } else {
            cout << "Erro: Tipo desconhecido no arquivo!" << endl;
            break;
        }

        animal->carregar(arquivo);
        if (arquivo.fail()) {
            delete animal;
            break;
        }

        animal->exibir();
        delete animal; // Evita vazamento de memória
    }

    arquivo.close();
}


void Cadastro::atualizar(const string& nome) {
    for (auto& animal : animais) {
        if (animal->getNome() == nome) {
            cout << "Atualizando dados de " << nome << "..." << endl;
            
            int novaIdade;
            cout << "Nova idade (não pode ser negativa): ";
            cin >> novaIdade;
            if (novaIdade >= 0) animal->setIdade(novaIdade);
            
            double novoPeso;
            cout << "Novo peso (não pode ser negativo): ";
            cin >> novoPeso;
            if (novoPeso >= 0) animal->setPeso(novoPeso);
            
            string novaRaca;
            cout << "Nova raça: ";
            cin.ignore();
            getline(cin, novaRaca);
            animal->setRaca(novaRaca);
            return;
        }
    }
    cout << "Animal não encontrado!" << endl;
}

//MODIFICADO
//A FUNCAO REMOVER CRIA UM ARQUIVO TEMPORARIO PARA GUARDAR A INFORMACAO QUE NAO DEVE SER PERDIDA
void Cadastro::remover(const string& nome, const string& arquivoNome) {
    ifstream arquivo(arquivoNome, ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return;
    }

    ofstream temp("temp.dat", ios::binary);
    if (!temp) {
        cout << "Erro ao abrir o arquivo temporário!" << endl;
        arquivo.close();
        return;
    }

    bool encontrado = false;

    while (arquivo.peek() != EOF) { 
        char tipo;
        arquivo.read(&tipo, sizeof(tipo));

        AnimalDomestico* animal = nullptr;
        if (tipo == 'C') {
            animal = new Cachorro();
        } else if (tipo == 'G') {
            animal = new Gato();
        } else {
            cout << "Erro: Tipo desconhecido no arquivo!" << endl;
            break;
        }

        animal->carregar(arquivo);

        if (animal->getNome() == nome) {
            encontrado = true;
            delete animal; // Exclui o objeto da memória
            continue; // Não copia para o novo arquivo
        }

        // Escreve no novo arquivo se não for o removido
        temp.write(&tipo, sizeof(tipo));
        animal->salvar(temp);
        delete animal;
    }

    arquivo.close();
    temp.close();

    if (encontrado) {
        remove(arquivoNome.c_str());  // Apaga o arquivo original
        rename("temp.dat", arquivoNome.c_str()); // Renomeia o arquivo temporário
        cout << "Animal " << nome << " removido com sucesso!" << endl;
    } else {
        remove("temp.dat"); // Exclui o arquivo temporário se o animal não foi encontrado
        cout << "Animal não encontrado!" << endl;
    }
}


void Cadastro::salvarArquivo(const string &arquivoNome) const {
    ofstream arquivo(arquivoNome, ios::binary);
    for (const auto& animal : animais) {
        animal->salvar(arquivo);
    }
    arquivo.close();
}

//MODIFICADO
//MUDANCA REALIZADA PARA QUE O SISTEMA CONSIGA DISTINGUIR SE O ANIMAL EH GATO OU CACHORRO 
void Cadastro::carregarArquivo(const string &arquivoNome) {
    ifstream arquivo(arquivoNome, ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    while (arquivo.peek() != EOF) { 
        char tipo;
        arquivo.read(&tipo, sizeof(tipo)); // Lê o identificador do tipo

        AnimalDomestico* animal = nullptr;
        if (tipo == 'C') {
            animal = new Cachorro();
        } else if (tipo == 'G') {
            animal = new Gato();
        } else {
            cout << "Erro: Tipo desconhecido no arquivo!" << endl;
            break;
        }

        animal->carregar(arquivo);
        if (arquivo.fail()) {
            delete animal;
            break;
        }
        animais.push_back(animal);
    }

    arquivo.close();
}
