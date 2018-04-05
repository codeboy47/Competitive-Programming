#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;
 
class pairG{
public:
	int a;
	int b;
	pairG(int x,int y) : a(x) , b(y) { }
};
 
int main(){
	int t,i,j;
	vector<pairG> arr;
	vector<int> v;
	scanf("%d",&t);
	while(t--){
		int l , n;
		scanf("%d %d",&l,&n);
		char str[l];
		char grid[n][n];
		cin>>str;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				cin>>grid[i][j];
				if(grid[i][j] == '.'){
					pairG g(i,j);
					arr.push_back(g);
				}
			}
		}
		/*for(i = 0; i < arr.size(); i++){
			cout<<arr[i].a<<" "<<arr[i].b;
			cout<<endl;
		}*/
		int x,y;
		int count = 0;
		for(i = 0;i < arr.size();i++){
			count = 0;
			x = arr[i].a;
			y = arr[i].b;
			for(j = 0; str[j] != '\0'; j++){
				if(str[j] == 'D'){
					x = x + 1;
					y = y + 0;
					if(grid[x][y] == '#' || x >= n ){
						break;
					}else{
						count++;
					}
				}
				else if(str[j] == 'U'){
					x = x - 1;
					y = y;
					if(grid[x][y] == '#' || x <= -1 ){
						break;
					}else{
						count++;
					}
				}
				else if(str[j] == 'L'){
					x = x;
					y = y - 1;
					if(grid[x][y] == '#' || y <= -1 ){
						break;
					}else{
						count++;
					}
				}
				else if(str[j] == 'R'){
					x = x;
					y = y + 1;
					if(grid[x][y] == '#' || y >= n ){
						break;
					}else{
						count++;
					}
				}
			}
			if(count != 0)
				v.push_back(count);
			count = 0;
		}

		//int prev,curr = -1,ans=0;
		//bool flag = true;

		if(v.empty()){	// if moves is zero so array is empty
			cout<<0<<endl;
		}
		else if(v.size() == 1){		// if it makes moves but only for one position
			cout<<v[0]<<endl;
		}
		else{ 	// general case 
			for(i = 1; i < v.size(); i++){
				//cout<<v[i]<<" ";
				v[i] = v[i]^v[i-1];
			}
			/*for(i = 0; i < v.size(); i++){
					prev = curr;
					curr = v[i];
					if(prev != -1){
						if(flag == true){
							flag = false;
							ans = prev^curr;
						}else{
							ans = ans^curr;
						}
					}
			}*/
			printf("%d\n",v[i-1]);
		}
		arr.clear();
		v.clear();
		/*for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				cout<<grid[i][j];
			}
			cout<<endl;
		}*/
	}
	return 0;
} 