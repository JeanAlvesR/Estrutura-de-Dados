/*Faça um programa que leia um vetor X[10]. Substitua a seguir, todos os
valores nulos e negativos do vetor X por 1. Em seguida mostre o vetor X.*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//Lista
typedef struct lista{
	int num;
	struct lista* prox;
}Lista;

// Inserir Lista final da lista
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

//Trocar num<=0 por 1
void verificacao(Lista* p2){
	Lista* aux = p2;
	while(aux!=NULL){
		if(aux->num <= 0){
			aux->num = 1;
		}
		aux = aux->prox;
	}
}
//Impressao
void imprimir(Lista* p3){
	Lista* aux = p3;
	while(aux!= NULL){
		printf("\nELEMENTO: %d",aux->num);
		aux = aux->prox;
	}

}

int main (){
	Lista* p;
	p = NULL;
	int n;
	//Ciclo para pegar os 10 valores e criar as listas dinamicamente
	for(int i = 1;i<=10; i++){
		scanf("%d",&n);
		p = inserirFinal(p, n);
	}
	imprimir(p);

	verificacao(p);
	
	imprimir(p);

	return 0;
}
