#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int ipow(mp::cpp_int base, mp::cpp_int exp)
{
    mp::cpp_int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}
mp::cpp_int power(mp::cpp_int x, mp::cpp_int y)
{
    mp::cpp_int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main(){
	int T;
	long long int M;
	mp::cpp_int X,A,N,a,count;
	scanf("%d",&T);
	while(T--){
		cin>>A>>N>>M;
		//scanf("%lld %lld %lld",&A,&N,&M);
		a = A;
		count = 1;
		while(a!=0){
			count = count*10;
			a = a/10;
		}
		X = A*power(count,N-1);
		A = X/count;
		while(A>0){
			X = X+A;
			A = A/count;
		}
		cout<<X<<" "<<X%M<<endl;
		//printf("%lld\n",X%M);
	}
	return 0;
} 
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

long long int ipow(long long int base, long long int exp)
{
    long long int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}
int main(){
	int T;
	long long int A,N,M,a,i,j,count,X;
	//mp::cpp_int X;//T,A,N,M,i,j,a,count;
	//const long long int c = 1e9+7;
	//cin>>T;
	scanf("%d",&T);
	while(T--){
	//for(i = 0;i < T;i++){
		//cin>>A>>N>>M;
		scanf("%lld %lld %lld",&A,&N,&M);
		a = A;
		count = 1;
		while(a!=0){
			count = count*10;
			a = a/10;
		}
		X = A*ipow(count,N-1);
		A = X/count;
		while(A>0){
			X = X+A;
			A = A/count;
		}
		cout<<X<<" "<<X%M<<endl;
		//printf("%lld\n",X%M);
	}
	return 0;
} 

*/
