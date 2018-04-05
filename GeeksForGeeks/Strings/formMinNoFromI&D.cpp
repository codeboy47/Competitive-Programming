#include <bits/stdc++.h>
using namespace std;

// time and space complexity is O(n)
void formMinNo(string str){

     stack<int> s;
     string output = "";

     for(int i = 0; i <= str.length(); i++){

          s.push(i+1);

          if(i == str.length() || str[i] == 'I'){
               while(!s.empty()){
                    output += to_string(s.top());
                    s.pop();
               }
          }
     }

     cout<<output<<endl;
}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){

          cin>>str;

          formMinNo(str);

     }

     return 0;
}
