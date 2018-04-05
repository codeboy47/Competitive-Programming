#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	bool flag = true;
	long long int i,j,L,R,k,N,count=0,sum = 0,largest=0,total=0;
	scanf("%lld %lld %lld",&N,&L,&R);
	vector<long long int> arr;
	vector<pair<long long int,long long int> > v;
	for(i = 0;i <N;i++){
		scanf("%lld",&k);
		arr.push_back(k);
	}
	//sort(arr,arr+N);
	sort(arr.begin(), arr.end());

	long long int temp = -100,sub,add,p=-100,s,e;
	
	for(i = 0;i < N-1;i++){
		sub = arr[i+1] - arr[i] + 1;
		add = arr[i+1] + arr[i] - 1;
		v.push_back(make_pair(sub,add));
	}
	sort(v.begin(), v.end());
	/*for (vector<pair<long long int,long long int>>::iterator it = v.begin() ; it != v.end(); ++it)
	    cout<<" "<<it->first<<" "<<it->second<<endl;
	*/

	for(i = 0;i < N-1;i++){ // consider L also
		s = v[i].first;
		e = v[i].second;
		
		if(L <= e && R >= s){	// R > s runs 3 test cases
			temp = s;
			s = max(L,max(s,p)); 
			
			if(e >= s){
					if(temp > p){
						count = count + min(R,e) - s + 1 ;
					}
					else count = count + min(R,e) - s  ;
								
			}

			p = min(R,max(s,e));
			//p = max(p,min(R,e));
			//p = max(p,e);
			
			if(p >= R){ // runs task 2
				break;
			} 
		} 
	}
	if(count!=0 || i < N)
	cout<< count;
	else
		cout<<0;
	return 0;
}


/*#include <bits/stdc++.h>
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

	long long int prevAdd = -100,sub,add,prevSub=-100,prevAns = -1,condition=-1;
	for(i = 0;i < N-1;i++){
		sub = arr[i+1] - arr[i] + 1;
		add = arr[i+1] + arr[i] - 1;

		if(L > add && R > add){ // cond 1
			count = count + 0;
		}
		else if(R < sub && L < sub){  // cond 2
			count = count + 0;
		}
		else if(L <= sub && add >= R ){	// cond 3 : L sub R add
			if(prevAdd > sub &&  sub > prevSub){
				//count = abs(sub - prevSub);
				if(condition == 5){
					count = count - (prevAns - sub);
				}
				else count = count - (prevAdd - sub -1);
			}
			if(prevAdd > sub && prevSub >= sub){
				//count = count - prevAns;
				count = 0;
			}
			if(R == add){
				count = count + R - sub -1;
				prevAns = R - sub -1;
				prevAdd = R - 1;
				prevSub = sub;
				condition = 3;
			}
			if(R < add){
				count = count + R - sub ; 
				prevAdd = R; // if pA = add last 2 cases will not work
				prevSub = sub;
				prevAns = R - sub;
				condition = 3;
			}
		}

		else if(L <= sub && add <= R){	// cond 4 : L sub add R 
			if(prevAdd > sub && prevSub < sub){
				//count = abs(sub - prevSub);
				count = count - (prevAdd - sub -1);
			}
			else if(prevAdd > sub && prevSub >= sub){
				count = 0;
				//count = count - prevAns;
			}
			count = count + add - sub - 1;
			prevAdd = add;
			prevSub = sub;
			condition = 4;
			prevAns = add - sub - 1;
		}

		else if(L >= sub && add >= R){ // cond 5 : sub L  R add
			if(prevAdd > sub && prevSub < sub){
				count = count - (prevAdd - sub -1);
				//count = 0;
			}
			else if(prevAdd > sub && prevSub >= sub){
				count = 0;
				//count = count - prevAns;
			}
			if(L == R){
				count = 1;
				break;
			}
			count = count + R - L + 1;
			prevAdd = R;
			prevSub = L;
			prevAns = R - L + 1;
			condition = 5;
		}

		else if(L >= sub && add <= R ){ // 6 : sub L add R
			if(prevAdd > sub && prevSub < sub){
				//count = abs(sub - prevSub);
				count = count - (prevAdd - sub -1);
			}
			if(prevAdd > sub && prevSub >= sub){
				count = 0;
				//count = count - prevAns;
			}
			count = count + add - L;
			prevAdd = add;
			prevSub = L; // this thing is very important runs 4 test cases right
			prevAns = add - L;
			condition = 6;
		}

	}

	printf("%lld",count);
	return 0;
}
*/