#include <bits/stdc++.h>
using namespace std;


bool findBadString(char *str){

     int vow = 0, cons = 0;
     for(int i = 0; str[i] != '\0'; i++){

          if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
               vow++;
               cons = 0;
               if(vow > 5){
                    return false;
               }
          }
          else if(str[i] == '?'){
               vow++;
               cons++;
               if(vow > 5 || cons > 3){
                    return false;
               }
          }
          else{
               cons++;
               vow = 0;
               if(cons > 3){
                    return false;
               }
          }
     }
     return true;
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){

          cin>>str;

          bool ans = findBadString(str);
          if(ans == true){
               cout<<"1"<<endl;
          }else{
               cout<<"0"<<endl;
          }

     }

     return 0;
}
