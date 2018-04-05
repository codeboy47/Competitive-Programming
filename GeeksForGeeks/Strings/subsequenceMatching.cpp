#include <bits/stdc++.h>
using namespace std;

bool subsequenceMatching(string str, string *s, int idx){

	if(str[idx] == '\0'){
		return true;
	}

	for(int i = 0; i < 3; i++){
		int k = idx;
		for(int j = 0; j < s[i].size(); j++,k++){
			if(str[k] != s[i][j]){
				return false;
			}
		}
		bool ans = subsequenceMatching(str,s,idx+s[i].size());
		if(ans){
			return ans;
		}
	}
	
	return false;
}

int main(){

    int t;
    string str;
    string s[3] = {"R", "RY", "RYY"}; 
    cin>>t;
    while(t--){
    
        cin>>str;
        
        bool ans  = subsequenceMatching(str,s,0);  
        ans ? cout<<"YES"<<endl : cout<<"NO"<<endl;

          
    }

    return 0;
}