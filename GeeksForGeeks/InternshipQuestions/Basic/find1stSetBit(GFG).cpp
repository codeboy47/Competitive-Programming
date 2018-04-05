#include <bits/stdc++.h>
using namespace std;

int findPosOf1stBitSetFromRight(int n){
    
    if(n == 0){
        return 0;
    }
    
	int pos = 1;
	while(1){
	    if(n&1){
	        break;
	    }
		n >>= 1;
		pos++;
	}

	return pos;
}


int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
    
        cout<<findPosOf1stBitSetFromRight(n)<<endl;
          
    }

    return 0;
}