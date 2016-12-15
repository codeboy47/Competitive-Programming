#include <iostream>
using namespace std;

int fibo(int n){
    int *fib = new int[50];
    //OR static int fib[50];
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(fib[n] > 0) return fib[n];
    fib[n] =  fibo(n-1) + fibo(n-2);
    return fib[n];
}

int main() {
    int n;
    cin>>n;
    cout<<fibo(n);
	return 0;
}
