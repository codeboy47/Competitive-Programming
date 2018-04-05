// Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island.

#include <iostream>
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


int countIslands(int arr[][1000], int r, int c){

     int count = 0;
     for(int i = 0; i < r; i++){
          for(int j = 0; j <  c; j++){
               if(arr[i][j] == 1){
                    dfsHelper(i,j,arr,r,c);
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
          int row,col;
          cin>>row>>col;
          for(int i = 0; i < row; i++){
               for(int j = 0; j <  col; j++){
                    cin>>arr[i][j];
               }
          }

          cout<<countIslands(arr,row,col)<<endl;
     }

     return 0;
}
