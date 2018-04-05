#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
          cin>>str;
          string res = "";
          int i,s = 0;
          for( i = 0; i < str.size(); i++){
              if(str[i] == '.'){
                  reverse(str.begin()+s,str.begin()+i);
                  
                  s = i+1;
              }
          }
          reverse(str.begin()+s,str.begin()+i);
          cout<<str<<endl;
     }

     return 0;
}