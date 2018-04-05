#include <bits/stdc++.h>
using namespace std;

// this is a math question

// Power Of Two Integers
int isPower(int A) {

    if(A == 1)  return 1;
    for(long i = 2; i <= sqrt(A); i++){

        long j = i;
        while(j < A){

            j =  i*j;
        }

        if(j == A){
            return 1;
        }
    }

    return 0;

}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        cout<<isPower(n)<<endl;


    }

    return 0;
}
