#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     char res[1000][1000];
     cin>>t;
     while(t--){
          
          cin>>str;
          int len = strlen(str);
          
          for(int i = 0; i < len; i++){
              for(int j = 0; j < len; j++){
                  res[i][j] = ' ';
              }
          }
          
          for(int i = 0; i < len; i++){
              for(int j = 0; j < len; j++){
                  if(i == j){
                      res[i][j] = str[i];
                  }
              }
          }
          
          for(int i = 0; i < len; i++){
              for(int j = 0; j < len; j++){
                  if(i+j == len-1){
                      res[i][j] = str[j];
                  }
              }
          }
          for(int i = 0; i < len; i++){
              for(int j = 0; j < len; j++){
                  cout<<res[i][j];
              }
              //cout<<endl;
          }
          cout<<endl;
     }

     return 0;
}