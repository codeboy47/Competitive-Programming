#include <bits/stdc++.h>
using namespace std;

string superSeq(char* str1, int m, char* str2, int n) {

    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }

    for(int i = 0; i <= n; i++){
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++){

           if (str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1]; // same as lcs
           else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]); in lcs
        }
    }

    cout<<dp[m][n]<<endl;

    string res = "";
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            res = str1[i-1] + res;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j] ){
                res = str1[i-1] + res;
                i--;
            }
            else if(dp[i][j-1] <= dp[i-1][j]){
                res = str2[j-1] + res;
                j--;
            }
        }
    }

    while(i >= 0){
        res = str1[i-1] + res;
        i--;
    }

    while(j >= 0) {
        res = str2[j-1] + res;
        j--;
    }

    return res;
}


int main(){

    int t;
    cin>>t;
    char s1[10000],s2[10000];
    while(t--){

        cin>>s1>>s2;

        cout<<superSeq(s1,strlen(s1),s2,strlen(s2))<<endl;

    }

    return 0;
}
