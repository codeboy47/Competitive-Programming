/// program print first n Fibonacci numbers using recursion
#include <iostream>
using namespace std;

int fibo(int n){
    if(n == 0) return 0;
	if(n==1 || n==2 ){
		return 1;
	}else{
		return fibo(n-1) + fibo(n-2);
	}
	//return;
}

int main() {
	// your code goes here
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
       cout<<fibo(i)<<" ";
	}
	return 0;
}
