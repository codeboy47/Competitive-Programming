#include <bits/stdc++.h>
using namespace std;

// time complexity is O(nlogn)
void findElements(int arr[], int n){

     sort(arr,arr+n);

     for(int i = 0; i < n-2; i++){
          cout<<arr[i]<<" ";
     }
     cout<<endl;
}

// time complexity is O(n)
void findElements2(int arr[], int n){

     int first, second;
     first = second = INT_MIN;

     // first find 2 largest numbers
     for(int i = 0; i < n; i++){
          if(arr[i] > first){
               second = first;
               first = arr[i];
          }
          else if(arr[i] > second){
               second = arr[i];
          }
     }

     // print all nos except these two
     for(int i = 0; i < n; i++){
          if(arr[i] != first && arr[i] != second){
               cout<<arr[i]<<" ";
          }
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

          findElements2(arr,n);

     }

     return 0;
}
