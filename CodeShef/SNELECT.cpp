#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	vector<char> arr;
	char str[1000];
	scanf("%d",&t);
	while(t--){
		cin>>str;
		for(int i = 0; str[i] != '\0';i++){
			if(str[i] == 'm'){
				if(i != 0 && str[i-1] == 's'){
					str[i-1] = '*';
				}
				else if(str[i+1] == 's'){
					str[i+1] = '*';
				}
			}
		}
		int scount = 0, mcount = 0;
		for(int i = 0; str[i] != '\0';i++){
			if(str[i] == 's'){
				scount++;
			}
			if(str[i] == 'm'){
				mcount++;
			}
		}
		if(mcount > scount){
			printf("mongooses\n");
		}
		else if(scount > mcount){
			printf("snakes\n");
		}
		else{
			printf("tie\n");
		}
	}
	return 0;
}