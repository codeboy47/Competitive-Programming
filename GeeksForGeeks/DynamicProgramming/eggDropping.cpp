// Egg/Plate Dropping Dynamic Programming

#include <iostream>
#include <climits>
using namespace std;

int findMinimumTrials(int n, int k){
	int dp[n+1][k+1];


	for(int i = 0; i <= k; i++){
		dp[0][i] = 0;
	}

	for(int i = 0; i <= n; i++){
		dp[i][0] = 0;  // we need 0 trials for 0th floor
		dp[i][1] = 1;  // we need only 1 trial for 1st floor i.e. egg breaks or not doesn't matter as trial will always remain 1
	}

    for(int i = 0; i <= k; i++){
		dp[1][i] = i; // we always start from 1st floor as we have one egg only
	}

	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= k; j++){
			dp[i][j] = INT_MAX;
			for(int x = 1; x <= j; x++){ // checking for every floor
				int ans = 1 + max(dp[i-1][x-1],dp[i][j-x]);
				dp[i][j] = min(ans,dp[i][j]);
			}
		}
	}

	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
	        cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/

	return dp[n][k];
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k; // n is eggs or plates
				   // k is floors
		cout<<findMinimumTrials(n,k)<<endl;
	}

	return 0;
}
