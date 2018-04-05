#include <bits/stdc++.h>
using namespace std;


int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
           char ch;
           int n;
          cin>>str;
          cin>>ch;
          cin>>n;

          int count = 0;
          int pos = 0;
          bool flag = true;
          for(int i = 0; str[i] != '\0' ; i++){
              if(str[i] == ch){
                  count++;
              }
              if(count == n){
                     if(n == 0){
                         pos = 0;
                     }else
                      pos = i+1;
                    flag = false;
                    break;
              }
          }

          if(flag == true || str[pos] == '\0'){
              cout<<"Empty string";
          }else{
              for(int i = pos; i < strlen(str); i++){
                  cout<<str[i];
              }
          }
          cout<<endl;

     }

     return 0;
}
