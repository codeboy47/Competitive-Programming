#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          int count = 0;
          int n = strlen(str);
          for(int i = 0; i < n; i++){
              if(str[i] == '1'){
                  count++;
              }
          }
          
          int ans = count*(count-1)/2;
          cout<<ans<<endl;

          
     }

     return 0;
}