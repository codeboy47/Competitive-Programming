#include<iostream>
using namespace std;
void sol(int *A,int N){
    int sum=0,s=0;
    for(int i=0;i<N;i++){
        sum=sum+A[i];
    }
    //cout<<sum<<endl;
    for(int i=0;i<N;i++){
        s=s+A[i];
        if(s==(sum-s-A[i+1])){
            return i+1;
            //cout<<i+1<<"/";
        }
    }
    return -1;
}
int main() {
    int A[100],N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sol(A,N);
    //cout<<sol(A,N);
}
