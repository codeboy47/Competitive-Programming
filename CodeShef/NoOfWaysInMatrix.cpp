#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Ques: Finding the number of ways to reach from a starting position to an ending position
// travelling in specified directions only.
// dp[i][j] = dp[i-1][j] + dp[i][j-1]

// Now ques is few cells are blocked. Now find no  of ways to reach end. (CodeShef Question)
// https://www.codechef.com/problems/CD1IT4

int dp[10000][10000];

int numWays(int Row, int Col){

     // If first or last cell is blocked, return 0
    if(dp[0][0] == -1 || dp[Row-1][Col-1] == -1)
        return 0;

    //Number of ways for the first row
    for(int j = 0;j<Col;j++){
        if(dp[0][j] == -1)
            break;
        dp[0][j] = 1;
    }

    //Number of ways for first column
    for(int i = 0;i<Row;i++){
        if(dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }

    for(int i = 1;i<Row;i++) {
        for(int j = 1;j<Col;j++) {
            if(dp[i][j] == -1)
                continue;

            //Calculate no. of ways to visit (i,j)
            dp[i][j] = 0;
            if(dp[i][j-1] != -1)
                dp[i][j] = dp[i][j-1] % MOD;
            if(dp[i-1][j] != -1)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
        }
     }


    return dp[Row-1][Col-1];

}

int main(){

    int m,n,p;
    cin>>m>>n>>p;

    for(int i = 0; i < p; i++){
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1] = -1;
    }

    cout<<numWays(m,n)<<endl;

    return 0;
}
