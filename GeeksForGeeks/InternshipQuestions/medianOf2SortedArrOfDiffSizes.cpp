// Median of two sorted arrays of different sizes

#include <iostream>
using namespace std;

float getMedian(int arr[], int n){
     if(n&1){
          return arr[n/2];
     }
     return (arr[n/2]+arr[n/2-1])/2.0;
}

float getMedian2(int a, int b, int c){

     return a + b + c - min(a,min(b,c)) - max(a,max(b,c));
}

float getMedian3(int a, int b, int c, int d){
     int largest = max(a,max(b,max(c,d)));
     int smallest = min(a,min(b,min(c,d)));
     return (a + b + c + d - largest - smallest) / 2.0;
}

float findMedian(int *arr1, int *arr2, int n, int m){

     if(n == 0){
          if(m == 0){
               return -1;
          }
          if(m != 0){
               return getMedian(arr2,m);
          }
     }

     if(n == 1){
          if(m == 1){
               return (arr1[0]+arr2[0]) / 2.0;
          }
          if(m&1){ // m is odd
               if(arr2[m/2] > arr1[0])
                    return ( arr2[m/2] + max(arr2[m/2-1],arr1[0]) ) / 2.0;
               else
                    return ( arr2[m/2] + min(arr2[m/2+1],arr1[0]) ) / 2.0;
          }
          if(m%2 == 0){ // m is even
               return getMedian2(arr2[m/2],arr2[m/2-1],arr1[0]);
          }

     }

     if(n == 2){
          if(m == 2){
               return getMedian3(arr1[0],arr1[1],arr2[0],arr2[1]);
          }
          if(m&1){
               return getMedian2(arr2[m/2],max(arr1[0],arr2[m/2-1]),min(arr1[1],arr2[m/2+1]));
          }
          if(m%2 == 0){
               return getMedian3(arr2[m/2],arr2[m/2-1],max(arr1[0],arr2[m/2-2]),min(arr1[1],arr2[m/2+1]));
          }
     }

     int i1 = (n-1)/2;
     int i2 = (m-1)/2;

     if(arr1[i1] >= arr2[i2]){
          return findMedian(arr1,arr2+i1,n/2+1,m-i1);
     }
     else{
          return findMedian(arr1+i1,arr2,n/2+1,m-i1);
     }


}



int main(){

     int n,m;
     cin>>n>>m;
     int arr1[10000],arr2[10000];

     for(int i = 0; i < n; i++){
		cin>>arr1[i];
	}
	for(int i = 0; i < m; i++){
		cin>>arr2[i];
	}

     if(n < m){
          cout<<findMedian(arr1,arr2,n,m)<<endl;
     }else{
          cout<<findMedian(arr2,arr1,m,n)<<endl;
     }

     return 0;
}
