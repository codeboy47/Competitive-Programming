#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(int arr[], int n){

     int *output = new int[n];
     output[n-1] = -1;
     stack<int> s;
     s.push(arr[n-1]);
     for(int i = n-2; i >= 0; i--){

          while(!s.empty() && arr[i] > s.top())
               s.pop();

          if(!s.empty())
               output[i] = s.top();
          else
               output[i] = -1;

          s.push(arr[i]);

     }

     for(int i = 0; i < n; i++){
          cout<<output[i]<<" ";
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

          nextGreaterElement(arr,n);
     }

     return 0;
}
