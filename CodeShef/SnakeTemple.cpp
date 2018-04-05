#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t,n,count;
	vector<int> arr;
	scanf("%d",&t);
	while(t--){
		count = 0;
		scanf("%d",&n);
		for(int i  = 0; i < n; i++){
			int d;
			cin>>d;
			arr.push_back(d);
		}
		sort(arr.begin(),arr.end());
		if(n == 2){
			count = count + arr[1] + arr[0] - 1;
		}else{
			int a = 1,b = 2,rem = 0;
			for(int i = 0; i < n; i++){
				if(rem < b){
					if(arr[i] - a < 0){
						count = count + arr[i];
					}else{
						count = count + arr[i] - a;
						rem++;
					}
				}
				if(rem >= 2){
					if(a >= n/2){
						b = 1;
					}
					rem = 0;
					a++;
					rem = 0;
				}
			}
		}
		printf("%d\n", count);
		arr.clear();
	}
	return 0;
}