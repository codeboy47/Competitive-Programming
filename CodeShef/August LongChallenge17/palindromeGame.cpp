#include <bits/stdc++.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main(){

     int t;
     unordered_map<char,int> hash1;
     unordered_map<char,int> hash2;
     //cin>>t;
     scanf("%d", &t);
     while(t--){
          string a,b;
          cin>>a>>b;
          //cout<<a<<" "<<b<<endl;
          for(int i = 0; i < a.length(); i++){
               if(!hash1.count(a[i])){
                    hash1[a[i]] = 0;
               }
               hash1[a[i]]++;
          }
          for(int i = 0; i < b.length(); i++){
               if(!hash2.count(b[i])){
                    hash2[b[i]] = 0;
               }
               hash2[b[i]]++;
          }

          bool case6 = false;
          int c = 0;
          for(auto it = hash1.begin(); it != hash1.end(); it++){

               // case 6 both strings are unique
               if(!hash2.count(it->first)) {
                    if(it->second >= 2) {
                         case6 = true;
                         break;
                    }
               }


          }

          bool case7 = true;
          int count = 0;
          for(auto it = hash2.begin(); it != hash2.end(); it++){
               if(!hash1.count(it->first)){
                    case7 = false;
               }
               count = count + hash1[it->first];
          }


          if(case7 == true && count < a.length()){
               cout<<"A"<<endl;
          }
          else if(case6 == true){
               cout<<"A"<<endl;
          }
          else{
               cout<<"B"<<endl;
          }

		hash1.clear();
		hash2.clear();

          // cases :
          // case 1 : both strings are same or count of each char is same in a and b is same - B
          // case 2 : both strings are different means not a single character is matching - B
          // case 3 : a has atleast 2 same characters and b has all unique characters - A
          // case 4 : all characters of a are same and b has that character in it - B
          // case 5 : all characters of b are same and a has that character + some other character as well - A
          // case 6 : choose a pair in a that is not found in b - A extention of case 3
          // case 7 : one char in a should not be present in b plus a's remaining chars will match to b like acd dcd - A
          // case 7 is extention of case 5
     }

     return 0;
}

/*
6
ab
ab
aba
cde
ab
cd
ac
aa
aa
ac
cde
aba

14
abbx
cbbb
acd
dcd
abc
efg
aaa
bbb
aba
cef
aba
cbf
aba
caf
aaa
aaa
aba
bbb
aba
aaa
aba
eba
aba
efa
aabcbbc
aefbhij

*/
