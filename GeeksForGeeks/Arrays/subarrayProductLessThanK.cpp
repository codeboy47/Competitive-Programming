//Link: https://www.quora.com/How-can-I-count-the-no-of-subarrays-that-have-the-product-of-elements-smaller-than-a-number-D

// Ques. Given a array find how many subarray's product smaller than k

#include <iostream>
#define mod 1000000007
using namespace std;

// brute force O(N^2)
int countSubarrayBruteForce(int *arr, int n, int k){

     int count = 0;
     for(int i = 0; i  < n; i++){
          int product = 1;
          for(int j = i; j  < n; j++){
               if(product*arr[j] < k){
                    product = arr[j]*product;
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

    int s = 0, e = 0, count = 0, p = arr[0];
    while(e < n){
        if(p < k){
            e++;
            count += e - s;
            p *= arr[e];
        }
        else{
            p /= arr[s];
            s++;
        }
    }

    return count;
}

// correct approach for sliding window O(N)
int countSubarraySlidingWindow(int *arr, int n, int k){

     int count = 0;

     int right = 0;
     int product = 1;
     for(int left = 0; left < n; left++){

          while(right < n && (arr[right]*product) < k){
               product = (product*arr[right]);
               right++;
          }

          int range = right - left; // it means no of subarray whose product is less than k
          count = range + count;
          if(left == right){
          	product = 1;
          	right++;
          }else{
          	product = product/arr[left];
          }
     }

     return count;
}



int main(){
     /*
     sample input 1 :
     3 4
     1 2 3
     ans : 4
     sample input 2 :
     7 65
     3 2 1 3 2 10 5
     ans : 21
     sample input 3 :
     6 10,7
     3 2 9 1 9 1
     ans : 11,5
     */
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
