#include <bits/stdc++.h>
using namespace std;

int countTotalDecodingMessages(string s, int n){

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){

        dp[i] = 0;

        if(s[i-1] > '0'){
            dp[i] = dp[i-1];
        }
        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')){
            dp[i] += dp[i-2];
        }
    }

    if(s[0] == '0'){
        return 0;
    }
    return dp[n];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        string s;

        cin>>s;

        cout<<countTotalDecodingMessages(s,n)<<endl;

    }

    return 0;
}
