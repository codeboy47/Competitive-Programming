#include <bits/stdc++.h>
using namespace std;


// https://hack.codingblocks.com/contests/c/28/256

int minMoney(int *prices, int w){

    int *dp = new int[w+1];
    dp[0] = 0;
    dp[1] = prices[1];

    for(int i = 2; i <= w; i++){
        dp[i] = prices[i];
        for(int j = 1; j <= i/2; j++){
            if(prices[j] == -1) // as we cannot use this kg of orange
                continue;
            else if(dp[i] == -1)
                dp[i] = dp[j]+dp[i-j];
            else
                dp[i] = min(dp[i], dp[j]+dp[i-j]);
        }
    }

    return dp[w];
}

int main(){

    int n,w;
    cin>>n>>w;
    int prices[1000000];
    for(int i = 1; i <= w; i++){
        cin>>prices[i];
    }

    cout<<minMoney(prices,w)<<endl;
    return 0;
}
