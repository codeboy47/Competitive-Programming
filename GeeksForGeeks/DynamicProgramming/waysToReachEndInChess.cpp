#include <bits/stdc++.h>
using namespace std;

/* no of ways to reach end(m,n) starting from(0,0) in chess game for:
i) horse
ii)elephant
iii)queen
*/

int waysForHorse(int arr[][1000], int n){

    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > 0 && j > 1)
                dp[i][j] = dp[i-1][j-2];
            if(i > 1 && j > 0)
                dp[i][j] += dp[i-2][j-1];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n-1][n-1];
}

int waysForElephant(int arr[][1000], int n){

    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;

    int sum = 2;
    for(int i = 2; i < n; i++){
        dp[0][i] += sum;
        sum += dp[0][i];
    }

    sum = 2;
    for(int i = 2; i < n; i++){
        dp[i][0] += sum;
        sum += dp[i][0];
    }


    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            for(int k = 1; k <= i; k++) // up
                dp[i][j] += dp[i-k][j] ;
            for(int k = 1; k <= j; k++) // left
                dp[i][j] += dp[i][j-k] ;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n-1][n-1];
}

int waysForQueen(int arr[][1000], int n){

    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;

    int sum = 2;
    for(int i = 2; i < n; i++){
        dp[0][i] += sum;
        sum += dp[0][i];
    }

    sum = 2;
    for(int i = 2; i < n; i++){
        dp[i][0] += sum;
        sum += dp[i][0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            for(int k = 1; k <= i; k++) // up
                dp[i][j] += dp[i-k][j];
            for(int k = 1; k <= j; k++) // left
                dp[i][j] += dp[i][j-k];
            for(int k = 1; k <= min(i,j); k++) // diagonally up left
                dp[i][j] += dp[i-k][j-k];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n-1][n-1];
}

int main(){

    int n = 4;
    int arr[1000][1000];

    cout<<waysForHorse(arr,n)<<endl;
    cout<<waysForElephant(arr,n)<<endl;
    cout<<waysForQueen(arr,n)<<endl;

    return 0;
}
