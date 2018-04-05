#include <bits/stdc++.h>
using namespace std;

void commentRemoval(string str){

	for(int i = 0; i < str.size(); i++){

		if(str[i] == '/' && str[i+1] =='*'){
			int s = i, j = i+1;
			while(str[j-1] != '*' || str[j] != '/'){
				j++;
			}
			str.erase(str.begin()+s,str.begin() + j+1);
		}

		else if(str[i] == '/' && str[i+1] =='/'){
			int s = i, j = i+1;
			while(str[j-1] != '\\' || str[j] != 'n'){
				j++;
			}
			str.erase(str.begin()+s,str.begin() + j+1);
		}
	}
	cout<<str<<endl;
}

int main(){

     int t;
     string str;
     cin>>t;
     char ch;
     cin.get(ch);
     while(t--){
          
          getline(cin,str);
          
          commentRemoval(str);
          
     }

     return 0;
}