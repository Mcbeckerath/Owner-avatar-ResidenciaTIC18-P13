#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Definindo a estrutura Produto
struct Produto {
    string codigo;
    string nome;
    double preco;
};

const int MAX_PRODUTOS = 300;

// Função para imprimir a lista de produtos
void listarProdutos(const Produto produtos[], int quantidade) {
    cout << "Lista de produtos:" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "Codigo: " << produtos[i].codigo << endl;
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preco: R$ " << fixed << setprecision(2) << produtos[i].preco << endl;
        cout << endl;
    }
}

// Função para verificar se um produto com o mesmo código já existe
bool produtoExiste(const Produto produtos[], int quantidade, const string& codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}

// Função para inserir um novo produto
void inserirProduto(Produto produtos[], int& quantidade) {
    if (quantidade >= MAX_PRODUTOS) {
        cout << "Nao e possivel adicionar mais produtos. Limite atingido." << endl;
        return;
    }

    Produto novoProduto;
    cout << "Digite o codigo do produto (13 caracteres numericos): ";
    cin >> novoProduto.codigo;

    if (produtoExiste(produtos, quantidade, novoProduto.codigo)) {
        cout << "Produto com o mesmo codigo já existe. Nao e possivel adiciona-lo." << endl;
        return;
    }

    cout << "Digite o nome do produto (ate 20 caracteres): ";
    cin.ignore();
    getline(cin, novoProduto.nome);

    cout << "Digite o preco do produto: ";
    cin >> novoProduto.preco;

    produtos[quantidade] = novoProduto;
    quantidade++;

    cout << "Produto adicionado com sucesso!" << endl;
}

// Função para excluir um produto
void excluirProduto(Produto produtos[], int& quantidade) {
    string codigo;
    cout << "Digite o codigo do produto que deseja excluir: ";
    cin >> codigo;

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < quantidade - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            quantidade--;
            cout << "Produto excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Produto nao encontrado. Nenhum produto foi excluido." << endl;
}

// Função para consultar o preço de um produto
void consultarPreco(const Produto produtos[], int quantidade) {
    string codigo;
    cout << "Digite o codigo do produto para consultar o preco: ";
    cin >> codigo;

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            cout << "Preco do produto " << produtos[i].nome << ": R$ " << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto nao encontrado." << endl;
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade = 0;
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar o preco de um produto" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirProduto(produtos, quantidade);
                break;
            case 2:
                excluirProduto(produtos, quantidade);
                break;
            case 3:
                listarProdutos(produtos, quantidade);
                break;
            case 4:
                consultarPreco(produtos, quantidade);
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }

    } while (opcao != 0);

    return 0;
}
