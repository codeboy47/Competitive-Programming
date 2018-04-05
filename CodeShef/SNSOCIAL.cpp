#include <bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;

bool same(vector<long> *arr,long n, long m){
    long i , j;
	for( i = 0; i  < n; i++){
		for( j = 0; j < m; j++){
			if(arr[0][0] != arr[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	long t;
	scanf("%ld",&t);
	int i , j;
	vector<long> arr[1000];
	vector<bool> visited[1000];
	vector<pair<long,long> > v;
	while(t--){
		long n, m, d;
		scanf("%ld %ld",&n,&m);
		for( i = 0; i  < n; i++){
			for( j = 0; j < m; j++){
				scanf("%ld",&d);
				arr[i].push_back(d);
				visited[i].push_back(false);
			}
		}
		long large = -1;
		for( i = 0; i  < n; i++){
			for( j = 0; j < m; j++){
				large = max(large,arr[i][j]);
			}
		}
		for( i = 0; i  < n; i++){
			for( j = 0; j < m; j++){
				if(large == arr[i][j]){
					v.push_back(make_pair(i,j));
				}
			}
		}
		long ans = 0;
		if(v.size() == 1){
			long ver,h,ans1 = 10000;
			for( i = 0; i < v.size(); i++){
				ver = max(n-1-v[i].first,v[i].first-0);
			 	h = max(m-1-v[i].second,v[i].second-0);
				ans1 = min(ans1,max(ver,h));
			}
			ans = ans1;
		}else{
			long count = n;
			while(count--){
				for( i = 0; i < v.size(); i++){
					int f = v[i].first;
					int s = v[i].second;
					if(f > 0 && visited[f-1][s] == false){	// north
						arr[f-1][s] = arr[f][s];
						visited[f-1][s] = true;
					}
					else if(f > 0 && s > 0 && visited[f-1][s-1] == false){	//	nw
						arr[f-1][s-1] = arr[f][s];
						visited[f-1][s-1] = true;
					}
					else if(f > 0 && s < m-1 && visited[f-1][s+1] == false){	// ne
						arr[f-1][s+1] = arr[f][s];
						visited[f-1][s+1] = true;
					}
					else if(s < m-1 && visited[f][s+1] == false){ // east
						arr[f][s+1] = arr[f][s];
						visited[f][s+1] = true;
					}
					else if(s > 0 && visited[f][s-1] == false){	// west
						arr[f][s-1] = arr[f][s];
						visited[f][s-1] = true;
					}
					else if(f < n-1 && visited[f+1][s] == false){	// south
						arr[f+1][s] = arr[f][s];		
						visited[f+1][s] = true;				
					}
					else if(f < n-1 && s > 0 && visited[f+1][s-1] == false){	// sw
						arr[f+1][s-1] = arr[f][s];
						visited[f+1][s-1] = true;
					}
					else if(f < n-1 && s < m-1 && visited[f+1][s+1] == false){	// se
						arr[f+1][s+1] = arr[f][s];
						visited[f+1][s+1] = true;
					}
				}
				ans++;
			}
		}
		if(same(arr,n,m)){
			printf("0\n");
		}else 
			printf("%ld\n", ans);
		for(i = 0; i < n; i++){
			arr[i].clear();
		}
		v.clear();
	}
	return 0;
}