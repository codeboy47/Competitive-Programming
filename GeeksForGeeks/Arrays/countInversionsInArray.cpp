#include <bits/stdc++.h>
using namespace std;

int merge(int *arr, int *left, int *right, int s, int e){

     int i = s;
     int mid = (s+e)/2;
     int j = mid+1;
     int k = s;

     int count = 0;
     while(i <= mid && j <= e){
          if(left[i] <= right[j]){
               arr[k++] = left[i++];
               count += j - (mid+1);
          }
          else{

               arr[k++] = right[j++];
          }
     }
     if(i <= mid){
          count += (mid-i+1)*(j-(mid+1));
     }
     while(i <= mid){
          arr[k++] = left[i++];
     }
     while(j <= e){
          arr[k++] = right[j++];
     }

     return count;
}

// time complexity is O(nlogn) but it is complex
int countInversionsUsingMergeSort(int arr[], int s, int e){

     int count = 0;
     if(s < e){
          int mid = (s+e)/2;
          int left[1000], right[1000];
          for(int i = s; i <= mid; i++){
               left[i] = arr[i];
          }
          for(int i = mid+1; i <= e; i++){
               right[i] = arr[i];
          }
          int countL = countInversionsUsingMergeSort(left,s,mid);
          int countR = countInversionsUsingMergeSort(right,mid+1,e);
          count += countL + countR + merge(arr,left,right,s,e);
     }
     return count;
}

// time complexity less than O(n^2) but it is simple
int countInversionUsingSets(int *arr, int n){

     int count = 0;

     set<int> s;
     s.insert(arr[0]);
     for(int i = 1; i < n; i++){

          auto itr = s.upper_bound(arr[i]);
          s.insert(arr[i]);
          count += distance(itr,s.end());
     }
     return count;
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

          cout<<countInversionUsingSets(arr,n)<<endl;
          cout<<countInversionsUsingMergeSort(arr,0,n-1)<<endl;
     }

     return 0;
}
