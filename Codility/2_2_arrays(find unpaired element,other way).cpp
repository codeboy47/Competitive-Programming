/* OddOccurrencesInArray
Find value that occurs in odd number of elements. 66% correct */

#include<iostream>
using namespace std;
int solution(int *A, int N) {
    int i,j;
    for(i=0,j=1;i<N-1,j<N;) {
        if(A[i]!=A[j]){
            j++;
        }
        if(A[i]==A[j]){
            A[i]=-1;
            A[j]=-1;
            i=i+1;
            j=i+1;
        }
        if(A[i]==-1) {
            i = i+1;
            j = i+1;
        }
    }
    for(i=0;i<N;i++) {
        if(A[i]!=-1) {
            return A[i];
        }
    }
}
int main() {
    int A[100],i,j,N;
    cin>>N;
    for (i=0;i<N;i++) {
        cin>>A[i];
    }
    cout<<solution(A,N);
}
