#include <bits/stdc++.h>
using namespace std;

int nthPadovanSequence(int n){

    int dp[n+1];
    dp[0] = dp[1] = dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-2] + dp[i-3])%1000000007;
    }

    return dp[n];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        cout<<nthPadovanSequence(n)<<endl;

    }

    return 0;
}
