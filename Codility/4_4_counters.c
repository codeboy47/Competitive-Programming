#include<stdio.h>
/*struct Results {
  int * C;
  int L;
};
struct Results solution(int N, int A[], int M) {
    struct Results result;
    result.C = A;
    result.L = N;
    long long int t=0,l=0,k,B[100000],c=1,i;
    for(i=0;i<N;i++){
        B[i] = 0;
    }
    for(i=0;i<M;i++){
        k = A[i];
        if(A[i] == N + 1){
            c = l + 1;
            t = l;
        }
        if(A[i] <= N && A[i] >= 1){
            if(B[k-1] == 0){
                B[k-1] = B[k-1] + c;
                c = 1;
            }else{
                B[k-1]++;
            }
        }
        l = B[k-1];
    }
    for(i=0;i<N;i++){
        if(B[i] == 0 || t > B[i]){
            B[i] = t;
        }
    }
    for(i=0;i<N;i++){
        A[i] = B[i];
    }
    return result;
}*/
int main(){
    int f=0,t=0,l=0,k,A[1000],M,N,i,B[1000],c=1;
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
        B[i] = 0;
    }
    for(i=0;i<M;i++){
        k = A[i];
        if(A[i] == N + 1){
            c = l;
            t = l;
            f = 1;
        }
        if(A[i] <= N && A[i] >= 1){
            if(f == 1){
                //f = 0;
                B[k-1] = c + 1;
                p = c;
                //c = 1;
            }
            if(B[k-1] < p && f!=1){
                B[k-1] = p++;
            }
            if(B[k-1] >= p && f!=1){
                B[k-1]++;
            }
            f = 0;
            l = B[k-1];
        }
    }
    for(i=0;i<N;i++){
        if(B[i] == 0 || t > B[i]){
            B[i] = t;
        }
    }
    for(i=0;i<N;i++){
        printf("%d ",B[i]);
    }
    return 0;
}
