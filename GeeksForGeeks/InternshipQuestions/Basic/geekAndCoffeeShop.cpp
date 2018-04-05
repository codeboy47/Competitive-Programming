#include <bits/stdc++.h>
using namespace std;


int findUnits(int n, int m){
    
    m--;
	while(m--){
		n /= 2;
	}

	return n;
}

int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n,m;
        cin>>n>>m;
        
        cout<<findUnits(n,m)<<endl;
        
          
    }

    return 0;
}