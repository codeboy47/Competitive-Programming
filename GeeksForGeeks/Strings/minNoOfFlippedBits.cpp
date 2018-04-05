#include <bits/stdc++.h>
using namespace std;


int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){

          cin>>str;

          int count1 = 0;
          for(int i = 0; str[i] != '\0'; i++){
              if(i%2 == 0 && str[i] == '1'){
                  count1++;
              }
              else if(i%2 == 1 && str[i] == '0'){
                  count1++;
              }
          }

          int count2 = 0;
          for(int i = 0; i < strlen(str); i++){
              if(i%2 == 0 && str[i] == '0'){
                  count2++;
              }
              else if(i%2 == 1 && str[i] == '1'){
                  count2++;
              }
          }

          cout<<min(count1,count2)<<endl;

     }

     return 0;
}
