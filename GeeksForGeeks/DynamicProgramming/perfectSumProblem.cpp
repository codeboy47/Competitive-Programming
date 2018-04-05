#include <bits/stdc++.h>
using namespace std;

// this problem is like subset sum problem where we check if there is subset that is equal to given sum

// here we add all subset possible 
int countSubsets(int arr[], int n, int sum){

    int dp[n+1][sum+1];


    for(int i = 0; i <= sum; i++){
		dp[0][i] = 0; // 1st row is made false
	}
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1; // this is because sum zero can be made from empty subset of any set
	}

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
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

        int sum;
        cin>>sum;

        cout<<countSubsets(arr,n,sum)<<endl;

    }

    return 0;
}
