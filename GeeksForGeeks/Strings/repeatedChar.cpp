#include <bits/stdc++.h>
using namespace std;

char findFirstRepeatedCharacter(char *str){

     unordered_map<char,pair<bool,int> > hash;

     for(int i = 0; i < strlen(str); i++){
          if(hash.count(str[i]) == 0){
               hash[str[i]] = make_pair(false,i);
          }
          else{
               hash[str[i]].first = true;
          }
     }

     int pos = INT_MAX;
     char ch = '?';
     for(auto it = hash.begin(); it != hash.end(); it++){
          if(it->second.first == true && pos > it->second.second){
               pos = it->second.second;
               ch = it->first;
          }
     }

     return ch;
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){

          cin>>str;

          char s = findFirstRepeatedCharacter(str);
          if(s == '?'){
              cout<<-1<<endl;
          }
          else{
              cout<<s<<endl;
          }

     }

     return 0;
}
