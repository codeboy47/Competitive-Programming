#include<iostream>
using namespace std;

int lcm(int a,int b){
	int i=2,l=1;
	while(i <= a){ // a!=1 && b!=1 &&
		if(a%i==0 && b%i==0 ){
            a = a/i;
            b = b/i;
			l = l*i;
		}else if(a%i==0 && b%i!=0 ){
			a = a/i;
			l = l*i;
			cout<<"l="<<l<<"a="<<a<<"b="<<b;
		}else if(b%i==0 && a%i!=0 ){
			b = b/i;
			l = l*i;
			cout<<"l="<<l<<"a="<<a<<"bbb="<<b;
		}
		else{
            i++;
		}
	}
    return l;
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a>b) cout<<lcm(a,b);
    else cout<<lcm(b,a);

}
