#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(string str)
{
  unordered_map<char,int> hash;
  
  for (int i = 0; i < str.size();  i++)
  {
    if (hash.count(str[i]) == 0){
        hash[str[i]] = i;
    }
    else{
        hash[str[i]] = INT_MAX;
    }
  }  
  
  int pos = INT_MAX;
  for(auto it = hash.begin(); it != hash.end(); it++){
      pos = min(pos,it->second);
  }
   
  return pos;
}

int main(){

     int t;
     string str,patt;
     cin>>t;
     while(t--){
          
          int n;
          cin>>n;
          cin>>str;
          
          int i = firstNonRepeating(str);
          if(i == INT_MAX){
              cout<<-1<<endl;
          }
          else
          cout<<str[i]<<endl;
          
     }

     return 0;
}