#include <iostream>
#include <queue>
using namespace std;

int findMedian(int *arr, int n){

	int median;
	priority_queue< int, vector<int> , greater<int> > minHeap;
	priority_queue<int> maxHeap;

	for(int i = 0; i <= n; i++){

		if(maxHeap.empty() || maxHeap.top() > arr[i]){
			maxHeap.push(arr[i]);
			if(maxHeap.size()-minHeap.size() > 1){
				int top = maxHeap.top();
				maxHeap.pop();
				minHeap.push(top);
			}
		}
		else{
			minHeap.push(arr[i]);
			if(minHeap.size()-maxHeap.size() > 1){
				int top = minHeap.top();
				minHeap.pop();
				maxHeap.push(top);
			}
		}

	}

	if(minHeap.size() == maxHeap.size()){
		return (minHeap.top() + maxHeap.top())/ 2;
	}
	if(minHeap.size() > maxHeap.size()){
		return minHeap.top();
	}
	if(maxHeap.size() > minHeap.size()){
		return maxHeap.top();
	}

}

void printMedian(int *arr, int n){

	int median;

	for(int i = 0; i < n; i++){
		cout<<findMedian(arr,i)<<endl;
	}

}

int main(){

	int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int size = sizeof(arr)/sizeof(arr[0]);

	printMedian(arr,size);

	return 0;
}
