else{
    No *aux = raiz ->esquerda;
    while(aux-> != NULL)
        aux = aux -> direita;
    raiz -> conteudo = aux -> conteudo;
    aux -> conteudo = chave;
    raiz -> esquerda = remover(raiz->esquerda, chave);//criar uma função de nome remover.
    return raiz;
}