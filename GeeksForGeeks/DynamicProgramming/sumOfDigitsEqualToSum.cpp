#include <bits/stdc++.h>
using namespace std;


long countOfNDigitsEqualToSum(int n, int sum){

    if(n*9 < sum){
        return -1;
    }

    long dp[n+1][sum+1];

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int i = 0; i <= sum; i++){
        dp[0][i] = 0;

    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = 0;
            for(int k = 0; k <= min(9,j); k++) // as we cant take digit 14 or 237 as digit is only one no from 0 to 9 
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%1000000007;
        }
    }

    return dp[n][sum];
}

int main(){

   int t;
   cin>>t;
   while(t--){

         int n, sum;
         cin>>n>>sum;

         cout<<countOfNDigitsEqualToSum(n,sum)<<endl;

   }

   return 0;
}
