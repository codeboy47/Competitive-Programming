#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers where each element represents the max number of steps that can be
made forward from that element. Write a function to return the minimum number of jumps to
reach the end of the array (starting from the first element). If an element is 0,
then cannot move through that element.
*/

// time complexity is O(n^2)
// dynamic programming
int minJumps(int arr[], int n){

     if(arr[0] == 0){
             return -1;
     }
     int *jumps = new int[1000];
     for(int i = 0; i < n; i++){
          jumps[i] = INT_MAX;
     }

     jumps[0] = 0;
     for(int i = 0; i < n; i++){
          for(int j = i+1; j <= n-1 && j <= arr[i] + i; j++){
               jumps[j] = min(jumps[j],jumps[i]+1);
          }
     }

     return jumps[n-1] == INT_MAX ?  -1 : jumps[n-1];
}

// time complexity is O(n)
int minJumps2(int arr[], int n){

     if(n <= 1){
          return 1;
     }
     if(arr[0] == 0){
          return -1;
     }

     int maxReach = arr[0];
     int steps = arr[0];
     int jumps = 1;
     for(int i = 1; i < n-1; i++){

          maxReach = max(maxReach,arr[i]+i);
          steps--;
          if(steps == 0){
               jumps++;
               if(i >= maxReach){
                    return -1;
               }
               steps = maxReach - i;
          }

     }

     return jumps;
}

int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          cout<<minJumps2(arr,n)<<endl;

     }

     return 0;
}
