#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     string str,patt;
     cin>>t;
     while(t--){
          
          cin>>str;
          cin>>patt;  
          unordered_map<char,bool> hash;
          for(int i = 0; i < patt.size(); i++){
              hash[patt[i]] = true;
          }
            int i;
          for(i = 0; i < str.size(); i++){
              if(hash.count(str[i])){
                  cout<<str[i]<<endl;
                  break;
              }
          }
          
          if(i == str.size()){
              cout<<"No character present"<<endl;
          }
     }

     return 0;
}