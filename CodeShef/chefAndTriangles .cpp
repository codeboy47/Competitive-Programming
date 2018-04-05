#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
#include <bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

int main(){
	vector<long long int> arr;
	//vector<mp::cpp_int> arr;
	long long int i,j,L,R,k,N,count=0;
	//mp::cpp_int i,j,L,R,k,N,count=0;
	scanf("%lld %lld %lld",&N,&L,&R);

	for(i = 0;i <N;i++){
		scanf("%lld",&k);
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());

	//for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	for(i = L;i <= R;i++){
		for( j = 0;j < N-1;j++){
			if(i+arr[j] > arr[j+1] && i+arr[j+1] > arr[j] && arr[j]+arr[j+1] > i){
				count++;
				break;
				//flag = false;
			}

		}		
	}
	
	printf("%lld",count);
	
}
