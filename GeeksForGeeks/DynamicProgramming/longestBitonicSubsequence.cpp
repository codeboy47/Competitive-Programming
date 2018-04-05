#include <bits/stdc++.h>
using namespace std;


int longestZigZagSubsequence(int arr[], int n){

	int *dp1 = new int[n];
	int *dp2 = new int[n];

    // Longest Increasing Subsequence from front
	dp1[0] = 1;
	for(int i = 1; i < n; i++){
        int ans = 0;
		for(int j = i-1; j >= 0; j--){
			if(arr[i] > arr[j])
				ans = max(ans,dp1[j]);
		}
		dp1[i] = ans + 1;
	}

	// Longest Increasing Subsequence from back
	dp2[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
        int ans = 0;
		for(int j = i+1; j <= n-1; j++){
			if(arr[i] > arr[j])
				ans = max(ans,dp2[j]);
		}
		dp2[i] = ans + 1;
	}

	int large = 0;
	for(int i = 0; i < n; i++){
		large = max(large,dp1[i]+dp2[i]);
	}

	return large-1;
}



int main(){

    int t;
    cin>>t;
    int arr[100000];
    while(t--){

        int n;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<longestZigZagSubsequence(arr,n)<<endl;
    }

    return 0;
}
