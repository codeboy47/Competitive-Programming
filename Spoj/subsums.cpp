#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long int

// ### Bitmasking + STL + Binary search (Spoj - http://www.spoj.com/problems/SUBSUMS/ )

// bitmasking
vector<ll> subsetSums(vector<ll> v){

	vector<ll> ans;
	ll n = v.size();

	for(ll i = 1; i < (1<<n); i++){

		ll temp = i;
		ll sum = 0;
		ll pos = 0;
		while(temp){
			if(temp&1){
				sum += v[pos];
			}
			temp >>= 1;
			pos++;
		}
		ans.push_back(sum);
	}

	return ans;
}


int main(){

	ll n, a, b;
	cin>>n>>a>>b;

	ll n1 = n/2; // first set
	ll n2 = n - n1; // second set

	vector<ll> v1, v2;

	for(ll i = 0; i < n1; i++){
		ll d;
		cin>>d;
		v1.push_back(d);
	}

	for(ll i = 0; i < n2; i++){
		ll d;
		cin>>d;
		v2.push_back(d);
	}


	vector<ll> ss1 = subsetSums(v1); // subset sum 1
	vector<ll> ss2 = subsetSums(v2); // subset sum 2

   	//sort(ss1.begin(),ss1.end());
	sort(ss2.begin(),ss2.end());

	/*for(ll i = 0; i < ss1.size(); i++){
        cout<<ss1[i]<<" ";
    }
    cout<<endl;
    for(ll i = 0; i < ss2.size(); i++){
        cout<<ss2[i]<<" ";
    }
    cout<<endl;
	*/

	ll ans = 0;
	for(ll i = 0; i < ss1.size(); i++){

		ll new_a = a - ss1[i];
		ll new_b = b - ss1[i];

		auto it1 = lower_bound(ss2.begin(), ss2.end(), new_a);
		auto it2 = upper_bound(ss2.begin(), ss2.end(), new_b);

		ll s = it1 - ss2.begin();
		ll e = it2 - ss2.begin();

		ans += (e - s);
	}

	// including subset sums from 1st set
	for(ll i = 0; i < ss1.size(); i++){
		if(a <= ss1[i] && ss1[i] <= b){
			ans++;
		}
	}

	// including subset sums from 2nd set
        for(ll i = 0; i < ss2.size(); i++){
                if(a <= ss2[i] && ss2[i] <= b){
                        ans++;
                }
        }

	// also including empty set if it lies in give range(a,b)
	if(a <= 0 && 0 <= b){
		ans++;
	}

	cout<<ans<<endl;

	return 0;
}
