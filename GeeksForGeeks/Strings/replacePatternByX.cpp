#include <bits/stdc++.h>
using namespace std;

// important question nice trick
bool compare(char *pat, char *str, int idx){

    int j = 0;
	for(int i = idx; i < idx+strlen(pat); i++,j++){
		if(str[i] != pat[j]){
			return false;
		}
	}
	return true;
}

void replacePatternWithX(char *str, char *pat){

	int i = 0;
	int j = 0;
	int len = strlen(pat);

	while(j < strlen(str)){

		int count = 0;
		while(compare(pat,str,j)){
			j += len;
			count++;
		}

		if(count > 0){
			str[i++] = 'X';
		}
		else{
			str[i++] = str[j++];
		}
	}

	str[i] = '\0';
	cout<<str<<endl;

}

int main(){

     int t;
     char str[10000],pat[10000];
     cin>>t;
     while(t--){
          
          cin>>str>>pat;
          
          replacePatternWithX(str,pat);
          
     }

     return 0;
}