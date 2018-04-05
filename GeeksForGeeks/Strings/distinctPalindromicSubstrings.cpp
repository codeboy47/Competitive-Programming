#include <bits/stdc++.h>
using namespace std;

int PrintAllPalindromicSubstring(string str){
    
    set<string> s;
	int n = str.size();
	int maxLength = 1;
	int start = 0;
	string res = "";
	res += str[start];
	s.insert(res);

	for(int i = 1; i < n; i++){

		int l = i - 1;
		int h = i + 1;
		res = "";
		res += str[i];
		s.insert(res);

		while(l >= 0 && h < n && str[l] == str[h]){
			
			res = str[l] + res + str[h];
			s.insert(res);
			l--;
			h++;
		}

		l = i - 1;
		h = i;
		res = "";

		while(l >= 0 && h < n && str[l] == str[h]){
			
			res = str[l] + res + str[h];
			s.insert(res);
			l--;
			h++;
		}

	}
	
    
	for(auto it = s.begin(); it != s.end(); it++){
		cout<<*it<<endl;
	} 
	
	return s.size();
}


int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          cout<<PrintAllPalindromicSubstring(str)<<endl;
          
     }

     return 0;
}