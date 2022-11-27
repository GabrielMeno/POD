#include <stdio.h>
#include <stdlib.h>

void criaHeap(int A[], int i, int n){
    
    int maior = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    int aux = 0;

    if(left < n && A[left] > A[i]){
        maior = left;
    }

    if(right < n && A[right] > A[maior]){
        maior = right;
    }

    if(maior != i){
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        criaHeap(A, maior, n);
    }

}

void heapSort(int A[], int n){

    int aux;

    for(int k = ((n/2)-1); k >= 0; k--){
        criaHeap(A, k, n);
    }

    for(int k = (n-1); k >= 1; k--){
        aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        criaHeap(A, 0, k);
    }

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

    heapSort(A, n);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}