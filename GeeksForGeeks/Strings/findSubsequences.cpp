#include <bits/stdc++.h>
using namespace std;

bool isVowel(char* str){
    int i = 0;
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
        return true;
    }
    return false;
}

bool isConsonant(char *str){
    int i = strlen(str) - 1;
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
        return false;
    }
    return true;
}

void findSubsequences(char *str,char *out, int i, int j, set<string> &s){

     if(str[j] == '\0'){
          out[i] = '\0';
          if(isVowel(out) && isConsonant(out) && strlen(out) > 1){
              string ss(out);
              s.insert(ss);
          }
          return;
     }

     out[i] = str[j];
     findSubsequences(str,out,i+1,j+1,s);

     findSubsequences(str,out,i,j+1,s);
}

bool compare(string s1, string s2){
    return s1 < s2;
}

int main(){

     set<string> s;
     vector<string> arr;
     int t;
     char str[10000], out[10000];
     cin>>t;
     while(t--){

          cin>>str;

          findSubsequences(str,out,0,0,s);

          if(s.empty()){
              cout<<-1<<endl;
          }
          else{
              for(auto it = s.begin(); it != s.end(); it++){
                  arr.push_back(*it);
              }

              sort(arr.begin(),arr.end(),compare);
              for(int i = 0; i < arr.size(); i++){
                  cout<<arr[i]<<" ";
              }
              cout<<endl;
          }
          s.clear();
          arr.clear();
     }

     return 0;
}
