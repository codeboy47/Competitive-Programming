#include <bits/stdc++.h>
using namespace std;

// this is a dp question
int printMaxSquare(int arr[][1000], int n, int m){

    int dp[n][m];
    for(int i = 0; i <  n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = arr[i][j];
        }
    }

    for(int i = 1; i <  n; i++){
        for(int j = 1; j < m; j++){
            if(dp[i][j] == 1){
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }

    int ans = 1;
    for(int i = 1; i <  n; i++){
        for(int j = 1; j < m; j++){
            ans = max(ans,dp[i][j]);
        }
    }

    return ans;

}

int main(){

    int t;
    cin>>t;
    int arr[1000][1000];
    while(t--){

        int n,m;
        cin>>n>>m;

        for(int i = 0; i <  n; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }

        cout<<printMaxSquare(arr,n,m)<<endl;

    }

    return 0;
}
