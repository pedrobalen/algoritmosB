#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Inscrito {
    string nome;
    string matricula;
    string email;
    bool presente;

    Inscrito(string nome, string matricula, string email)
        : nome(nome), matricula(matricula), email(email), presente(false) {} //objeto pre definido como nao presente
};

void inscrever(vector<Inscrito>& inscritos) {
    string nome, matricula, email;
    cout << "Digite o nome do inscrito: ";
    cin >> nome;
    cout << "Digite a matrícula do inscrito: ";
    cin >> matricula;
    cout << "Digite o email do inscrito: ";
    cin >> email;
    inscritos.push_back(Inscrito(nome, matricula, email));
    cout << "Inscrição realizada com sucesso!" << endl;
}

void listarInscritos(vector<Inscrito>& inscritos) {
    cout << "Lista de inscritos:" << endl;
    for (Inscrito& inscrito : inscritos) {
        cout << "Nome: " << inscrito.nome << endl;
        cout << "Matrícula: " << inscrito.matricula << endl;
        cout << "Email: " << inscrito.email << endl;
        cout << "Status de Presença: ";
        if (inscrito.presente) {
            cout << "Presente" << endl;
        } else {
            cout << "Ausente" << endl;
        }
        cout << endl;
    }
}

void registrarEntrada(vector<Inscrito>& inscritos) {
    string matricula;
    cout << "Digite a matrícula do inscrito que deseja registrar a entrada: ";
    cin >> matricula;
    for (Inscrito& inscrito : inscritos) {
        if (inscrito.matricula == matricula) {
            inscrito.presente = true;
            cout << "Entrada registrada com sucesso!" << endl;
            return;
        }
    }
    cout << "Inscrito não encontrado." << endl;
}

void registrarSaida(vector<Inscrito>& inscritos) {
    string matricula;
    cout << "Digite a matrícula do inscrito que deseja registrar a saída: ";
    cin >> matricula;
    for (Inscrito& inscrito : inscritos) {
        if (inscrito.matricula == matricula) {
            inscrito.presente = false;
            cout << "Saída registrada com sucesso!" << endl;
            return;
        }
    }
    cout << "Inscrito não encontrado." << endl;
}

int main() {
    vector<Inscrito> inscritos;
    int escolha;

    do {
        cout << "\nMenu do Evento:" << endl;
        cout << "1 - Inscrever" << endl;
        cout << "2 - Listar Inscritos" << endl;
        cout << "3 - Registrar Entrada" << endl;
        cout << "4 - Registrar Saída" << endl;
        cout << "5 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                inscrever(inscritos);
                break;
            case 2:
                listarInscritos(inscritos);
                break;
            case 3:
                registrarEntrada(inscritos);
                break;
            case 4:
                registrarSaida(inscritos);
                break;
            case 5:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (escolha != 5);

    return 0;
}
