#include <bits/stdc++.h>
using namespace std;

void typeOfArray(int *arr, int n){

     int i;

     for(i = 0; i < n-1; ){
          if(arr[i] < arr[i+1]){
               i++;
          }
          else{
               break;
          }
     }
     if(i == n-1){
          cout<<arr[n-1]<<" "<<1<<endl;
          return;
     }
     if(i == 0){
          for(i = 0; i < n-1; ){
               if(arr[i] > arr[i+1]){
                    i++;
               }
               else{
                    break;
               }
          }
          if(i == n-1){
               cout<<arr[0]<<" "<<2<<endl;
               return;
          }
          if(arr[i-1] < arr[i+1]){
               cout<<arr[i+1]<<" "<<3<<endl;
               return ;
          }
          if(arr[i-1] > arr[i+1]){
               cout<<arr[i-1]<<" "<<4<<endl;
               return;
          }
     }

     if(arr[i-1] > arr[i+1]){
          cout<<arr[i]<<" "<<4<<endl;
          return;
     }

     if(arr[i-1] < arr[i+1]){
          cout<<arr[i]<<" "<<3<<endl;
          return;
     }

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

          typeOfArray(arr,n);
     }

     return 0;
}
