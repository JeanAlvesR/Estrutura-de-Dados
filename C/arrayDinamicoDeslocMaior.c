/*
Desenvolver uma funcao que desloca o maior elemento da lista para o
inıcio; Para resolver este problemas, devera ser utilizado um ponteiro auxiliar para percorrer a lista.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//Lista
typedef struct lista{
    int num;
    struct lista* prox;
}Lista;

// Inserir Lista final da lista (em sequência)
Lista* inserirFinal(Lista* p1, int n){
    Lista* aux = p1;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->num = n;
    novo->prox = NULL;
    
    if(p1==NULL){
        return novo;
    }
    
    while(aux->prox!=NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return p1;
}

//Trocar de posicao -> tentei generalizar o máximo que imaginei pegando apenas o maior valor...
Lista* TrocaDePosicao(Lista* p2){
    Lista* aux = p2;
    Lista* maiorValor;
	//Pegar o maior 
	maiorValor = aux;
    while(aux != NULL){
        if(aux->num >= maiorValor->num){
            maiorValor = aux;
        }
            	
    aux = aux->prox;
    }
	/*Fiz isso abaixo, pois caso o primeiro valor fosse o maior,
	 a a condição que eu criei lá embaixo maiorValor->prox = p2 
	 faria o maiorValor apontar para ele mesmo. PythonTutor ajudou bastante para eu enxerga isso e outros detalhes. */
	if(maiorValor == p2){
		return maiorValor;
	}
	//aux pega a primeira lista novamente
    aux = p2;

    while(aux!=NULL){
		//Para não apontar mais para o maior valor, maiorValor.
        if(aux->prox==maiorValor)
            aux->prox = maiorValor->prox;
		        
        aux=aux->prox;
    }
    //Aponta para o primeiro inicial
    maiorValor->prox = p2;
	//fazendo isso ponteiro da main apontará para maiorValor
    return maiorValor;
}
//Impressao
void imprimir(Lista* p3){
    Lista* aux = p3;
    while(aux!= NULL){
        printf("\nELEMENTO: %d\n",aux->num);
        aux = aux->prox;
    }

}

int main (){
    Lista* p = NULL;
    
	//Cria a lista adicionando o subsequente no final 
    p = inserirFinal(p, 10);
    p = inserirFinal(p, 20);
    p = inserirFinal(p, 30);
    p = inserirFinal(p, 15);

   imprimir(p);

    p = TrocaDePosicao(p);
   printf("\n\nMundanca de posicao\n"); 
   imprimir(p);
	free(p);
    return 0;
}
