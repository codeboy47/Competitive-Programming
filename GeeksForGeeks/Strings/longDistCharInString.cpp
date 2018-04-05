#include <bits/stdc++.h>
using namespace std;

void longestDistinctCharactersInString(char *str){
	
	unordered_map<char,int> hash;

	int i = 0, j = 1;
	hash[str[0]] = 0;
	int len = 0;
	while(i < j && j < strlen(str)){

		if(hash.count(str[j]) == 0){
			hash[str[j]] = j;
			 
		}
		else{
		    if(hash[str[j]] < i){
		        hash[str[j]] = j;
		    }
		    else{
    			len = max(len,j-i);
    			//cout<<str[j]<<" "<<str[i]<<endl;
    			i = hash[str[j]] + 1;
    			hash[str[j]] = j;
		    }
		}
		j++;
	}  
    len = max(len,j-i);
	cout<<len<<endl; 
}


int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          longestDistinctCharactersInString(str);

          
     }

     return 0;
}