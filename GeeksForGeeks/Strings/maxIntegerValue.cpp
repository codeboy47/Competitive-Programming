#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          int val = (str[0]-48);
          for(int i = 1; i < strlen(str); i++){
              if(str[i] == '1' || str[i] == '0' || str[i-1] == '1' || str[i-1] == '0'){
                  val += (str[i]-48);
              }
              else{
                  val *= (str[i]-48);
              }
          }
          cout<<val<<endl;
     }

     return 0;
}