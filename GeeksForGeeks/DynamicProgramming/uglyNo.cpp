#include <bits/stdc++.h>
using namespace std;


int nthUglyNo(int n){

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    int i2 = 1;
    int i3 = 1;
    int i5 = 1;

    for(int i = 2; i <= n; i++){

        int ans = min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5));
        dp[i] = ans;
        if(ans%2 == 0)  i2++;
        if(ans%3 == 0) i3++;
        if(ans%5 == 0) i5++;

    }

    return dp[n];
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        cout<<nthUglyNo(n)<<endl;
    }

    return 0;
}
