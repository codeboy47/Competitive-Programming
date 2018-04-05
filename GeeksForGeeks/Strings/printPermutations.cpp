#include <bits/stdc++.h>
using namespace std;

void printPermutations(char *str, int i, int j, vector<string> &vs){

	if(str[i] == '\0'){
		string s(str);
		vs.push_back(s);
		return;
	}

	for(int j = i; j < strlen(str); j++){
		swap(str[i],str[j]);
		printPermutations(str,i+1,j+1,vs);
		swap(str[i],str[j]);
	}
}

bool compare(string s1, string s2){

	return s1 < s2;
}

int main(){

    int t;
    vector<string> vs;
    char str[10000];
    cin>>t;
    while(t--){
        
        cin>>str;
        printPermutations(str,0,0,vs);  
        sort(vs.begin(), vs.end(), compare);
        for(int i = 0; i < vs.size(); i++){
        	cout<<vs[i]<<" ";
        }
    	cout<<endl;
    	vs.clear();
    }

    return 0;
}