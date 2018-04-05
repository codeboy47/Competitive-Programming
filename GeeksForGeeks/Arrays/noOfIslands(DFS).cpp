#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int x, int y, int arr[][1000], int r, int c){

     arr[x][y] = 2;

     // top-right
     if(x != 0 && y != c-1 && arr[x-1][y+1] == 1){
          dfsHelper(x-1,y+1,arr,r,c);
     }

     // right
     if(y != c-1 && arr[x][y+1] == 1){
          dfsHelper(x,y+1,arr,r,c);
     }

     // down-right
     if(x != r-1 && y != c-1 && arr[x+1][y+1] == 1){
          dfsHelper(x+1,y+1,arr,r,c);
     }

     //down
     if(x != r-1 && arr[x+1][y] == 1){
          dfsHelper(x+1,y,arr,r,c);
     }

     // down-left
     if(x != r-1 && y != 0 && arr[x+1][y-1] == 1){
          dfsHelper(x+1,y-1,arr,r,c);
     }

     //left
     if(y != 0 && arr[x][y-1] == 1){
          dfsHelper(x,y-1,arr,r,c);
     }

     // top-left
     if(x != 0 && y != 0 && arr[x-1][y-1] == 1){
          dfsHelper(x-1,y-1,arr,r,c);
     }

     // top
     if(x != 0 && arr[x-1][y] == 1){
          dfsHelper(x-1,y,arr,r,c);
     }

}

int noOfIslands(int arr[][1000], int N, int M)
{
    int count = 0;
     for(int i = 0; i < N; i++){
          for(int j = 0; j <  M; j++){
               if(arr[i][j] == 1){
                    dfsHelper(i,j,arr,N,M);
                    count++;
               }
          }
     }

     return count;
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

          cout<<noOfIslands(arr,n,m)<<endl;

     }

     return 0;
}
