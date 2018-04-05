#include <iostream>
using namespace std;

/*
Partition problem is to determine whether a given set can be partitioned into
two subsets such that the sum of elements in both subsets is same.
*/

// This problem is almost similar to the problem subset sum but here sum is not given
// instead we divide array into 2 subsets. Sum of each subset will be equal to (sum of array / 2).  Why ?
// Because when we add sum of 2 subsets will be equal to sum of array. So each subset sum will be half of array sum.

bool subsetSumDP(int *arr, int n, int sum){
	bool output[n+1][sum+1];
	for(int i = 0; i <= sum; i++){
		output[0][i] = false; // 1st row is made false
	}
	for(int i = 0; i <= n; i++){
		output[i][0] = true; // this is because sum zero can be made from empty subset of any set
	}

	int currSum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			if(arr[i-1] > j){
				output[i][j] = output[i-1][j];
			}
			else{
				output[i][j] = output[i-1][j] || output[i-1][j-arr[i-1]];
			}
		}
	}
	return output[n][sum];
}


int main() {
    int t;
    cin>>t;
    while(t--){
    	int arr[1000000];
    	int n;
    	cin>>n;  // n is size of array and m is sum

    	int sum = 0;
    	for(int i = 0;i < n; i++){
    		cin>>arr[i];
    		sum += arr[i];
    	}

    	if(sum&1){
    	    cout<<"NO\n";
    	}
    	else
    	    subsetSumDP(arr,n,sum/2)? cout<<"YES\n" : cout<<"NO\n";
    }
	return 0;
}
