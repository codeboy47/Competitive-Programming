// KMP (Knuth Morris Pratt) Pattern Searching

#include <bits/stdc++.h>
using namespace std;

void createLPS(int *lps, char *pat){

	int j = 0;
	lps[0] = 0;
	for(int i = 1; i < strlen(pat); i++){

		if(pat[i] == pat[j]){
			lps[i] = j + 1;
			j++;
		}
		else{
			
			if(j > 0){
				j = lps[j-1];
  			    i--;
			}
			else{
				lps[i] = 0;
			}
		}
	}
}


bool searchKMP(char* pat, char* txt){

	int n = strlen(pat); 
	int *lps = new int[n];
	createLPS(lps, pat);

	int j = 0;
	for(int i = 0; i < strlen(txt); i++){
		
		if(pat[j] == txt[i]){
			j++;
			if(j == n){
			    //return true;
		        // to find all indices
		        cout<<"Found pattern at index "<<i+1-j<<endl;
		        j = lps[j-1];
		    }
		}

		else if(pat[j] != txt[i]){
			if(j != 0){
				j = lps[j-1];
				i--;
			}
		}
	}
    
    
    return false;

}


int main(){

     int t;
     char str[10000],patt[10000];
     cin>>t;
     while(t--){
          
          cin>>str>>patt;
          
           bool ans  = searchKMP(patt,str);
           ans ? cout<<"found"<<endl : cout<<"not found"<<endl;
     }

     return 0;
}