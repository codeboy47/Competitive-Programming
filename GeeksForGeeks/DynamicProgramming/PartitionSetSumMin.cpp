#include <bits/stdc++.h>
using namespace std;

// formula abs((sum - sC) - sC)

int findMinRec(int arr[], int n, int sumSoFar, int sum){

	if (n==0)
		return abs((sum-sumSoFar) - sumSoFar);

	// For every item arr[n], we have two choices
	// (1) We do not include it in first set
	// (2) We include it in first set
	return min(findMinRec(arr, n-1, sumSoFar+arr[n-1], sum),
			findMinRec(arr, n-1, sumSoFar, sum));

}


int findMinBottomUPDp(int arr[], int n, int sum){

	bool dp[n+1][sum+1];

	for(int i = 0; i <= sum; i++){
		dp[0][i] = false;
	}

	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}

	for(int i = 1; i <= n; i++){
		for(int  j = 1; j <= sum; j++){

			if(j < arr[i-1]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}

	int diff = INT_MAX;
	for(int j = 0; j <= (sum)/2; j++){
		if(dp[n][j])
			diff = min(diff,(sum - j) - j);
	}

	return diff;
}


int main(){

    int t;
    cin>>t;
    while(t--){
        int arr[100000];
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        int sumTotal = 0;
	    for (int i=0; i<n; i++)
		    sumTotal += arr[i];

	    cout<<findMinBottomUPDp(arr, n, sumTotal)<<endl;

    }

    return 0;
}
