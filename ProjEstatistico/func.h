#include <iostream>
#include <math.h>
using namespace std;

float KclassesCalculo(int n){
    float k=0;
    k = 1+(3.22*log10(n));
    return k;
}
int maior(int vet[],int TAM){
    int maior = vet[0];
    for (int i = 1; i < TAM; i++) {
        if (vet[i] > maior) {
            maior    = vet[i];
        }
    }
        return maior;
}
int menor(int vet[],int TAM){
    int menor = vet[0];
    for (int i = 1; i < TAM; i++) {
        if (vet[i] < menor) {
            menor    = vet[i];
        }
    }
        return menor;
}

int verificaIntervalo(int k,int vet[],int tam,int h){
    float menorr = menor(vet,tam);
    float maiorr = maior(vet,tam);

    menorr -=0.5;
    maiorr -=0.5;
    float intervaloTest = menorr;
    int contador=0;
    while(intervaloTest <= maiorr){
        intervaloTest +=h;
        contador++;
    }
        return contador;
}

void definindoIntervalos(int small,int k,int h,float intervalo[][2]){
    float interval = small - 0.5;

    for(int i = 0;i<k;i++){
        for(int j =0;j<2;j++){
            intervalo[i][j] = interval + (h*j);
            interval += (h*j); // quando h for 0 vai ser o primeiro intervalo
        }
    }

}

void calculoPMedio(float tabela[][6],float intervalos[][2],int k){
    for(int i = 0;i<k;i++){
            tabela[i][0]= (intervalos[i][0] + intervalos[i][1])/2;
    }
}
void zeraTAbela(float tabela[][6],int k){
    for(int i=0;i<k;i++){
        for(int g = 0;g<6;g++){
            tabela[i][g] = 0;
        }
    }
}
void calculoFrequenciaClasse(float tabela[][6],float intervalos[][2],int k,int dados[],int tam){

    for(int i = 0;i<k;i++){
            for(int j=0;j<tam;j++){
                //cout <<dados[j]<<endl;
                if(dados[j]>=intervalos[i][0] && dados[j]<=intervalos[i][1] ){
                    tabela[i][1]+=1;
                }

            }


    }
}

