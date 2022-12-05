#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  
long int trocou = 0, comparacoes;

long int tam = 0;

void selection_sort(int vet[],int tam) {
  int i, j, min, aux;
  
  for (i = 0; i < (tam - 1); i++) {
  	comparacoes++;
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < tam; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vet[j] < vet[min]) {
   		min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
      
    }
    trocou++;
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
    for(i = 0; i < tam; i++){
        vet[i] = i;
        //printf("%d\n\n ", vet[i]);
        //printf("\n\n");
	}
selection_sort(vet, tam);
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
