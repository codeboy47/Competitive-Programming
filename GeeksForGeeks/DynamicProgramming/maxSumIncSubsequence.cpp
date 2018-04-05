#include <bits/stdc++.h>
using namespace std;

int maxSumLIS( int arr[], int n ) {

    int i, j;
    int dp[n];
    dp[0] = arr[0];

    for ( i = 1; i < n; i++ ){
        int ans = 0;
        for ( j = i-1; j >= 0; j-- ){
            if ( arr[i] > arr[j] ){
                ans = max(ans,dp[j]);
            }
        }
        dp[i] = ans + arr[i];
    }

    int sum = -1;
    for ( i = 0; i < n; i++ )
        sum = max(sum,dp[i]);

    return sum;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int arr[100000];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<maxSumLIS(arr,n)<<endl;

    }

    return 0;
}
