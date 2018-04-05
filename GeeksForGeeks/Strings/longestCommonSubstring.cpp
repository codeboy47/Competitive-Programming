#include <bits/stdc++.h>
using namespace std;


// dp method
void longestCommonSubstring(char *str1, char *str2, int n1, int n2){

	int dp[n1+1][n2+1];

	int ans = 0;
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= n2; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(str1[i-1] == str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans,dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}

	cout<<ans<<endl;
}

int main(){

     int t;
     char str1[10000],str2[1000];
     cin>>t;
     while(t--){
          
          int n1,n2;
          cin>>n1>>n2;
          cin>>str1>>str2;
         
          longestCommonSubstring(str1,str2,n1,n2);
          
     }

     return 0;
}