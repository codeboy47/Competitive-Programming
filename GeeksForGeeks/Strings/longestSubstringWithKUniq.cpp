#include <bits/stdc++.h>
using namespace std;


// sliding window is used here 
int lengthOfKUniques(string str, int k){
	
	
	unordered_map<char,int> hash;

	int i, s = 0, len = -1;
	for(i = 0; i < str.size(); i++){

		hash[str[i]]++;

		if(hash.size() > k){

			len = max(len,i-s);

			while(s < i && hash.size() > k){
				hash[str[s]]--;
				if(hash[str[s]] == 0){
					hash.erase(str[s]);
				}
				s++;
			}
		}
	}
	
	if(hash.size() == k)
	    len = max(len,i - s);

	return len;
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
        cin>>str;
         
        int k;
        cin>>k;

        cout<<lengthOfKUniques(str,k)<<endl;
          
     }

     return 0;
}