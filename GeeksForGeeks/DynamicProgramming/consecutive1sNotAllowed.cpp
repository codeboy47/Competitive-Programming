#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
*/


// time and space is O(n)
long fibBottomUpDP(int n){

    long *dp = new long[n+1];

    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }

    return dp[n];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        cout<<fibBottomUpDP(n)<<endl;


    }

    return 0;
}
