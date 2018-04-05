#include <bits/stdc++.h>
using namespace std;

// iterative method
void generateCode(int n){

	vector<string> v;
	v.push_back("0");
	v.push_back("1");

	for(int i = 2; i < (1<<n); i = i<<1){

		for(int j = i-1; j >= 0; j--){
			v.push_back(v[j]);
		}		

		int j;
		for( j = 0; j < i; j++){
			v[j] = "0" + v[j];
		}

		for(; j < 2*i; j++){
			v[j] = "1" + v[j];
		}

	}

	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<" ";
	}
}

// recursive method
void generateGreyCodes(int n, vector<string> &v){

	if(n > 2){
		generateGreyCodes(n-1,v);
		//return;
	}
	
	string r1 = "";
	for(int i = 0; i < v.size(); i++){
		r1 += '0';
		r1 += v[i];
		r1 += " ";
	}

	string r2 = "";
	for(int i = v.size()-1; i >= 0; i--){
		r2 += "1";
		r2 += v[i];
		r2 += " ";
	}
	
	r1 = r1 + r2;
	//cout<<r1<<endl;
	
	v.clear();
	for(int i = 0; i < 1<<(n); i++){
		v.push_back("");
	}
	int idx = 0;
	for(int i = 0; idx < v.size() && i < r1.size()-1; i++){
		if(r1[i] == ' '){
			idx++;
		}
		else{
			v[idx] += r1[i];
		}
	}
	//cout<<v[2]<<endl<<v[3]<<endl;
	return;
}

int main(){
	

	vector<string> v;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		v.push_back("0");
		v.push_back("1");
		generateGreyCodes(n,v);
		for(int i = 0; i < v.size(); i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		v.clear();
	}
	return 0;
}