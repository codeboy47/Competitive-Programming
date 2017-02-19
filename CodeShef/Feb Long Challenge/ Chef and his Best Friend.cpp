#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
#include <bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

bool check(vector<long> &arr,long n){
	bool flag = false;
	long i;
	for( i = 1;i < arr.size();){
		if(flag == false && arr[i] == arr[i-1] && arr[i] == 1){
			i++;
		}
		else if(flag == true && arr[i] == arr[i-1] && arr[i] == 0){
			i++;
		}
		else if(arr[i] == 0 && arr[i-1] == 1){
			i++;
			flag = true;
		}else{
			return false;
			//break;
		}
	}
	if(i == n)	return true;
	else return false;
}

int main(){
	vector<long> arr;
	long t,n,time = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(long i = 0;i <n;i++){
			long k;
			scanf("%d",&k);
			arr.push_back(k);
		}
		//cout<<arr.size();
		//while(1){
		for(long j = 0;j < n;j++){
		for(long i = 1;i < arr.size();){
			if(arr[i] == 1 && arr[i-1] == 0){
				long temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
				//arr.swap(arr[i],arr[i-1]);
				i = i + 2;
			}else{
				i++;
			}
		}
		//cout<<arr[j]<<" ";
		if(check(arr,n) == false){
			time++;
		}else{
			break;
		}	
		}
		long q;
		for( q = 1;q < arr.size();){
			if(arr[q] == arr[q-1]){
				q++;
			}else{
				break;
			}
		}
		if(q == n) cout<<0<<endl;
		else if(time == 0) cout<<time<<endl;
		else
		printf("%ld\n",time+1);
		arr.clear();
		time = 0;
	}
	return 0;
}