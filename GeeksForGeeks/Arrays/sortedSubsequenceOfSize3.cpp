#include <iostream>
using namespace std;

void findSubsequence(int arr[], int n){

     int smaller[10000], greater[100000];

     smaller[0] = -1;
     for(int i = 1; i < n; i++){
          if(arr[i] > arr[i-1]){
               smaller[i] = i-1;
          }
          else{
               if(arr[i] > arr[smaller[i-1]]){
                    smaller[i] = smaller[i-1];
               }
          }
     }

     greater[n-1] = -1;
     for(int i = n-2; i >= 0; i--){
          if(arr[i] < arr[i+1]){
               greater[i] = i+1;
          }
          else{
               if(arr[i] < arr[greater[i+1]]){
                    greater[i] = greater[i+1];
               }
          }
     }

     for(int i = 0; i < n; i++){
          if(smaller[i] != -1 && greater[i] != -1){
               cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]]<<endl;
               break;
          }
     }
     
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

          findSubsequence(arr,n);
     }
}
