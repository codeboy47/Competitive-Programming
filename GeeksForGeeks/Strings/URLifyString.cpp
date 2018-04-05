#include <bits/stdc++.h>
using namespace std;

void changeString(string str, int n){

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            str.erase(str.begin()+i, str.begin()+i+1);
            str.insert(i,"%20");
        }
    }
    cout<<str<<endl;

}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){

          char ch;
          cin.get(ch);
          getline(cin,str);

          int n;
          cin>>n;
          //cout<<str;
          changeString(str,n);

     }

     return 0;
}
