// Wildcard Matching Dynamic Programming

#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool findAns(string str, string pattern){

	int s = str.size();
	int p = pattern.size();
	bool dp[s+1][p+1];

	//memset(dp, false, sizeof(dp));

	for(int i = 0; i <= p; i++){
		dp[0][i] = false;
	}
	for(int i = 0; i <= s; i++){
		dp[i][0] = false;
	}

	dp[0][0] = true;

	// This is a special case. It is done if pattern starts with '*'
	// In that case only '*' can match with empty string
	for (int j = 1; j <= p; j++)
        if (pattern[j-1] == '*')
            dp[0][j] = dp[0][j-1];

	for(int i = 1; i <= s; i++){
		for(int j = 1; j <= p; j++){
			if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
				dp[i][j] = dp[i-1][j-1]; // check if 2 strings are matched before i and j
			}
			else if(pattern[j-1] == '*'){
				//		  * is empty set	  that character is removed from str
				dp[i][j] = dp[i][j-1] || dp[i-1][j];
			}
			else{
				dp[i][j] = false;
			}
		}
	}
    return dp[s][p];
}

int main(){

	string str, pattern;
	cin>>str;
	cin>>pattern;

	bool ans = findAns(str,pattern);

	if(ans == true){
		cout<<"MATCHED";
	}else{
		cout<<"NOT MATCHED";
	}

	return 0;
}
