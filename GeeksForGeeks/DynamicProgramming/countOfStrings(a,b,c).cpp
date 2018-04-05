#include <bits/stdc++.h>
using namespace std;

int countStr(int n)
{
    return 1+(n*2)+(n*((n*n)-1)/2);
}

int countStrings(int n, int a, int b, int c, int dp[][2][3]){

    if(n == 0)  return 1;

    if(dp[n][b][c] != -1)    return dp[n][b][c];

    int ans = 0;
    ans += countStrings(n-1,a-1,b,c,dp);
    if(b > 0) ans += countStrings(n-1,a,b-1,c,dp);
    if(c > 0) ans += countStrings(n-1,a,b,c-1,dp);

    dp[n][b][c] = ans;
    return dp[n][b][c];
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int dp[n+1][2][3];
        memset(dp,-1,sizeof(dp));
        cout<<countStrings(n,n,1,2,dp)<<endl;

    }

    return 0;
}
