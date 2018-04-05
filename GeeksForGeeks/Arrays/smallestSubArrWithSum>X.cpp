#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n)
void smallestSubarrayWithSumGreaterThanX(int arr[], int n, int x){

     int i,sum = 0;
     int ans = INT_MAX;
     int s = 0, e = 0;
     for( i = 0; i < n; i++){
          sum += arr[i];
          while(sum > x && s <= i){
               ans = min(ans,i - s + 1);
               sum -= arr[s];
               s++;
          }
     }

     cout<<ans<<endl;
}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n,x;
          cin>>n>>x;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          smallestSubarrayWithSumGreaterThanX(arr,n,x);
     }

     return 0;
}
