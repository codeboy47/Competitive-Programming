#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

// we can also find median in this way also i.e. k = n/2(odd) k = n/2(even)

// we can sort and then find kth largest/smallest element - O(nlogn)

// time complexity is O(k + (n-k)logK)
int findKthSmallestElementInArray(int *arr, int n, int k){

     priority_queue<int> maxHeap;

     int i;
     for(i = 0; i < k; i++){
          maxHeap.push(arr[i]);
     }

     for(; i < n; i++){
          if(arr[i] < maxHeap.top()){
               maxHeap.pop();
               maxHeap.push(arr[i]);
          }
     }

     return maxHeap.top();

}

int partition(int *arr, int start, int end){

     int &pivot = arr[end];
     int pivotIndex = start;
     for(int i = start; i < end; i++){
          if(arr[i] <= pivot){
               swap(arr[i],arr[pivotIndex]);
               pivotIndex++;
          }
     }
     swap(arr[pivotIndex],pivot);
     return pivotIndex;
}

// worst case complexity is O(N^2)
int findKthSmallestElementUsingQuickselect(int *arr, int start, int end, int k){

     if(start <= end){

          int pivotIndex = partition(arr,start,end);
          if(pivotIndex == k-1){
               return arr[pivotIndex];
          }
          else if(pivotIndex < k){
               return findKthSmallestElementUsingQuickselect(arr,pivotIndex+1,end,k);
          }
          else{
               return findKthSmallestElementUsingQuickselect(arr,start,pivotIndex-1,k);
          }
     }
     return -1;
}

// not work for duplicates for that use priority_queue
int findKthLargestElementInArray(int *arr, int n, int k){

     set<int> minHeap;

     int i;
     for(i = 0; i < k; i++){
          minHeap.insert(arr[i]);
     }

     for(; i < n; i++){
          if(arr[i] > *(minHeap.begin())){
               minHeap.erase(minHeap.begin());
               minHeap.insert(arr[i]);
          }
     }

     return *(minHeap.begin());


}


int main(){

     int n,k;
     cin>>n>>k; // n = 6 and k = 3
     int arr[100000]; // arr[] = {7, 10, 4, 3, 20, 15}
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     cout<<findKthSmallestElementInArray(arr,n,k)<<endl;  // ans is 7
     cout<<findKthSmallestElementUsingQuickselect(arr,0,n-1,k)<<endl; // ans is 7
     cout<<findKthLargestElementInArray(arr,n,k)<<endl;  // ans is 10

     return 0;
}
