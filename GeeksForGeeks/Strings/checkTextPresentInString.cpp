#include <bits/stdc++.h>
using namespace std;


void smallestWindow(string str, string text){

    int len1 = str.length();
    int len2 = text.length();
    
    if (len1 < len2){
        cout<<-1<<endl;
        return;
    }
    
	unordered_map<char,int> hashPattern;
	unordered_map<char,int> hashString;

	for(int i = 0; i < text.size(); i++){
		hashPattern[text[i]]++;
	}

	int count = text.size();
	int start = 0, si = -1, ei = 0, len = INT_MAX;
	for(int i = 0; i < str.size(); i++){

			hashString[str[i]]++;
		    
			if(hashPattern.count(str[i]) && hashString[str[i]] <= hashPattern[str[i]]){
				count--;
			}
			
			if(count == 0){

				while(hashString[str[start]] > hashPattern[str[start]] || hashPattern[str[start]] == 0){
					hashString[str[start]]--;
					start++;
				}

				if(len > i-start){
					len = i-start;
					ei = i;
					si = start;
				}
			}
			
	}
		
	if(si == -1){
		cout<<-1<<endl;
		return;
	}


	for(int i = si; i <= ei; i++){
		cout<<str[i];
	}
	cout<<endl;
}


int main(){

     int t;
     string str, text;
     cin>>t;
     while(t--){
          
          cin>>str>>text;
          
          smallestWindow(str,text);
          
     }

     return 0;
}