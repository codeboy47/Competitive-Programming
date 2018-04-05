#include <bits/stdc++.h>
using namespace std;

void convertDecimalToBinary(string &str, int m){

     int x = m;
     while(x != 0){
          str += (x%2)+48;
          x /= 2;
     }

     int n = str.size()-1;
     int i = 0;
     while(i <= n/2){
          swap(str[i],str[n-i]);
          i++;
     }
}

void findKthChar(string str, int k, int n){

     for(int i = 0; i < n; i++){

          for(int j = 0; j < str.size(); j = j+2){
               if(str[j] == '0'){
                    str.insert(j+1,"1");
               }
               else if(str[j] == '1'){
                    str.insert(j+1,"0");
               }
          }
     }

     cout<<str[k]<<endl;
}

int main(){

     int t;
     string str;
     //char str[10000];
     cin>>t;
     int n,m,k;
     while(t--){

          cin>>m>>k>>n;
          convertDecimalToBinary(str,m);
          findKthChar(str,k,n);
          str.clear();

     }

     return 0;
}
