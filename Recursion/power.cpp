#include <iostream>
#include<string.h>
using namespace std;

int power(int n,int p){
	if(p == 1) return n;
	return n * power(n,p-1);
}

/*
int power(int n,int p){
	int i,num = n;
	for(i = 1;i<p;i++){
		n = n*num;
		cout<<n<<" ";
	}
	return n;
}
*/
int main() {
	int n,p;
	cin>>n>>p;
	cout<<power(n,p);
	return 0;
}
