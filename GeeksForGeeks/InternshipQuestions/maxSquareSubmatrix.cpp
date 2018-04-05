// Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
// Link: http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

#include <iostream>
using namespace std;

void findMaximumSquareSubmatrix(int arr[][10000], int n, int m){

     int dp[n][m];

     for(int i = 0; i < n; i++){
          dp[i][0] = arr[i][0];
     }

     for(int i = 0; i < m; i++){
          dp[0][i] = arr[0][i];
     }

     for(int i = 1; i < n; i++){
          for(int j = 1; j < m; j++){
               if(arr[i][j] == 0){
                    dp[i][j] = 0;
               }
               else{
                    dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
               }
          }
     }


     int max = dp[0][0] , x = 0, y = 0;
     for(int i = 0; i < n; i++){
          for(int j = 0; j <  m; j++){
               if(max < dp[i][j]){
                    max = dp[i][j];
                    x = j;
                    y = i;
               }
          }
     }

     for(int i = y-max+1; i <= y; i++){
          for(int j = x-max+1; j <=  x; j++){
               cout<<arr[i][j]<<" ";
          }
          cout<<endl;
     }
}


int main(){

     int arr[10000][10000];
     int n,m;
     cin>>n>>m;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               cin>>arr[i][j];
          }
     }

     findMaximumSquareSubmatrix(arr,n,m);

     return 0;
}
