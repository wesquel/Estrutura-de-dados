#include <stdio.h>

int insertion_sort(int v[],int n){
	int i,j,aux;
	for (i=1;i<n;i++){
		aux = v[i];
		j=i-1;
		while ((j>=0) && (aux < v[j])){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = aux;
	}
	
}

int main (){
	int vet[10] = {22,16,34,12,19,10,2,3,7,4};
	int tamanho;
	tamanho = 10;
	insertion_sort(vet,tamanho);
	for (int i=0;i<10;i++){
		printf("%d\n",vet[i]);
	}
}

