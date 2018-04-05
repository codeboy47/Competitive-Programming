#include <bits/stdc++.h>
using namespace std;

int countChar(char *str, int n){

     unordered_map<char,int> hash;

     for(int i = 0; i < strlen(str); i++){
          if(hash.count(str[i]) == 0 && str[i] != str[i+1]){
               hash[str[i]] = 1;
          }
          else if(hash.count(str[i]) == 1 && str[i] != str[i+1]){
               hash[str[i]]++;
          }
     }

     int count = 0;
     for(auto it = hash.begin(); it != hash.end(); it++){
          if(it->second == n){
               count++;
          }
     }
     return count;
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>str;
          cin>>n;

          cout<<countChar(str,n)<<endl;

     }

     return 0;
}
