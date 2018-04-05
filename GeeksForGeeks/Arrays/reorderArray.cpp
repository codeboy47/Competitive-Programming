#include <bits/stdc++.h>
using namespace std;

void reorderArrayAccToIndexes(int arr[], int index[], int n){

     for(int i = 0; i < n; i++){
          if(arr[i] > 0){
               int j = i;
               int next = arr[i];
               do{
                    int temp = arr[index[j]];
                    arr[index[j]] = -next;
                    j = index[j];
                    next = temp;
               }while(j != i);
          }
     }

     for(int i = 0; i < n; i++){
          arr[i] = -arr[i];
     }

     for(int i = 0; i < n; i++){
          cout<<arr[i]<<" ";
     }
     cout<<endl;
}

int main(){

     int t;
     int arr[100000], index[100000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }
          for(int i = 0; i < n; i++){
               cin>>index[i];
          }

          reorderArrayAccToIndexes(arr,index,n);
     }

     return 0;
}
