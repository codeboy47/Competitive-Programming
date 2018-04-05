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
	vector<long long int> stock;
	vector<long long int> ques;
	scanf("%lld",&t);
	while(t--){		// t <= 5
		scanf("%lld %lld",&n,&q);
		for(i = 0; i < n;i++){		// n <= 10^5
			scanf("%lld",&k);
			stock.push_back(k);
		}
		for(i = 0; i < q;i++){		// q <= 10^5
			ans = 0;
			count = 1;
			for(j = 0; j < 3;j++){
				scanf("%lld",&k);
				ques.push_back(k);
			}
			// O(q*n) i.e. 10^10
			for(k = ques[0]-1;k < ques[1]-1;k++){ 	// range <= 10^5
				//cout<<k;
				if(stock[k] == stock[k+1]){
					count++;
				}
				else if(stock[k] != stock[k+1]){
					if(count >= ques[2]){
						ans++;
					}
					count = 1;
				}
			}
			if(count >= ques[2]){
					ans++;
					count = 1;
			}
			cout<<ans<<endl;
			ques.clear();
		}
		stock.clear();
	}
	return 0;
}