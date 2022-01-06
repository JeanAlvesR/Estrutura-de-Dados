#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct lista{
  int valor;
  struct lista* prox; 
}Lista;

typedef struct fila{
  Lista* ini; 
  Lista* fim; 
}Fila;


void insereFila(Fila* F, int valor){
  Lista* novo;
  novo=(Lista*) malloc(sizeof(Lista));
  novo->valor=valor;
  novo->prox=NULL;
  
  if(F->fim==NULL){
	  F->fim=novo;
	  F->ini=novo;
  }else{
	  F->fim->prox = novo;
	  F->fim=novo;
  }
}  

void removeFila(Fila* F){
	Lista *aux;	
	aux=F->ini;
	if(F->ini!=NULL){
	    F->ini = aux->prox;
	    
	    if(F->ini==NULL)
	       F->fim = NULL;
	       
	    free(aux);	    
	}   
}


void imprimeF(Fila *F)
{
  Lista* aux=F->ini;
  
  while(aux!=NULL){
	  printf("A%d\t", aux->valor);
	  aux=aux->prox;
   }	  
}

int main(){
   //Cria a Fila vazia (nó sentinela)
	
   Fila* F=(Fila*) malloc(sizeof(Fila));
   F->ini=NULL;
   F->fim=NULL;
   int p = 0,i,a;
   bool parametro = true;
   int vetorOeste[1000] = {0};//-1
   int vetorNorte[1000]={0};//-3
   int vetorSul[1000]= {0};//-2
   int vetorLeste[1000]= {0};//-4
   
	//Funciona bem, mas nele é possível, por exemplo, sair do -1, ir para o -4 e voltar para o -1, contudo a lógica com base nas entradas propostas está aparentemente certa.
	while(parametro){
		if(p==0){
			scanf("%d",&p);	
		}	
		i=0;		
		switch(p){
			
			case -1: //Oeste
				while(1){
					fflush(stdin);
					scanf("%d",&a);
					if(a==0){
						parametro = false;
						break;
					}
					if(a==-2||a==-3||a==-4){
						p=a;
						break;
					}
					else
					vetorOeste[i]=a;
					i++;
				}
				break;
			case -3: //Norte
				while(1){
					fflush(stdin);
					scanf("%d",&a);
					
					if(a==0){
						parametro = false;
						break;
					}
					if(a==-1||a==-2||a==-4){
						p=a;
						break;
					}
					else
					vetorNorte[i]=a;
					i++;
					
				}
				break;
			case -2: //Sul
				while(1){
					fflush(stdin);
					scanf("%d",&a);
					
					if(a==0){
						parametro = false;
						break;
					}
					if(a==-1||a==-3||a==-4){
						p=a;
						break;
					}
					else
					vetorSul[i]=a;
					i++;
				}
			break;
			case -4: //Leste
				while(1){
					fflush(stdin);
					scanf("%d",&a);
					if(a==0){
						parametro = false;
						break;
					}
					if(a==-1||a==-2||a==-3){
						p=a;
						break;
					}
					else
					vetorLeste[i]=a;
					i++;
				}
			break;
			default:
				printf("\nInseriu errado!\n");
				p=0;  //=>Acrescentei para não dar erro na hora que a pessoa errar duas vezes em seguida...
				break;
		}//Fim do switch
		
}//Fim do while

	//Laço para pega o valor de cada vetor e inserir na FILA.
	for(i=0; i<1000;i++){
		if(vetorOeste[i]!=0){
			insereFila(F,vetorOeste[i]);
		}
		if(vetorNorte[i]!=0){
			insereFila(F,vetorNorte[i]);
		}
		if(vetorSul[i]!=0){
			insereFila(F,vetorSul[i]);
		}
		if(vetorLeste[i]!=0){
			insereFila(F,vetorLeste[i]);
		}
		if(vetorOeste[i]==0 && vetorNorte[i]==0 && vetorSul[i]==0 && vetorLeste[i]==0){
			break;
		}
	
	}
	//FIFO -> First in first out...->Impressão.
	imprimeF(F);

  return 0;
}

