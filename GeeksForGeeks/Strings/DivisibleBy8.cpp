#include <bits/stdc++.h>
using namespace std;

int toNo(string str){
    int n = 0;
    for(int i = 0; i < str.size(); i++){
        n = n*10 + str[i] - 48;
    }
    return n;
}

void findDivisible(int no){
          string  str = to_string(no);
          sort(str.begin(), str.end());
          bool f = true, flag0 = false;
          do{ 
              if(str[0] == '0'){
                  flag0 = true;
              }
              no = toNo(str);
              if(no%8 == 0){
                  cout<<"Yes"<<endl;
                  f = false;
                  break;
              }
              str = to_string(no);
              if(flag0 == true){
                  str = "0" + str;
                  flag0 = false;
              }
              
          }while(next_permutation(str.begin(),str.end()));
          
          if(f)
          cout<<"No"<<endl;
}

int main(){

     int t;
     cin>>t;
     while(t--){
          
          int no;
          cin>>no;
          findDivisible(no);
     }

     return 0;
}