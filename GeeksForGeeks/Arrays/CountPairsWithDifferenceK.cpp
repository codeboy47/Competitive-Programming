#include <bits/stdc++.h>
using namespace std;

int countAllPairDifference(int *arr, int n, int diff){

     sort(arr,arr+n);
     unordered_map<int,int> hash;
     int i = 0, j = 1, count = 0;
     while(i < n && j < n){
          if(i == j){
              j++;
              if(j==n){
                  break;
              }
          }
          if(arr[j] - arr[i] < diff){
               j++;
          }
          else if(arr[j] - arr[i] > diff){
               i++;
          }
          else if(arr[j] - arr[i] == diff){
              if(hash.count(arr[i]) == 0){
                  count++;
                  hash[arr[i]] = arr[j];
              }
              i++;j++;
          }
     }
     return count;
}

int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n,diff;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }
          cin>>diff;

          cout<<countAllPairDifference(arr,n,diff)<<endl;

     }

     return 0;
}
