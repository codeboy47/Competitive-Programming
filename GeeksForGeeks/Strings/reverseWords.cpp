#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     vector<string> v;
     string str;
     cin>>t;
     while(t--){
          
          cin>>str;
          
          string res = "";
          for(int i = 0; i < str.size(); i++){
              if(str[i] == '.'){
                  v.push_back(res);
                  res = "";
              }
              else{
                  res += str[i];
              }
          }
          
          v.push_back(res);
          reverse(v.begin(),v.end());
          
          for(int i= 0; i < v.size()-1; i++){
              cout<<v[i]<<".";
          }
          
          cout<<v[v.size()-1]<<endl;
          
          v.clear();

          
     }

     return 0;
}