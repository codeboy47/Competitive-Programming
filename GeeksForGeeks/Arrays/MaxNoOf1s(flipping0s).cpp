#include <bits/stdc++.h>
using namespace std;

int maxNoOfOnes(int arr[], int n, int m){

     int count = 0;
     for(int i = 0; i < n; i++){
          if(arr[i] == 0){
               count++;
          }
     }

     if(count <= m){
          return n;
     }

     count = 0;
     int ans = -1, l = 0, r = 0;
     while(r < n){

          while(r < n && count <= m){
               if(arr[r] == 0){
                    count++;
               }
               r++;
          }

          if(count > m){
               ans = max(ans,r - l - 1);
               while(count > m){
                    if(arr[l] == 0){
                         count--;
                    }
                    l++;
               }
          }
     }

     ans = max(ans,r-l-1);
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
          int m;
          cin>>m;
          cout<<maxNoOfOnes(arr,n,m)<<endl;

     }

     return 0;
}
