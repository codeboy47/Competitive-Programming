#include <bits/stdc++.h>
using namespace std;


void findSum(string str1, string str2){

     string result = "";
     int carry = 0;
     int i = str1.size()-1,  j = str2.size()-1;
     while(i >= 0 && j >= 0){
          int no = str1[i]-48 + str2[j]-48;
          if(carry == 1){
               no++;
          }
          if(no < 10){
               result += no + 48;
               carry = 0;
          }
          else{
               carry = 1;
               result += no + 38;
          }
          i--;
          j--;
     }

     while(i >= 0){
          int no = str1[i]-48;
          if(carry == 1){
               no++;
          }
          if(no < 10){
               result += no + 48;
               carry = 0;
          }
          else{
               carry = 1;
               result += no + 38;
          }
          i--;
     }
     while(j >= 0){
          int no = str2[j]-48;
          if(carry == 1){
               no++;
          }
          if(no < 10){
               result += no + 48;
               carry = 0;
          }
          else{
               carry = 1;
               result += no + 38;
          }
          j--;
     }

     if(carry == 1)
        result += carry + 48;

     if(result.size() == str1.size()){
          int n = result.size()-1;
          int i = 0;
          while(i <= n/2){
               swap(result[i],result[n-i]);
               i++;
          }
          cout<<result<<endl;
     }else{
          cout<<str1<<endl;
     }
}

int main(){

     int t;
     string str1, str2;
     cin>>t;
     while(t--){

          cin>>str1>>str2;

          findSum(str1,str2);

     }

     return 0;
}
