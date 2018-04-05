#include <bits/stdc++.h>
using namespace std;

// Find minimum number of coins that make a given value

int coinsNeededTopDown(int *arr, int n, int size, int dp[]){
    if(n < 0)   return INT_MAX;
    if(n == 0)  return 0;

    if(dp[n] != -1)    return dp[n];

    int ans = INT_MAX;
    for(int i = 0; i < size; i++){
        ans = min(ans,coinsNeededTopDown(arr,n-arr[i],size,dp));
    }
    dp[n] = 1 + ans;
    return dp[n];
}

int coinsNeededBottomUp(int *arr, int amt, int size){

    int *dp = new int[amt+1];

    dp[0] = 0;

    for(int i = 1; i <= amt; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < size; j++){
            if(i - arr[j] >= 0){
                if(dp[i-arr[j]] != INT_MAX && dp[i] > 1 + dp[i-arr[j]])
                    dp[i] = 1 + dp[i-arr[j]];
            }
        }
    }

    return dp[amt] == INT_MAX ? -1 : dp[amt];
}

int main(){

    int us_coins[] = {1,7,10};
    int amount = 15; // Ans should be 3

    int indian_coins[] = {1,2,5,10,50};
    int paise = 39;

    int dp[100];
    memset(dp,-1,sizeof(int)*100);
    cout<<coinsNeededTopDown(indian_coins,paise,5,dp)<<endl;
    cout<<coinsNeededBottomUp(indian_coins,paise,5)<<endl;

    memset(dp,-1,sizeof(int)*100);
    cout<<coinsNeededTopDown(us_coins,amount,3,dp)<<endl;
    cout<<coinsNeededBottomUp(us_coins,amount,3)<<endl;

    return 0;
}
