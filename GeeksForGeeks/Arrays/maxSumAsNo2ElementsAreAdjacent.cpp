#include <bits/stdc++.h>
using namespace std;

// 1-D DP
// O(n)
int solve(int *arr, int n){

    arr[1] = max(arr[1],arr[0]);
    for(int i = 2;i < n; i++){
        arr[i] = max(arr[i-2]+arr[i],arr[i-1]);
    }

    return arr[n-1];
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

          cout<<solve(arr,n)<<endl;


     }

     return 0;
}
