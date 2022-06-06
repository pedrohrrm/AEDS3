void exibirPreOrdem(No *raiz){/*Pré-Ordem vai imprimir o nó que ele esta percorrendo,
Inicia na raiz e vai imprimindo até o último nó da esquerda, depois retorna na raiz 
e percorre o lado direito*/
    if(raiz != NULL){/*Vai verificar a existêcia do nó atual, 
    assim, quando chamarmos raiz->direita ou raiz->esquerda, 
    teremos a certeza que não serão NUlos.*/
        cout << raiz->numero << endl;//assim que está no nó, já faz a exibição
        exibirPreOrdem(raiz->esquerda);//faz a chamada recursiva pro nó a esquerda
        exibirPreOrdem(raiz->direita);/*chamada recursiva para nó à direita, após terminar os
        nós da esquerda*/
    }
}
