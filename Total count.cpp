#include <iostream>
using namespace std;

int main() {
	//code
	int arr[1000],i,s,j,n,k,t,count=0;
	cin>>t;

	for(i = 0; i < t; i++){
	    cin>>n>>k;
	    count = 0;
	    for(j = 0; j < n; j++){
	        cin>>arr[j];
	    }
	    for(j = 0; j < n; j++){
	        if(arr[j] < k){
	            count++;
	        }
	        else if(arr[j]%k == 0 ){
	            count = count + arr[j]/k;
	        }else{
	            count = count + (arr[j]/k) + 1;
	        }
	    }
	    cout<<count<<endl;
	}

	return 0;
}
