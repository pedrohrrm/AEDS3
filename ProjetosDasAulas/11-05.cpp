#include<iostream> 
#include<stdlib.h>
using namespace std;
struct No {
        int dado;
        No *esquerdo, *direito;
        No *no_atual; //conferir essa sintaxe
};
struct ArvoreBinaria{
        No *raiz;
        void Criar();
        void Inserir(int dado); //cria um nó para conectar esse nó na árvore.
        void Imprimir(No* no_atual);
        };
        void ArvoreBinaria::Criar(){
            raiz = NULL;
        }
void ArvoreBinaria::Inserir(int dado){
        //raiz é nulo
        if(raiz == NULL)
        //alocando um novo nó e colocando o enderaço desse novo nó em raiz.
        raiz = new No;

        raiz -> dado = dado;

        raiz -> esquerdo = NULL;
        raiz -> direito = NULL;
}
    else{
        no_atual = raiz;
        //encontrar a posição para inserir o novo nó
        while(no_atual != NULL){
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
        //se o valor a ser inserido é maior que o valor do raiz
        if(dado > no_atual->dado){
            if(no_atual->direito == NULL){
                no_atual->direito = new No;
                no_atual->direito->dado = dado;
                no_atual->direito->esquerdo = NULL;
                no_atual->direito->direito = NULL;
            }

        }
        //se o valor do raiz é maior qye o valor a ser inserido
    else if(no_atual->dado > dado){


    }
}
     void ArvoreBinaria::Imprimir(No *no_atual){
         if(no_atual != NULL ){
             cout << no_atual->dado << endl;
             Imprimir(no_atual->esquerdo);
             Imrpimir(no_atual->direito);
         }
     }  
int main (){
    ArvoreBinaria minha_arvore;
    
    minha_arvore.Criar();

    minha_arvore.Inserir(12);
    minha_arvore.Inserir(99);
    minha_arvore.Inserir(120);
    //cout << "Hello World!" << endl;
    return 0;
}
