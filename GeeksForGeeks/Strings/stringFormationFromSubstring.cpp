// Find if a given string can be represented from a substring by iterating the substring “n” times
// this question is an application of KMP pattern searching where lps is used

#include <bits/stdc++.h>
using namespace std;

void createLPS(int *lps, char *pat){

  int j = 0;
  lps[0] = 0;
  for(int i = 1; i < strlen(pat); i++){

    if(pat[i] == pat[j]){
      lps[i] = j + 1;
      j++;
    }
    else{
      if(j > 0){
          j = lps[j-1];
          i--;
      }
      else{
        lps[i] = 0;
      }
      
    }
  }
}

bool check(string str, int len , int n){

    string res, aux = str.substr(0,len);
    for(int i = 0; i < n/len; i++){
        res += aux;
    }
    if(res == str){
        return true;
    }
    return false;
}

int main(){

     int t;
     char str[100000];
     int arr[100000];
     cin>>t;
     while(t--){
          
          cin>>str;
          createLPS(arr,str);
          int n = strlen(str);
          
          if(arr[n-1] == 0){
              cout<<"False"<<endl;
          }
          else{
              
              int len;
              if(arr[n-1] <= n/2){
                  len = arr[n-1];
              }
              else{
                  len = n%arr[n-1];
              }
              if(check(str,len,n)){
                  cout<<"True"<<endl;
              }else{
                  cout<<"False"<<endl;
              }
          }
          
     }

     return 0;
}