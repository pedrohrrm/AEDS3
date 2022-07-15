#include<iostream>

using namespace std;

#include <vector>
#include <list>

struct Grafo{
    vector<list<int>> lista_adj;
    void Inicializar(int num_vertices){
        lista_adj.resize(num_vertices);
    }
    void AddAresta(int v1, int v2){
        lista_adj[v1].push_back(v2);/*Adicionar uma aresta */
    }
    void AddVertice(){
        lista_adj.push_back(list<int>());
    }
};


int main(){
    Grafo meu_grafo;

    meu_grafo.Inicializar(5);

    meu_grafo.AddAresta(1, 3);
    meu_grafo.AddAresta(1, 4);

    meu_grafo.AddVertice(3);

    

    return 0;
}