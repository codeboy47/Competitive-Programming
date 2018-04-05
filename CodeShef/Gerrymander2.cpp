#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	long long int t;
	vector<long long int> arr,store; 
	long long int o1,o2,n,i,j,count1=0,count = 0,k,z=0;
	long long int gov1=0;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&o1,&o2);
		n = o1*o2;
		for(i = 0;i < n;i++){
			long long int e;
			scanf("%lld",&e);
			arr.push_back(e);
		}
		for(i = 0;i < n;i++){
			if(arr[i] == 1){
				count1++;
			}	
		}
		if(count1 > n/2){ 
			printf("1\n");
		}
		else if(count1 < ((o1/2)+1)*((o2/2)+1) ){
			printf("0\n");
		}
		else{
			bool flag = true;
			count = 0;
			gov1 = 0;
			for(i = 0;i < n;i = i+o2){
				for(j = i;j < o2+i;j++){
					if(arr[j] == 1){
						count++;
					}
				}
				if(count > o2/2){
					gov1++;
				}
				if(gov1 > o1/2){
					cout<<1<<endl;
					flag = false;
					break;
				}
				store.push_back(count);
				count = 0;
			}
		
			count=0;
			gov1 = 0;
			if(flag == true){
				for(i = 1;i < o2;i++){
					k = 0;
					for(j = i;j < n;j = j + o2,k++){ // o1 times
						int s = j;
						int e = j + o2 - 1;
						if(e >= n){
							e = o2 - (n - j) - 1;
						}
						if(arr[s-1] == 1){
							store[k] = store[k] -1;
						}
						if(arr[e] == 1){
							store[k] = store[k] + 1;
						}
					}
					count = 0;
					for(z = 0;z < store.size();z++){
						if(store[z] > o2/2){
							count++;
						}
						if(count > o1/2){
							cout<<1<<endl;
							flag = false;
							break;
						}
					}
					if(flag == false){
						break;
					}
				}
			}
			if(flag == true){
				printf("0\n");
			}
		}
		gov1 = 0;
		count1 = 0;
		count = 0;
		k = 0;
		arr.clear();
		store.clear();
	}

	return 0;
}
