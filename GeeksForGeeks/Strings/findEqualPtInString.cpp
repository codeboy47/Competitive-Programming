#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          int s = 0, e = strlen(str)-1;
          
          while(s <= e){
              
              if(str[s] == '(' && str[e] == ')'){
                  s++;
                  e--;
              }
              
              else if(str[s] == ')' && str[e] == ')'){
                  s++;
              }
              
              else if(str[s] == '(' && str[e] == '('){
                  e--;
              }
              
              else{
                  s++;
                  e--;
              }
          }
          
          cout<<e+1<<endl;
          
     }

     return 0;
}