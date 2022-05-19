#include <iostream>

using namespace std;

void Desenhar(int tam){
    for (int i=0; i<tam;i++) {
        for (int j=0;j<=i;j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

int main(){
    int tam;
    cout << "Digite o tamanho do desenho: ";
    cin >> tam;
    cout << "\n";
    Desenhar(tam);
    return 0;
}