#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;


int main(){
	long t,i,j,k;
	long count,end;
	char str[1000000],prev = 'a';
	scanf("%ld",&t);
	while(t--){
		prev = 'a';
		count = 0;
		cin>>str;
		for(i = 0; str[i] != '\0';i++){ }
		end = i;
		long e = end;
		bool flag2 = true;
		for(i = e-1; i >=0;i--){
			if(str[i] == '1' && flag2 == true){
				end--;
			}else{
				flag2  = false;
			}
		}
		e = end;
		while(1){
			for(j = 0; j < end; j++){
				//cout<<" j3="<<j<<str<<" ";
				if(str[j] == '1' && str[j+1] == '1' && prev != '1'){
					// do nothing
				}
				else if(str[j] == '1' && prev == '1'){
					str[j-1] = '1';
					prev = 'a';
					//cout<<" count1="<<j<<" "<<str<<" ";
					break;
				}
				else if(str[j] == '1' && prev != '1'){
					str[j] = '0';
					prev = '1';
					count++;
				}
				else if(str[j] == '0' && prev == '1'){
					count++;
				}
			}
			if(j == end && prev != '1'){
				break;
			}
			else if(j == end && prev == '1'){
				str[j-1] = '1';
				end--;
				prev = 'a';
				//cout<<" count2="<<str<<endl;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}