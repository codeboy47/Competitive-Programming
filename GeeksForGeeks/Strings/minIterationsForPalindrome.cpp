// Dynamic Programming | Set 28 (Minimum insertions to form a palindrome)

#include <bits/stdc++.h>
using namespace std;

void minIterations(string str){

	int n = str.size();
	int dp[n][n];

	for(int i = 0; i < n; i++){
		dp[i][i] = 0;
	}

	for(int k = 1; k < n; k++){
		for(int i = 0; i < n-k; i++){
		    int j = i+k;
			if(j - i == 1){
				if(str[i] == str[j]){
					dp[i][j] = 0;
				}else{
					dp[i][j] = 1;
				}
			}
			else if(str[i] == str[j]){
				dp[i][j] = dp[i+1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
    
    
	cout<<dp[0][n-1]<<endl;
}

int main(){

    int t;
    string str;
    cin>>t;
    while(t--){
    
        cin>>str;
       	
       	minIterations(str);

          
    }

    return 0;
}