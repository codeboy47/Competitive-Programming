#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
    static int i = 2;
    if(i == n/2 && (n/2)%i ==0){
        return true;
    }else if(n%i == 0) return false;
    else{
        i++;
        return isPrime(n);
    }
}

int main(){
    int n,ans;
    cin>>n;
    ans = isPrime(n);
    if(ans == 0) cout<<"not prime";
    else cout<<"prime";
}
