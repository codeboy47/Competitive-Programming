#include<bits/stdc++.h>
using namespace std;

int findMinCutSquare(int a, int b){

    int dp[a+1][b+1];

    for(int i = 0; i <= a; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= b; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){

            int ans = INT_MAX;
            for(int k = 1; k <= j/2; k++){
                ans = min(ans, dp[i][k] + dp[i][j-k]);
            }
            for(int k = 1; k <= i/2; k++){
                ans = min(ans, dp[k][j] + dp[i-k][j]);
            }

            if(i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = ans;
        }
    }

    return dp[a][b];

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int a,b;
        cin>>a>>b;

        cout<<findMinCutSquare(a,b)<<endl;

    }

    return 0;
}
