#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i = 0; i < m; i++){
			scanf("%d %d",&u,&v);
		}
		if(n%2 == 0){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}