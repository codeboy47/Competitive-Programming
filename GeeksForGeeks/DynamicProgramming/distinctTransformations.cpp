#include <bits/stdc++.h>
using namespace std;

int printUniqueTransformations(string a, string b){

    int n1 = b.size();
    int n2 = a.size();
    int dp[n1+1][n2+1];

    for(int i = 0; i <= n1; i++){
        dp[i][0] = 0;
    }

    for(int i = 0; i <= n2; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){

            if(i > j){
                dp[i][j] = 0;
            }
            else if(b[i-1] == a[j-1]){
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n1][n2];
}

int main(){

    int t;
    cin>>t;
    while(t--){

        string a,b;
        cin>>a>>b;

        cout<<printUniqueTransformations(a,b)<<endl;

    }

    return 0;
}
