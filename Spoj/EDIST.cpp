#include <iostream>
using namespace std;

// min steps required to convert s1 to s2

int editDistance(string s1, string s2){

    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }

    for(int i = 0; i <= m; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                //                  replace          remove         insert
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }

        }
    }

    return dp[n][m];

}


int main() {

int t = 10;
cin>>t;
while(t--){
    string str1,str2;
    cin>>str1>>str2;

    cout<<editDistance(str1,str2)<<endl;
}
}
