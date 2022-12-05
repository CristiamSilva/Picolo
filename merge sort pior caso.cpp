#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

long int tam;
typedef struct detalhes_s
{
    int comps;                /* Quantidade de comparacoes */
    int trocas;               /* Quantidade de trocas */
    unsigned long duracao_us; /* Tempo total de processamento em microsegundos */
} detalhes_t;

void merge( int *array, int inicio, int meio, int fim, detalhes_t *detalhes )
{
    int *vetAux, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    vetAux = (int *) malloc( tamanho * sizeof(int) );

    if(vetAux != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                detalhes->comps++;
                if(array[p1] < array[p2]){
                    vetAux[i] = array[p1++];
                    detalhes->trocas++;
                }
                else{
                    vetAux[i] = array[p2++];
                    detalhes->trocas++;
                }
                if(p1 > meio)
                    fim = 1;
                if(p2 > fim)
                    fim2 = 1;
            } else {
                detalhes->comps++;
                if(!fim1){
                    vetAux[i] = array[p1++];
                    detalhes->trocas++;
                }
                else{
                    vetAux[i] = array[p2++];
                    detalhes->trocas++;
                }
            }
        }

        for(j = 0, k = inicio; j < tamanho; j++, k++){
            array[k] = vetAux[j];
        }
    }

    free(vetAux);
}

void mergeSortR(int *array, int inicio, int fim, detalhes_t *detalhes )
{
    int meio;
    if(inicio < fim) {
        meio = floor( (fim + inicio) / 2 );
        mergeSortR( array, inicio, meio, detalhes );
        mergeSortR( array, meio+1, fim, detalhes );
        merge( array, inicio, meio, fim, detalhes );
    }
}

void mergeSort(int *array, int inicio, int fim, detalhes_t *detalhes )
{
    struct timeval t0, t1;

    /* Inicializa estrutura de detalhes */
    detalhes->comps = 0;
    detalhes->trocas = 0;

    gettimeofday(&t0, NULL);
    mergeSortR( array, inicio, fim, detalhes );
    gettimeofday(&t1, NULL);

    /* Calcula tempo de processamento */
    detalhes->duracao_us = ((t1.tv_sec - t0.tv_sec) * 1000000L) + (t1.tv_usec - t0.tv_usec);
}

int main( void )
{
    unsigned int i, j;
    detalhes_t info;
	printf("Digite o tamanho do vetor: ");
	scanf("%i", &tam);
	
    /* Vetor */
    int vet[tam];
	srand(time(NULL));
    /* Exibe Vetor de entrada */
    for( i = 0; i < tam; i++){
       vet[i] = rand();
    printf("\n");}

    /* Ordena vetor */
    mergeSort( vet, 0, tam, &info );

    /* Exibe vetor ordenado */
    for( i = 0; i <tam; i++ )
        printf("%d\n", vet[i] );
    printf("\n");

    /* Exibe Informacoes */
    printf( "Comparacoes: %d\n", info.comps );
    printf( "Trocas: %d\n", info.trocas );
    printf( "Duracao: %ldus\n", info.duracao_us);

    return 0;
}
