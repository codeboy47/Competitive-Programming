#include <bits/stdc++.h>
using namespace std;

void rotateBy90(int arr[][1000], int n){

     // first we make transpose of matrix
     for(int i = 0; i < n; i++){
          for(int j = i; j < n; j++){
               if(i != j)
                    swap(arr[i][j],arr[j][i]);
          }
     }

     // now we reverse each column
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n/2; j++){
               swap(arr[j][i],arr[n-j-1][i]);
          }
     }

     // print matrix
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
               cout<<arr[i][j]<<" ";
          }
     }
     cout<<endl;
}

int main(){

     int t;
     int arr[1000][1000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++){
                    cin>>arr[i][j];
               }
          }

          rotateBy90(arr,n);

     }

     return 0;
}
