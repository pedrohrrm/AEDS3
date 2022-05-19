#include <iostream>

using namespace std;

struct No{
    int dado;
    No *esquerdo, *direito;
};

struct ArvoreBinaria{
    No* raiz;
    void Criar();
};

void ArvoreBinaria::Criar(){
    raiz = NULL;
}

int main()
{
    ArvoreBinaria minha_arvore;

    cout << "Hello World!" << endl;
    return 0;
}