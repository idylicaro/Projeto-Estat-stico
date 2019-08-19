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

