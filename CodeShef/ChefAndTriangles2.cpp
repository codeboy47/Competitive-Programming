#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<set>
using namespace std;

int main(){
	bool flag = true;
	long long int i,j,L,R,k,N,count=0,sum = 0,largest=0,total=0;
	scanf("%lld %lld %lld",&N,&L,&R);
	vector<long long int> arr;
	for(i = 0;i <N;i++){
		scanf("%lld",&k);
		arr.push_back(k);
	}
	//sort(arr,arr+N);
	sort(arr.begin(), arr.end());
	if(N <= 1000){
	for(i = L;i <= R;i++){
		//for( j = N-2;j >= 0;j--){
		for( j = 0;j < N-1;j++){
			if(i+arr[j] > arr[j+1] && i+arr[j+1] > arr[j] && arr[j]+arr[j+1] > i){
				count++;
				break;
				//flag = false;
			}

		}		
	}}else{
	long long int prevAdd = -100,sub,add,prevSub=-100;
	for(i = 0;i < N-1;i++){
		sub = arr[i+1] - arr[i];
		add = arr[i+1] + arr[i];
		/*if(prevAdd > sub){
			count = count - (prevAdd - currSub);
		} */
		//count = count + add - sub;
		if(L > sub && L > add){ // optional
			count = count + 0;
		}
		else if(R < sub && R < add){  // optional
			count = count + 0;
		}
		else if(L <= sub && add <= R){  // 4
			if(prevAdd > sub && prevSub < sub){
				//count = abs(sub - prevSub);
				count = count - (prevAdd - sub -1);
			}
			else if(prevAdd > sub && prevSub >= sub){
				count = 0;
			}
			count = count + add - sub - 1;
			prevAdd = add;
			prevSub = sub;
		}
		else if(L >= sub && add <= R && add > L){ // 6
			/*if(prevAdd > sub && prevSub < sub){
				count = abs(sub - prevSub);
				//count = count - (prevAdd - L -1);
			}*/
			if(prevAdd > L && prevSub >= L){
				count = 0;
			}
			count = count + add - L;
			prevAdd = add;
			prevSub = L; // this thing is very important runs 4 test cases right
		}
		else if(L <= sub && add >= R){ // 3
			if(prevAdd > sub && prevSub < sub){
				count = abs(sub - prevSub);
				//count = count - (prevAdd - sub -1);
			}else if(prevAdd > sub && prevSub >= sub){
				count = 0;
			}
			count = count + R - sub ; // -1
			//break;
			prevAdd = R; // if pA = add last 2 cases will not work
			prevSub = sub;
		}
		else if(L >= sub && add >= R){ // make test cases for this interval // 5
			if(prevAdd > L && prevSub >= L){
				count = 0;
			}
			if(L == R){
				count = 1;
				break;
			}
			count = count + R - L + 1;
			//break;
			prevAdd = R;//R;
			prevSub = L;//L;
		}
		

	}
	}
	printf("%lld",count);
	return 0;
}