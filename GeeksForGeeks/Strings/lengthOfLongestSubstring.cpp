#include <bits/stdc++.h>
using namespace std;

void findLongestSubstring(string str){

	unordered_map<char,int> hash;

	int s = 0, len = 0;
	int i;
	for( i = 0; i < str.size(); i++){

		if(hash.count(str[i])){
			if(s > hash[str[i]]){
				hash[str[i]] = i;
			}
			else{
				len = max(len,i-s);
				s = hash[str[i]]+1;
				hash[str[i]] = i;
			}
		}
		else{
			hash[str[i]] = i;
		}
	}
	
    len = max(len,i-s);
	cout<<len<<endl;
}

int main(){

    int t;
    string str;
    cin>>t;
    while(t--){
    
        cin>>str;

        findLongestSubstring(str);
    }

    return 0;
}