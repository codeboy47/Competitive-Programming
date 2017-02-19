#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int t,row,col,i,j;
	bool flag = true;
	char str[10000][10000];
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&row,&col);
		for(i = 0;i <row ;i++){
			for(j = 0;j < col;j++){
				cin>>str[i][j];
			}
		}
		for(i = 0;i <row ;i++){
			for(j = 0;j < col;j++){
				if(str[i][j] == 'W'){
					if(str[i][0] == 'W' || str[i][col-1] == 'W'){
						flag = false;
						break;
					}else if(str[i][j+1] == 'A' || str[i][j+1] == 'A' ){
						flag = false;
						break;				
					}else if(str[i+1][j] == 'A'){ // if air is below water 
						flag = false;
						break;
					}
				}else if(str[i][j] == 'B' && i!=row-1){
					if(str[i+1][j] == 'A'){ // if air is below brick 
						//cout<<str[i][j];
						flag = false;
						break;
					}else if(str[i+1][j] == 'W'){	// if air is below brick
						flag = false;
						break;
					}
				}	
			}
			if(flag == false){
				break;
			}
		}
		if(flag == true) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		flag = true;
		/*for(i = 0;i <row ;i++){
			for(j = 0;j < col;j++){
				cout<<str[i][j];
			}cout<<endl;
		}*/
	}
	return 0;
}