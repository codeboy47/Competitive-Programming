#include<bits/stdc++.h>
using namespace std;

bool checkAbcType(char *str){

	bool flagA = true, flagB = false, flagC = false;
	for(int i = 0; i < strlen(str); i++){
		if(flagA && str[i] == 'a'){
			flagB = true;
		}
		else if(flagB && str[i] == 'b'){
			flagA = false;
			flagC = true;
		}
		else if(flagC && str[i] == 'c'){
			flagA = false;
			flagB = false;
		}
		else{
			return false;
		}
	}

    if(!flagA && !flagB && flagC)
	return true;

}

int countSubsequence(char *str, char *out, int i, int j){

	if(str[j] == '\0'){
		out[i] = '\0';
		if(checkAbcType(out)){
			//cout<<out<<" ";
			return 1;
		}
		return 0;
	}

	out[i] = str[j];

	int c1 = countSubsequence(str,out,i+1,j+1);
	

	int c2 = countSubsequence(str,out,i,j+1);

	return c1 + c2;
}


// O(n) method
int countSubsequences(string s){
    int aCount = 0;
 
    int bCount = 0;

    int cCount = 0;
 
    for (unsigned int i=0; i<s.size(); i++){
        if (s[i] == 'a')
            aCount = (1 + 2 * aCount); 
        
/* Can you please explain the logic behind multiplication with 2? for aCount, bCount and cCount?
it is x2 because let's say you have one string with u 'a1b1.....'
now there are two ways u can make string with a new char 'b2'
either include it (a1b1b2....) or don't (a1b1.....)
so now u end up with 2

let's say you had 2 strings 'a1...' & 'a1b1...'
there are 2 ways each of making strings with new char 'b2'
'a1...' (don't include b2) or 'a1b2...' (include b2)
'a1b1....' (don't include b2) or 'a1b1b2...' (include b2)
so now u end up with 2X2 = 4
*/

        else if (s[i] == 'b')
            bCount = (aCount + 2 * bCount);

        else if (s[i] == 'c')
            cCount = (bCount + 2 * cCount);
    }
 
    return cCount;
}



int main(){

	int t;
	cin>>t;
	char str[1000];
	char out[1000];

	while(t--){
		cin>>str;
		cout<<countSubsequences(str);
		cout<<endl;
	}
	return 0;
}
