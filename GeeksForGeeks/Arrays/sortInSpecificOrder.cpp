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


// time complexity is O(nlogn) and space complexity is O(1)
void SortUsingPartition(int *arr, int n){

     int fp = 0;
     for(int i = 0; i < n; i++){
          if(arr[i]&1){
               swap(arr[i],arr[fp]);
               fp++;
          }
     }

     sort(arr,arr+fp,greater<int>());
     sort(arr+fp,arr+n);

     for(int i = 0; i < n; i++){
          cout<<arr[i]<<" ";
     }
     cout<<endl;
}

// time complexity is O(nlogn) and space complexity is O(1)
void SortByMakingOddNoNegative(int *arr, int n){

     for(int i = 0; i < n; i++){
          if(arr[i]&1){
               arr[i] = (-1)*arr[i];
          }
     }

     sort(arr,arr+n);

     for(int i = 0; i < n; i++){
          if(arr[i]&1){
               arr[i] = (-1)*arr[i];
          }
     }

     for(int i = 0; i < n; i++){
          cout<<arr[i]<<" ";
     }
     cout<<endl;

}


// time complexity is O(n) and space complexity is O(n)
void Sort(int *arr, int n){

    sort(arr,arr+n);
    priority_queue<int> odd;
    priority_queue<int, vector<int> , greater<int> > even;
    for(int i = 0; i < n; i++){
        if(arr[i]&1){
            odd.push(arr[i]);
        }
        else{
            even.push(arr[i]);
        }
    }

    int k = 0;
    while(!odd.empty()){
        arr[k++] = odd.top();
        odd.pop();
    }

    while(!even.empty()){
        arr[k++] = even.top();
        even.pop();
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

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

          SortByMakingOddNoNegative(arr,n);
     }

     return 0;
}
