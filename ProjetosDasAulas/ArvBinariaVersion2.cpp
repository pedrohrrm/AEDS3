#include <iostream>

using namespace std;

struct No{
    int dado;
    No *esquerdo, *direito;
};

struct ArvoreBinaria{
    No *raiz;
    void Criar();
    void Inserir(int dado);

    void Imprimir(No* no_atual);
};

void ArvoreBinaria::Criar(){
    raiz = NULL;
}

void ArvoreBinaria::Inserir(int dado){

    No* no_atual;

    //raiz é nulo
    if(raiz == NULL){
        //Alocando um novo nó
        raiz = new No;

        raiz->dado = dado;

        raiz->esquerdo = NULL;
        raiz->direito = NULL;
    }
    else{
        no_atual = raiz;

        //Encontrar a posição para inserir o novo nó
        while (no_atual != NULL) {

            if(dado < no_atual->dado){
                if(no_atual->esquerdo == NULL)
                    break;
                no_atual = no_atual->esquerdo;
            }
            else if(dado > no_atual->dado){
                if(no_atual->direito == NULL)
                    break;
                no_atual = no_atual->direito;
            }
        }

        if(dado < no_atual->dado){
            no_atual->esquerdo = new No;
            no_atual->esquerdo->dado = dado;
            no_atual->esquerdo->esquerdo = NULL;
            no_atual->esquerdo->direito = NULL;
        }
        else if(dado > no_atual->dado){
            no_atual->direito = new No;
            no_atual->direito->dado = dado;
            no_atual->direito->esquerdo = NULL;
            no_atual->direito->direito = NULL;
        }
    }
}

No* ArvoreBinaria::Inserir(No *no_atual, int dado){
    //caso Base
    if(no_atual == NULL){
        no_atual = new No;
        no_atual->dado = dado;
        no_atual->direito = NULL;
        no_atual->esquerdo = NULL;

        return no_atual;
    }
}
//situação recursiva:
else{
    //fazer uma chamada recursiva a partir da ramificação esquerda
    if( dado < no_atual->dado){
        no_atual->esquerdo = Inserir(no_atual->esquerdo, dado);

    }
    else if(dado > no_atual->dado){
        no_atual->direito = Inserir(no_atual->direito, dado);
    }
    return no_atual;
}
   

void ArvoreBinaria::Imprimir(No *no_atual){
    if(no_atual != NULL){
        cout << no_atual->dado << endl;
        Imprimir(no_atual->esquerdo);
        Imprimir(no_atual->direito);
    }
}



int main()
{
    ArvoreBinaria minha_arvore;

    minha_arvore.Criar();
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 12);
    //nesse caso inserir interativo seria: minha_arvore.Inserir(12);
    minha_arvore.Inserir(99);
    minha_arvore.Inserir(120);

    minha_arvore.Imprimir(minha_arvore.raiz);

    //cout << "Hello World!" << endl;
    return 0;
}