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
	set<int> s;
	vector<int> v,info;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d %d",&n,&q);
		for(int i = 0; i < n; i++){
			int d;
			scanf("%d",&d);
			v.push_back(d);
		}
		
		for(int i = 0; i < q; i++){
			int d,count = 0,elCount = n;
			scanf("%d",&d);

			for(int j = 0; j < n; j++){
				if(v[j] < d){
					s.insert(v[i]);
				}else{
					count++;
					elCount--;
				}
			}
	
			while(!s.empty()){
				elCount--;
				if(elCount >= d - *s.rbegin()){
					count++;
					elCount = elCount - d + *s.rbegin();
					s.erase(*s.rbegin());
				}
				else{
					break;
				}
			}
			cout<<count<<endl;
			s.clear();
		}
		v.clear();
	}
	return 0;
}
/*
4
5 2
21 9 5 8 10
10
15
5 1
1 2 3 4 5
100
8 2
21 5 9 8 8 10 8 10
10
15
6 1
1 1 1 1 1 1
2
*/
