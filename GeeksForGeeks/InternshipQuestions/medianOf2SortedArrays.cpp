#include <iostream>
using namespace std;

// time complexity is O(n)
int findMedianUsingMerging(int *arr1, int *arr2, int n){

     int m1 = arr1[0],m2 = arr2[0];

     int i = 0, j = 0;
     for(int count = 0; count <= n; count++){

          if(i == n){
               m1 = m2;
               m2 = arr2[0];
               break;
          }
          if(j == n){
               m1 = m2;
               m2 = arr1[0];
               break;
          }
          if(arr1[i] < arr2[j]){
               m1 = m2;
               m2 = arr1[i];
               i++;
          }
          else{
               m1 = m2;
               m2 = arr2[j];
               j++;
          }

     }

     return (m1+m2)/2;

}


int getMedian(int *arr, int n){
     if(n&1){
          return arr[n/2];
     }
     return (arr[n/2]+arr[n/2-1])/2;
}

// time complexity is O(logn) (Divide and Conquer)
int findMedianUsingBinarySearch(int *arr1, int *arr2, int n){

     if(n == 1){
          return (arr1[0]+arr2[0])/2;
     }
     if(n == 2){
          return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]))/2;
     }

     int m1 = getMedian(arr1,n);
     int m2 = getMedian(arr2,n);

     if(m1 == m2){
          return m1;
     }
     if(m1 > m2){
          if(n&1)
               return findMedianUsingBinarySearch(arr1,arr2+n/2,n/2+1);
          return findMedianUsingBinarySearch(arr1,arr2+n/2-1,n/2+1);
     }
     if(m1 < m2){
          if(n&1)
               return findMedianUsingBinarySearch(arr1+n/2,arr2,n/2+1);
          return findMedianUsingBinarySearch(arr1+n/2-1,arr2,n/2+1);
     }
}

// same thing with other way
int findMedianUsingBinarySearch2(int *arr1, int *arr2, int n){

     if(n == 1){
          return (arr1[0]+arr2[0])/2;
     }
     if(n == 2){
          return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]))/2;
     }

     int mid = (n-1)/2;

     if(arr1[mid] >= arr2[mid]){
          return findMedianUsingBinarySearch2(arr1,arr2+mid,n/2+1);
     }
     if(arr1[mid] < arr2[mid]){
          return findMedianUsingBinarySearch2(arr1+mid,arr2,n/2+1);
     }
}


int main(){
	int n;
	cin>>n;
	int arr1[1000], arr2[1000];
	for(int i = 0; i < n; i++){
		cin>>arr1[i];
	}
	for(int i = 0; i < n; i++){
		cin>>arr2[i];
	}
     cout<<findMedianUsingMerging(arr1,arr2,n)<<endl;
	cout<<findMedianUsingBinarySearch(arr1,arr2,n)<<endl;  // arr1 is the address of zeroth index array
     cout<<findMedianUsingBinarySearch2(arr1,arr2,n)<<endl;
     return 0;
}
