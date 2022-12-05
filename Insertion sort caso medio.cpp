#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  
long int trocou = 0, comparacoes;

long int tam = 0;

void insertion_sort(int *a)
{
 int i, j, tmp;
  
 for(i = 1; i < tam; i++)
 {
  comparacoes++;
  tmp = a[i];
  for(j = i-1; j >= 0 && tmp < a[j]; j--)
  {
   
   a[j+1] = a[j];
    trocou++;
  }
  a[j+1] = tmp;
 
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
        //printf(" %d\n\n ", vet[i]);
        //printf("\n\n");
	}
insertion_sort(vet);
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
