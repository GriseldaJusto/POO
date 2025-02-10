#include <iostream>
#include "Cadastro.h"
#include "Gato.h"
#include "Peixe.h"

using namespace std;

void exibirMenu() {
    cout << "=== Sistema de Cadastro de Animais ===\n";
    cout << "1. Adicionar Animal\n";
    cout << "2. Listar Animais\n";
    cout << "3. Atualizar Animal\n";
    cout << "4. Remover Animal\n";
    cout << "5. Salvar em Arquivo\n";
    cout << "6. Carregar do Arquivo\n";
    cout << "7. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Cadastro cadastro;
    int opcao;
    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();
        switch (opcao) {
            case 1: {
                int codigo, idade;
                float peso;
                string nome;
                char sexo;
                
                cout << "Codigo de registro: ";
                cin >> codigo;
                cin.ignore();
                
                cout << "Nome do animal: ";
                getline(cin, nome);
                
                cout << "Idade: ";
                cin >> idade;
                
                cout << "Sexo (M/F): ";
                cin >> sexo;
                
                cout << "Peso: ";
                cin >> peso;
                cin.ignore();

                // Informações do tutor
                string nomeTutor, endereco, telefone;
                cout << "Nome do tutor: ";
                getline(cin, nomeTutor);
                cout << "Endereco do tutor: ";
                getline(cin, endereco);
                cout << "Telefone do tutor: ";
                getline(cin, telefone);

                Pessoa* tutor = new Pessoa(nomeTutor, endereco, telefone);

                cout << "Tipo de animal (1 - Gato, 2 - Peixe): ";
                int tipoAnimal;
                cin >> tipoAnimal;

                if (tipoAnimal == 1) {
                    bool ronroneia, usaCaixa;
                    string raca, pelo;
                    cout << "Ronroneia com frequencia? (1 - Sim, 0 - Não): ";
                    cin >> ronroneia;
                    cout << "Usa caixa de areia? (1 - Sim, 0 - Não): ";
                    cin >> usaCaixa;
                    cout << "Raca: ";
                    cin.ignore();  // Limpar o buffer
                    getline(cin, raca);
                    cout << "Tipo de pelo: ";
                    getline(cin, pelo);

                    Gato* gato = new Gato(codigo, nome, idade, sexo, peso, ronroneia, usaCaixa, raca, pelo, tutor);
                    cadastro.adicionarAnimal(gato);
                } else if (tipoAnimal == 2) {
                    string escamas, temperatura, especie;
                    cout << "Tipo de escamas: ";
                    cin.ignore();  // Limpar o buffer
                    getline(cin, escamas);
                    cout << "Temperatura da agua: ";
                    getline(cin, temperatura);
                    cout << "Especie: ";
                    getline(cin, especie);

                    Peixe* peixe = new Peixe(codigo, nome, idade, sexo, peso, escamas, temperatura, especie, tutor);
                    cadastro.adicionarAnimal(peixe);
                }
                break;
            }
            case 2:
                cadastro.listarAnimais();
                break;
            case 3: {
                int codigo;
                cout << "Digite o codigo do animal a ser atualizado: ";
                cin >> codigo;
                cadastro.atualizarAnimal(codigo);
                break;
            }
            case 4: {
                int codigo;
                cout << "Digite o codigo do animal a ser removido: ";
                cin >> codigo;
                cadastro.removerAnimal(codigo);
                break;
            }
            case 5:
                cadastro.salvarArquivo("animais.dat");
                break;
            case 6:
                cadastro.carregarArquivo("animais.dat");
                break;
            case 7:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 7);

    return 0;
}
