#include <bits/stdc++.h>
using namespace std;

void extractno(string str){

          long i,no = 0;
          long ans = -1;
          bool flag = false, flag9 = false;
          for( i = 0; i < str.size(); i++){
              
              if(str[i] >= '0' && str[i] <= '9'){
                  if(str[i] == '9'){
                      flag9 = true;
                  }
                  no = no*10 + str[i] - 48;
                  flag = true;
              }
              else{
                  if(flag == true && flag9 == false){
                      ans = max(ans,no);
                  }
                  flag = false;
                  flag9 = false;
                  no = 0;
              }
          }
          if(flag == true && flag9 == false){
                ans = max(ans,no);
          }
          cout<<ans<<endl;

}

int main(){

     int t;
     string str;
     cin>>t;
     char ch;
     cin.get(ch);
     while(t--){
          
          getline(cin,str);

          extractno(str);
          
     }

     return 0;
}