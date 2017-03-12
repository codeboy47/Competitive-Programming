#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	long long int i,j,t,n,m,sum = 0,large,large1,l=0,r=0,s=0,e=0,ans=0;
	vector<long long int> a,b;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(i = 0;i < n;i++){
			long long int q;
			scanf("%lld",&q);
			a.push_back(q);
			//cout<<a[i]<<" ";
		}
		for(i = 0;i < m;i++){
			long long int q;
			scanf("%lld",&q);
			b.push_back(q);
			//cout<<b[i]<<" ";
		}
		long long int end = n;
		l = 0;
		r = n;
		ans = 0;
		for(i = 0;i < m;i++){
			if(i%2 == 0){
				//cout<<l<<" "<<r<<" ";
				//cout<<" hfbkj";
				e = b[i]; 
				large = 0;
				if(i==0){
					s = l;
					e = e + s;
					end = r+1;
				}else{
					s = l+1;
					e = e + s;
					end = r;
				}
				while(e < end){
					sum = 0;
					for(j = s;j < e;j++){
						sum = sum + a[j];
					}
					//cout<<sum<<" ";
					if(sum > large){
						large = sum;
						//cout<<large<<" ";
						l = s;
						r = e; 
					}
					s++;
					e++;
				}
				ans = large + ans;
				cout<<ans<<" ";
			}
			if(i%2 == 1){
				//cout<<l<<" "<<r<<" ";
				e = b[i]; 
				large1 = 0;
				s = l+1;
				e = e + s;
				end = r;
				while(e < end){
					sum = 0;
					for(j = s;j < e;j++){
						sum = sum + a[j];

					}
					//cout<<"sum="<<sum<<" ";
					if(sum > large1){
						large1 = sum;
						l = s;
						r = e; 
					}
					s++;
					e++;
				}
				ans = ans - large1;
				cout<<ans<<" ";
			}
		}
		cout<<ans<<endl;
		a.clear();
		b.clear();
	}
	return 0;
}