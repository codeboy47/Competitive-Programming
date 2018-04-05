#include <bits/stdc++.h>
#include <queue>
#define pq priority_queue< int, vector<int> , greater<int> >
using namespace std;

void findMedian(priority_queue<int>&maxHeap, pq&minHeap, int data){

		if(maxHeap.empty() || maxHeap.top() > data){
			maxHeap.push(data);
			if(maxHeap.size()-minHeap.size() > 1){
				int top = maxHeap.top();
				maxHeap.pop();
				minHeap.push(top);
			}
		}
		else{
			minHeap.push(data);
			if(minHeap.size()-maxHeap.size() > 1){
				int top = minHeap.top();
				minHeap.pop();
				maxHeap.push(top);
			}
		}

}

int printMedian(priority_queue<int>&maxHeap, pq&minHeap){

	if(minHeap.size() == maxHeap.size()){
		if(minHeap.top() < maxHeap.top()){
			int top = minHeap.top();
			minHeap.pop();
			return top;
		}
		if(minHeap.top() > maxHeap.top()){
			int top = maxHeap.top();
			maxHeap.pop();
			return top;
		}
	}
	if(minHeap.size() > maxHeap.size()){
		int top = minHeap.top();
		minHeap.pop();
		return top;
	}
	if(maxHeap.size() > minHeap.size()){
		int top = maxHeap.top();
		maxHeap.pop();
		return top;
	}

}

int main(){

	priority_queue< int, vector<int> , greater<int> > minHeap;
	priority_queue<int> maxHeap;

	int d;
	while(scanf("%d", &d) != EOF){

		if(d == 0){

			while(!minHeap.empty()){
				minHeap.pop();
			}
			while(!maxHeap.empty()){
				maxHeap.pop();
			}
			printf("\n");
		}

		else if(d == -1){
			if(!minHeap.empty() || !maxHeap.empty()){
				int median = printMedian(maxHeap, minHeap);
				printf("%d\n", median);
			}
		}

		else{
			findMedian(maxHeap, minHeap, d);
		}
	}

	return 0;
}
