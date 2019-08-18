#include <iostream> //biblioteca de entrada e saida de dados
#include <math.h>   //biblioteca matematica
using namespace std;

float KclassesCalculo(int n);
int main()
{
    int tam;
    cout <<"Quantos dados deseja registrar?"<<endl;
    cin  >> tam;
    //system("cls");
    int dados[tam];
    int k = KclassesCalculo(tam)+1;  //entao como o tipo e int , ele retira tudo apos a virgula , ai adiciona 1 pq o autor do livro fala que e pra arrendondar pra cima


    cout <<k;
    return 0;
}
float KclassesCalculo(int n){
    float k=0;
    k = 1+(3.22*log10(n));
    return k;
}

