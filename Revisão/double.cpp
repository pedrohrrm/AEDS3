#include <iostream>

using namespace std;

double calcular_media(double num1, double num2) {
    double media;
    media = (num1+num2)/2;
    return media;
}

int main () {
    double num1, num2, media;
    cout << "Digite o primeiro número: ";
    cin >> num1;
    cout << "Digite o segundo número: ";
    cin >> num2;
    media = calcular_media(num1, num2);
    cout << "A média é: " << media << endl;
    return 0;
}
