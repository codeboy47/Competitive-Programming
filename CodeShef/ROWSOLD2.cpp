#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;


int main(){
	long long int t,i,j,k;
	long long int count,end,choose;
	//char str[1000000]; // this also works and gives 100 pts
	char *str = new char[1000000];
	scanf("%lld",&t);
	while(t--){
		count = 0;
		choose = 1;
		cin>>str;
		for(i = 0; str[i] != '\0';i++){ }
		end = i;
		long long int e = end;
		bool flag2 = true;
		for(i = e-1; i >=0;i--){
			if(str[i] == '1' && flag2 == true){
				end--;
			}else{
				flag2  = false;
			}
		}
		e = end;
		end--;

		for(i = e-1; i >= 0;i--){
			if(str[i] == '1'){
				count = count + end - i + choose;
				end--;
				if(i-1 >= 0 && str[i-1] != '1'){
					choose++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}