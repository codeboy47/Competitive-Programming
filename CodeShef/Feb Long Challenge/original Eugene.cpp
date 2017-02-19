#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;


int main(){
	long long int T,A,N,M,i,j;
	const long long int c = 1e9+7;
	scanf("%lld",&T);
	for(i = 0;i < T;i++){
		scanf("%lld %lld %lld",&A,&N,&M);
		long long int a = A;
		long long int count = 1;
		while(a!=0){
			count = count*10;
			a = a/10;
		}
		long long int original = A;
		mp::cpp_int X = A;
		for(j = 0;j < N-1;j++){
			//A = A*2 + original;
			X = (X*count) + A;
		}
		cout<<X%M<<endl;
		//printf("%lld\n",X%M);
	}
	return 0;
} 

/*. run time error
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string>
#include<cmath>
using namespace std;


int main(){
	long long int T,A,N,M,X,i,j=0;
	string str,copy;
	scanf("%lld",&T);
	for(i = 0;i < T;i++){
		scanf("%lld %lld %lld",&A,&N,&M);
		str = to_string(A);
		copy = str;
		j = 0;
		while(j<N-1){
			//str += str;
			str.append(copy);
			X = stoll(str)%c;
			str = to_string(X);
			j++;
		}
		X = stoll(str);
		printf("%lld\n",X%M);
	}
	return 0;
}
*/