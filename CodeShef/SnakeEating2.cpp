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
	vector<int> v,info;
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
			//v[i] = d;
			v.push_back(d);
		}
		sort(v.begin(),v.end());
		/*int j = n-1,c = 0;
		for(int i = v[n-1]; i >= 0;i--){
			if(i == v[j]){
				found[i] = true;
				if(j == n-1){
					info[i] = c;
				}
				else {
					c++;
					info[i] = c;
				}
				j--;
			}
			else{
				info[i] = c + 1;
			}
		}*/
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
		/*for(int i = 0;i <= v[n-1]; i++){
			cout<<i<<"="<<info[i]<<" ";
		}cout<<endl;*/
		/*for(int i = 0; i <= v[n-1]; i++){
			if(i != v[j]){
				info[i] = n-j;
			}else{
				if(v[i] == v[i+1]){
 
				}
				found[i] = true;
				info[v[j]] = n-j-1;
				j++;
			}
		}
		for(int i = 0; i < n-1; i++){
			if(v[i] == v[i+1]){
				cons[v[i]] = cons[v[i]] + 1;
			}
		}*/
		for(int i = 0; i < q; i++){
			int d,count = 0,elCount = n;
			scanf("%d",&d);
 		
			/*if(v[n - info[d] - 1] == d)
				count = count + info[d];
			else*/
			//if(found[d] == false)
				count = count + info[d];
			
 
			int end = n - count - 1;
			//if(end > 0){
			elCount = end+1;
			while(end > 0){
				int x = elCount;
				elCount--;
				if(x/2 <= d - v[end] && d - v[end] < x){
					count = count + 1;
					break;
				}
				else if(d - v[end] >= x){
					break;
				}
				else if(elCount >= d - v[end]){
					count++;
					elCount = elCount - (d - v[end]);				
				}
				else{
				    break;
				}
				end--;
			}
			//}
			cout<<count<<endl;
		}
		v.clear();
		info.clear();
		//found.clear();
		//cons.clear();
	}
	return 0;
}