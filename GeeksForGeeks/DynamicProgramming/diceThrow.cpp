#include <bits/stdc++.h>
using namespace std;


long findWays(int m, int n, int x, long dp[][100]){

    if(x < 0 || n < 0){
        return 0;
    }

    if(x == 0 && n == 0){
        return 1;
    }

    if(dp[n][x] != -1) return dp[n][x];

    long ans = 0;
    for(int i = 1; i <= m; i++){
        ans += findWays(m,n-1,x-i,dp);
    }

    dp[n][x] = ans;
    return dp[n][x];
}

long findWaysBottomUp(int m, int n, int x){

    long table[n + 1][x + 1];
    memset(table, 0, sizeof(table));

    // Table entries for only one dice
    for (int j = 1; j <= m && j <= x; j++)
        table[1][j] = 1;

    // Fill rest of the entries in table using recursive relation
    // i: number of dice, j: sum
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k <= j; k++)
                table[i][j] += table[i-1][j-k];

    /*
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= x; j++)
        cout << table[i][j] << " ";
      cout << endl;
    } */
    return table[n][x];

}

int main(){

    int t;
    cin>>t;
    long dp[100][100];
    while(t--){

        int m, n, x;
        cin>>m>>n>>x;
        memset(dp,-1,sizeof(dp));

        //cout<<findWays(m,n,x,dp)<<endl;
        cout<<findWaysBottomUp(m,n,x)<<endl;

    }

    return 0;
}
