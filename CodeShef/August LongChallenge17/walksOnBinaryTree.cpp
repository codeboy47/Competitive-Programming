#include <bits/stdc++.h>
typedef long long int ll;
ll p = 1000000007;
#include <string.h>
#include <vector>
using namespace std;


ll modularExponentiation(ll a, ll b){
	if(b == 0){
		return 1;
	}
	ll y = modularExponentiation(a,b/2);
	y = (y*y)%p;
	if(b&1){
		return (a*y)%p;
	}
	else{
		return y;
	}
}


void changeX(ll *arr, ll n, ll &x, ll c, ll &count){

     vector<ll> v;
     ll a = modularExponentiation(2,c);
	ll b = modularExponentiation(2,n);
	x = (x + a)%(b);
     ll decNo = x;
     while(decNo>0){
          v.push_back(decNo%2);
          decNo=decNo/2;
     }

     while(v.size() < n){
          v.push_back(0);
     }

     if(arr[1] == 0){
          arr[1] = 1;
          count++;
     }

     ll index = 1;
     for(ll i = v.size()-1; i >= 0; i--){
           if(v[i] == 1){
               index = 2*index + 1;
          }
          if(v[i] == 0){
               index = 2*index;
          }
          if(arr[index] == 0){
                 arr[index] = 1;
               count++;
          }
     }

}

void printNoOfNodes(ll v){
     cout<<v<<endl;
}

int main(){

     ll t;
     scanf("%lld",&t);

     for(ll a = 0; a < t; a++){

          ll n,q;
          ll visitCount = 0;
          ll x = 0;
          scanf("%lld %lld",&n,&q);
          ll z = modularExponentiation(2,n+1);
          ll arr[z];
          memset(arr,0,sizeof(arr));

          for(int i = 0; i < q; i++){
               char ch;
               cin>>ch;
               //scanf("%c", ch);
               if(ch == '!'){
                    ll c;
                    scanf("%lld", &c);
                    changeX(arr,n,x,c,visitCount);
               }
               else if(ch == '?'){
                    printNoOfNodes(visitCount);
               }
          }

     }

     return 0;
}
