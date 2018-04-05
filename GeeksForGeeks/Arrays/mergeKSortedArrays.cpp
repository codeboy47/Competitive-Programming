#include <bits/stdc++.h>
using namespace std;

class Pair{
public:
     int data;
     int r;
     int c;
     Pair(int x, int y, int z){
          data = x;
          r = y;
          c = z;
     }
};

class compare{
public:
     bool operator () (Pair &a, Pair &b){
          return a.data > b.data;
     }
};

void mergeKSortedArray(int arr[][1000], int n){

     priority_queue< Pair , vector<Pair>, compare > minHeap;

     for(int i = 0; i < n; i++){
          Pair p(arr[i][0],i,0);
          minHeap.push(p);
     }

     int *output = new int[n*n];

     int index = 0;
     while(index < n*n){
          Pair top = minHeap.top();
          minHeap.pop();
          output[index++] = top.data;
          if(top.c != n-1){
               Pair q(arr[top.r][top.c+1],top.r,top.c+1);
               minHeap.push(q);
          }
     }

     return output;
}

int main(){

     int t;
     int arr[1000][1000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++){
                    cin>>arr[i][j];
               }
          }

          int *out = mergeKSortedArray(arr,n);
          for(int i = 0; i < n*n; i++){
               cout<<out[i]<<" ";
          }
          cout<<endl;
     }

     return 0;
}
