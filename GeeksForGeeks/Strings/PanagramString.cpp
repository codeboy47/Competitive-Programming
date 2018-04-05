#include<bits/stdc++.h>
using namespace std;
 
bool checkPangram(string &str){

    vector<bool> mark(26, false);
 
    int index = 0;
 
    for (int i=0; i<str.length(); i++)
    {

        if ('A' <= str[i] && str[i] <= 'Z')
            index = str[i] - 'A';

        else if('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
 
        mark[index] = true;
    }
 
    for (int i=0; i<=25; i++)
        if (mark[i] == false)
            return false;

    return true;
}

int main(){

     int t;
     string str;
     cin>>t;
     char ch;
     cin.get(ch);
     while(t--){
          
          getline(cin,str);
          
          cout<<checkPangram(str)<<endl;
          
     }

     return 0;
}