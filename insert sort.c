#include<stdio.h>

void insertionSort(int *A, int n){
    int i, j, aux, p;
    
    for(i=1; i<=(n-1); i++){
        p = A[i];
        for(j=i; (j>=1) && (p<A[j-1]); j--){
            A[j] = A[j-1];
        }
        A[j] = p;
    }

    for(i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int n;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    int A[n];

    printf("Digite os valores do vetor:\n");
    for(int x=0; x<n; x++){
        scanf("%d", &A[x]);
    }

    insertionSort(A, n);
}