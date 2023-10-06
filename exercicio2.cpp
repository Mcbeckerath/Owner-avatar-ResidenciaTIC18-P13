#include <iostream>
#include <string>

using namespace std;

// Definindo a estrutura Empregado
struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

// Função para reajustar o salário em 10%
void Reajusta_dez_porcento(Empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        empregados[i].salario *= 1.10; // Aumenta o salário em 10%
    }
}

int main() {
    Empregado empregados[50]; // Vetor para armazenar até 50 empregados
    int quantidade;

    cout << "Quantos empregados deseja cadastrar (ateh 50)? ";
    cin >> quantidade;

    if (quantidade <= 0 || quantidade > 50) {
        cout << "Quantidade invalida." << endl;
        return 1;
    }

    // Preencha os dados dos empregados
    for (int i = 0; i < quantidade; i++) {
        cout << "Dados do empregado " << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin >> empregados[i].nome;
        cout << "Sobrenome: ";
        cin >> empregados[i].sobrenome;
        cout << "Ano de nascimento: ";
        cin >> empregados[i].anoNascimento;
        cout << "RG: ";
        cin >> empregados[i].RG;
        cout << "Ano de admissao: ";
        cin >> empregados[i].anoAdmissao;
        cout << "Salario: ";
        cin >> empregados[i].salario;
    }

    // Chame a função para reajustar os salários
    Reajusta_dez_porcento(empregados, quantidade);

    // Imprima os dados atualizados
    cout << "\nDados dos empregados após o reajuste de 10%:" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << endl;
        cout << "Ano de nascimento: " << empregados[i].anoNascimento << endl;
        cout << "RG: " << empregados[i].RG << endl;
        cout << "Ano de admissao: " << empregados[i].anoAdmissao << endl;
        cout << "Salario reajustado: " << empregados[i].salario << endl;
        cout << endl;
    }

    return 0;
}
