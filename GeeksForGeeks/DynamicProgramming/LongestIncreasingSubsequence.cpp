#include <iostream>
using namespace std;

// this is bottom up dynamic programming
// time complexity is O(n^2)
// both are same

// starting from front of array
int lis(vector<int> arr){

    int n = arr.size();
	int *dp = new int[n];

	dp[0] = 1;
	for(int i = 1; i < n; i++){

        int ans = 0;
		for(int j = i-1; j >= 0; j--){
			if(arr[i] > arr[j])
				ans = max(ans,dp[j]);
		}

		dp[i] = ans + 1;
	}

	int large = 0;
	for(int i = 0; i < n; i++){
		large = max(large,dp[i]);
	}

	return large;
}

// O(nlogn) solution

int getIndex(vector<int> &tail, int s, int e, int key){
	int ans = -1;
	while(s <= e){
		int mid = (s + e)/2;
		if(tail[mid] >= key){
			ans = mid;
			e = mid -1;
		}
		if(tail[mid] < key){
			s = mid + 1;
		}
	}
	return ans;
}

int LongestIncreasingSubsequenceLength(vector<int> &arr){

	// array that stores end element of list (index represents length of that list)
	vector<int> tail(arr.size(),0);
	int length = 1;
	tail[0] = arr[0];
	for(int i = 1; i < arr.size(); i++){
		// this means arr[i] is smallest element among lists
		if(tail[0] > arr[i]){
			tail[0] = arr[i];
		}
		else if(tail[length-1] < arr[i]){
			tail[length++] = arr[i];
		}
		else{
			tail[getIndex(tail,0,length-1,arr[i])] = arr[i];
		}
	}

	/*for(int i = 0; i < tail.size(); i++){
		cout<<tail[i]<<" ";
	}
	cout<<endl;*/

	return length;
}

int main() {
	vector<int> v = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	cout<<"Length of Longest Increasing Subsequence is "<<LongestIncreasingSubsequenceLength(v)<<'\n';
   	return 0;
}
