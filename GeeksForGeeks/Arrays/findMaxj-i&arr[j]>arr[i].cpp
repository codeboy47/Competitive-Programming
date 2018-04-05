#include <bits/stdc++.h>
using namespace std;

// both time and space complexity is O(n)
int maxIndexDiff(int *arr, int n){

     int maxR[10000];
     int minL[10000];

     minL[0] = arr[0];
     for(int i = 1; i < n; i++){
          minL[i] = min(arr[i],minL[i-1]);
     }

     maxR[n-1] = arr[n-1];
     for(int i = n-2; i >= 0; i--){
          maxR[i] = max(arr[i],maxR[i+1]);
     }

     int i = 0, j = 0, ans = -1;
     while(i < n && j < n){
          if(minL[i] <= maxR[j]){
               ans = max(ans,j-i);
               j++;
          }
          else{
               i++;
          }
     }
     return ans;
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

          cout<<maxIndexDiff(arr,n)<<endl;

     }

     return 0;
}
