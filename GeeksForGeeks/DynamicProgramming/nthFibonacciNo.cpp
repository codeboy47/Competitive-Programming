#include <bits/stdc++.h>
using namespace std;

// time complexity is O(2^n) and space is O(n)
int fibRecursive(int n){
    if(n == 1 || n == 0) return n;
    return fibRecursive(n-1) + fibRecursive(n-2);
}

// time and space is O(n)
int fibTopDownDP(int n, int *dp){
    if(n == 1 || n == 0) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibTopDownDP(n-1,dp) + fibTopDownDP(n-2,dp);
    return dp[n];
}

// time and space is O(n)
int fibBottomUpDP(int n){

    int *dp = new int[n];

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// time is O(n) and space is O(1)
int fib(int n){

    int a = 0;
    int b = 1;

    int c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return b;

}

int main(){

    cout<<fibRecursive(5)<<endl;

    int dp[100];
    memset(dp,-1,sizeof(int)*100);
    cout<<fibTopDownDP(5,dp)<<endl; // memoization

    cout<<fibBottomUpDP(5)<<endl; // tabular

    cout<<fib(5)<<endl;
    return 0;
}
