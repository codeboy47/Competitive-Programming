#include <iostream>
#include <vector>
using namespace std;

// Kadane's algorithm
int maxSubarraySum(vector<int> &arr, int n){
	int cs = 0;
	int ms = 0;
	for(int i = 0; i < n; i++){
		cs = cs + arr[i];
		ms = max(cs,ms);
		if(cs  <  0){
			cs = 0;
		}
	}	
	return ms;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i =0 ; i < n; i++){
		int d;
		cin>>d;
		arr.push_back(d); 
	}
	cout<<maxSubarraySum(arr,n);
	
	return 0;
}