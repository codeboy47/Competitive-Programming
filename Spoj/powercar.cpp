#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <string.h>
using namespace std;
#define sd(x) scanf("%d",&x)

/**** Spoj - Power Car : http://www.spoj.com/problems/POWERCAR/  ********/
// Recusion + top down DP (memoization)

int n;
char s[2000];
int dp[2000][2000][2];

int minTimeTaken(int i, int flag, int b){

	// base case
	if(s[i] == 'E'){
	    if(flag){
	        return 2;
	    }
		return 0;
	}

	if(dp[i][b][flag] != -1)
        return dp[i][b][flag];

	if(flag){
		int ans1 = INT_MAX, ans2 = INT_MAX;


		// 2 options are there:
		if(s[i+1] != '#')
			ans1 = 4 + minTimeTaken(i+1,0,b); // go up

		ans2 = 2 + minTimeTaken(i+1,1,b); // go right

		dp[i][b][flag] = min(ans1,ans2);
		return dp[i][b][flag];

	}
	else if(s[i+1] == '#'){
		int ans1 = INT_MAX, ans2 = INT_MAX;


		// if path is blocked there are 2 options :
		if(b != 0){
			ans1 = 1 + minTimeTaken(i+1,0,b-1);  // use bullet
		}
		ans2 = 2 + minTimeTaken(i,1,b) ; //  use offpath

		dp[i][b][flag] = min(ans1,ans2);
		return dp[i][b][flag] ;
	}
	else{

		// else just move forward
		dp[i][b][flag]  = 1 + minTimeTaken(i+1,0,b);
		return dp[i][b][flag] ;
	}

}


int main() {
	int t,b;
	sd(t);
	while(t--) {
	memset(dp,-1,sizeof(dp));
	    sd(n);
	    sd(b);
	    scanf("%s",s);
		printf("%d\n",minTimeTaken(0,0,b));
	}
}
