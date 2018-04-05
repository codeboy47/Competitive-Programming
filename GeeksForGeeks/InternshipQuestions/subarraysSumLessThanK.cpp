// Number of subarrays with sum less than or equal a given 'k'

#include <iostream>
using namespace std;

// brute force O(N^2)
int countSubarrayBruteForce(int *arr, int n, int k){

     int count = 0;
     for(int i = 0; i  < n; i++){
          int sum = 0;
          for(int j = i; j  < n; j++){
               if(sum+arr[j] < k){
                    sum = arr[j] + sum;
                    count++;
               }
               else{
                    break;
               }
          }
     }

     return count;

}


int countSubarraySlidingWindow(int *arr, int n, int k){

     int count = 0;

     int sum = 0;
     int left = 0,right = 0;
     for(left = 0; left < n; left++){

          while(right < n && arr[right]+sum < k){
               sum = sum + arr[right];
               right++;
          }

          int range = right - left;
          count = count + range;
          
          sum = sum - arr[left];
     }

     return count;

}


int main(){

     int arr[100000];
     int n,k;
     cin>>n>>k;
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     cout<<countSubarrayBruteForce(arr,n,k)<<endl;
     cout<<countSubarraySlidingWindow(arr,n,k)<<endl;

     return 0;
}
