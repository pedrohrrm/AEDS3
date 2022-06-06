else{ //remove nós que possuem apenas um filho, independente de estar a direita ou esquerda
    if(raiz -> esquerda == NULL || raiz -> direita ==NULL){
        No *aux //criamos uma variável para receber o nó filho, de maneira que quando excluirmos o nó pai ele não seja excluido junto.
        if(raiz -> esquerda !=NULL)
        aux=raiz -> esquerda;
        else
            aux = raiz -> direita;
            free(raiz);
            return aux;        
    }
}