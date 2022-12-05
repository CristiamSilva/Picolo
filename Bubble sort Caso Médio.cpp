#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  
int trocou = 0, comparacoes;
void bubbleSort(int A[], int n) {  
    for (int i = 1; i < n; i++) {
        bool troca = 0;
	
        for (int j = n - 1; j >= i; j--) {  
        	comparacoes++;
            if (A[j - 1] > A[j]) {
                int aux = A[j - 1];
                A[j - 1] = A[j];
                A[j] = aux;
              trocou++;
                troca = 1;
       }
         
        }
       /* if (!troca) {
            return;
        }*/
    }
}

int main() {
	int tam = 0;
    int i;
    double time_spent = 0.0;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam);
    int vet[tam];
	
	clock_t begin = clock();
    
	//printf("Vetor desordenado:\n");
	//printf("\n\n");
    for(i = 0; i < tam; i++){
        vet[i] = i+1;
       // printf(" %d\n ", vet[i]);
        //printf("\n\n");
	}
bubbleSort(vet, tam);
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
