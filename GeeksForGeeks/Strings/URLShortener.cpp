#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*
Convert from decimal to base :
Let the given input decimal number be “inputNum” and target base be base(62) 
We repeatedly divide inputNum by base and store the remainder. We finally reverse the obtained string.
*/

void urlShortener(ll n, char *map){

	string res = "";

	while(n!=0){

		int rem = n%62;
		res = map[rem] + res;
		n /= 62;
	}

	cout<<res<<endl;
}

int main(){

    int t;
    ll n;
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cin>>t;
    while(t--){
    
        cin>>n;
        urlShortener(n,map);
        cout<<n<<endl;

    }

    return 0;
}