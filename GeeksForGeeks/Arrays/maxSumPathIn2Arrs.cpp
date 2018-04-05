#include <bits/stdc++.h>
using namespace std;

int maxSumPath(int arr1[], int n, int arr2[], int m){

     int i = 0, j = 0;
     int ansSum = 0, sum1 = 0, sum2 = 0;
     while(i < n && j < m){
          if(arr1[i] > arr2[j]){
               sum2 += arr2[j];
               j++;
          }
          else if(arr1[i] < arr2[j]){
               sum1 += arr1[i];
               i++;
          }
          else{
               sum1 += arr1[i];
               sum2 += arr2[j];
               if(sum1 > sum2){
                    ansSum += sum1;
               }else{
                    ansSum += sum2;
               }
               sum1 = 0;
               sum2 = 0;
               i++,j++;
          }
     }

     while(i < n){
         sum1 += arr1[i++];
     }
     while(j < m){
         sum2 += arr2[j++];
     }
     if(sum1 > sum2){
          ansSum += sum1;
     }else{
          ansSum += sum2;
     }

     return ansSum;
}

int main(){

     int t;
     int arr1[10000], arr2[10000];
     cin>>t;
     while(t--){
          int n,m;
          cin>>n>>m;
          for(int i = 0; i < n; i++){
               cin>>arr1[i];
          }
          for(int i = 0; i < m; i++){
               cin>>arr2[i];
          }
          cout<<maxSumPath(arr1,n,arr2,m)<<endl;
     }

     return 0;
}
