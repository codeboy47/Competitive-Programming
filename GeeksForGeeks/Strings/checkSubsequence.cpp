#include<bits/stdc++.h>
using namespace std;

// O(n) approach
bool checkSubsequence1(char *str1, char *str2, int i, int j){

	if(i == 0){
		return true;
	}

	if(j == 0){
		return false;
	}

	if(str1[i] == str2[j]){
		return checkSubsequence1(str1,str2,i-1,j-1);
	}

	if(str1[i] != str2[j]){
		return checkSubsequence1(str1,str2,i,j-1);
	}


}

// standard method but take time
bool checkSubsequence2(char *str1,char *str2, char *out, int i, int j){

	if(str2[j] == '\0'){
		out[i] = '\0';
		if(strcmp(out,str1) == 0){
			return true;
		}
		return false;
	}

	out[i] = str2[j];

	bool ans1 = checkSubsequence2(str1,str2,out,i+1,j+1);
	if(ans1){
		return true;
	}

	return checkSubsequence2(str1,str2,out,i,j+1);
}

int main(){

	int t;
	cin>>t;
	char str1[1000], str2[1000], output[1000];

	while(t--){
		cin>>str1>>str2;
		checkSubsequence1(str1,str2,strlen(str1),strlen(str2)) == true ? cout<<1<<endl : cout<<0<<endl;
	}
	return 0;
}