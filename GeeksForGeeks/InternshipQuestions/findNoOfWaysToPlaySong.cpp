/*
Array of song's duration is given and airTime is given. RJ wants to play exactly 3 songs in that airTime
Find total no of ways he can play the songs.
Sample Input :
5 21
10 7 9 5 2
ans : 3
8 40
7 14 21 19 17 2 29 5
ans :
7 58
22 9 27 3 23 28 8
ans : 4
*/

#include <iostream>
#include <algorithm>
using namespace std;

// time complexity is O(N^3)
int findWaysBruteForce(int *arr, int n, int airTime){
     int count = 0;
     for(int i = 0;i < n-2; i++){
          for(int j = i+1;j < n-1; j++){
               for(int k = j+1; k < n; k++){
                    if(arr[i]+arr[j]+arr[k] == airTime){
                         count++;
                    }
               }
          }
     }
     return count;
}

// time complexity is O(N^2)
int findWaysSlidingWindow(int *arr, int n, int airTime){

     sort(arr,arr+n);

     int count = 0;
     for(int i = 0; i < n-1; i++){
          int x = airTime - arr[i];
          int s = i+1, e = n-1;
          while(s < e){
               if(arr[s] + arr[e] < x){
                    s++;
               }
               else if(arr[s] + arr[e] > x){
                    e--;
               }
               else{
                    count++;
                    s++;
                    e--;
               }
          }
     }

     return count;
}

int main(){

     int n,airTime;
     int songs[100000];
     cin>>n>>airTime;
     for(int i = 0; i < n; i++){
          cin>>songs[i];
     }
     cout<<findWaysBruteForce(songs,n,airTime)<<endl;
     cout<<findWaysSlidingWindow(songs,n,airTime)<<endl;

     return 0;
}
