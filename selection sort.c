#include<stdio.h>

void selectionSort(int *A, int n){
    int i, j, aux, menor;
    
    for(i=0; i<=n-2; i++){
        menor = i;
        for(j=i+1; j<=n-1; j++){
            if(A[menor]>A[j]){
                menor = j;
            }
        }
        aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }

    for(i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int n;

    printf("tamanho do vetor:\n");
    scanf("%d", &n);
    int A[n];

    printf("valores do vetor:\n");
    for(int x=0; x<n; x++){
        scanf("%d", &A[x]);
    }

    selectionSort(A, n);
}