#include <bits/stdc++.h>
using namespace std;


void countPalindromicSubstrings(string str){

	int n = str.size();
	int count = 0;


	for(int i = 1; i < n; i++){

		int l = i - 1;
		int h = i + 1;

		while(l >= 0 && h < n && str[l] == str[h]){
			
			count++;
			l--;
			h++;
		}

		l = i - 1;
		h = i;

		while(l >= 0 && h < n && str[l] == str[h]){
			
			count++;
			l--;
			h++;
		}

	}

	cout<<count<<endl;

}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          int n;
          cin>>n;
          cin>>str;
          
          countPalindromicSubstrings(str);
          
     }

     return 0;
}