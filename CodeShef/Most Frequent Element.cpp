#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	//long long int j = 0;
	//vector<long long int> store;
	vector<long long int> arr;
	long long int m,n,l,r,k,i,count = 1,no=0,large1,large2,el=-1;
	scanf("%lld %lld",&n,&m);
	for(i = 0;i < n;i++){
		int e;
		scanf("%lld",&e);
		arr.push_back(e);
	}
	/*for(j = 0;j <= 1000000000;j++){
		store.push_back(1);
	}*/
	while(m--){
		bool flag = true;
		large1 = -1;
		large2 = -1;
		count = 1;
		scanf("%lld %lld %lld",&l,&r,&k);
		for(i = l-1;i < r-1;i++){
			if(arr[i] == arr[i+1]){
				count++;
				//store[arr[i]] = store[arr[i]] + 1; 
			}
			else{
				if(large2 == -1){
					large2 = count;
				}
				if(large2 != -1){
					if(large2 > large1)
						el = arr[i];
					large1 = max(large1,large2);
					large2 = -1;
				}
				if(large1 >= k){
					printf("%lld\n",el);
					flag = false;
					break;
				}
				
				count = 1;
			}

		}
		if(large2 == -1){
			large2 = count;
		}
		if(large2 != -1){
			if(large2 > large1)
				el = arr[i];
			large1 = max(large1,large2);
			large2 = -1;
		}

	//	cout<<large1<<" "<<el<<" ";
		if(flag == true && large1 >= k){
			printf("%lld\n",el);
		}if(flag == true && large1 < k){
			printf("-1\n");
		}

	}

	return 0;
}