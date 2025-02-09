#include "Cadastro.h"

int main() {
    Cadastro cadastro;
    
    // Criando alguns objetos
    Cachorro* c = new Cachorro("Rex", 3, "Labrador", 30.5, "Preto", "M", "João", "Rua A", "9999-9999", "Vacinado");
    Gato* g = new Gato("Mia", 2, "Siamês", 4.2, "Branco", "F", "Maria", "Rua B", "8888-8888", "Castrada");

    // Adicionando os animais ao cadastro
    cadastro.adicionar(c);
    cadastro.adicionar(g);
    
    // Listando antes de salvar
    cout << "Lista de animais antes de salvar:" << endl;
    cadastro.listar();
    
    // Salvando no arquivo
    cadastro.salvarArquivo("animais.dat");
    
    // Limpando os dados em memória antes de carregar do arquivo
    cadastro = Cadastro();
    
    // Carregando os dados do arquivo
    cadastro.carregarArquivo("animais.dat");
    
    // Listando após carregar
    cout << "Lista de animais após carregar:" << endl;
    cadastro.listar();
    
    // Testando atualização
    cadastro.atualizar("Rex");
    
    // Removendo um animal
    cadastro.remover("Mia");
    
    // Listando após atualização e remoção
    cout << "Lista final de animais:" << endl;
    cadastro.listar();
    
    return 0;
}
