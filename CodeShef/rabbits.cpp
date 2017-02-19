#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	long long int  T,n,k,count = 0;
	
	cin>>T;

	for(long long int a = 0 ;a < T;a++){
		cin>>n>>k;
		vector<long long int> v(n);
		for(long long int j = 0;j < n;j++){
			cin>>v[j];
		}
		for(long long int i = 0; i < n;i++){
			for(long long int j = 0;;j++){
				long long int p = pow(k,j);
				if(p == v[i]){
					count++;
					//cout<<v[i]<<" ";
				}
				if(p > v[i]){
					break;
				}
			}
		}
		cout<<count<<endl;
		count = 0;
	}
	return 0;
}