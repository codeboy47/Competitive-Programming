#include <bits/stdc++.h>
using namespace std;

/*
Let dp[i][j] be the length of Longest Arithmetic progression that ends in positions i and j, i.e. last element is A[j] and element before last is A[i]. How can we calculate a value for fixed i and j? We know two last elements. So we know which number should be before position i. It’s number X such that A[i] - X == A[j] - A[i] -> X == 2 * A[i] - A[j]. I.e we can iterate all over 0 <= k < i and if A[k] == X then update dp[i][j] by the value of dp[k][i] + 1(it’s easy to understand we only need to find rightmost such position).
*/

int longestAP(int arr[], int n){

    if(n == 1){
        return 1;
    }

	int dp[n][n];
	memset(dp,0,sizeof(dp));


	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			dp[i][j] = 2;
			for(int k = 0; k < i; k++){
				if(arr[k] == 2*arr[i] - arr[j]){
					dp[i][j] = max(dp[i][j],dp[k][i] + 1);
				}
			}
		}
	}

    int ans = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = max(ans,dp[i][j]);
		}
	}

	return ans;
}



int main(){

    int t;
    cin>>t;
    int arr[1000000];
    while(t--){

        int n;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<longestAP(arr,n)<<endl;
    }

    return 0;
}
