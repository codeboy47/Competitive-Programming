#include <bits/stdc++.h>
using namespace std;

// product of all elements exept current element and division is not allowed

void TotalProductWithoutCurrElement(int arr[], int n){

     int *prod = new int[10000];

     int temp = 1;
     for(int i = 0; i < n; i++){
          prod[i] = temp;
          temp *= arr[i];
     }

     temp = 1;
     for(int i = n-1; i >= 0; i--){
          prod[i] *= temp;
          temp *= arr[i];
     }

     for(int i = 0; i < n; i++){
          cout<<prod[i]<<" ";
     }
     cout<<endl;
}


void TotalProductWithoutCurrElement2(int *arr, int n){

     double sum = 0;
     for(int i = 0; i < n; i++){
          sum += log(arr[i]);
     }

     for(int i = 0; i < n; i++){
          double ans = exp(sum - log(arr[i]));
          cout<<ans<<" ";
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

          TotalProductWithoutCurrElement(arr,n);
     }

     return 0;
}
