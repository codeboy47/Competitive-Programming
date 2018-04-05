#include <bits/stdc++.h>
using namespace std;

int main(){

     int t;
     int arr[1000][1000];
     cin>>t;
     while(t--){
          int r,c;
          cin>>r>>c;
          for(int i = 0; i < r; i++){
              for(int j = 0; j < c; j++){
                  cin>>arr[i][j];
              }
          }

          bool flagCol = false;
          bool flagRow  = false;

          for(int i = 0; i < r; i++){
               if(arr[i][0] == 1){
                    flagRow = true;
               }
          }

          for(int i = 0; i < c; i++){
               if(arr[0][i] == 1){
                    flagCol = true;
               }
          }



          for(int i = 1; i < r; i++){
              for(int j = 1; j < c; j++){
                   if(arr[i][j] == 1){
                        arr[i][0] = 1;
                        arr[0][j] = 1;
                   }
              }
          }

          for(int i = 1; i < r; i++){
              for(int j = 1; j < c; j++){
                    if(arr[i][0] == 1 || arr[0][j] == 1){
                         arr[i][j] = 1;
                    }
              }
          }

          if(flagCol){
               for(int i = 0; i < c; i++){
                    arr[0][i] = 1;
               }
          }
          if(flagRow){
               for(int i = 0; i < r; i++){
                    arr[i][0] = 1;
               }
          }

          for(int i = 0; i < r; i++){
              for(int j = 0; j < c; j++){
                  cout<<arr[i][j]<<" ";
              }
          }

            cout<<endl;

     }

     return 0;
}
