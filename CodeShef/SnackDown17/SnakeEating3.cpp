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
	int t;
	//std::vector<bool> found;
	vector<int> v,sum,info;
	scanf("%d",&t);
	
	while(t--){
		for(int i = 0; i <= 100000; i++){
			info.push_back(0);
			//v.push_back(-1);
			//cons.push_back(1);
			//found.push_back(false);
		}
		int n,q;
		scanf("%d %d",&n,&q);
		for(int i = 0; i < n; i++){
			int d;
			scanf("%d",&d);
			v.push_back(d);
			sum.push_back(0);
		}
		sort(v.begin(),v.end());
		int prev = sum[0];
		for(int i = 0; i <n; i++){
			sum[i] = prev + v[i];
			prev = sum[i];
			//cout<<sum[i]<<" ";
		}
		//cout<<endl;

		int c = 2;
		info[v[n-1]] = 1;
		for(int i = n-2;i >=0;i--){
			if(v[i] != v[i+1]){
				info[v[i]] = info[v[i]] + c;
			}
			if(v[i] == v[i+1]){
				info[v[i]] = info[v[i]] + 1;
			}
			c++;
		}
		int j = v[n-1];
		for(int i = v[n-1]-1;i >= 0; i--){
			if(info[i] == 0)
				info[i] = info[j];
			else{
				j = i;
			}
 
		}
		
		for(int i = 0; i < q; i++){
			int d,count = 0,elCount = n,mid;
			scanf("%d",&d);		
			count = count + info[d];
			
			int end = n - count - 1;
			elCount = end + 1;
			mid = end/2;
			
			for(j = mid; j <= end; j++){
				if(elCount/2 <= d - v[elCount-1] && d - v[elCount-1] < elCount){
					count = count + 1;
					break;
				}
				else if(d - v[elCount-1] >= elCount){
					count = count + 0;
					break;
				}
				int x = end - j;
				int q = (x*d) - (sum[end] - sum[j]);
				if(j+1 >= q){
					count = x + count;
					break;
				}
				elCount--;
			}
			cout<<count<<endl;
		}
		v.clear();
		info.clear();
		sum.clear();
		//found.clear();
		//cons.clear();
	}
	return 0;
}