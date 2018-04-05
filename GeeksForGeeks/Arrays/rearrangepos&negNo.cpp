// Move all negative numbers to beginning and positive to end with constant extra space
/* Conditions :
1. No data structure is allowed like using an auxiliary array
2. Order of elements should be maintained
// This is done with help of merge sort algorithm
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse(int *arr ,int s, int e){

     while(s < e){
          swap(arr[s],arr[e]);
          s++;
          e--;
     }
}

void merge(int arr[], int s1, int n1, int s2, int n2){

     int i;
     for(i = s1; i < s1+n1; i++){
          if(arr[i] > 0){
               break;
          }
     }
     int j;
     for(j = s2; j < s2+n2; j++){
          if(arr[j] > 0){
               break;
          }
     }

     // reversal theorem
     reverse(arr,i,n1-1);
     reverse(arr,s2,j-1);
     reverse(arr,i,j-1);

}

// time complexity is O(nlogn) and space complexity is O(logn)
// relative order is maintained
void rearrangeNos(int arr[], int s, int e){

     if(s == e){
          return ;
     }

     int mid = (s+e)/2;

     rearrangeNos(arr,s,mid);
     rearrangeNos(arr,mid+1,e);
     merge(arr,s,mid-s+1,mid+1,e-mid);

}

// time complexity is O(n) and space complexity is O(1)
// order of elements is not maintained
void rearrangeNosUsingPartition(int arr[], int n){

     int pIndex = 0;
     for(int i = 0; i < n; i++){
          if(arr[i] < 0){
               swap(arr[i],arr[pIndex]);
               pIndex++;
          }
     }

}

// time and space complexity is O(n) but auxiliary array is used here
void rearrangeNosUsingArray(int arr[], int n){

     vector<int> neg,pos;
     for(int i = 0; i < n; i++){
          if(arr[i] < 0){
               neg.push_back(arr[i]);
          }
          else{
               pos.push_back(arr[i]);
          }
     }

     int i;
     for(i = 0; i < neg.size(); i++){
          arr[i] = neg[i];
     }
     int j = 0;
     for(; i < n; i++){
          arr[i] = pos[j++];
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

          rearrangeNos(arr,0,n-1);
          //rearrangeNosUsingPartition(arr,n);
          //rearrangeNosUsingArray(arr,n);

          for(int i = 0; i < n; i++){
               cout<<arr[i]<<" ";
          }
          cout<<endl;
     }

     return 0;
}
