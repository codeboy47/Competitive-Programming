#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
	long long int t,row,col,i,j,v,u,n,largest=0,index;
	vector<long long int> arr[1000000];//array of vectors somewhat like 2D array(2D array!=array of vectors)
	vector<long long int> p;
	set<long long int> s;
	bool checking = false,check = false;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i = 0;i < n;i++){
			long long int c;
			scanf("%lld",&c);
			p.push_back(c);
		}
		for(i = 0;i < n-1;i++){
			scanf("%lld %lld",&u,&v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(i = 0;i < n;i++){
			//s.insert(p[i]);
			s.insert(i);
		}
		for(i = 0;i < n;i++){
			s.erase(i);
			for(j =0;j < arr[i+1].size();j++){ // erase adjacent elements from set
				s.erase(arr[i+1][j]-1);
			}
			largest = 0;
			//ans[i] = 0; // wrong method
			//ans.push_back(0);  right method
			set<long long int>::iterator it = s.begin();
			for(j = 0;j < s.size();j++){
				long long int c = *it;
				if(p[c] > largest){
					index = c;
					largest = p[c];
				}
				//ans[i] = max(p[c],ans[i]);
				it++;
			}
			cout<<index+1<<" ";
			s.insert(i);
			for(j =0;j < arr[i+1].size();j++){ 
				s.insert(arr[i+1][j]-1);
			}
			arr[i].clear();
		}
		/*for(i = 0;i < n;i++){
			cout<<ans[i]<<" ";
		}
		for(set<long long int>::iterator it=s.begin(); it!=s.end(); ++it){
			cout<<*it;
		}*/
		s.clear();
		//ans.clear();
		p.clear();
		cout<<endl;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
	long long int t,row,col,i,j,v,u,n,largest=0;
	vector<long long int> arr[1000000];//array of vectors somewhat like 2D array(2D array!=array of vectors)
	vector<long long int> p,ans;
	set<long long int> s;
	bool checking = false,check = false;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i = 0;i < n;i++){
			long long int c;
			scanf("%lld",&c);
			p.push_back(c);
		}
		for(i = 0;i < n-1;i++){
			scanf("%lld %lld",&u,&v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(i = 0;i < n;i++){
			//s.insert(i);
			s.insert(p[i]);
		}
		for(i = 0;i < n;i++){
			s.erase(p[i]);
			for(j =0;j < arr[i+1].size();j++){ // erase adjacent elements from set
				s.erase(p[arr[i+1][j]-1]);
			}
			//ans[i] = 0;
			ans.push_back(0);
			set<long long int>::iterator it = s.begin();
			for(j = 0;j < s.size();j++){
				long long int c = *it;
				ans[i] = max(c,ans[i]);
				it++;
			}
			s.insert(p[i]);
			for(j =0;j < arr[i+1].size();j++){ 
				s.insert(p[arr[i+1][j]-1]);
			}
			arr[i].clear();
		}
		for(i = 0;i < n;i++){
			for(j = 0;j < n;j++){
				if(p[j] == ans[i]){
					cout<<j+1<<" ";
				}
			}
			//cout<<ans[i]<<" ";
		}
		
		s.clear();
		ans.clear();
		p.clear();
		cout<<endl;
	}
	return 0;
}*/
