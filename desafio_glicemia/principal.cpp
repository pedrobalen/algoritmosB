/*

2)desafio da glicose

Estrutura
	string data
	string hora
	int valorMedicao

Menu
	1 - Cadastrar medicao(mg/dl)
	2 - Listar medicoes
	3 - Calcular e mostrar media e mediana

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Medicao {
    string data;
    string hora;
    int valorMedicao;
};

int main() {
    vector<Medicao> medicoes;
    int opcao;
    Medicao novaMedicao;
    do {
        cout << "Menu\n";
        cout << "1 - Cadastrar medicao \n";
        cout << "2 - Listar medicoes\n";
        cout << "3 - Calcular e mostrar media e mediana\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;


        switch (opcao) {
            case 1:
                cout << "Digite a data (DD/MM/AAAA): ";
                cin >> novaMedicao.data;
                cout << "Digite a hora (HH:MM): ";
                cin >> novaMedicao.hora;
                cout << "Digite o valor da medicao (mg/dl): ";
                cin >> novaMedicao.valorMedicao;
                medicoes.push_back(novaMedicao);
                break;

            case 2:
                cout << "Medicoes cadastradas:\n";
                for (const Medicao &med : medicoes) {
                    cout << "Data: " << med.data << " | Hora: " << med.hora << " | Valor: " << med.valorMedicao << " mg/dl\n";
                }
                break;

            case 3:
                if (medicoes.empty()) {
                    cout << "Nenhuma medicao cadastrada.\n";
                } else {
                    vector<int> valores;
                    for (const Medicao &med : medicoes) {
                        valores.push_back(med.valorMedicao);
                    }

                   
                    double media = 0;
                    for (int valor : valores) {
                        media += valor;
                    }
                    media /= valores.size();

                    
                    sort(valores.begin(), valores.end());
                    int tamanho = valores.size();
                    double mediana;
                    if (tamanho % 2 == 0) {
                        mediana = (valores[tamanho / 2 - 1] + valores[tamanho / 2]) / 2.0;
                    } else {
                        mediana = valores[tamanho / 2];
                    }

                    cout << "Media das medicoes: " << media << " mg/dl\n";
                    cout << "Mediana das medicoes: " << mediana << " mg/dl\n";
                }
                break;

            case 0:
                cout << "Saindo do programa.\n";
                break;

            default:
                cout << "Opcao invalida. Escolha novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 1;
}
