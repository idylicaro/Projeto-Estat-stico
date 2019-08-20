#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
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
    int A,k,h,small,biger;
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


    float tabela[k][6];
    zeraTAbela(tabela,k);

    calculoPMedio(tabela,intervalos,k);
    calculoFrequenciaClasse(tabela,intervalos,k,dados,tam);
    calculoFrequenciaClasseAcumulada(tabela,k);
    calculoFrequenciaClasseRelativa(tabela,k,tam);
    calculoFrequenciaClasseRelativaAcumulada(tabela,k);


    cout <<"LEGENDA:\n" <<"P.M = Ponto Medio\n"<<"F.C=Frequencia Absoluta Da Classe\n"<<"F.C.A=Frequencia Absoluta Acumulada Da Classe\n"
         <<"F.C.R=Frequencia Relativa Da Classe\n"<<"F.C.R.A=Frequencia Relativa Acumulada Da Classe\n"<<endl;

    cout <<setiosflags(ios::internal);
    cout <<"     INTERVALO"<< setw(5)<<"||"<<setw(9) <<"P.M" <<"||" <<setw(9) <<"F.C" <<"||" <<setw(9)
         <<"F.C.A" <<"||" <<setw(9) <<"F.C.R"<<"||" <<setw(9) <<"F.C.R.A" <<"||"<<endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i = 0;i<k;i++){
            cout <<setw(7)<<intervalos[i][0]<< " " <<setw(7)<< intervalos[i][1]<<" ";
        for(int j =0;j<6;j++){
            cout << " || " <<setw(7)<<tabela[i][j];

        }
        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    }


    return 0;
}



