// http://www.geeksforgeeks.org/count-possible-groups-size-2-3-sum-multiple-3/
#include <bits/stdc++.h>
using namespace std;

int countPossibleGroups(int *arr, int n){

     int count = 0;
     int c[3];
     memset(c,0,sizeof(c));
     for(int i = 0; i < n; i++){
          c[arr[i]%3]++;
     }

     // for group 2, we have 2 possiblities :
     count += (c[0]*(c[0]-1))/2;   // c[0] C 2
     count += c[1]*c[2];

     // for group 3, we have 4 possiblities :
     count += (c[0]*(c[0]-1)*(c[0]-2))/6;  // c[0] C 3
     count += (c[1]*(c[1]-1)*(c[1]-2))/6;  // c[1] C 3
     count += (c[2]*(c[2]-1)*(c[2]-2))/6;  // c[2] C 3
     count += c[0]*c[1]*c[2]; // one element from each index

     return count;
}

int main(){

     int t;
     cin>>t;
     while(t--){
          int n;
          int arr[100000];
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          cout<<countPossibleGroups(arr,n)<<endl;

     }

     return 0;
}
