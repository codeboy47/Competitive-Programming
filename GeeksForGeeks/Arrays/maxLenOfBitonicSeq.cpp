#include <iostream>
using namespace std;

int maxLengthOfBitonicSubarray(int arr[], int n){

     int start = 0;
     int i = 0;
     int index = 0;
     int maxLen = 0;
     while(i < n-1){
          while(i < n-1 && arr[i] <= arr[i+1]){
               i++;
          }

          while(i < n-1 && arr[i] >= arr[i+1]){
               // if there are duplicates while decreasing
               if(arr[i] > arr[i+1]){
                    index = i+1;
               }
               i++;
          }

          maxLen = max(maxLen,i-start+1);

          start = index;

     }

     return maxLen;
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

          cout<<maxLengthOfBitonicSubarray(arr,n)<<endl;
     }
}
