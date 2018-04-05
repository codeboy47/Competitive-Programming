#include <bits/stdc++.h>
using namespace std;

// recursive approach
void solve(float k, int i, int j, float dp[][1000]){

    float n;

    if(dp[i][j] == 1){
        n = max(k,dp[i][j]);
        n = n/2;
    }
    else{

	    if(k >= 1)
	        dp[i][j] += 1;
	    else if(k < 1)
	        dp[i][j] += k;

	    if(dp[i][j] < 1)
	        return;

	    n = max(k,dp[i][j]);

        if(dp[i][j] > 1)
	        dp[i][j] = 1;

        n = (n-1)/2;
    }

    solve(n, i+1, j, dp); // left

    solve(n, i+1, j+1, dp); //right


}


float pascalTriangle(float k, int i, int j){

    float dp[i+1][1000];
    memset(dp,0,sizeof(dp));

    solve(k,1,1,dp);

    /*for(int a = 1; a <= i; a++){
        for(int b = 1; b <= i; b++){
            cout<<dp[a][b]<<" ";
        }
        cout<<endl;
    }*/

    return dp[i][j];

}


// iterative approach time and space is O(i^2)
float pascalTriangle2(float k, int i, int j){

    float dp[i+1][i+1];
    memset(dp,0,sizeof(dp));

    dp[1][1] = k;
    for(int x = 1; x <= i; x++){
        for(int y = 1; y <= x; y++){

            k = dp[x][y];

            dp[x][y] = (k >= 1) ? 1 : k;

            // if k < 1 means we cannot transfer to next glass
            dp[x+1][y] += (k >= 1) ? (k-1)/2 : 0;
            dp[x+1][y+1] += (k >= 1) ? (k-1)/2 : 0;

        }
    }

    for(int a = 0; a <= i; a++){
        for(int b = 0; b <= i; b++){
            cout<<dp[a][b]<<" ";
        }
        cout<<endl;
    }

    return dp[i][j];
}

// OR both above and below are same
float pascalTriangle2(float k, int i, int j){

    float dp[i+1][i+1];
    memset(dp,0,sizeof(dp));

    dp[1][1] = k;
    for(int x = 1; x <= i; x++){
        for(int y = 1; y <= x; y++){

            k = dp[x][y];

            if(k >= 1){
                dp[x][y] = 1;               // current glass
                dp[x+1][y] += (k-1)/2;      // left glass
                dp[x+1][y+1] += (k-1)/2;    // right glass
            }

            // if k < 1 means we cannot transfer to next glass
            else{
                dp[x][y] = k;
                dp[x+1][y] += 0;
                dp[x+1][y+1] += 0;
            }

        }
    }

    return dp[i][j];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        float k;
        cin>>k;

        int i,j;
        cin>>i>>j;

        cout<<pascalTriangle2(k,i,j)<<endl;

    }

    return 0;
}
