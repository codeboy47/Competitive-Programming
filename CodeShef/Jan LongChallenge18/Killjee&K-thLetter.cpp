#include<bits/stdc++.h>
using namespace std;
 
void findSubstrings(char *str, vector<string> &v){
 
	
	for(int i = 0; i < strlen(str); i++){
		string res = "";
		for(int j = i; j < strlen(str); j++){
			res += str[j];
			v.push_back(res);
		}
	}
 
 
 
}
 
 
int main(){
 
	vector<string> v;
	char str[200000];
 
	cin>>str;
 
	findSubstrings(str,v);
 
	sort(v.begin(),v.end());
 
	string res = "";
	for(int i = 0; i < v.size(); i++){
	    //cout<<v[i];
		res += v[i]; 
	}
 
	long long int  q, g = 0;
	cin>>q;
	while(q--){
 
		long long int p,m;
		cin>>p>>m;
 
		long long int k = (p*g)%m + 1;
		cout<<res[k-1]<<endl;
		g += res[k-1];
 
	}
 
	return 0;
}