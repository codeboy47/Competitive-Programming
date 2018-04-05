#include <bits/stdc++.h>
using namespace std;

// it is 1-d dp question

int solve(int *arr, int n){

    for(int i = 0;i < n; i++){
        if(i == 2){
            arr[i] = arr[i] + arr[0];
        }
        if(i > 2){
            arr[i] = arr[i] + max(arr[i-2],arr[i-3]);
        }
    }

    return max(arr[n-1],arr[n-2]);
}

int solve2(int *arr, int n){

    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i = 2;i < n; i++){
         dp[i] = max(arr[i] + dp[i-2],dp[i-1]);
    }

    return dp[n-1];
}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          cout<<solve2(arr,n)<<endl;


     }

     return 0;
}
