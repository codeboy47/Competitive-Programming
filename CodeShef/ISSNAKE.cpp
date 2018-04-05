#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t,n;
	char ch;
	vector<char> arr[2];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				cin>>ch;
				arr[i].push_back(ch);
			}
		}
		int i = 0, j =0,row,col;
		bool up = true,down = true;
		// finding starting position of snake
		for(int a = 0; a < n; a++){
		    if(arr[1][a] == '#' && arr[0][a] == '#'){
				j = a;
				for(int b = a; b < n; b++){
					if(arr[0][b] == '.'){
						row = 0;
						col = b;
						break;
					}
					else if(arr[1][b] == '.'){
						row = 1;
						col = b;
						break;
					}
				}
				if((col - a)%2 == 1 && row == 1){
					i = 1;
				}
				else if((col - a)%2 == 0 && row == 0){
					i = 1;
				}
				else if((col - a)%2 == 1 && row == 0){
					i = 0;
				}
				else if((col - a)%2 == 0 && row == 1){
					i = 0;
				}
				break;
			}
			else if(arr[1][a] == '#'){
				i = 1;
				j = a;
				break;
			}
			else if(arr[0][a] == '#'){
				i = 0;
				j = a;
				break;
			}
		}
		
		while(1){
			if(down == true && i == 0 && j < n && arr[i+1][j] == '#'){
				up = false;
				arr[i][j] = '.';
				i++;
			}
			else if(down == true && i == 0 && j < n-1 && arr[i][j+1] == '#'){
				arr[i][j] = '.';
				j++;
			}
 
			else if(up == false && i >= 0 && i < 2 && j < n-1 && arr[i][j+1] == '#'){ // arr[i-1][j] == '.'
				up = true;
				arr[i][j] = '.';
				j++;
			}
 
			else if(up == true && i == 1 && j < n && arr[i-1][j] == '#'){ 
				down = false;
				arr[i][j] = '.';
				i--;
			}
			else if(up == true && i == 1 && j < n-1 && arr[i][j+1] == '#'){
				arr[i][j] = '.';
				j++;
			}
 
			else if(down == false && i >= 0 && i < 2 && j < n-1 && arr[i][j+1] == '#'){ 
				down = true;
				arr[i][j] = '.';
				j++;
			}
 
			else{
			    if(i >= 0 && i < 2 && j < n)
			        arr[i][j] = '.';
				break;
			}
		}
		bool flag = true;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				if(arr[i][j] == '#'){
					printf("no\n");
					flag = false;
					break;
				}
			}
			if(flag == false){
				break;
			}
		}
		if(flag == true){
			printf("yes\n");
		}
		/*for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}*/
		for(int i = 0; i < 2; i++){
			arr[i].clear();
		}
	}
	return 0;
} 