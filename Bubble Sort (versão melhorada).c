#include <stdio.h>

void buble(int A[], int n){
    int aux, i, j;
    for(j=n-1; j>=1; j--){
        for(i=0;i<j; i++){
            if (A[i]>A[i+1]){
                aux=A[i];
                A[i]=A [i+1];
                A[i+1]=aux;
            }    
        }
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

    buble(A, n);
}