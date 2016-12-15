#include<stdio.h>
/*
struct Results solution(int A[], int N, int K) {
    struct Results result;
    result.A = A;
    result.N = N;
    int i = 0,j,k,t;
    while(i < K){
        k = 0;
        for(j = 1;j < N;j++){
            t = A[k];
            A[k] = A[j];
            A[j] = t;
        }
        i++;
    }
    return result;
}

*/
int main(){
    int A[100],i,j,N,K,t,k;
    scanf("%d",&N);
    scanf("%d",&K);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    i=0;
    while(i < K){
        k = 0;
        for(j = 1;j < N;j++){
            t = A[k];
            A[k] = A[j];
            A[j] = t;
        }
        i++;
    }
    printf("\n");
    for(i = 0;i < N;i++){
        printf("%d ",A[i]);
    }
    //printf("%d",Results(A,N,K));
    return 0;
}
