#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

bool isHeap(int arr[], int i, int n){

     // If a leaf node
     if (i > (n - 2)/2){
          return true;
     }

     if ((2*i+1 >= n || arr[i] >= arr[2*i + 1]) && (2*i+2 >=n || arr[i] >= arr[2*i + 2]) &&
	isHeap(arr, 2*i + 1, n) && isHeap(arr, 2*i + 2, n))
	    return true;

     return false;
}

bool isMaxHeap(int *arr ,int i, int n){

    if(i >= n){
        return true;
    }
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    bool left,right;

    if(leftChild < n && arr[i] < arr[leftChild]){
        return false;
    }
    left = isMaxHeap(arr,leftChild,n);

    if(rightChild < n && arr[i] < arr[rightChild]){
        return false;
    }
    right = isMaxHeap(arr,rightChild,n);

    return (left && right);

}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          isMaxHeap(arr,0,n) == true ? cout<<1<<endl : cout<<0<<endl;


     }

     return 0;
}
