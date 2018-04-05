#include <iostream>
using namespace std;

// 0-1 Knapsack is always done by dp (bottom up approach or top down approach)
// to do fractional knapsack we use greedy algorithm

// top down approach
int knapsackDP1(int wt[], int price[], int totalWt, int n, int dp[][10000]){

	if(totalWt == 0 || n == 0)	return 0;

	if(dp[totalWt][n] != 0)	return dp[totalWt][n];

	int inc = 0, exc = 0;
	// including item
	if(totalWt >= wt[n-1]){
		inc = price[n-1] + knapsackDP1(wt,price,totalWt-wt[n-1],n-1,dp);
	}

	// excluding item
	exc = knapsackDP1(wt,price,totalWt,n-1,dp);

	dp[totalWt][n] = max(inc,exc);
	return dp[totalWt][n];
}



// bottom up approach
int knapsackDP2(int wt[], int price[], int totalWt, int n){

	int dp[n+1][totalWt+1];

	for(int i = 0; i <= n; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i <= totalWt;i++){
		dp[0][i] = 0;
	}

	for(int i = 1; i <= n; i++){ 	// i = 1 because we check for prev row i-1
		for(int j = 0; j <= totalWt; j++){

			if(wt[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				// to find max we check if we include that wt(row) or exclude
				// if we exclude simply use previous row result for that col wt
				// if include then value of wt(row) + value of wt(col) - wt(row) in above row
				dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i-1][j - wt[i-1]]);

				// if we are given that we can use one item more than once than we do
				// dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-wt[i-1]]);
			}
		}
	}

	return dp[n][totalWt];
}

int main() {
	int totalWeight;
	cin>>totalWeight;
	int n;  // no of items
	cin>>n;
	int wt[10000];
	int price[10000];
	for(int i = 0; i < n; i++){
		cin>>wt[i];
		cin>>price[i];
	}

	cout<<knapsackDP2(wt,price,totalWeight,n)<<endl;

	return 0;
}
