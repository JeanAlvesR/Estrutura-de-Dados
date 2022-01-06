#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct lista{
  char info;
  struct lista* prox; 
}Lista;

typedef struct pilha{
  Lista* topo;  
}Pilha;

//Insere no topo
void push(Pilha* P, char valor[], int i){
   Lista* novo;
   novo = (Lista*) malloc(sizeof(Lista));
   novo->info = valor[i];
   novo->prox = P->topo;
   
   P->topo = novo;
}

//Remove e retorna um char...
char pop(Pilha* P){
    Lista* aux;
    aux=P->topo;
    char c[1]; 
    c[0] = P->topo->info; 
    if(P->topo!=NULL){
      P->topo=aux->prox;
      free(aux);        
    }

    return c[0];
}

//Conta os diamantes e retorna a qtd
int conta_diamantes(Pilha * P){
    Pilha* aux = P;
    int i;
    int esquerda = 0, direita =0, qtd = 0;
    char temp;
    
    char string[1000];
   fflush(stdin);
    scanf("%s",string);
        for(i=0; i<strlen(string);i++){
            if(string[i]!='.'){
                push(aux, string, i);
            }
        }
                
        while(aux->topo!=NULL){
            
            temp = pop(aux);
				//A ordem de verificação é o inverso da entrada por isso tem a direita está associada ao '<'
            	if(temp=='<' && esquerda!=0){
            		direita ++;
					          							
				}
                if(temp=='>'){
                    esquerda++;
                  
                }
				//verifica se existe direita e esquerda acima de 0. como eu já verifiquei que para somar uma lado, deve existir o outro, só preciso acrescentar uma vez e retirar 1 de cada..
                if( direita>0 && esquerda>0){
                	qtd++;
                	esquerda--;
                	direita--;
				}
        }
    
    return qtd;
}

//Função Principal
int main(){

    setlocale(LC_ALL,"Portuguese");
    Pilha* P;
    int qtd, ent;
    
    scanf("%d",&ent);
    
    	while(ent--){
    		//Coloquei a inicialização dentro do while, pois eu "libero" o espaço no final de cada ciclo.
    		P = (Pilha*)malloc(sizeof(Pilha));
    		P->topo = NULL;
    		qtd = conta_diamantes(P);
    		printf("A quantidade de Diamantes é: %d.\n",qtd);
    	}
        
    return 0;
}
