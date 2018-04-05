#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;
 
int main(){
	int r,l;
	char str[1000],prev;
	scanf("%d",&r);
	while(r--){
		bool flag = true,ans = true;
		scanf("%d",&l);
		cin>>str;
		for(int i = 0;i < l;i++){
			if(flag == true && str[i] == 'T'){ // if 1st element is T not H
				printf("Invalid\n");
				ans = false;
				break;
			}
			else if(flag == true && str[i] == 'H'){
				flag = false;
				prev = 'H';
				continue;
			}
			else if(prev == 'H' && str[i] == 'T'){
				prev = 'T';
				continue;
			}
			else if(prev == 'T' && str[i] == 'H'){
				prev = 'H';
				continue;
			}
			else if(prev == 'H' && str[i] == 'H'){
				printf("Invalid\n");
				ans = false;
				break;
			}
			else if(prev == 'T' && str[i] == 'T'){
				printf("Invalid\n");
				ans = false;
				break;
			}

		}
		if(ans == true && prev == 'H'){
			printf("Invalid\n");
		}
		else if(ans == true){
			printf("Valid\n");
		}
	}
	return 0;
}