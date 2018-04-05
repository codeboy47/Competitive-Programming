#include <bits/stdc++.h>
using namespace std;

int solve(string str){
    
    int bet=1;
    int sum=4;
    for(int i=0;i<str.length();i++){
        if(str[i]=='W'){
            sum += bet;
            
            bet = 1;
            
            
        }
        if(str[i]=='L'){
            sum-=bet;
            
            if(sum<0){
                return -1;
            }
            bet=2*bet;
            
            
        }
        //cout<<sum<<" ";
        if(bet > sum && i != str.size()-1){
            return -1;
        }
    }
    return sum;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    cout<<solve(str)<<"\n";
	}
	return 0;
}