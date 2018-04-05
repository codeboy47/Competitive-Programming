#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/path-in-matrix/0


int minCost(int cost[][1000], int m, int n) {

    int i, j;
    int dp[m][n] = {0};

    for(int i = 0; i < n; i++){
        dp[0][i] = cost[0][i];
    }

    for (i = 1; i < m; i++){
        for (j = 0; j < n; j++){
            if(i != 0){
                dp[i][j] = max(dp[i][j],cost[i][j] + dp[i-1][j]);
            }
            if(i != 0 && j != 0){
                dp[i][j] = max(dp[i][j],cost[i][j] + dp[i-1][j-1]);
            }
            if(i != 0 && j != n-1){
                dp[i][j] = max(dp[i][j],cost[i][j] + dp[i-1][j+1]);
            }
        }
    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[n-1][i]);
    }

     return ans;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int cost[1000][1000];

        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++){
                cin>>cost[i][j];
            }
        }
        cout<<minCost(cost,n,n)<<endl;

    }

    return 0;
}
