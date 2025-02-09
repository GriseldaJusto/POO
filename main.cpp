
#include "Cadastro.h"

int main() {
    Cadastro cadastro;
    Cachorro c("Rex", 3, "Labrador", 30.5, "Preto", "M", "João", "Rua A", "9999-9999", "Vacinado");
    Gato g("Mia", 2, "Siamês", 4.2, "Branco", "F", "Maria", "Rua B", "8888-8888", "Castrada");

    cadastro.adicionar(&c);
    cadastro.adicionar(&g);

    cadastro.listar();
    cadastro.salvarArquivo("animais.dat");
    cadastro.carregarArquivo("animais.dat");
    cadastro.atualizar("Rex");
    cadastro.remover("Mia");
    
    return 0;
}
