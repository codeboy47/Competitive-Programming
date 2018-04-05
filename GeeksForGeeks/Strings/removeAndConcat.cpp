#include <bits/stdc++.h>
using namespace std;

void removeCommonCharAndConcatenate(string str1, string str2){

     unordered_map<char,bool> hash;

    string result = "";
    for(int i = 0; i < str2.size(); i++){
         if(hash.count(str2[i]) == 0){
              hash[str2[i]] = true;
         }
    }

    for(int  i = 0; i < str1.size(); i++){
         if(!hash.count(str1[i])){
             result += str1[i];
         }
         else {
             hash[str1[i]] = false;
         }
    }

    for(int i = 0; i < str2.length(); i++){
        if(hash[str2[i]] == true){
            result += str2[i];
        }
    }

    if(result == ""){
        cout<<-1<<endl;
    }
    else{
        cout<<result<<endl;
    }
}

int main(){

     int t;
     string str1,str2;
     cin>>t;
     while(t--){

          cin>>str1>>str2;

          removeCommonCharAndConcatenate(str1,str2);

     }

     return 0;
}
