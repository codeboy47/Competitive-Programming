#include<iostream>
using namespace std;
int solution(int A[], int N) {
    // write your code in C99
    int sum=0,s=0,d=1000000,i,modulus=0;
    for(i=0;i<N;i++){
        sum=sum+A[i];
    }
    for(i=0;i<N;i++){
        s=s+A[i];
        modulus=s-(sum-s);
        if(modulus<0){
            modulus=-modulus;
        }
        if(modulus<d){
            d=modulus;
        }
    }
    return d;
}
int main() {
    int A[100],N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<solution(A,N);
}
