#include <bits/stdc++.h>
using namespace std;

void LongestPalindromicSubsequence(string str){
    
    int n = str.size();
    int dp[n+1][n+1];
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= n; i++){
        dp[0][i] = 0;
    }
    
    string revStr = str;
    reverse(revStr.begin(),revStr.end());

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
            if(str[i-1] == revStr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    cout<<dp[n][n]<<endl;
    
    /* for printing longest palindromic subsequence

    int i = n1, j = n2;
    string lcs = "";
    while(i > 0 && j > 0){

        if(str1[i-1] == str2[j-1]){
            lcs += str1[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
        
    }
    
    reverse(lcs.begin(),lcs.end());

    cout<<lcs<<endl;*/
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          LongestPalindromicSubsequence(str);
          
     }

     return 0;
}