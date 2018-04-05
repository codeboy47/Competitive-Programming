#include <bits/stdc++.h>
using namespace std;

/* here we need to find longest palindromic substring. There are 2 methods :
i)  Dynamic programming (O(n^2) time and O(n^2) space)
ii) To generate all even length and odd length palindromes and keep track of the longest palindrome.
	(O(n^2) time and O(1) space)

When there is subsequence related question - DP is used like find longest palindromic subsequence	
*/


// dp method
void LongestPalindromicSubstringDP(string str){

	int n = str.size();

	int dp[n][n];
	memset(dp,false,sizeof(dp));

	for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    int start = 0;
    int maxLength = 1;
    // we fill dp table diagonally i.e. move from diagonal towards dp[0][n]
    for(int k = 0; k < n; k++){
    	for(int i = 0; i < n-k; i++){
    		int j = i + k + 1;
    		if(str[i] == str[j]){
    			if(dp[i+1][j-1] == true || j - i == 1){ // or length is 2
    				dp[i][j] = true;
    				if(maxLength < j - i + 1){
    					maxLength = j - i + 1;
    					start = i;
    				}
    			}
    		}
    		else{
    			dp[i][j] = false;
    		}
    	}
    }

    for(int i = start; i < start+maxLength; i++){
		cout<<str[i];
	} 
	cout<<endl;

}

void LongestPalindromicSubstring(string str){

	int n = str.size();
	int maxLength = 1;
	int start = 0;

	for(int i = 1; i < n; i++){

		int l = i - 1;
		int h = i + 1;

		while(l >= 0 && h < n && str[l] == str[h]){
			
			if(maxLength < h-l+1){
				maxLength = h-l+1;
				start = l;
			}
			l--;
			h++;
		}

		l = i - 1;
		h = i;

		while(l >= 0 && h < n && str[l] == str[h]){
			
			if(maxLength < h-l+1){
				maxLength = h-l+1;
				start = l;
			}
			l--;
			h++;
		}

	}

	cout<<"Max length is : "<<maxLength<<endl;
	cout<<"String is : ";
	for(int i = start; i < start+maxLength; i++){
		cout<<str[i];
	} 
	cout<<endl;

}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          LongestPalindromicSubstringDP(str);
          
     }

     return 0;
}