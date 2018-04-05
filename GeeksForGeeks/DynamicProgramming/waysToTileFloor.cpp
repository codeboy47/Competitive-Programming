#include <bits/stdc++.h>
using namespace std;

/*
Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to find the number of ways the
floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile.
*/

long fib(int n){

    long a = 1;
    long b = 1;

    long c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return b;

}

// time and space is O(n)
long fibBottomUpDP(int n, int m = 2){

    if(n < m){
        return 1;
    }

    long *dp = new long[n+1];

    for(int i = 0; i < m; i++){
        dp[i] = 1;
    }

    for(int i = m; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-m];
    }

    return dp[n];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        cout<<fib(n)<<endl;


    }

    return 0;
}
