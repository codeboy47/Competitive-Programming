#include <bits/stdc++.h>
#include<vector>
using namespace std;
 
int main(){
	vector<long int> arr,brr;
	bool flag = true;
	long int T,N,i;
	scanf("%ld %ld",&T,&N);
	i = 0;
	while(i < N){
		long int c,d;
		scanf("%ld %ld",&c,&d);
		arr.push_back(c);
		brr.push_back(d);
		i++;
	}
	if(flag == true){
		i = 0;
		while(i<T){
			cout<<0<<endl;
			i++;
		}
	}
	flag = false;
	return 0;
} 