/* Given an unsorted array of positive and negative numbers. Create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers respectively. Solution should start with positive number.*/

#include <iostream>
#include <string.h>
using namespace std;

// comlexity : O(n) time complexity and O(n) space complexity
void rearrangeNos(int *arr, int n){

     int countNegative = 0;
     for(int i = 0; i < n ; i++){
          if(arr[i] < 0){
               countNegative++;
          }
     }

     int *aux = new int[n];
     memset(aux,0,sizeof(int)*n);

     int k = 1;
     if(countNegative <= n - countNegative){
          for(int i = 0; i < n ; i++){
               if(arr[i] < 0){
                    aux[k] = arr[i];
                    k = k + 2;
               }
          }
     }

    k  = 0;
    int i = 0;
     for( i = 0; i < n && countNegative > 0 ; i++){
          if(arr[i] >= 0){
               aux[k] = arr[i];
               k = k + 2;
               countNegative--;
          }
     }

     for( ;i < n; i++){
         if(arr[i] >= 0){
               aux[k] = arr[i];
               k = k + 1;
          }
     }

     for(int i = 0; i < n ; i++){
          cout<<aux[i]<<" ";
     }

}


// time complexity is O(n^2) and space complexity is O(1)
void rearrangeNos2(int *arr, int n){

     int pivot;
     for(int  i = 0; i < n ; i++){
         pivot = -1;
          if(i%2==1){ // odd
               if(arr[i] >= 0){
                    for(int j = i; j < n; j++){
                         if(arr[j] < 0){
                              pivot = j;
                              break;
                         }
                    }
                    for(int j = pivot; j > i; j--){
                         swap(arr[j],arr[j-1]);
                    }
               }
          }
          else{ // even
               if(arr[i] < 0){
                    for(int j = i; j  < n; j++){
                         if(arr[j] >= 0){
                              pivot = j;
                              break;
                         }
                    }
                    for(int j = pivot; j > i; j--){
                         swap(arr[j],arr[j-1]);
                    }
               }
          }
     }

     for(int i = 0; i < n ; i++){
          cout<<arr[i]<<" ";
     }

}


// time complexity is O(n) and space complexity is O(1) but partition changes the relative order of elements
void rearrangeNos3(int *arr, int n){

     int pIndex = 0;

     for(int i = 0; i < n; i++){
          if(arr[i] < 0){
               swap(arr[i],arr[pIndex]);
               pIndex++;
          }
     }

     int negIndex = 0;
     while(pIndex < n && negIndex < pIndex){
          swap(arr[negIndex],arr[pIndex]);
          negIndex = negIndex + 2;
          pIndex++;
     }

}

int main(){

     int arr[10000];
     int t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          rearrangeNos3(arr,n);
          cout<<endl;

     }

}
