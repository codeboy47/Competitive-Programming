#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){

          vector<string> arr;
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
              string s;
              cin>>s;
              arr.push_back(s);
          }

          unordered_map<string,int> hash;

          for(int i = 0; i < arr.size(); i++){
              if(hash.count(arr[i]) == 0){
                  hash[arr[i]] = 1;
              }
              else{
                  hash[arr[i]]++;
              }
          }

          int count = 0;
          for(auto it = hash.begin(); it != hash.end(); it++){
              if(it->second == 2){
                  count++;
              }
          }

          cout<<count<<endl;
     }

     return 0;
}
