#include <bits/stdc++.h>
using namespace std;

/*  Ladders with n steps with k as max step. We are standing on ground. We have
to reach the top. If k = 3 then we can take one step,
two step or three steps. We have to tell total no of ways to reach the top.
This problem is similar to nth fibonacci and no of ways to form N.
*/

// time complexity is O(k^n) i.e. O(3^n)
int waysRecursion(int n){

    if(n < 0)  return 0;
    if(n == 0) return 1;

    return waysRecursion(n-1) + waysRecursion(n-2) + waysRecursion(n-3);
}

// time complexity is O(k^n) i.e. O(3^n)
int waysRecursion2(int n, int k){

    if(n < 0)  return 0;
    if(n == 0) return 1;

    int count = 0;
    for(int i = 1; i <= k; i++){
        count += waysRecursion2(n-i,k);
    }
    return count;
}

// time complexity is O(n*k)
int waysTopDown(int n, int k, int *dp){
    if(n < 0)  return 0;
    if(n == 0) return 1;
    if(dp[n]!=-1) return dp[n];
    int count = 0;
    for(int i = 1; i <= k; i++){
        count += waysTopDown(n-i,k,dp);
    }
    dp[n] = count;
    return dp[n];
}

// time complexity is O(n*k)
int waysBottomUp(int n, int k){

    int *dp = new int[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= k; j++){
            if(i >= j)
                dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

// time complexity is O(n)
int waysBottomUp2(int n, int k){

    int *dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        if(i-k-1 >= 0)
            dp[i] = dp[i-1] + (dp[i-1] - dp[i-k-1]);
        else
            dp[i] = 2*dp[i-1];
    }
    return dp[n];
}


int main(){

    int n = 7;
    int k = 5;

    int dp[100];
    memset(dp,-1,sizeof(int)*100);
    cout<<waysRecursion(n)<<endl;
    cout<<waysRecursion2(n,k)<<endl;
    cout<<waysTopDown(n,k,dp)<<endl;
    cout<<waysBottomUp(n,k)<<endl;
    cout<<waysBottomUp2(n,k)<<endl;

    return 0;
}
