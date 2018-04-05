#include <bits/stdc++.h>

using namespace std;

int noOfBST(int n){

    int dp[n+1];

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }

    return dp[n];

}

int main() {
	//code
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int res = noOfBST(n);
	    cout<<res<<endl;
	}
	return 0;
}
