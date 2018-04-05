#include <bits/stdc++.h>
using namespace std;

int findLength(int n){

	int count = 0;
	while(n != 0){
		n /= 2;
		count++;
	}
	return count;
}

int replaceKthBit(int n, int k){

	int len = findLength(n);

	return (n & ~(1 << (len-k))); 

}

int main(){

    int t;
    cin>>t;
    while(t--){

    	int n,k;
    	cin>>n>>k;
          
        cout<<replaceKthBit(n,k)<<endl;
          
    }

    return 0;
}