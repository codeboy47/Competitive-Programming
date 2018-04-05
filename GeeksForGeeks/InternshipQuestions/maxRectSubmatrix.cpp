// Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
//Link: http://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

#include <iostream>
#include <stack>
using namespace std;

int findArea(int *arr, int n){

     stack<int> s;

     int area = 0;
     for(int i = 0; i < n; i++){
          while(!s.empty() && arr[i] < arr[s.top()]){
               int top = s.top();
               s.pop();
               if(s.empty()){
                    area = max(area,arr[top]*i);
               }
               else{
                    area = max(area,arr[top]*(i-s.top()-1));
               }
          }
          s.push(i);
     }

     while(!s.empty()){
          int top = s.top();
          s.pop();
          if(s.empty()){
               area = max(area,arr[top]*n);
          }
          else{
               area = max(area,arr[top]*(n-s.top()-1));
          }
     }

     return area;

}

int maxRectArea(int arr[][10000], int n, int m){

     for(int i = 1; i < n; i++){
          for(int j = 0; j < m; j++){
               if(arr[i][j] != 0)
                    arr[i][j] = arr[i][j] + arr[i-1][j];
          }
     }

     int maxarea = 0;
     for(int i = 0; i < n; i++){
          maxarea = max(maxarea,findArea(arr[i],m));
     }

     return maxarea;

}

int main(){

     int n,m;
     int arr[10000][10000];
     cin>>n>>m;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               cin>>arr[i][j];
          }
     }

     cout<<maxRectArea(arr,n,m);

     return 0;
}
