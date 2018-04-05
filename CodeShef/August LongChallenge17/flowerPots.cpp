#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll findMinStrength(ll *arr, ll n, ll sec, ll cost, ll i){

     ll ans = INT_MAX;

     if(sec == 1){
          return (cost + (arr[n-1] - arr[i])*(arr[n-1] - arr[i]));
     }

	ll prevCost = cost;
     //ll i = 0,seconds = b;
     for(ll j = i+1; j <= n-sec; j++){
          cost += (arr[i] - arr[j])*(arr[i] - arr[j]);
          ll x = findMinStrength(arr,n,sec-1,cost,j);
          ans = min(ans,x);
          cost = prevCost;
         // cout<<ans<<" "<<x<<endl;
     }

     return ans;

}


ll findMinStrengthBinarySearch(ll *arr, ll n, ll b){
     ll s = 0, e = n-1;
     ll sec = b;
     ll cost = 0;
     while(s < e){
          ll mid = (s+e)/2;
          if((s+e)%2 != 0){
               mid = mid + 1;
          }
          if(n-mid < sec){
               e = mid;
               continue;
          }
          if(b >= n){
				b--;
			}
          sec--;
          cost += (arr[mid] - arr[s])*(arr[mid] - arr[s]);
          if(sec == 1){
               cost += (arr[n-1] - arr[mid])*(arr[n-1] - arr[mid]);
               break;
          }
          s = mid;
          if(s >= e){
               e = n-1;
          }
     }

     return cost;
}


int main(){

     int t;
     scanf("%d", &t);
     ll arr[1000000];
     while(t--){

          ll n,b,c;
          scanf("%lld %lld %lld",&n,&b,&c);
          for(ll i = 0; i < n; i++){
               scanf("%lld", &arr[i]);
          }

		if(b >= n-1){
               ll cost = 0;
               for(ll i = 1; i < n; i++){
                    cost += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]);
               }
               cout<<cost<<endl;
          }
          else
          cout<<findMinStrength(arr,n,b,0,0)<<endl;
          //else
          //cout<<findMinStrengthBinarySearch(arr,n,b)<<endl;

     }

     return 0;
}
