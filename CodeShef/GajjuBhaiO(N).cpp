// here we store distances of places in array arr[]
#include<bits/stdc++.h>
using namespace std;

int main(){
	long int t,i,arr[1000000],u,v,sum = 0;
	scanf("%ld",&t);
	while(t--){
		long int n,m;
		scanf("%ld %ld",&n,&m);
		arr[1] = 0;
		for(i = 0;i < n-1;i++){
			scanf("%ld %ld",&u,&v);
			arr[v] = arr[u] + 1; // value of distance of child arr[v] is distance of parent arr[u] + 1
		}
		for(int i = 0;i< m;i++){
			long int k; // we want to know distance of k
			scanf("%ld",&k);
			sum = sum + arr[k];
		}
		// implicit type casting
		printf("%.6lf\n",(sum*2.0)/m);	// to print upto six decimal places
		sum = 0; // the most important thing
	}
	return 0;
}