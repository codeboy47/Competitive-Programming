#include<bits/stdc++.h>
using namespace std;
 

int main(){

	int t;
	cin>>t;
	int arr[1000][1000];
	while(t--){
		
		long n; 
		cin>>n;
		for(long i = 0; i < n; i++){
			for(long j = 0; j < n; j++){
				cin>>arr[i][j];
			}
		}

		
		long last = -1;

		for(long i = 0; i < n; i++){
			last = max(last,arr[n-1][i]);
		}

		long sum = last;
		for(long i = n-2; i >= 0; i--){
			long el = -1;
			for(long j = 0; j < n; j++){
				if(arr[i][j] < last && arr[i][j] > el){
					el = arr[i][j];
				}
			}
			if(el != -1){
				sum += el;
				last = el;
			}
			else{
				cout<<-1<<endl;
				break;
			}
		}

		if(i == -1){
			cout<<sum<<endl;
		}
	}

	return 0;
}