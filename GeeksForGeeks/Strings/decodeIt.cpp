#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          int n;
          cin>>n;
          
          string res = "";
          
          int i = 0,no = 0;
          int power = 1;
          for( i = 0; i < strlen(str) ; i++){
              if(str[i] > 57){
                  if(i > 0 && str[i-1] <= 57){
                      string s = res;
                      for(int j = 0; j < no-1; j++){
                          res += s;
                      }
                  }
                  res += str[i];
                  no = 0;
                  power = 1;
              }
              else{
                  if(str[i] >= 48 && str[i] <= 57){
                  
                      no = no*power + str[i] - 48;
                      power *= 10;
                  }
              }
          }
          if(i > 0 && str[i-1] <= 57){
                      string s = res;
                      for(int j = 0; j < no-1; j++){
                          res += s;
                      }
                  }
          cout<<res[n-1]<<endl;
          
     }

     return 0;
}