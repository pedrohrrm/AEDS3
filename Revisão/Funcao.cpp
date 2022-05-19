#include <iostream>

using namespace std;

void funcao( float a){
    a = a + 3;
    cout << "Função" << endl;
    cout << "Valor de a = " << a << endl;
}

int main () {
   float a = 15.3;
   cout << "Main" << endl;
   cout << "Valor de a = " << a << endl;
   funcao(a);
   cout << "Main" << endl;
   cout << "Valor de a = " << a << endl;
}
int a = 7;
int b = 3;

int soma(){
    int soma;
    soma  = a + b;
    return soma;
}

int main () {
   int result;
   int a, b;
   a = 5;
   b = 10;
   result = soma();
   cout << "Resultado da soma = " << result << endl;
}