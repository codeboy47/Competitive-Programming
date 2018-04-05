#include <bits/stdc++.h>
using namespace std;

int maxGold(int arr[][1000], int n, int m){

    int dp[n][m];
    memset(dp,0,sizeof(dp));

    for(int i = 0; i < n; i++){
        dp[i][0] = arr[i][0];
    }

    for(int j = 1; j < m; j++){
        for(int i = 0; i < n; i++){

            if(i == 0 && i == n-1){
                dp[i][j] = arr[i][j] + dp[i][j-1];
            }
            else if(i == 0){
                dp[i][j] = arr[i][j] + max(dp[i][j-1],dp[i+1][j-1]);
            }
            else if(i == n-1){
                dp[i][j] = arr[i][j] + max(dp[i-1][j-1],dp[i][j-1]);
            }
            else{
                dp[i][j] = arr[i][j] + max(dp[i-1][j-1], max(dp[i][j-1],dp[i+1][j-1]));
            }
        }
    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[i][m-1]);
    }

    return ans;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int arr[1000][1000];
        int n,m;
        cin>>n>>m;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }

        cout<<maxGold(arr,n,m)<<endl;

    }

    return 0;
}
