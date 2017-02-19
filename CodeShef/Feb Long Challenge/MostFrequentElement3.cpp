/* To run in 1sec you have to store previous result before going into main loop
	always consider this fact that  your algo does not do the work it has done previously. For that try to
	store that previous result somewhere like in array
*/

#include <bits/stdc++.h>
#include <math.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	vector<int> arr,left,right;
	int m,n,l,r,k,i,el=-1,s,e,mid,range,count=1;
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i++){
		int e;
		scanf("%d",&e);
		arr.push_back(e);
		left.push_back(-1);
		right.push_back(-1);		
	}
	count = 1;
		for(i = n-1;i > 0;i--){
			if(arr[i] == arr[i-1]){
				right[i] = count;
				count++;
			}
			else{
				right[i] = count;
				count = 1;
			}
		}
	right[0] = count;

	count = 1;
		for(i = 0;i < n-1;i++){
			if(arr[i] == arr[i+1]){
				left[i] = count;
				count++;
			}
			else{
				left[i] = count;
				count = 1;
			}
		}
	left[n-1] = count;


	while(m--){
		s = -1;
		e = -1;
		scanf("%d %d %d",&l,&r,&k);
	
		mid = (l-1+r-1)/2;
		
		s = max(mid-left[mid]+1,l-1);
		e = min(right[mid]+mid-1,r-1);

		//cout<<"mid="<<mid<<" s="<<s;
	
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