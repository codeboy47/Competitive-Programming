#include <bits/stdc++.h>
using namespace std;
 
bool partition(long x, long n){

	long sum = 0;
		for(long i = 1; i <= n; i++){
			sum += i;
		}
		sum -= x;

		if(sum%2 != 0){
			return false;
		}

			string str;
			for(long i = 0; i < n; i++){
			    str += "0";
			}

			long s = 1, e = n;
			if(s == x){
			    s++;
			}
			if(e == x){
			    e--;
			}

			str[s-1] = '1', str[e-1] = '1';
			s++;
			e--;
			long currSum = s + e;
			do{
 
				if(s == x){
					s++;
				}
				else if(e == x){
					e--;
				}
				else if(sum/2 == currSum){
					break;
				}
				else if(currSum > sum/2){
					if(str[currSum-sum/2-1] == '1'){
						str[currSum-sum/2-1] = '0';
						break;
					}
					else{
						if(str[s] != '0'){
							str[s] = '0';
							currSum -= s+1;
							if(s != 1){
								s--;
							}
						}
						else{
							str[e] = '0';
							currSum -= e+1;
							if(e != n){
								e++;
							}
						}
						
					
					}
 
				}
				else if(sum/2 - currSum >= e){
					str[e-1] = '1';
					currSum += e;
					e--;
				}
				else{
					str[s-1] = '1';
					currSum += s;
					s++;
				}
 
 
			}while(s <= e);
				
			if(s > e){
			    return false;
			}
			else{
				str[x-1] = '2';
				cout<<str<<endl;
			}
		
	return true;

}

int main() {
	
	int t;
	cin>>t;
	for(int k = 0; k < t; k++){
		
		long x,n;
		cin>>x>>n;
		
		bool ans = partition(x,n);
		if(!ans){
			cout<<"impossible"<<endl;
		}
		
	}
	return 0;
} 

/*
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
	
	ll t;
	cin>>t;
	while(t--){
		ll x,n;
		cin>>x>>n;
		
		ll sum = ((n*(n+1))/2) - x;
		//cout<<sum<<endl;
		if(sum%2 != 0){
			cout<<"impossible"<<endl;
		}
		else{
			ll half = sum/2;
			sum = 0;
			ll i;
			ll *arr = new ll[n];
			for(ll i = 0; i < n; i++){
			    arr[i] = 0;
			}
 
			ll s = 1, e = n;
			if(s == x){
			    s++;
			}
			else if(e == x){
			    e--;
			}
			arr[s-1] = 1, arr[e-1] = 1;
			sum = s + e;
			s++;e--;
			while(s <= e){
 
				if(s == x){
					s++;
				}
				else if(e == x){
					e--;
				}
				else if(sum == half){
					break;
				}
				else if(sum > half){
					if(arr[sum-half-1] == 1){
						arr[sum-half-1] = 0;
						break;
					}
					else{
						if(arr[e] != 0){
							arr[e] = 0;
							sum -= e+1;
							if(e!=n)
							e++;
						}
						if(arr[s] != 0){
							arr[s] = 0;
							sum -= s+1;
							if(s != 1)
							s--;
						}
					
					}
 
				}
				else if(half - sum >= e){
					arr[e-1] = 1;
					sum += e;
					e--;
				}
				else if(sum < half){
					arr[s-1] = 1;
					sum += s;
					s++;
				}
 
 
			}
			if(s > e){
				cout<<"impossible"<<endl;
			}
			else{
				arr[x-1] = 2;
				for(i = 0; i < n; i++){
					cout<<arr[i];
				}
				cout<<endl;
			}
			
		}
	}
	return 0;
} 
*/