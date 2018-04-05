#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;


void fillArray(int *arr, int n){

     int left = 0;
     if(arr[0] == 0){
          for(int i = 0; i < n; i++){
               if(arr[i] == 1){
                    left = i;
                    break;
               }
          }
     }

     int right = 0;
     if(arr[n-1] == 0){
          for(int i = n-1; i >= 0; i--){
               if(arr[i] == 1){
                    right = n - 1 - i;
                    break;
               }
          }
     }

     int sp = -1;
     int ep = 0;
     int diff = INT_MIN;
     for(int i = 0; i < n; i++){
          if(arr[i] == 1){
               ep = i;
               diff = max(diff,ep-sp);
               sp = ep;
          }

     }
     
     if(diff == INT_MIN){
          cout<<-1<<endl;
     }
     else{
          int ans = max(diff/2,max(left,right));
          cout<<ans<<endl;
     }
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

          fillArray(arr,n);
     }

     return 0;
}
