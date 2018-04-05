#include <bits/stdc++.h>
using namespace std;

void findLongestCommonSubsequence(string str1, int n1, string str2, int n2){

    int dp[n1+1][n2+1];

    for(int i = 0; i <= n1; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= n2; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){

            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }


    cout<<dp[n1][n2]<<endl;
}

int main(){

     int t;
     char str1[10000] , str2[10000];
     cin>>t;
     while(t--){

          int n1,n2;
          cin>>n1>>n2;
          cin>>str1>>str2;

          findLongestCommonSubsequence(str1,n1,str2,n2);

     }

     return 0;
}
