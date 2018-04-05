#include <bits/stdc++.h>
using namespace std;

int unitsTrappedWater(int *arr, int n){

     int left[10000];
     left[0] = arr[0];
     for(int i = 1; i < n; i++){
          left[i] = max(arr[i],left[i-1]);
     }

     int right[10000];
     right[n-1] = arr[n-1];
     for(int i = n-2; i >= 0; i--){
          right[i] = max(arr[i],right[i+1]);
     }

     int units = 0;
     for(int i = 0; i < n; i++){
          units += min(left[i],right[i]) - arr[i];
     }
     return units;
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

          cout<<unitsTrappedWater(arr,n)<<endl;

     }

     return 0;
}
