#include <bits/stdc++.h>
#include <math.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	vector<int> arr;
	int m,n,l,r,k,i,el=-1,s,e,mid,range;
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i++){
		int e;
		scanf("%d",&e);
		arr.push_back(e);		
	}
	
	while(m--){
		s = -1;
		e = -1;
		scanf("%d %d %d",&l,&r,&k);
	
		mid = (l-1+r-1)/2;
		//mid = (l+r)/2 -1;//floor((r-l+1)/2);
		//cout<<arr[mid]<<store[mid];
		i = mid;
		while(i >=l-1 && arr[i] == arr[mid]){
			i--;
		}
		s = i+1;
		//cout<<"mid="<<mid<<" s="<<s;
		
		i = mid;
		while(i <= r-1 && arr[i] == arr[mid]){
			i++;
		}
		e = i-1;
		//cout<<" e="<<e<<endl;
		range = e - s + 1;
		if(range >= k){
			printf("%d\n",arr[mid]);
		}else{
			printf("-1\n");
		}	
	}

	return 0;
}