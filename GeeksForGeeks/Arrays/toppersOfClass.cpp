#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;


void printToppers(int *arr ,int n, int k){

     priority_queue<int , vector<int> , greater<int> > pq;

     int i;
     unordered_map<int,vector<int>> hash;

     for( i = 0; i < k; i++){
		if(hash[arr[i]].size() == 0){
			pq.push(arr[i]);
		}else{
			k++;
		}
		hash[arr[i]].push_back(i);
     }


     for( ; i < n; i++){
          if(pq.top() <= arr[i]){
          	if(hash[arr[i]].size() == 0){
               	pq.pop();
               	pq.push(arr[i]);
          	}
            hash[arr[i]].push_back(i);
          }
     }

     stack<int> s;

     while(!pq.empty()){
		int top = pq.top();
		pq.pop();
		for(int i = hash[top].size()-1; i >= 0; i--){
			s.push(hash[top][i]);
		}
     }

     while(!s.empty()){
     	cout<<s.top()<<" ";
     	s.pop();
     }
     cout<<endl;

}

int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          int count = 0;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }
          int k;
          cin>>k;
          printToppers(arr,n,k);
     }

     return 0;
}
