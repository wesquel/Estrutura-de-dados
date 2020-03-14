#include <stdio.h>
#include <stdlib.h>

void Merge (int inicio,int meio,int fim,int V[]){
	int *Vaux,i,m,k;
	Vaux = (int*)malloc((fim-inicio+1)*sizeof(int));
	i = inicio;
	m = meio+1;
	k = 0;
	
	while ((i <= meio) && (m <= fim)){
		if (V[i] <= V[m]){
			Vaux[k++] = V[i++];
		}
		else{
			Vaux[k++] = V[m++];
		}
	}
	while (i <= meio){
		Vaux[k++] = V[i++];
	}
	while (m <= fim){
		Vaux[k++] = V[m++];
	}
	for (i=inicio; i<=fim; i++){
		V[i] = Vaux[i-inicio];
	}
	free(Vaux);
	
}

int Merge_sort(int inicio,int fim,int V[]){	
	if (fim > inicio){
		int meio = (inicio + fim)/2;
		Merge_sort(inicio,meio,V);
		Merge_sort(meio+1,fim,V);
		Merge(inicio,meio,fim,V);
	}	
}

int main(){
	int Vet[10] = {0,3,4,5,9,10,11,23,45,14},tamanho;
	tamanho = sizeof(Vet)/sizeof(int);
	printf("%d",tamanho);	
	Merge_sort(0,tamanho-1,Vet);
	for (int i = 0 ; i < 10;i++){
		printf("%d\n",Vet[i]);
	}	
}

