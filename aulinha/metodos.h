
//Exercicio 1
int elevapotencia(int num){
    return num*num;
} 




//Exercicio 3
bool informaprimo(int num){
    if(num > 1 || num / num == 1 || num / 1 == 1 ){
        return true;
    } else
    return false;

}


//Exercicio 4
int calculaidade(int atual, int nasc){
    return atual - nasc;
}

//Exercicio 5
int calculamaior(int vetor[]){
    int i;
    int maior = vetor[0];

    for (i = 1; i < sizeof(vetor); i++){
        if (vetor[i] > maior){
             maior = vetor[i];
        }
    }
    return maior;
}


//Exercicio 6
void mostraemcomum(int vetor1[], int vetor2[]){
    int i, j;
   

    for(i = 1; i < sizeof(vetor1); i++){
        for(j = 1; j < sizeof(vetor2); j++){
            if (vetor1[i] == vetor2[j]) {
                cout << vetor1[i] << " ";
                break; 
            }

        }
    }
}
