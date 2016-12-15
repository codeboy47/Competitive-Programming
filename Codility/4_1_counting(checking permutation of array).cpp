#include<iostream>
using namespace std;
int solution(int A[],int N){
    long long int i,B[100000],k;
    for(i=0;i<N+1;i++){
        B[i] = 0;
    }
    for(i=0;i<N;i++){
         k = A[i];
        B[k] = A[i];
    }
    for(i=1;i<N+1;i++){
        if(B[i] == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int A[100],N,i;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<solution(A,N);
    return 0;
}
