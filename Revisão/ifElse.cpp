#include <iostream>

using namespace std;

int main(int argc, char*argv[]){

    double soma;

    if(argc > 1){
        soma = stoi(argv[1]) + stoi(argv[2]);
        cout << "A soma é: " << soma << endl;
    }
    else{
        cout << "O número de parâmetros é insuficiente!" << endl;
    }

    return 0;
}