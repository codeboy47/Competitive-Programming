// Count of subarrays whose maximum element is greater than k

#include <iostream>
using namespace std;

// concept : total no of subarrays are n*(n+1) / 2 

// time complexity is O(n)
int countSubarray(int *arr, int n, int k){

     int i = 0;
     int ans = 0;
     while(i < n){

          if(arr[i] > k){
               i++;
               continue;
          }

          int count = 0;
          while(i < n && arr[i] <= k){
               i++;
               count++;
          }

          ans = ans + (count*(count+1))/2;

     }

     return ((n*(n+1))/2) - ans;

}


int main(){

     int arr[100000];
     int n,k;
     cin>>n>>k;
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

    cout<<countSubarray(arr,n,k);

     return 0;
}
