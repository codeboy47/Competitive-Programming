#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;


int main(){
	int t;
	scanf("%d",&t);
	while(t--){		// t <= 5
		int n,q,i,j,k;
		int count,M = -1;
		vector<int> stock,arr,type;
		int l ,r , f;
		scanf("%d %d",&n,&q);
		for( i = 0; i < n;i++){		// n <= 10^5
			scanf("%ld",&k);
			stock.push_back(k);
			arr.push_back(1);
			type.push_back(1);
		}

		// if all nos are distinct
		bool flag = true;
		for(i = 0; i < n-1; i++){
			if(stock[i] == stock[i+1]){
				flag = false;
				break;
			}
		}

		// storing types/distinct nos from backward of array
		count = 1;
		for(i = n-2; i >= 0; i--){
			if(stock[i] != stock[i+1]){
				type[i] = type[i] + count;
				count++;
			}
			if(stock[i] == stock[i+1]){
				type[i] = count;
			}
		}

		// creating array of that counts freq of occurence of no from backward
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
		for(i = 0; i < n;i++){
			M = max(arr[i],M);
		}
		for(i = 0; i < q;i++){		// q <= 10^5
			count = 0;
			scanf("%d %d %d",&l,&r,&k);
			// if all nos are distinct
			if(flag == true){
				if(k >= 2){
					count = 0;
				}else{
					count = r - l + 1;
				}
			}
			// if all nos are same between range l and r then count = 1
			else if(type[l-1] == type[r-1]){
				if(r - l + 1 >= k){
					count++;
				}else{
					count = 0;
				}
			}
			// we will not find any freq i.e. k = 4 if M is 3 so count is 0
			else if(k > M){
				count = 0;
			}
			// if k(frequency of occurance) is one  
			else if(k == 1){
				count = type[l-1] - type[r-1] + 1;  // O(1)
			}
			else{
				for(j = l-1;j <= r-1;){  // range <= 10^5 so O(n*q)
					if(arr[j] + j <= r-1){
						if(arr[j] >= k){
							count++;
						}	
							j = j + arr[j];
					
					}
					else if(arr[j] + j > r-1){
						if(r-j >= k){
							count++;
							break;
						}
						else{
							j++;
						}
					}
				}
			}
			printf("%d\n",count);
			//cout<<count<<endl;		
		}
		type.clear();
		arr.clear();
		stock.clear();
	}
	return 0;
}
