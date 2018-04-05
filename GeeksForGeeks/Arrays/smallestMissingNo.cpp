#include <bits/stdc++.h>
using namespace std;

// we can use sorting and hashing also but they take more memory and time

// gfg method but its simple
// time complexity is O(n) and space complexity is O(1)
int findSmallestMissingNo(int arr[], int n){

     // separate +ve no from -ve no
     int fp = 0;
     for(int sp = 0; sp < n; sp++){
          if(arr[sp] > 0){
               swap(arr[sp],arr[fp]);
               fp++;
          }
     }

     for(int i = 0; i < fp; i++){
          if(arr[i] > 0  && arr[arr[i]-1] > 0 ){
               arr[arr[i]-1] = -arr[arr[i]-1];
          }
          else if(arr[i] < 0  && arr[-arr[i]-1] > 0 ){
                    arr[-arr[i]-1] = -arr[-arr[i]-1];
          }
     }

     for(int i = 0; i < fp; i++){
          if(arr[i] > 0){
               return i+1;
          }
     }
     return n+1;

}

// my method but difficult to implement
// time complexity is O(n) and space complexity is O(1)
int findSmallestMissingNo2(int arr[], int n){

     for(int i = 0; i < n; i++){
          if(arr[i] < 0){
               arr[i] = 0;
          }
     }

     for(int i = 0; i < n; i++){
          if(arr[i] < 0){
               if(arr[-arr[i]-1] == 0){
                    arr[-arr[i]-1] = arr[i];
               }
               else if(-arr[i]-1 < n && arr[-arr[i]-1] > 0){
                    arr[-arr[i]-1] = -arr[-arr[i]-1];
               }
          }
          else if(i != 0 && arr[arr[i]-1] == 0){
               arr[arr[i]-1] = -arr[i];
          }
          else if(arr[i] > 0 && arr[i]-1 < n && arr[arr[i]-1] > 0){
               arr[arr[i]-1] = -arr[arr[i]-1];
          }
     }

     for(int i = 0; i < n; i++){
          if(arr[i] >= 0){
               return i+1;
          }
     }
     return n+1;
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

          cout<<findSmallestMissingNo(arr,n)<<endl;

     }

     return 0;
}
