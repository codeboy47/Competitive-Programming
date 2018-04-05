#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string addStrings(string s1, string s2){

	ll n1 = 0;
	for(ll i = 0; i < s1.size(); i++){
		n1 = n1*10 + s1[i] - 48;
	}

	ll n2 = 0;
	for(ll i = 0; i < s2.size(); i++){
		n2 = n2*10 + s2[i] - 48;
	}

	ll n = n1 + n2;

	string s = to_string(n);
	return s;

}


bool checkSumString(string str, int beg, int l1, int l2){

	string s1 = str.substr(beg,l1);
	string s2 = str.substr(beg+l1,l2);
	string s3 = addStrings(s1,s2);

    int x;
	for( x = 0; x < s3.size(); x++){
		if(s3[x] != str[beg+l1+l2+x]){
			return false;
		}
	}

	if(beg + l1 + l2 + x == str.size()){
		return true;
	}
	
	return checkSumString(str,beg+s1.size(),s2.size(),s3.size());
}


bool sumString(string str){
    
    int n = str.size();
	for(int i = 1; i < n; i++){
	 	for(int j = 1; j < n-i; j++){
	 		if(checkSumString(str,0,i,j)){
	 			return true;
	 		}
	 	}
	}

	return false;
}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
          cin>>str;
          
          cout<<sumString(str)<<endl;
          
     }

     return 0;
}