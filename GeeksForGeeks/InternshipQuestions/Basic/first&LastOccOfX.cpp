#include <bits/stdc++.h>
using namespace std;

// binary search is used here

int firstOccurrence(int *arr, int n, int key){

    int s = 0, e = n-1;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid] < key){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;

}

int lastOccurrence(int *arr, int n, int key){

    int s = 0, e = n-1;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid] == key){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return ans;

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

          int x;
          cin>>x;

          int index = firstOccurrence(arr,n,x);
          cout<<index<<" ";
          if(index!= -1)
          cout<<lastOccurrence(arr,n,x);
          cout<<endl;
     }

     return 0;
}
