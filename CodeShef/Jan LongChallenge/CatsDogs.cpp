#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int C,D,L,T,remLegs=0,catsPossible;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld %lld %lld",&C,&D,&L);
		remLegs = L - (D*4);
		catsPossible = remLegs/4;
		if(L%4 != 0){ // odd legs
			printf("no\n");
		}
		else if(L == 0 && C == 0 && D == 0){
			printf("yes\n");
		}
		else if(L < 4 && (C >=1 || D >= 1)){
			printf("no\n");
		}
		else if(remLegs < 0){
			cout<<"no"<<endl;
		}
		else if(C >= catsPossible && C <= catsPossible + (D*2)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}

	}
	return 0;
}
/* TeST CASES
15
4 4 32
16 6 37
4 5 36
1 1 2
1 0 2
0 0 1
0 0 0
0 0 3
0 1 2
5 4 12
0 0 10
0 8 32
8 0 32
3 5 30
14 5 32
*/