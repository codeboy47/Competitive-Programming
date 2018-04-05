#include <bits/stdc++.h>
using namespace std;


int findMissingNo(int *arr, int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    for(int i = 0; i < n-1; i++){
        sum = sum - arr[i];
    }
    return sum;
}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n-1; i++){
               cin>>arr[i];
          }

          cout<<findMissingNo(arr,n)<<endl;

     }

     return 0;
}
