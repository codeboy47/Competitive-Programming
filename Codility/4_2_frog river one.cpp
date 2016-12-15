//Find the earliest time when a frog can jump to the other side of a river.
#include<iostream>
using namespace std;
int solution(int X,int A[],int N){
    int i,B[100000],k,r,j;
    j = X;
    for(i=0;i<X+1;i++){
        B[i] = 0;
    }
    for(i=0;i<N;i++){
        k = A[i];
        if(B[k] == 0 && j!=0){
            B[k] = A[i];
            r = i;
            j--;
        }
    }
    for(i=1;i<X+1;i++){
        if(B[i] == 0){
            return -1;
        }
    }
    return r;
}
int main(){
    int A[100],N,i,X;
    cin>>N;
    cin>>X;
    for(i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<solution(X,A,N);
    return 0;
}
