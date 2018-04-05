#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool checkInfected(vector<long long int> &v,long long int j){
	for(int  i = 0;i<v.size();i++){
		if(v[i] == j){
			return true;
		}	
	}
	return false;
}
bool checkInfected2(vector<long long int> &arr,long long int l,long long int r,long long int x){
   if (r >= l){
        int mid = l + (r - l)/2;
 
        if (arr[mid] == x)  return true;
 
        if (arr[mid] > x) return checkInfected2(arr, l, mid-1, x);
 
        return checkInfected2(arr, mid+1, r, x);
   }
   return false;
}


int main(){
	long long int t,row,col,i,j,v,u,n,largest=-1000000,index= -1,checkCount = 0;
	vector<long long int> arr[1000000];//array of vectors somewhat like 2D array(2D array!=array of vectors)
	vector<long long int> pop;
	bool checking = false,check = false;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i = 0;i < n;i++){
			long long int c;
			scanf("%lld",&c);
			pop.push_back(c);
		}
		for(i = 0;i < n-1;i++){
			scanf("%lld %lld",&u,&v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(i = 1;i <= n;i++){
			for(j = 0;j < n;j++){
				//bool check = checkInfected2(arr[i],0,arr[i].size()-1,j+1);
				if(checking == false){
					check = checkInfected2(arr[i],0,arr[i].size()-1,j+1);
				}
				if(check == true){
					checkCount++;
				}
				if(checkCount >= arr[i].size()){
					checking = true;
				}
				if(j+1 != i && largest < pop[j] && check == false){
					largest = pop[j];
					index = j+1;
				}
				check = false;
			}
			arr[i].clear();
			printf("%lld ",index);
			index = -1;
			largest = -100000;
			checking = false;
			checkCount = 0;
		}
		/*for(i = 1;i <= n;i++){
			for(j = 0;j < arr[i].size();j++){
				printf("%lld ",arr[i][j]);
			}cout<<endl;
		}*/
		pop.clear();
		cout<<endl;
	}

	return 0;
}