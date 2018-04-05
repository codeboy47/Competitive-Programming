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

// by using sliding window my way O(N)
int countSubarraySlidingWindowMyWay(int *arr, int n, int k){

    int s = 0, e = 0, count = 0, sum = arr[0];
    while(e < n){
        if(sum < k){
            e++;
            count += e - s;
            sum += arr[e];
        }
        else{
            sum -= arr[s];
            s++;
        }
    }

    return count;
}

// O(N) approach
int countSubarraySlidingWindow(int *arr, int n, int k){

     int count = 0;

     int sum = 0;
     int left = 0,right = 0;
     for(left = 0; left < n; left++){

        while(right < n && arr[right]+sum < k){
           sum = sum + arr[right];
           right++;
        }

        count += right - left;

        if(left == right){
        	sum = 0;
        	right++;
        }
        else{
        	sum = sum - arr[left];
        }

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
