#include <stdio.h>
#include <stdlib.h>

void intercala(int A[], int inicio, int meio, int fim){
    
    int tamanho = fim - inicio + 1;
    int *auxiliar = malloc(tamanho * sizeof(int));
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    
    while(i <= meio && j <= fim){
        if(A[i] <= A[j]){
            auxiliar[k] = A[i];
            i++;
        }
        else{
            auxiliar[k] = A[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        auxiliar[k] = A[i];
        k++;
        i++;
    }

    while(j <= fim){
        auxiliar[k] = A[j];
        k++;
        j++;
    }

    for(k = inicio; k <= fim; k++){
        A[k] = auxiliar[k - inicio];
    }
    free(auxiliar);

}

void mergeSort(int A[], int inicio, int fim){
    
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(A, inicio, meio);
        mergeSort(A, meio + 1, fim);
        intercala(A, inicio, meio, fim);
    }

}

int main(){
    int n;
    
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    int A[n];
    int inicio = 0;
    int fim = n;

    printf("Digite os valores do vetor:\n");
    for(int x=0; x<n; x++){
        scanf("%d", &A[x]);
    }

    mergeSort(A, inicio, fim);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}