#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Estrutura para representar uma passagem vendida
struct Passagem {
    int numeroAssento;
    string dataHora;
    string cpf;
    string nome;
    int idade;
};

// Função para calcular o total arrecadado para uma viagem específica
double calcularTotalArrecadado(const vector<Passagem>& passageiros, double precoPassagem) {
    return passageiros.size() * precoPassagem;
}

int main() {
    const int numViagens = 10; // 5 viagens de ida e 5 de volta
    const int assentosPorViagem = 40;
    const double precoPassagem = 80.0;

    vector<vector<Passagem>> registros(numViagens);

    map<string, double> totalArrecadadoPorHora;

    while (true) {
        cout << "Opções disponíveis:" << endl;
        cout << "1. Vender passagem" << endl;
        cout << "2. Consultar total arrecadado para uma viagem" << endl;
        cout << "3. Consultar total arrecadado em um determinado mês" << endl;
        cout << "4. Consultar nome do passageiro de uma poltrona específica" << endl;
        cout << "5. Calcular horário de viagem mais rentável" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            // ... Código para vender passagem ...
        } else if (opcao == 2) {
            // ... Código para consultar total arrecadado para uma viagem ...
        } else if (opcao == 3) {
            // ... Código para consultar total arrecadado em um determinado mês ...
        } else if (opcao == 4) {
            // ... Código para consultar nome do passageiro de uma poltrona específica ...
        } else if (opcao == 5) {
            // Calcular o horário de viagem mais rentável
            for (int i = 0; i < numViagens; i++) {
                const vector<Passagem>& passageiros = registros[i];
                double totalViagem = calcularTotalArrecadado(passageiros, precoPassagem);
                totalArrecadadoPorHora[passageiros[0].dataHora] += totalViagem;
            }

            string horarioMaisRentavel;
            double maiorArrecadacao = 0.0;

            for (const auto& par : totalArrecadadoPorHora) {
                if (par.second > maiorArrecadacao) {
                    maiorArrecadacao = par.second;
                    horarioMaisRentavel = par.first;
                }
            }

            cout << "Horário de viagem mais rentável: " << horarioMaisRentavel << endl;
        } else if (opcao == 6) {
            break; // Encerra o programa
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
