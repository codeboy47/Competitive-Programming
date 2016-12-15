#include<iostream>
using namespace std;
int solution(int A[], long long int N) {
    // write your code in C99
    long long int i,sum=0;
    for(i=0;i<N;i++){
        sum=sum+A[i];
    }
    N=((N*(N+1))/2) + N+1;
    N=N-sum;
    return N;
}
int main() {
    int A[100];
    long long int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<solution(A,N);
}
