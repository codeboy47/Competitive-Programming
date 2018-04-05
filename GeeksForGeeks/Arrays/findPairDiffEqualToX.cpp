#include <bits/stdc++.h>
using namespace std;

int pairDifference(int *arr, int n, int diff){

     sort(arr,arr+n);

     int i = 0, j = 1;
     while(i < n && j < n){
          if(arr[j] - arr[i] < diff){
               j++;
          }
          else if(arr[j] - arr[i] > diff){
               i++;
          }
          else{
               return 1;
          }
     }
     return -1;
}

int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n,diff;
          cin>>n>>diff;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }


          cout<<pairDifference(arr,n,diff)<<endl;

     }

     return 0;
}
