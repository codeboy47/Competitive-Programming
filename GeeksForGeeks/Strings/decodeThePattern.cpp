#include <bits/stdc++.h>
using namespace std;

string decodePattern(int n){

	if(n == 1){
		return "1";
	}
	if(n == 2){
		return "11";
	}

	else{

		string str = decodePattern(n-1);
		int count = 1;
		string res = "";
		int i;
		for( i = 0; i < str.size()-1; i++){
			if(str[i] == str[i+1]){
				count++;
			}
			else{
				res += count + 48;
				res += str[i];
				count = 1;
			}
		}
		res += count + 48;
		res += str[i];
		return res;
	}
}


int main(){

     int t;
     cin>>t;
     while(t--){
          
          int n;
          cin>>n;
          
          cout<<decodePattern(n)<<endl;
     }

     return 0;
}