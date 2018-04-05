#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
 	 
	ll n;
	cin>>n;
	ll arr[1000000];
	for(ll i = 0; i < n; i++){
		cin>>arr[i];
	}

	ll q;
	cin>>q;

	ll actions[10000000][2];

	for(ll i = 0; i < q; i++){
		cin>>actions[i][0]>>actions[i][1];
	}

	ll ans[10000000];
	for(ll i= 0; i < q; i++){
		ans[i] = n;
	}

		for(ll i = 0; i < n; i++){
			ll j;
			for(j = 0; j < q; j++){
				
				ll no = i&actions[j][0];
				if(no == i){
					arr[i] -= actions[j][1];
				}

				if(arr[i] <= 0){
					ans[j]--;
					break;
				}

			}
		
		}

		ll sum = 0;
		ll ans2[10000000];
		
		for(ll i= 0; i < q; i++){
		    ans2[i] = ans[i];
		}
		
		for(ll i= 0; i < q-1; i++){
			sum = sum + (n-ans[i]);
			ans2[i+1] -= sum;
		}

		for(ll i= 0; i < q; i++){
			cout<<ans2[i]<<endl;
		}

	

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll setBits(ll n){
	ll count = 0;
	while(n > 0){
		count++;
		n = n&(n-1);
	}
	return count;
}

ll countBits(ll n){
	ll count = 0;
	while(n){
		count++;
		n >>= 1;
	}
	return count;
}

ll countBits2(ll number)
{	 
	// log function in base 2 
	// take only integer part
	return (ll)log2(number)+1;
}

bool areAllBitsSet(int n)
{
    // all bits are not set
    if (n == 0)
        return false;
 
    // if true, then all bits are set
    if (((n + 1) & n) == 0)
        return true;
 
    // else all bits are not set
    return false;
}

ll isPowerof2(ll x){
    return (x && !(x & x-1));
}

void func(ll N, ll n, ll i, ll bits, ll *arr, ll &count){

	if(i == bits){
		if(n <= N && arr[n] == 1){
			arr[n] = 0;
			count--;
		}
		cout<<n<<" "<<count<<endl;
		return;
	}

	// check if last lsb bit is set 
	ll no = n>>i;
	if(no&1 && (n > N || arr[n] == 1)){
		ll n1 = n;
		n1 ^= 1<<i;
		if(n1 > N || arr[n1] == 1){
			func(N,n1,i+1,bits,arr,count);
		}
		if(n > N || arr[n] == 1){
			func(N,n,i+1,bits,arr,count);
		}
	}
	else{
		if(n > N || arr[n] == 1){
			func(N,n,i+1,bits,arr,count);
		}
	}
}

int main(){
 	
 	bool flagH = true;
 	bool flagY = true; 
	ll n;
	cin>>n;
	ll arr[1000000];
	for(ll i = 0; i < n; i++){
		cin>>arr[i];
		if(arr[i] != 1){
			flagH = false;
		}
	}

	ll q;
	cin>>q;

	ll actions[1000000][2];

	for(ll i = 0; i < q; i++){
		cin>>actions[i][0]>>actions[i][1];
		if(actions[i][1] != 1){
			flagY = false;
		}
	}

	if(flagH && flagY){
        //cout<<"jdfk";
		ll count = n;
		ll par = -1;
		for(ll x = 0; x < q; x++){
			if(par < actions[x][0]){
				ll X = setBits(actions[x][0]);
				if(isPowerof2(actions[x][0])){
					if(arr[0] == 1){
						arr[0] = 0;
						count--;
					}
					if(actions[x][0] <= n-1 && arr[actions[x][0]] == 1){
						arr[actions[x][0]] = 0;
						count--;
					}
				}
				else if(count > 0 && areAllBitsSet(actions[x][0])) {
					if(actions[x][0] >= n-1){
						count = 0;
					}
					else{
						for(){

						}
					}
					par = max(par,actions[x][0]);
				}
				else if(count > 0){
					ll bits = countBits(actions[x][0])-1;
					ll prev = actions[x][0];
					ll n1 = prev;
					while(prev >= n-1){
						n1 = prev;
						prev ^= 1<<bits;
						bits--;
					}
					//cout<<n1<<endl;
					bits = countBits(n1);
					func(n-1,n1,0,bits,arr,count);
				}
			}
			cout<<count<<endl;
		}

	}
	else{
		ll count = n;
		for(ll x = 0; x < q; x++){
			for(ll i = 0; i < n; i++){

				if(arr[i] > 0){
					ll no = i&actions[x][0];
					if(no == i){
						arr[i] -= actions[x][1];
					}

					if(arr[i] <= 0){
						count--;
					}
				}
				//cout<<arr[i]<<" ";
			}
			cout<<count<<endl;
		}
	}

	return 0;
}
*/
