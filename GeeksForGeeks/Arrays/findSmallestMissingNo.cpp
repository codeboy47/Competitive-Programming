#include <bits/stdc++.h>
using namespace std;

// time complexity is O(logn)
// binary search
int smallestMissingNo(int arr[], int n){

     int s = 0, e = n-1;
     while(s <= e){
          if(s != arr[s]){
              return s;
          }
          int mid = (s+e)/2;
          if(arr[mid] > mid){
               e = mid;
          }
          else{
               s = mid+1;
          }
     }

    return -1;
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

          cout<<smallestMissingNo(arr,n)<<endl;

     }

     return 0;
}
