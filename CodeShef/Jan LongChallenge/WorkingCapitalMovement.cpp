// use of maps , sets , array of vectors (STL)
//https://discuss.codechef.com/questions/90266/capimove-editorial
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
	long long int t,row,col,i,j,v,u,n,largest=0;
	vector<long long int> arr[1000000];//array of vectors somewhat like 2D array(2D array!=array of vectors)
	vector<long long int> p,ans;
	map<long long int,long long int> m;
    map<long long int,long long int>::iterator it ;
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
			m.insert({p[i],i});
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
			if (!s.empty()){  // to find largest
        		ans[i] = *s.rbegin();
      		}
			s.insert(p[i]);
			for(j =0;j < arr[i+1].size();j++){ 
				s.insert(p[arr[i+1][j]-1]);
			}
			arr[i].clear();
		}
		for(i = 0;i < n;i++){
			it = m.find(ans[i]);
			cout<<(*it).second+1<<" ";
		}
		/*for(set<long long int>::iterator it=s.begin(); it!=s.end(); ++it){
			cout<<*it;
		}*/
		s.clear();
		ans.clear();
		p.clear();
		cout<<endl;
	}
	return 0;
}
