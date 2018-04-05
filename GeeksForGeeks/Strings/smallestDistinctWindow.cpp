#include <bits/stdc++.h>
using namespace std;

void detectSmallestWindow(string str){

	unordered_map<char,int> hash;

	for(int i = 0; i < str.size(); i++){
		hash[str[i]]++;
	}

	int count = hash.size();

	hash.clear();
	int s = 0, len = str.size();
	for(int i = 0; i < str.size(); i++){

		if(hash.count(str[i]) == 0){
			hash[str[i]] = 1;
			count--;
			if(count == 0){
				while(hash[str[s]] > 1){
					hash[str[s]]--;
					s++;
				}
				len = min(len,i - s + 1);
				hash.erase(str[s]);
				s++;
				count = 1;
			}
		}
		else{
		    
			hash[str[i]]++;
			//cout<<hash[str[i]]<<"-"<<str[i]<<" ";
		}
	}

	cout<<len<<endl;
}

int main(){

    int t;
    string str;
    cin>>t;
    while(t--){
    
        cin>>str;
          
        detectSmallestWindow(str);
    }

    return 0;
}