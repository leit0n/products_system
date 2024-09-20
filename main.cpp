#include <iostream>

using namespace std;

struct produto all[100];
int quantidadeatual = 0;

struct produto{
    string nome;
    float preco;
    int stock;
};

void addproduto(produto produtos, int& quantidadeatual){
    produto p;
    cout << "nome do produto:";
    cin >> p.nome;
    cout << "preco do produto";
    cin >> p.preco;

}

void exibirproduto(const produto,int& quantidadeatual){
    cout << "\nLista de produtos:\n";
    for (int i = 0; i < quantidadeatual; i++) {
        cout << "Produto " << i + 1 << ": " << all[i].nome 
             << ", Preco: " << all[i].preco 
             << ", Stock: " << all[i].stock << endl;
    }
}

float calcularvalortotal(const produto produtos, int quantidadeatual){
    
    
    float total = 0.0;
    for (int i = 0; i < quantidadeatual; i++) {
        total += all[i].preco * all[i].stock;
    }
    return total;


}
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
                    cout << "\nValor total do stock: " << total << endl;
                }
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (choice != 4);
}

int main(){

menu();

    return 0;
}