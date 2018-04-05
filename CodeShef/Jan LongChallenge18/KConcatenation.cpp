#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll kadaneSum(ll *arr, ll n){
 
	ll cs = 0;
	ll ms = 0;
	for(ll i = 0; i < n; i++){
		cs = cs + arr[i];
		ms = max(cs,ms);
		if(cs  <  0){
			cs = 0;
		}
	}
 
	return ms;
 
} 
 
 
int main(){
 
	ll arr[10000001];
	ll t;
	cin>>t;
	while(t--){
		
		ll n,k;
		cin>>n>>k;
 
		for(ll i = 0; i < n; i++){
			cin>>arr[i];
		}
 
		ll totalSum = 0;
		bool flagPos = true;
		for(ll i = 0; i < n; i++){
			if(arr[i] < 0){
				flagPos = false;
			}
			totalSum += arr[i];
		}
 
        ll sum = kadaneSum(arr,n);
        
        bool flagNeg = true;
        ll minNeg = arr[0];
        if(!flagPos){
        	// check if all are negative or not
        	
        	for(ll i = 0; i < n; i++){
				if(arr[i] > 0){
					flagNeg = false;
				}
				minNeg = max(arr[i],minNeg);
			}
        }
 
        
		if(flagPos){
			totalSum *= k;
			cout<<totalSum<<endl;
		}
		else if(flagNeg){
			cout<<minNeg<<endl;
		}
 
		else if(totalSum <= 0){
 
			if(k > 1){
 
				ll ms1 = 0;
					ll cs = 0;
					for(ll i = 0; i < n; i++){
						cs = cs + arr[i];
						if(ms1 < cs){
							ms1 = cs;
						}	
					}	
				
				cs = 0;
				ll ms2 = 0; 
					for(ll i = n-1; i >= 0; i--){
						cs = cs + arr[i];
						if(ms2 < cs){
							ms2 = cs;
						}
					}
				
				long long int s = ms2+ms1;
                if(s > sum){
                	sum = s;
                }
			}
 
			cout<<sum<<endl;
 
		}
		
		else{
 
			if(k > 1){
 
				ll cs = 0;
				ll ms1 = 0;
				for(ll i = n-1; i >= 0; i--){
					cs = cs + arr[i];
					if(ms1 < cs){
						ms1 = cs;
					}
					
				}
 
				totalSum *= k-2;
 
				cs = 0;
				ll ms2 = 0;
				for(ll i = 0; i < n; i++){
					cs = cs + arr[i];
					if(ms2 < cs){
						ms2 = cs;
					}
				}
 
 
				long long int s = ms2+ms1+totalSum;
                if(s > sum){
                	sum = s;
                }
 
			}
 
			cout<<sum<<endl;
 
 
		}
 
 
	}
	return 0;
}