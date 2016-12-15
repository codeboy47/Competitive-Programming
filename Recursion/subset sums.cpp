#include <iostream>
using namespace std;

void subsetSums(int *arr,int n){
    if(n == 0 ) return;
    int sum = subsetSums(arr,n-1) + subsetSums(arr,n-)

}

int main() {
	//code
	int arr[1000],i,n,t,j;
	cin>>t;
	for(i=0;i<t;i++){
	    cin>>n;
	    for(j=0;j<n;j++){
	        cin>>arr[j];
	    }
	    subsetSums(arr,n);
	}
	return 0;
}
