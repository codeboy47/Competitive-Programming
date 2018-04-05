#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
            
          int n;
          cin>>n;
          cin>>str;
          
          int i = 0, j = strlen(str)-1;
          while(i <= j && str[i] == str[j]){
              i++;
              j--;
          }
            
          if(i > j){
              cout<<"Yes"<<endl;
          }else{
              cout<<"No"<<endl;
          }
          
     }

     return 0;
}