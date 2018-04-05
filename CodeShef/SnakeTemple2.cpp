#include <bits/stdc++.h>
using namespace std;
 
int main(){
	long t,n,count;
	vector<long> arr;
	scanf("%ld",&t);
	while(t--){
		count = 0;
		long sum = 0,total = 0;
		scanf("%ld",&n);
		for(long i  = 0; i < n; i++){
			long d;
			cin>>d;
			arr.push_back(d);
		}
		bool flag = true;
		sort(arr.begin(),arr.end());
		for(long i  = 0; i < n; i++){
			if(arr[i] != 1){
				flag = false;
			}
		}
		if(n == 2 || flag == true){
			count = 0;
			//count = count + arr[1] + arr[0] - 1;
		}
		else{
			if(n%2 == 1){
				for(long i = 1; i <= n/2; i++){
					total = total + i;
				}
				total = 2*total;
				total = total + n/2 + 1;
			}
			if(n%2 == 0){
				for(long i = 1; i <= n/2-1; i++){
					total = total + i;
				}
				total = 2*total;
				total = total + n/2;
			}
			for(long i = 0; i < n; i++){
				sum = sum + arr[i];
			}
			count = count + sum - total;
		}
		while(count < 0){
			total = 0;
			sum = 0;
			count = 0;
			if(n%2 == 0){
				n = n-1;
			}
			for(long i = 1; i <= (n-2)/2; i++){
				total = total + i;
			}
			total = 2*total;
			total = total + n/2 + 1;
			count = count + sum - total;
		}
			printf("%ld\n", count);
		arr.clear();
	}
	return 0;
}