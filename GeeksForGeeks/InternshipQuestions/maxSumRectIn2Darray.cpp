// Link :http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/

// we use kadane's algorithm
// 1st take 2 columns and then we calculate sum of every row within that columns and store it in temp array
// and apply kadane algorithm
// then we do this for every col pair


#include <iostream>
#include <string.h>
using namespace std;

int applyKadane(int *arr, int n){

     int cs = 0, ms = 0;
     for(int i = 0; i < n; i++){
          cs = arr[i] + cs;
          ms = max(ms,cs);
          if(cs < 0){
               cs = 0;
          }
     }
     return ms;
}

// time complexity is O(N)
int findMaxSumRectangle(int arr[][1000], int r, int c){

     int *temp = new int[10000];
     //int temp[r];
     int area = 0;
     for(int i = 0; i < c; i++){
          memset(temp,0,r*sizeof(int));
          for(int j = i; j < c; j++){
               int sum = 0;
               for(int k = 0; k < r; k++){
                    temp[k] = temp[k] + arr[k][j];
               }
               int x = applyKadane(temp,r);
          	   area = max(area,x);
          }



     }

	return area;
}

int main(){

     int r,c;
     int arr[1000][1000];
     cin>>r>>c;
     for(int i = 0; i < r; i++){
          for(int j = 0; j < c; j++){
               cin>>arr[i][j];
          }
     }

     cout<<findMaxSumRectangle(arr,r,c)<<endl;

     return 0;
}
