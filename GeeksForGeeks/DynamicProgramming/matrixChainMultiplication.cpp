#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

// top down
int minIterations(int *arr, int i, int j){

    if(i >= j){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        ans = min(ans, minIterations(arr,i,k) + minIterations(arr,k+1,j) + arr[i-1]*arr[k]*arr[j] );
    }

    dp[i][j] = ans;
    return ans;
}

// bottom up
int minIterations2(int *arr, int n){

    int dp[n][n];
    memset(dp,0,sizeof(dp));

    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }

    for(int outer = 2; outer < n; outer++){
        int i = 1;
        for(int j = outer; j < n; i++,j++){
            int ans = INT_MAX;
            for(int k = i; k < j; k++){
                ans = min(ans, dp[i][k] + dp[k+1][j] + (arr[i-1]*arr[k]*arr[j]) );
            }
            dp[i][j] = ans;
        }
    }

    return dp[1][n-1];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int arr[10000];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        memset(dp,-1,sizeof(dp));
        cout<<minIterations(arr,1,n-1)<<endl;
        cout<<minIterations2(arr,n)<<endl;

    }

    return 0;
}
