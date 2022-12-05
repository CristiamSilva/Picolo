#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  
long int trocou = 0, comparacoes;

long int tam = 0;

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
    	comparacoes++;
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            trocou++;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int main() {
	
    long int i, j;
    double time_spent = 0.0;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam);
    int vet[tam];
	
	clock_t begin = clock();
    //srand(time(NULL));
	//printf("Vetor desordenado:\n");
	//printf("\n\n");
    for(i = 0, j = tam; i < tam; i++, j--){
        vet[i] = j; //rand();
        //printf("%d\n\n ", vet[i]);
        //printf("\n\n");
	}
quick_sort(vet, 0, tam - 1);
printf("\n\n");
printf("Vetor em ordem:\n");
for(i = 0; i < tam; i++){
    printf(" %d\n ", vet[i]);
    printf("\n\n");
}
	printf("Numero de comparacoes = %i.", comparacoes);
	printf("Numero de trocas = %i.", trocou);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tempo de execução foi de %f segundos", time_spent);
    return 0;
}
