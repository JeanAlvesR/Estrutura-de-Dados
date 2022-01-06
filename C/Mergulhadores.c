# include<stdlib.h>
# include<stdio.h>
# include<string.h>

//Tipo Lista
typedef struct lista{
  int info;
  struct lista* prox;
}Lista;

//Lista em sequência, portanto add no fim
Lista* insereFim(Lista* p, int n){
	Lista* aux = p;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = n;
	novo->prox = NULL;
	if(p == NULL){
		return novo;
	}
	while(aux->prox != NULL){
		aux= aux->prox;
	}
	aux->prox = novo;
	return p;
}

//Usei função removeLista utilizada em sala de aula.
Lista* removeLista(Lista* L, int n){
	Lista* aux=NULL, *ant=NULL;
  	aux = L;
  	if(aux==NULL)
  		return NULL;

  	while(aux!=NULL && aux->info!=n){
    	ant=aux;
    	aux=aux->prox;
  	}
  	//Nao encontrou o elemento
  	if(aux==NULL)
    	return L;

  	//Remove o primeiro elemento
  	if(ant==NULL){
    	L=aux->prox;
    	free(aux);
    	return L;
  	}else{
    	ant->prox=aux->prox;
    	free(aux);
    	//retorna a lista com as alterações
    	return L;
  	}
}
//Quase igual a da sala, porém tem o incremento dá condição da lista ser nula.
void imprimir(Lista* p){
	Lista* aux = p;
	printf("\n");
	//Se todo mundo retornou -> Lista = NULL
	if(aux==NULL){
		printf("*\n");
	}
	//Os que não retornaram
	else{
		while(aux!=NULL){
			printf("%d ",aux->info);
			aux = aux->prox;
		}
	}
	printf("\n");
	
}

int main(){

  	Lista* pRef =  NULL;
	int qtdMerg, qtdRetornou, x, i;
	
	scanf("%d %d",&qtdMerg,&qtdRetornou);
	//Verificação para evitar incoerências

	//( 1 = qtdRetornou = qtdMerg = 104), 
	while(qtdRetornou>qtdMerg || qtdMerg>104 ||qtdRetornou<1){
		
		scanf("%d %d",&qtdMerg,&qtdRetornou);
	}
	//Inserção dos valores na lista com base na quantidade de mergulhadores.
	for(i = 1; i<=qtdMerg; i++ ){
		pRef = insereFim(pRef, i);
	}
	//Remover quem retornou 
	for(i = 0; i<qtdRetornou; i++){
		scanf("%d",&x);
		pRef = removeLista(pRef, x);
	}
	//Impressão
	imprimir(pRef);
	//Liberando o ponteiro
	free(pRef);

  	return (0);
}

