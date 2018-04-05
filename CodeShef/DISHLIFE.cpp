#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;


int main(){
	long int t,n,k;
	long int i,j;
	long int start,data,total=0,sum = 0;
	vector<long int> arr;
	//long arr[1000000];
	scanf("%ld",&t);
	while(t--){
		bool flag = true;
		sum = 0;
		total = 0;
		scanf("%ld %ld",&n,&k);
		//cout<<" n="<<n<<" k="<<k;
		arr.push_back(-1);
		for(i = 1;i <= k;i++){
			total = total + i;
			//arr[i] = i;
			arr.push_back(i);
		}
		for(i = 0;i < n;i++){
			//cout<<" n="<<n;
			//sum = 0;
			scanf("%ld",&start);
			//cout<<" start="<<start;
			for(j = 0;j < start;j++){
				scanf("%ld",&data);
				if(arr[data] != -1)
					sum = sum + data;
				arr[data] = -1;
			}
			if(i != n-1 && flag == true && sum == total){
				printf("some\n");
				flag = false;
			}
		}
		if(flag == true){
			bool check = true;
			for(i = 0;i <= k;i++){
				//cout<<arr[i]<<" ";
				if(arr[i] != -1){
					printf("sad\n");
					check = false;
					break;
				}
			}
			if(check == true){
				printf("all\n");
			}
		}
		arr.clear();
	}
	return 0;
}