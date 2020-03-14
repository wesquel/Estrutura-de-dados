int quick_sort (int V[],int inicio,int fim){
	if (inicio < fim) {
		p = Partition(V,inicio,fim);
		quick_sort(V,inicio,p-1);
		quick_sort(V,p+1,fim);
	}
}

int Partition(int V[],int inicio,int fim){
	int d,p,j;
	d = inicio - 1;
	p = V[fim];
	for (j=inicio;fim-1;j++){
		if (V[j] <= p){
			d = d + 1;
			swap(V[j],V[d])
		}
	}
	d = d + 1;
	swap (V[fim],V[d]);
	return d; 	
}

int swap (int V, int v[]){
	key = 
}
