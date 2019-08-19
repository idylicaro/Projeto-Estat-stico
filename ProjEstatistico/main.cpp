#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

#include "func.h"
/* LEgenda de variaveis
* k  - Numero de classes
* A  - Amplitude Total
* h  - Amplitude total classe
* f  - Frequencia relativa da classe
* pm - ponto medio
* nf - Frequencia absoluta da classe
* NF - Frequencia absoluta Acumulada da classse
* F  - Frequencia relativa Acumulada
*
*/

int main(void){
    int A,k,h,f,pm,nf,NF,F;
    int tam;
    cout <<"Quantos dados deseja registrar?"<<endl;
    cin  >> tam;
    system("cls");

    int dados[tam];
    for(int i=0;i<tam;i++){
        cout << "Digite o valor e pressione \"ENTER\"!"<<endl;
        cin>>dados[i];
    }

    k = KclassesCalculo(50)+1;  //entao como o tipo e int , ele retira tudo apos a virgula , ai adiciona 1 pq o autor do livro fala que e pra arrendondar pra cima
    A = (maior(dados,tam))-(menor(dados,tam));
    h = A/k;
    cout <<" "<<h;
    return 0;
}


