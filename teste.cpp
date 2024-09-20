#include <iostream>
#include <string>

using namespace std;

// Definição da struct produto
struct produto {
    string nome;
    float preco;
    int stock;
};

// Array para armazenar os produtos
produto all[100]; // Até 100 produtos
int quantidadeatual = 0; // Contador para o número de produtos

// Função para adicionar ou atualizar um produto
void addproduto(int& quantidadeatual) {
    produto p;
    cout << "                                                              Nome do produto: ";
    cin >> p.nome;
    cout << "                                                              Preço do produto: ";
    cin >> p.preco;
    cout << "                                                              Quantidade: ";
    cin >> p.stock;
    
    // Adiciona o produto no array global
    all[quantidadeatual] = p; 
    quantidadeatual++; // Incrementa o número de produtos
}

// Função para exibir todos os produtos
void exibirproduto(const produto all[], int quantidadeatual) {
    cout << "\n                                                             Lista de produtos:\n";
    for (int i = 0; i < quantidadeatual; i++) {
        cout << "                                                           Produto " << i + 1 << ": " << all[i].nome 
             << ",                                                          Preço: " << all[i].preco 
             << ",                                                          Stock: " << all[i].stock << endl;
    }
}

// Função para calcular o valor total do stock
float calcularvalortotal(const produto all[], int quantidadeatual) {
    float total = 0.0;
    for (int i = 0; i < quantidadeatual; i++) {
        total += all[i].preco * all[i].stock;
    }
    return total;
}

// Função do menu
void menu() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Adicionar/Atualizar produto\n";
        cout << "2. Exibir todos os produtos\n";
        cout << "3. Calcular valor total do stock\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addproduto(quantidadeatual);
                break;
            case 2:
                exibirproduto(all, quantidadeatual);
                break;
            case 3:
                {
                    float total = calcularvalortotal(all, quantidadeatual);
                    cout << "                                             Valor total do stock: " << total << endl;
                }
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "                                                 Opção inválida. Tente novamente.\n";
        }
    } while (choice != 4);
}

int main() {
    menu(); // Iniciar o menu
    return 0;
}
