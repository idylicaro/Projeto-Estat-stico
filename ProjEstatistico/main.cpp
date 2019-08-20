#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

#include "func.h"
/* Legenda de variaveis
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
    int A,k,h,f,nf,NF,F,small,biger;
    //float intervalos[]
    int tam;
    cout <<"Quantos dados deseja registrar?"<<endl;
    cin  >> tam;
    system("cls");

    int dados[tam];
    for(int i=0;i<tam;i++){
        cout << i+1 << " Digite o valor e pressione \"ENTER\"!"<<endl;
        cin>>dados[i];
        cout <<endl;
    }
    small = menor(dados,tam);
    biger = maior(dados,tam);

    k = KclassesCalculo(tam)+1;  //entao como o tipo e int , ele retira tudo apos a virgula , ai adiciona 1 pq o autor do livro fala que e pra arrendondar pra cima
    A = (biger)-(small);
    h = A/k;

    k = verificaIntervalo(k,dados,tam,h);

    float intervalos[k][2];
    definindoIntervalos(small,k,h,intervalos);


    /*
    for(int i = 0;i<k;i++){
        for(int j =0;j<6;j++){
            cout <<intervalos[i][0]<< " " intervalos[i][1]<< "||" <<tabela[i][j];

        }
        cout << "\n";
        cout << "----------------------"<<endl;
    }
    */

    float tabela[k][6];
    zeraTAbela(tabela,k);
    calculoPMedio(tabela,intervalos,k);

    calculoFrequenciaClasse(tabela,intervalos,k,dados,tam);


    for(int i = 0;i<k;i++){
            cout <<intervalos[i][0]<< " " << intervalos[i][1]<< "|-|";
        for(int j =0;j<6;j++){
            cout << " |-| " <<tabela[i][j];

        }
        cout << "\n";
        cout << "----------------------"<<endl;
    }


    //cout << tabela[0][1]<<endl;
    return 0;
}



