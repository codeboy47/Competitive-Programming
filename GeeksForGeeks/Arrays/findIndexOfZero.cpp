#include <bits/stdc++.h>
using namespace std;

// my method
int findIndexOfZero(int arr[], int n){

     int leftsum = 0, rightsum = 0, totalsum = 0;
     int pos = 0;
     for(int i = 0; i < n; i++){

          if(arr[i] == 0){
               if(i != n-1 && arr[i+1] == 1){
                    if(totalsum < leftsum+rightsum){
                         totalsum = leftsum + rightsum;
                         pos = i - rightsum - 1;
                    }
                    leftsum = rightsum;
                    rightsum = 0;
               }
               else{
                    if(totalsum < leftsum+rightsum){
                         totalsum = leftsum + rightsum;
                         pos = i;
                    }
                    leftsum = 0;
                    rightsum = 0;
               }
          }
          else{
               rightsum += arr[i];
          }
     }
     if(arr[n-1] == 1){
          if(totalsum < leftsum+rightsum){
               totalsum = leftsum + rightsum;
               pos = n-1 - rightsum;
          }
     }

     return pos;
}

// gfg method
int findIndexOfZero2(int arr[], int n){

     int prevZero = -1, prevPrevZero = -1;
     int count = 0, pos = 0;
     for(int i = 0; i < n; i++){
          if(arr[i] == 0){
               if(count < i - prevPrevZero){
                    count = i - prevPrevZero;
                    pos = prevZero;
               }
               prevPrevZero = prevZero;
               prevZero = i;
          }
     }

     if(count < n - prevPrevZero){
          pos = prevZero;
     }

     return pos;
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

          cout<<findIndexOfZero(arr,n)<<endl;
          cout<<findIndexOfZero2(arr,n)<<endl;

     }

     return 0;
}
