#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n^2 + klog(n^2))
int kthSmallest(int arr[][1000], int n, int k){

     priority_queue<int , vector<int> , greater<int> > minHeap;

     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
               minHeap.push(arr[i][j]);
          }
     }

     for(int i = 0; i < k-1; i++){
          minHeap.pop();
     }

     return minHeap.top();
}

class node{
public:
     int data;
     int row;
     int col;

     node(int a, int b, int c){
          data = a;
          row = b;
          col = c;
     }
};

class compare{
public:
     bool operator () (node &a, node &b){
          return a.data > b.data;
     }
};

// time complexity is O(n + klogn)
int kthSmallest2(int arr[][1000], int n, int k){

     priority_queue<node , vector<node> , compare > minHeap;

     for(int i = 0; i < n; i++){
          node n(arr[0][i],0,i);
          minHeap.push(n);
     }

     for(int i = 0; i < k-1; i++){
          node top = minHeap.top();
          minHeap.pop();
          int newRow = top.row+1;
          int newCol = top.col;
          int val = newRow < n ? arr[newRow][newCol] : INT_MAX;
          node p(val,newRow,newCol);
          minHeap.push(p);
     }

     return minHeap.top().data;

}

int main(){

     int t;
     int arr[1000][1000];
     cin>>t;
     while(t--){
          int n,k;
          cin>>n>>k;
          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++){
                    cin>>arr[i][j];
               }
          }

          cout<<kthSmallest2(arr,n,k)<<endl;

     }

     return 0;
}
