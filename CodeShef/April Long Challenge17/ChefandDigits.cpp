#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;
 
 
int main(){
	long long int t,l,r,i,j,count = 0;
	vector<long> arr,counter;
	scanf("%ld",&t);
	while(t--){
		count = 0;
		scanf("%ld %ld",&l,&r);
		count = r - l + 1;
		for(i = 0; i <= 9; i++){
			scanf("%ld",&j);
			arr.push_back(j);
			counter.push_back(0);
		}
		for(i = 0; i < 9;i++){

		}
		long a;
		for(a = 0; a <= 9; a++){
			if(arr[a] != 0){
				break;
			}
		}
		if(a != 10){
			for(i = l; i <= r; i++){
				for(j = 0; j <= 9; j++){
					counter.push_back(0);		
				}
				long no = i,digit; // let l = 213  
				while(no!=0){
					digit = no%10; // digit = 3 1 2
					counter[digit] = counter[digit] + 1;
					no = no/10; // 21 2 0
				}
				for(j = 0; j <= 9; j++){
					if(counter[j] == arr[j]){
						count--;
						break;
					}
				}
				counter.clear();
			}
			printf("%ld\n",count);
		}else{

			cout<<0<<endl;
		}
		arr.clear();
	}
	return 0;
} 
