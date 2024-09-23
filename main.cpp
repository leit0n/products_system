#include <iostream>

using namespace std;

struct produto {
    string nome;
    float preco;
    int stock;
};

produto all[100]; //Array que guarda os produtos
int quantidadeatual = 0; //Quantidade atual do stock

// Função para adicionar um produto
void addproduto(int& quantidadeatual) {
    produto p;
    cout << "nome do produto:";
    cin >> p.nome;
    cout << "preco do produto:";
    cin >> p.preco;
    cout << "quantidade:";
    cin >> p.stock;  

    // Adiciona o produto ao array
    all[quantidadeatual] = p;
    quantidadeatual++;  // Incrementa a quantidade de produtos
}

// Função para exibir todos os produtos
void exibirproduto(const produto all[], int quantidadeatual) {  
    cout << "Lista de produtos:" << endl;
    for (int i = 0; i < quantidadeatual; i++) {
        cout << "Produto " << i + 1 << ": " << all[i].nome 
             << ", Preco: " << all[i].preco 
             << ", Stock: " << all[i].stock << endl;
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

// Função de menu
void menu() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Adicionar/Atualizar produto" << endl;
        cout << "2. Exibir todos os produtos" << endl;
        cout << "3. Calcular valor total do stock" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção:";
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
                    cout << "Valor total do stock: " << total << endl;
                }
                break;
            case 4:
                cout << "Bye Bye";
                break;
            default:
                cout << "Opção inválida. Tente novamente.";
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}
