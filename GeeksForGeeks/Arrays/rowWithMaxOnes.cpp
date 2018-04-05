#include <bits/stdc++.h>
using namespace std;


// here we use binary search
// time complexity is O(n+m) if each row of matrix is sorted
int rowWithMax1s(int arr[][1000], int n, int m){

     int ans = INT_MIN , row = 0;
     int i = 0, pos = -1;
     int s = 0, e = m-1;
     while(i < n){
          sort(arr[i],arr[i]+m);
          if(pos != -1){
               if(arr[i][pos] == 1){
                    e = pos - 1;
                    s = 0;
               }
               else if(arr[i][pos] == 0){
                    s = pos+1;
                    e = m-1;
               }
          }
          else{
               s = 0;
               e = m-1;
          }
          while(s <= e){
               int mid = (s+e)/2;
               if(arr[i][mid] == 0){
                    s = mid+1;
               }
               else{
                    e = mid-1;
                    pos = mid;
               }
          }

          if(pos != -1 && ans < m - pos){
              row = i;
              ans = m - pos;
          }
          i++;
     }

     return row;
}

int main(){

     int t;
     int arr[1000][1000];
     cin>>t;
     while(t--){
          int n,m;
          cin>>n>>m;
          for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++){
                    cin>>arr[i][j];
               }
          }

          cout<<rowWithMax1s(arr,n,m)<<endl;

     }

     return 0;
}
