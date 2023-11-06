import random
import csv
from amigo import Amigo

listaamigos = []
listaamigosShuffle = []

def exibir_menu():
    print("Menu")
    print("1 - Cadastrar amigo")
    print("2 - Listar amigos")
    print("3 - Gerar amigo secreto")
    print("Sair")

def cadastrar():
    nome = input("Insira o nome: ")
    email = input("Insira o email: ")
    pessoa = Amigo(nome, email)
    listaamigos.append(pessoa)

def listar_amigos():
    for amigo in listaamigos: 
        print(amigo)

def gerar_amigosecreto(listaamigos, listaamigosShuffle, nome_arquivo):
    listaamigosShuffle = listaamigos.copy()
    random.shuffle(listaamigosShuffle)
    with open(nome_arquivo, mode='w', newline='') as arquivo_csv:
        escritor = csv.writer(arquivo_csv)
        pares_amigos = list(zip(listaamigos, listaamigosShuffle)) 
        for par in pares_amigos:
            escritor.writerow(par)
    return pares_amigos

while True:
    exibir_menu()
    opcao = input("Escolha uma opção: ")
    if opcao == "1":
        cadastrar()
    elif opcao == "2":
        listar_amigos()
    elif opcao == "3":
        gerar_amigosecreto(listaamigos, listaamigosShuffle, "amigoSecreto.csv")
    else:
        print("Opção inválida. Tente novamente.")
