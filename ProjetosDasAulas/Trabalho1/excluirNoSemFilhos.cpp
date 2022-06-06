No* remover(No *raiz, int chave){
if (raiz == NULL){
cout << “Valor não encontrado!” << endl;
return NULL;}
else{
if(raiz -> conteudo == chave){//remove nós folha(nós sem filhos)
if(raiz -> esquerda == NULL && raiz -> direita == NULL){ /*verificar se é nó folha, 
ou seja não possui filhos.*/
free(raiz); //comando para remover a raiz.
return NULL;
}
}else{
if(chave<raiz -> conteudo)
raiz->esquerda=remover(raiz -> esquerda, chave);
else
raiz -> direita = remover(raiz -> direita, chave);
return raiz;
}}}