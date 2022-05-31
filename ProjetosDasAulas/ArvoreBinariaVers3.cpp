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
    No * Inserir(No * no_atual, int dado);
    No * Remover(No * no_atual, int dado);
    void ImprimirPreOrdem(No* no_atual);
    void ImprimirOrdem(No* no_atual);
    void ImprimirPosOrdem(No* no_atual);
};

void ArvoreBinaria::Criar(){
    raiz = NULL;
}

void ArvoreBinaria::Inserir(int dado){

    No* no_atual;

    //raiz eh nulo
    if(raiz == NULL){
        //Alocando um novo no
        raiz = new No;

        raiz->dado = dado;

        raiz->esquerdo = NULL;
        raiz->direito = NULL;
    }
    else{
        no_atual = raiz;

        //Encontrar a posicao para inserir o novo no
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

    //caso base
    if(no_atual == NULL){
        no_atual = new No;
        no_atual->dado = dado;
        no_atual->esquerdo = NULL;
        no_atual->direito = NULL;

        return no_atual;
    }
    //Caso recursivo
    else{
        //Fazer uma chamada recursiva a partir da ramificacao esquerda
        if(dado < no_atual->dado){
            no_atual->esquerdo = Inserir(no_atual->esquerdo, dado);
        }
        else if(dado > no_atual->dado){
            no_atual->direito = Inserir(no_atual->direito, dado);
        }
    }

    return no_atual;
}

void ArvoreBinaria::ImprimirOrdem(No *no_atual){

    //Caso recursivo
    if(no_atual != NULL){

        ImprimirOrdem(no_atual->esquerdo);

        cout << no_atual->dado << endl;

        ImprimirOrdem(no_atual->direito);
    }
}

void ArvoreBinaria::ImprimirPosOrdem(No *no_atual){

    //Caso recursivo
    if(no_atual != NULL){

        cout << no_atual->dado << endl;

        ImprimirPosOrdem(no_atual->esquerdo);

        ImprimirPosOrdem(no_atual->direito);
    }
}

No *ArvoreBinaria::Remover(No *no_atual, int dado){

    No* no_temp;
    int temp;

    //Caso base
    //Caso tenha o elemento e esta no no_atual
    if(no_atual->dado == dado){
        //Caso 1
        //No folha
        if(no_atual->esquerdo == NULL && no_atual->direito == NULL){
            delete no_atual;
            return NULL;
        }
        //Caso 2
        //Subcaso 2.1, o no que sera removido tem apenas o filho a esquerda
        else if(no_atual->direito == NULL){
            no_temp = no_atual->esquerdo;
            delete no_atual;
            return no_temp;
        }
        //Subcaso 2.2, o no que sera removido tem apenas o filho a direita
        else if(no_atual->esquerdo == NULL){
            no_temp = no_atual->direito;
            delete no_atual;
            return no_temp;
        }
        //Caso 3
        else{
            //Encontrar um descendente para substituir o no que sera removido
            no_temp = no_atual->direito;

            //Encontrar o no com o menor valor, considerando a sub-árvore à direita
            while (no_temp->esquerdo != NULL) {
                no_temp = no_temp->esquerdo;
            }

            temp = no_atual->dado;
            no_atual->dado = no_temp->dado;
            no_temp->dado = temp;

            no_atual->direito = Remover(no_atual->direito, no_temp->dado);


        }
    }
    //Caso nao tenha o elemento
    else if(no_atual == NULL){
        return no_atual;
    }
    else if(dado < no_atual->dado){
        no_atual->esquerdo = Remover(no_atual->esquerdo, dado);
    }
    else if(dado > no_atual->dado){
        no_atual->direito = Remover(no_atual->direito, dado);
    }

    return no_atual;
}

int main()
{
    ArvoreBinaria minha_arvore;

    //int valor;

    minha_arvore.Criar();

    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 50);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 38);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 45);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 55);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 70);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 35);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 51);
    minha_arvore.raiz = minha_arvore.Inserir(minha_arvore.raiz, 81);
    minha_arvore.ImprimirOrdem(minha_arvore.raiz);
    cout << endl;

    minha_arvore.raiz =  minha_arvore.Remover(minha_arvore.raiz, 55);
    cout << "Remover 55" << endl;
    minha_arvore.ImprimirOrdem(minha_arvore.raiz);
    cout << endl;

    /*if(minha_arvore.Pesquisar(minha_arvore.raiz, 50)){
        cout << "Elemento encontrado" << endl;
    }
    else{
        cout << "Elemento nao encontrado" << endl;
    }
    minha_arvore.ImprimirOrdem(minha_arvore.raiz);*/

    minha_arvore.raiz =  minha_arvore.Remover(minha_arvore.raiz, 50);
    cout << "Remover 50" << endl;

    /*if(minha_arvore.Pesquisar(minha_arvore.raiz, 50)){
        cout << "Elemento encontrado" << endl;
    }
    else{
        cout << "Elemento nao encontrado" << endl;
    }*/

    minha_arvore.ImprimirOrdem(minha_arvore.raiz);
    return 0;
}