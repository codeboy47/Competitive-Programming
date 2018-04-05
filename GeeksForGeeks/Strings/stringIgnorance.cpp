#include <bits/stdc++.h>
using namespace std;

void printStringAlternate(string str)
{
    unordered_map<char, int> occ;
 
    for (int i = 0; i < str.length(); i++) {
 
        char temp = tolower(str[i]);
 
        if(occ[temp] == 1){
            occ[temp] = 0;
        }
        else
            occ[temp] = 1;
 
        if (occ[temp] == 1)
            cout << str[i];
    }
 
    cout << endl;
}

int main(){

     int t;
     string str;
     cin>>t;
     char ch;
     cin.get(ch);
     while(t--){
          
          getline(cin,str);
          
            printStringAlternate(str);
            
     }

     return 0;
}