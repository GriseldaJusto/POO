#include "Cadastro.h"

int main() {
    Cadastro cadastro;

    while (true) {
        cout << "=== Sistema de Cadastro de Animais ===" << endl;
        cout << "1. Adicionar Animal" << endl;
        cout << "2. Listar Animais" << endl;
        cout << "3. Atualizar Animal" << endl;
        cout << "4. Remover Animal" << endl;
        cout << "5. Salvar em Arquivo" << endl;
        cout << "6. Carregar do Arquivo" << endl;
        cout << "7. Sair" << endl;

        int opcao;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 7) break;

        switch (opcao) {
            case 1: {
                string nome, raca, cor, genero, dono, endereco, telefone, historicoMedico;
                int idade;
                double peso;
                cout << "Digite o tipo do animal (Cachorro/Gato): ";
                string tipo;
                cin >> tipo;
                cout << "Digite os detalhes do animal: " << endl;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Idade: ";
                cin >> idade;
                cout << "Raça: ";
                cin.ignore();
                getline(cin, raca);
                cout << "Peso: ";
                cin >> peso;
                cout << "Cor: ";
                cin.ignore();
                getline(cin, cor);
                cout << "Gênero: ";
                getline(cin, genero);
                cout << "Dono: ";
                getline(cin, dono);
                cout << "Endereço: ";
                getline(cin, endereco);
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Histórico Médico: ";
                getline(cin, historicoMedico);

                if (tipo == "Cachorro") {
                    Cachorro* c = new Cachorro(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico);
                    cadastro.adicionar(c);
                } else if (tipo == "Gato") {
                    Gato* g = new Gato(nome, idade, raca, peso, cor, genero, dono, endereco, telefone, historicoMedico);
                    cadastro.adicionar(g);
                } else {
                    cout << "Tipo de animal inválido!" << endl;
                }
                break;
            }
            case 2:
                cadastro.listar();
                break;
            case 3: {
                string nome;
                cout << "Digite o nome do animal a ser atualizado: ";
                cin.ignore();
                getline(cin, nome);
                cadastro.atualizar(nome);
                break;
            }
            case 4: {
                string nome;
                cout << "Digite o nome do animal a ser removido: ";
                cin.ignore();
                getline(cin, nome);
                cadastro.remover(nome);
                break;
            }
            case 5:
                cadastro.salvarArquivo("animais.dat");
                break;
            case 6:
                cadastro.carregarArquivo("animais.dat");
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}

