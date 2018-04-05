#include <bits/stdc++.h>
using namespace std;

int divSubArr(int arr[], int n, int k){ // n is size of array and k is the divisor
	int mod[1000000],count = 0;
	for(int i = 0; i < k; i++){
		mod[i] = 0;
	}
	mod[0]++; // this is done to add nos divisible by k itself like 10 divible by 2 or 5 by 5
	// if mod[0] is 1 but is not added in count, hence we increase mod[0] by 1
	int cumulativeSum = 0;
	for(int i = 0; i < n; i++){
		cumulativeSum = (cumulativeSum + arr[i])%k;
		while(cumulativeSum < 0){
		    cumulativeSum = cumulativeSum + k;
		}
        mod[cumulativeSum]++;
	}
	for(int i = 0; i < k; i++){
		count += (mod[i]*(mod[i]-1))/2;
	}
	return count;
}

int main(){

    int t,n,k;
    int arr[1000000];
    cin>>t;
    while(t--){

        cin>>n>>k;
        for(int i = 0;i < n; i++){
            cin>>arr[i];
        }
        cout<<divSubArr(arr,n,k)<<endl;

    }

    return 0;
}
