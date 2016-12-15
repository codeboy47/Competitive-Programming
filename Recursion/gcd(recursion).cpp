#include <iostream>
using namespace std;

int gcd(int n1,int i,int n2){
	if(n1%(i)==0 && n2%(i)==0 ){
		return i;
	}else{
		gcd(n1,i-1,n2);
	}
	//return;
}

int main() {
	// your code goes here
	int n1,n2;
	cin>>n1>>n2;
	if(n1 > n2)
        cout<<gcd(n1,n1-1,n2);
	if(n2 > n1)
        cout<<gcd(n1,n2-1,n2);
	return 0;
}

/*
#include <iostream>
using namespace std;

void gcd(int n1,int ns1,int n2,int ns2){
	if(n1%(ns1)==0 && n2%(ns1)==0 ){
		cout<<ns1;
		//return;
	}else if(n1%(ns1)==0 && n2%(ns2)!=0){
		gcd(n1,ns1,n2,ns2-1);
	}else if(n1%(ns1)!=0 && n2%(ns2)==0){
		gcd(n1,ns1-1,n2,ns2);
	}else{
		gcd(n1,ns1-1,n2,ns2-1);
	}
	return;
}

int main() {
	// your code goes here
	int n1,n2;
	cin>>n1>>n2;
	gcd(n1,n1-1,n2,n2-1);
	return 0;
}

*/

