#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;


int main(){
	long long int t,i,j,k;
	long long int n,q;
	long ans,count;
	vector<long long int> stock,arr;
	vector<long long int> ques;
	scanf("%lld",&t);
	while(t--){		// t <= 5
		scanf("%lld %lld",&n,&q);
		for(i = 0; i < n;i++){		// n <= 10^5
			scanf("%lld",&k);
			stock.push_back(k);
			arr.push_back(1);
		}
		
		count = 0;
		for(i = n-2; i >= 0; i--){
			if(stock[i] == stock[i+1]){
				count++;
				arr[i] = count + arr[i];
			}
			if(stock[i] != stock[i-1]){
				count = 0;
			}
		}
		for(i = 0; i < q;i++){		// q <= 10^5
			ans = 0;
			count = 1;
			for(j = 0; j < 3;j++){
				scanf("%lld",&k);
				ques.push_back(k);
			}
			for(k = ques[0]-1;k <= ques[1]-1;){
				if(arr[k] + k <= ques[1]-1){
					if(arr[k] >= ques[2]){
						ans++;
						k = k + arr[k];
					}else{
						k++;
					}
				}
				else if(arr[k] + k > ques[1]-1){
					if(ques[1]-k >= ques[2]){
						ans++;
						k++;
						break;
					}
					else{
						k++;
					}
				}
			}
			cout<<ans<<endl;		
			ques.clear();
		}
		arr.clear();
		stock.clear();
	}
	return 0;
}
