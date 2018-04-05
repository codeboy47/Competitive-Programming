#include <bits/stdc++.h>
using namespace std;

void sumClosestToZero(int *arr, int n){

     sort(arr,arr+n);
     int ans = INT_MAX;
     int s = 0, e = n-1;
     int first, second;
     while(s < e){
          if(arr[s] + arr[e] == 0){
              first = arr[s];
              second = arr[e];
              break;
          }
          if(arr[e] + arr[s] > 0){
               if(ans > arr[e] + arr[s]){
                    ans = arr[e] + arr[s];
                    first = arr[s];
                    second = arr[e];
               }
               e--;
          }
          if(arr[e] + arr[s] < 0){
               if(ans > abs(arr[e] + arr[s])){
                    ans = abs(arr[e] + arr[s]);
                    first = arr[s];
                    second = arr[e];
               }
               s++;
          }
     }
     cout<<first<<" "<<second<<endl;
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

          sumClosestToZero(arr,n);
     }

     return 0;
}
