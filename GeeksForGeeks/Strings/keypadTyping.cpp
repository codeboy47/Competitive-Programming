#include <bits/stdc++.h>
using namespace std;

void keypadTyping(string str, vector<string> v){

	unordered_map<char,int> hash;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			hash[v[i][j]] = i+2;
		}
	}

	string result = "";
	for(int i = 0; i < str.size(); i++){
		result += hash[str[i]] + 48;
	}
	cout<<result<<endl;
}


int main(){

    int t;
    vector<string> v;
    string str;
    string table[] = { "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
    cin>>t;
    for(int i= 0; i < 8; i++){
    	v.push_back(table[i]);
    }

    while(t--){
          
        cin>>str;
        
        keypadTyping(str,v);
          
    }

    return 0;
}