#include <bits/stdc++.h>
using namespace std;

int totalChocolates(int *input1, int input1_size){


	priority_queue<int, vector<int> , greater<int> > minHeap;

	for(int i = 0; i < input1_size; i++){
		minHeap.push(input1[i]);
	}

	int sum = 0;
	int rem = 0;
	while(!minHeap.empty()){

		int top = minHeap.top();
		minHeap.pop();

		if(minHeap.empty()){
			if(top <= 1000){
				sum += top;
			}
		}

		else if(top <= 1000){
			rem = top - (top/2);
			sum += top/2;
			int topSecond = minHeap.top();
			minHeap.pop();
			topSecond += rem;
			if(topSecond <= 1000)
				minHeap.push(topSecond);
			rem = 0;
		}

	}

	return sum;

}


int main(){

 int t;
 cin>>t;
 while(t--){
	int arr[10000];
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout<<totalChocolates(arr,n)<<endl;
 }
 
 return 0;
 
}
