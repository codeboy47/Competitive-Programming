#include <bits/stdc++.h>
using namespace std;

// element that appears more than n/2 times

// time complexity is O(n) with O(1) space
// moore's voting algorithm is used here. It is a 2 step process.
int majorityElement(int *arr, int n){

     // finding majorityElement
     int majEl = arr[0];
     int count = 1;
     for(int i = 1; i < n; i++){
          if(arr[i] == majEl){
               count++;
          }
          if(arr[i] != majEl){
               count--;
          }
          if(count == 0){
               count = 1;
               majEl = arr[i];
          }
     }

     // check if majEl found is a majorityElement or not
     count = 0;
     for(int i = 0; i < n; i++){
          if(arr[i] == majEl){
               count++;
          }
     }

     return count >= (n/2) + 1 ? majEl : -1;
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

          int ans = majorityElement(arr,n);
          ans != -1 ? cout<<ans<<endl : cout<<"NO Majority Element"<<endl;
     }

     return 0;
}
