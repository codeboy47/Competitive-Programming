#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	int T,N,count= 0,data,flag = true,index;
	vector<int> v;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		scanf("%d",&N);
		for(int j = 0;j < N;j++){
			scanf("%d",&data);
			v.push_back(data);
		}
		for(int j = 0;j < N;j++){
			if(flag == true && v[j] == 0){
				flag = false;
				index = j;
			}
			if(v[j] == 0){
				count++;
			}
		}
		if(count == 0)
		printf("0\n");
		else
		printf("%d\n",(count*1000)+(100*(N-index)));
		count = 0;
		//total = 0;
		index = 0;
		flag = true;
		v.clear();
	}
	return 0;
}