// Longest Even Length Substring such that Sum of First and Second Half is same
#include <bits/stdc++.h>
using namespace std;

// dp method can be used but it is difficult

// this method is just like to find longest palindromic substring
// fastest method O(n^2) time and O(1) space
void longestEvenLengthSubstring(char *str){

	int n = strlen(str);

	int len = 0;
	for(int i = 0; i < n-1; i++){

		int s1 = i;
		int s2 = i+1;

		int sumL = 0, sumR = 0;
		while(s1 >= 0 && s2 < n){
			sumL += str[s1] - 48;
			sumR += str[s2] - 48;
			
			if(sumL == sumR){
				len = max(len,s2-s1);
			}

			s1--;
			s2++;
		}
	}
    
    if(len == 0){
        cout<<0<<endl;
    }
    else{
	    cout<<len+1<<endl;
    }
}


int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          longestEvenLengthSubstring(str);
          
     }

     return 0;
}