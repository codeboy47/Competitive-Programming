#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



// time complexity is O(n^2)
// not work for duplicates
float findMedian(int *arr, int n){

     int a,b;
     for(int i = 0; i < n; i++){

          int large = 0, small = 0;
          for(int j = 0; j < n; j++){

               if(arr[i] > arr[j]){
                    small++;
               }
               if(arr[i] < arr[j]){
                    large++;
               }
          }

          if(n&1 && large == n/2 && small == n/2){
               return arr[i];
          }
          if(large == n/2-1 && small == n/2){
               a = arr[i];
          }
          if(large == n/2 && small == n/2-1){
               b = arr[i];
          }

     }

     return (float)(a+b)/2;
}

// time complexity is O(nlogn)
float findMedianUsingSorting(int *arr, int n){

     sort(arr,arr+n);

     if(n&1){
          return arr[n/2];
     }
     else{
          return (float)(arr[n/2] + arr[n/2-1]) / 2;
     }
}


// time complexity is O(k + (n-k)logK)
float findKthLargestElementInArray(int *arr, int n){

     priority_queue<int, vector<int> , greater<int> > minHeap;

     int k = (n/2) + 1;

     int i;
     for(i = 0; i < k; i++){
          minHeap.push(arr[i]);
     }

     for(; i < n; i++){
          if(arr[i] > minHeap.top()){
               minHeap.pop();
               minHeap.push(arr[i]);
          }
     }

     if(n&1){
          return minHeap.top();
     }else{
          int a = minHeap.top();
          minHeap.pop();
          int b = minHeap.top();
          return (float)(a+b)/2;
     }

}

int partition(int *arr, int start, int end){

     int &pivot = arr[end];
     int pivotIndex = start;
     for(int i = start; i < end; i++){
          if(arr[i] < pivot){
               swap(arr[i],arr[pivotIndex]);
               pivotIndex++;
          }
     }
     swap(arr[pivotIndex],pivot);
     return pivotIndex;
}

// works if n is odd
float findMedianUsingQuickSelect(int *arr, int start, int end, int n){

     if(start <= end){

          int pivotIndex = partition(arr,start,end);
          if(pivotIndex == n/2){
               return arr[pivotIndex];
          }
          else if(pivotIndex < n/2){
               return findMedianUsingQuickSelect(arr,pivotIndex+1,end,n);
          }
          else{
               return findMedianUsingQuickSelect(arr,start,pivotIndex-1,n);
          }
     }


}

int main(){

     int n;
     cin>>n;  // n = 7
     int arr[100000];  // arr = {1, 23, 12, 9, 30, 2, 50}
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     cout<<findMedian(arr,n)<<endl; //  ans is 12
     cout<<findMedianUsingSorting(arr,n)<<endl;
     cout<<findKthLargestElementInArray(arr,n)<<endl;
     cout<<findMedianUsingQuickSelect(arr,0,n-1,n)<<endl;

     return 0;
}
