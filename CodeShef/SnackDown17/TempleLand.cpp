#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;
 
int main(){
	int s;
	std::vector<int> arr;
	scanf("%d",&s);
	while(s--){
		bool flag = true;
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n; i++){
			int d;
			scanf("%d",&d);
			arr.push_back(d);
		}
		if(arr[0] != 1){
			printf("no\n");
		}
		else if(arr[n-1] != 1){
			printf("no\n");
		}
		else if(n%2 == 0){
			printf("no\n");
		}
		else{
			for(int i = 0; i < n/2; i++){
				if(arr[i]+1 != arr[i+1]){
					printf("no\n");
					flag = false;
					break;
				}
			}
			if(flag == true){
				for(int i = n/2; i < n-1; i++){
					if(arr[i]-1 != arr[i+1]){
						printf("no\n");
						flag = false;
						break;
					}
				}
				printf("yes\n");
			}
		}
		arr.clear();
	}
	return 0;
}