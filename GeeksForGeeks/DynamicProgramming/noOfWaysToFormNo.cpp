#include <bits/stdc++.h>
using namespace std;

/*
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N'
using the sum of the given three numbers.
(allowing repetitions and different arrangements).
*/

// this problem is like ladders problem and nth fibonacci no

int topdownDP(int n, int *dp){

    if(n < 0) return 0;

    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = topdownDP(n-5, dp) + topdownDP(n-3, dp) + topdownDP(n-1, dp);

    return dp[n];
}

int bottomUpDP(int n){

    int *dp = new int[n];

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        if(i-3 >= 0)
            dp[i] += dp[i-3];
        if(i-5 >= 0)
            dp[i] += dp[i-5];
    }

    return dp[n];
}


int main(){

    int dp[100];
    memset(dp,-1,sizeof(int)*100);
    cout<<topdownDP(6,dp)<<endl;
    cout<<bottomUpDP(6)<<endl;

    return 0;
}
