#include <iostream>
using namespace std;

int noOfWays(int *arr, int coin, int n){
	int output[n+1][coin+1];

	// it is necessary to keep this loop first
	for(int i = 0; i <= coin; i++){
		output[0][i] = 0; // 1st row of output is zero which is not considered
	}
	for(int i = 0; i <= n; i++){
		output[i][0] = 1; // coin 0 can be made by one way only
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= coin; j++){
			if(arr[i-1] > j){
				output[i][j] = output[i-1][j];
			}else{
				// total ways = no of ways to make jth coin excluding that coin +
				// no of ways to make (j-arr[i])th coin including arr[i] coin ) as no of ways to
				// make (j-arr[i])th coin is same for making jth coin from set{arr[0],..arr[i]}
 				output[i][j] = output[i-1][j] + output[i][j - arr[i-1]];
			}
		}
	}
	return output[n][coin];
}

int main(){
	int coin; // coin which is to be made from given denominations
	int n; // no of coins
	cin>>coin>>n;
	int arr[1000];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<noOfWays(arr,coin,n);
	return 0;
}
