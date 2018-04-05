#include <bits/stdc++.h>
using namespace std;

int findNoWithOddOccurence(int *arr, int n){

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }
    return ans;
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

          cout<<findNoWithOddOccurence(arr,n)<<endl;
     }

     return 0;
}
