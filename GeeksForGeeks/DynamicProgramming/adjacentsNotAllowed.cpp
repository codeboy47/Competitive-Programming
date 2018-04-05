#include <bits/stdc++.h>
using namespace std;

int adjacentsNotAllowed(int arr[][10000], int n){

    if(n == 1){
        return max(arr[0][0],arr[1][0]);
    }

    int dp[n];
    memset(dp,0,sizeof(dp));

    dp[0] = max(arr[0][0], arr[1][0]);
    dp[1] = max(arr[0][1], arr[1][1]);
    dp[2] = dp[0] + max(arr[0][2],arr[1][2]);
    for(int i = 3; i < n; i++){

        dp[i] = max(dp[i-2],dp[i-3]) + max(arr[0][i],arr[1][i]);
    }

    return max(dp[n-2],dp[n-1]);

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int arr[2][10000];

        for(int i = 0;  i < 2; i++){
            for(int j = 0; j < n; j++){
                cin>>arr[i][j];
            }
        }

        cout<<adjacentsNotAllowed(arr,n)<<endl;
    }

    return 0;
}
