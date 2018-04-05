#include <iostream>
using namespace std;

// this is improved algo for subset problem other than bitmasking and recursion
// but not works for negative numbers
// we use dynamic programing here
// time complexity is O(n*m) n is size of array and m is the sum that need to be find in set

bool subsetSumDP(int *arr, int n, int sum){
	bool output[n+1][sum+1];
	for(int i = 0; i <= sum; i++){
		output[0][i] = false; // 1st row is made false
	}
	for(int i = 0; i <= n; i++){
		output[i][0] = true; // this is because sum zero can be made from empty subset of any set
	}
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
/* output[i][j] = 1 if
1. output[i-1][j] is 1 : If output[i-1][j] is 1 it means that it is possible to obtain a sum of j by
selecting some numbers from {arr[0],arr[1],arr[2],…,arr[i-1]}, so obviously the same is also possible
with the set {arr[0],arr[1],arr[2],…,arr[i-1],arr[i]}.
2. output[i-1][j-arr[i]] is 1. If output[i-1][j-arr[i]] is 1 it means that it is possible to
obtain a sum of (j-arr[i]) by selecting numbers from {arr[0],arr[1],arr[2],…,arr[i-1]}. Now if we select
arr[i] too, then we can obtain a sum of (j-arr[i])+arr[i] = j. Therefore output[i][j] is 1.

The above two points serve as the DP equation for calculating all values in output[ ][ ].
*/

int main() {
	int arr[1000000];
	int n,m;
	cin>>n>>m;  // n is size of array and m is sum
	for(int i = 0;i < n; i++){
		cin>>arr[i];  // 3 34 4 12 5 2 and sum is 9
	}
	subsetSumDP(arr,n,m)?
	cout<<"Found a subset with given sum" :
	cout<<"No subset with given sum";
	return 0;
}
