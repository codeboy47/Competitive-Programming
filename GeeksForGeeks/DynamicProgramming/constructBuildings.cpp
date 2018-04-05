#include <bits/stdc++.h>
using namespace std;

/*
Given N, the number of plots on either sides of the road. Find the total ways to construct buildings
in the plots such that there is a space between any 2 buildings. All plots on one side of the road are continuous.
*/



int main(){

    int dp[100001];

    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i <= 100000; i++){
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        long tot = dp[n];
        cout<<(tot*tot)%1000000007<<endl;

    }

    return 0;
}
