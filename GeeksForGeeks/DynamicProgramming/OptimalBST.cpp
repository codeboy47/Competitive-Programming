#include <bits/stdc++.h>
using namespace std;

int optimalSearchTree(int *keys, int *freq, int n){

    int dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = INT_MAX;
        }
    }

    for(int k = 0; k < n; k++){
        int i = 0;
        for(int j = k; j < n; j++,i++){
            if(i == j){
                dp[i][j] = freq[i];
            }
            else{
                int sum = 0;
                for(int a = i; a <= j; a++){
                    sum += freq[a];
                }
                //cout<<" "<<sum<<"-";

                for(int a = i; a <= j; a++){
                    int ans = 0;
                    if(a != i)
                        ans += dp[i][a-1];
                    if(a != j)
                        ans += dp[a+1][j];

                    //cout<<" "<<a<<"-"<<ans<<"-"<<j<<" ";
                    dp[i][j] = min(ans,dp[i][j]);
                }

                dp[i][j] += sum;
            }
        }
    }

    return dp[0][n-1];
}

int main(){

    int keys[] = {10, 12, 16, 21};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));
    return 0;
}
