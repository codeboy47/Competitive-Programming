#include <bits/stdc++.h>
using namespace std;

/*
Given a pattern string and a test string, Your task is to implement RegEx substring matching. 
If the pattern is preceded by a ^, the pattern(excluding the ^) will be matched with the starting 
position of the text string. Similarly, if it is preceded by a $, the pattern(excluding the ^) will be 
matched with the ending position of the text string. If no such markers are present, it will be checked 
whether pattern is a substring of test.
*/

bool search(char* pat, char* txt){

    int p = strlen(pat);
    int t = strlen(txt);

    for(int i = 0; i <= t - p; i++){
        
        int j;
        for( j = 0; j < p; j++){
            if(txt[i+j] != pat[j]){
                break;
            }
        }

        if(j == p){
            return true;
        }

    }

    return false;

}

int main(){

     int t;
     char str[10000],pat[10000];
     cin>>t;
     while(t--){
          
          cin>>pat>>str;
          
          int n = strlen(pat);
          bool flag = false;
          if(pat[0] == '^'){
              int i;
              for( i = 1; i < n; i++){
                  
                  if(str[i-1] != pat[i]){
                    break;
                  }
              }
              if(i == n)
                flag = true;
          }
          else if(pat[n-1] == '$'){
              int i;
              int j = strlen(str)-1;
              for( i = n-2; i >= 0; i--,j--){
                  if(str[j] != pat[i]){
                      break;
                  }
              }
              if(i == -1)
                flag = true;
          }
          else{
              flag = search(pat,str);
          }
          
          if(flag){
              cout<<1<<endl;
          }
          else{
              cout<<0<<endl;
          }
          
     }

     return 0;
}