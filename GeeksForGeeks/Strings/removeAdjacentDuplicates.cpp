#include <bits/stdc++.h>
using namespace std;

void removeAdjacentDuplicates(string &str, int i){

	if(str[i] == '\0'){
		return;
	}

	if(str[i] == str[i-1]){
		str.erase(str.begin()+i,str.begin()+i+1);
		removeAdjacentDuplicates(str,i);
	}
    else
	    removeAdjacentDuplicates(str,i+1);
}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
          cin>>str;
          
          removeAdjacentDuplicates(str,1);
          cout<<str<<endl;
     }

     return 0;
}