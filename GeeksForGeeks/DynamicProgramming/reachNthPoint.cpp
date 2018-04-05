#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n*k)
long waysBottomUp(int n, int k){

    long *dp = new long[n+1];
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

int main(){

    int t;
    cin>>t;
    while(t--){

        long n;
        cin>>n;
        cout<<waysBottomUp(n,2)<<endl;


    }

    return 0;
}
