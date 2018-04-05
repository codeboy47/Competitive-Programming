#include <bits/stdc++.h>
using namespace std;

void printKMax(int *arr, int n, int k){

     deque<int> dq;

     for(int i = 0; i < k; i++){
          while(!dq.empty() && arr[dq.back()] < arr[i]){
               dq.pop_back();
          }
          dq.push_back(i);
     }

     for(int i = k; i < n; i++){
          cout<<arr[dq.front()]<<" ";
          if(i - dq.front() >= k){
               dq.pop_front();
          }
          while(!dq.empty() && arr[dq.back()] < arr[i]){
               dq.pop_back();
          }
          dq.push_back(i);
     }
     cout<<arr[dq.front()]<<" ";
}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n,k;
          cin>>n>>k;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          printKMax(arr,n,k);
          cout<<endl;

     }

     return 0;
}
