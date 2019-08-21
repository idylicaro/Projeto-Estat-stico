#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
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

int main(void)
{
    short int menuOpc=0;
    int A,k,h,small,biger;
    float mediaa=0,varianciaa=0;
    int tam;
    cout <<"Quantos dados deseja registrar?"<<endl;
    cin  >> tam;
    int dados[tam];
    system("cls");

    cout << "Digite(1) para Ler um arquivo.txt ou Digite(2) para Digitar os dados"<<endl;
    cin  >>menuOpc;

    if(menuOpc==1){
        lerArquivo(dados,tam);
    }else if(menuOpc==2){
        for(int i=0; i<tam; i++)
    {
        cout << i+1 << " Digite o valor e pressione \"ENTER\"!"<<endl;
        cin>>dados[i];
        cout <<endl;
    }
    }
    system("cls");

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
    calculoMediaClasse(tabela,k);
    mediaa = calculoMediaClasseAcumulada(tabela,k,tam);
    varianciaa = calculoVariancia(tabela,k,tam,mediaa);

    cout <<"LEGENDA:\n" <<"P.M = Ponto Medio\n"<<"F.C=Frequencia Absoluta Da Classe\n"<<"F.C.A=Frequencia Absoluta Acumulada Da Classe\n"
         <<"F.C.R=Frequencia Relativa Da Classe\n"<<"F.C.R.A=Frequencia Relativa Acumulada Da Classe\n"<<"M.C = Media De Cada Classe\n"<<endl;

    cout <<setiosflags(ios::internal);
    cout <<"     INTERVALO"<< setw(5)<<"||"<<setw(9) <<"P.M" <<"||" <<setw(9) <<"F.C" <<"||" <<setw(9)
         <<"F.C.A" <<"||" <<setw(9) <<"F.C.R"<<"||" <<setw(9) <<"F.C.R.A" <<"||"<<setw(9)<<"M.C"<<endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i = 0; i<k; i++)
    {
        cout <<setw(7)<<intervalos[i][0]<< " " <<setw(7)<< intervalos[i][1]<<" ";
        for(int j =0; j<6; j++)
        {
            cout << " || " <<setw(7)<<tabela[i][j];

        }
        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    }

    cout <<"\nMedia: "<<mediaa<<endl;
    cout <<"\nVariancia: "<<varianciaa<<endl;
    cout <<"\nDesvio Padrao: "<<setprecision(3)<<sqrt(varianciaa)<<" Aproximadamente.\n"<<endl;

    system("pause");

    return 0;
}



