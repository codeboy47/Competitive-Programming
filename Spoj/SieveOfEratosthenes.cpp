// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes

#include <iostream>
using namespace std;

void simpleSieve(int n){
    int i,j;
    bool arr[n+1];
    for(i=0;i<=n;i++){
        arr[i] = true;
    }

    for(i=2;i*i<=n;i++){
        if(arr[i] == true){
            for(j=2*i;j<=n;j=j+i){
                arr[j] = false;
            }
        }
    }

    for(j=2;j<=n;j++){
        if(arr[j] == true){
            cout<<j<< " ";
        }
    }

}

int main(){

    int n;
    cin>>n;
    simpleSieve(n);


    return 0;
}

