#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

struct no{
	int valor;
	no* esq;
	no* dir;	
};

no *criaNo(int v,no* e,no* d){
	no *novo = (no*)malloc(sizeof(no));
	novo->valor = v;
	novo->esq = e;
	novo->dir = d;
	return novo;
}

no *insere(no* raiz,int v){
	if(raiz == NULL){
		raiz = (no*)malloc(sizeof(no));
		raiz->valor = v;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	else if(v<raiz->valor){
		raiz->esq = insere(raiz->esq,v);
	}
	else{
		raiz->dir = insere(raiz->dir,v);
	}
}

void imprimeArvore(no *raiz){
	if(raiz != NULL){
		printf("%d ",raiz->valor);
		imprimeArvore(raiz->esq);
		imprimeArvore(raiz->dir);
	}
}

no* findValue(no* raiz,int v){
	if(raiz == NULL || raiz->valor == v){
		return raiz;
	}
	else{
		no* t = findValue(raiz->esq,v);
		if(t != NULL){
			return t;
		}
		else{
			return findValue(raiz->dir,v);
		}
	}
}

int heigth(no *raiz){
	if(raiz == NULL) return -1;
	else{
		int ae = heigth(raiz->esq);
		int ad = heigth(raiz->dir);
		if(ae > ad) return 1+ae;
		else return 1+ad;
	}
}

void printTree(no *raiz){
	if(raiz != NULL){
		printTree(raiz->esq);
		printf("%d ",raiz->valor);
		printTree(raiz->dir);
		
	}
}

int main(){
	no *raiz = criaNo(10,NULL,NULL);
	insere(raiz,9);
	insere(raiz,8);
	insere(raiz,11);
	insere(raiz,12);
	imprimeArvore(raiz);
	printf("\n");
	printTree(raiz);
	printf("\n");
	printf("Find encontrou = %d\n",findValue(raiz,30));
	printf("Altura = %d",heigth(raiz));

}
