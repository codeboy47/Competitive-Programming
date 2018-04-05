#include <bits/stdc++.h>
using namespace std;


int longestZigZagSubsequence(int arr[], int n){

	int *dp = new int[n];
    int state[n];

    state[0] = 0;
	dp[0] = 1;
	for(int i = 1; i < n; i++){

        int ans = 0;
		for(int j = i-1; j >= 0; j--){
			if(arr[i] > arr[j] && (state[j] == 0 || state[j] == -1)){
				if(ans < dp[j]){
                    ans = dp[j];
                    state[i] = 1;
                }
            }
            if(arr[i] < arr[j] && (state[j] == 0 || state[j] == 1))
                if(ans < dp[j]){
                    ans = dp[j];
                    state[i] = -1;
                }
		}
		dp[i] = ans + 1;
    }

	int large = 0;
	for(int i = 0; i < n; i++){
		large = max(large,dp[i]);
	}

	return large;
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
