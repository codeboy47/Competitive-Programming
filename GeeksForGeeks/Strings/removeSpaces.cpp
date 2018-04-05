#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     string str;
     cin>>t;
     char ch;
     cin.get(ch);
     while(t--){
         
          getline(cin,str);
          
          for(int i = 0; i < str.size();){
                if(str[i] == ' '){
                    str.erase(str.begin()+i,str.begin()+i+1);
                }
                else{
                    i++;
                }
          }
         
          cout<<str<<endl;
     }

     return 0;
}