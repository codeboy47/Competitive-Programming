#include <bits/stdc++.h>
using namespace std;

// The idea is to iterate through the array and for every element arr[i], calculate sum of elements form 0 to i.
// If the current sum has been seen before, then there is a zero sum array.

bool subarrayWithZeroSum(int *arr, int n){

     unordered_map<int,bool> hash;

     int sum = 0;
     hash[0] = true;
     for(int i = 0; i < n; i++){
          sum += arr[i];
          if(hash.count(sum) == 0)
               hash[sum] = true;
          else
               return true;
     }
     return false;
}

int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          bool ans = subarrayWithZeroSum(arr,n);
          ans == true ? cout<<"Yes"<<endl : cout<<"No"<<endl;

     }

     return 0;
}
