#include <bits/stdc++.h>
using namespace std;

// we maintain 2 values at each index
// positiveProduct stores max positive product at current index
// negativeProduct stores max negative product at current index
int maxProduct(int *arr, int n){

     int pp = 1, np = 1, mp = 1;
     for(int i = 0; i < n; i++){

          if(arr[i] > 0){
               pp *= arr[i];
               np = min(1,np*arr[i]);
          }

          if(arr[i] == 0){
               np = 1;
               pp = 1;
          }

          if(arr[i] < 0){
               int temp = np*arr[i];
               np = arr[i]*pp;
               pp = max(temp,1);
          }

          mp = max(mp,pp);

     }

     return mp;
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

          cout<<maxProduct(arr,n)<<endl;

     }

     return 0;
}
