#include <iostream>
#include <unordered_map>
using namespace std;

// store the index of a particular sum by making 0 as -1
// time and space complexity is both O(n)
int maxLen(int *arr, int n){

     int ml = 0;

     unordered_map<int,int> hash;

     for(int i = 0; i < n; i++){
          arr[i] = arr[i] == 0 ? -1 : 1;
     }

     int sum = 0;
     int s = 0, e = 0;
     for(int i = 0; i < n; i++){

          sum += arr[i];

          if(sum == 0){
               ml = i+1;
               s = 0;
               e = i;
          }

          if(hash.count(sum) == 1){
               if(ml < i - hash[sum]){
                    s = hash[sum] + 1;
                    e = i;
                    ml = i - hash[sum];
               }
          }
          else{
               hash[sum] = i;
          }
     }

     cout<<s<<" to "<<e<<endl;
     return ml;
}

int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               int d;
               cin>>arr[i];
          }

          cout<<maxLen(arr,n)<<endl;
     }
}
