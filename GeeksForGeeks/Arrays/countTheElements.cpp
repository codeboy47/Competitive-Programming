#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

// time complexity is O(n^2)
void countElements(int *arr1, int *arr2, int n){

     for(int i = 0; i < n; i++){
          int count = 0;
          for(int j = 0; j < n; j++){
               if(arr1[i] >= arr2[j]){
                    count++;
               }
          }
          cout<<count;
          if(i != n-1)
          cout<<",";
     }

}

// time complexity is O(n)
void countElements2(int *arr1, int *arr2, int n){

     int l = INT_MIN;
     for(int i = 0; i < n; i++){
          l = max(l,arr1[i]);
     }

     int temp[100000];
     memset(temp,0,sizeof(int)*(l+1));

     for(int i = 0; i < n; i++){
          temp[arr2[i]]++;
     }

     for(int i = 1; i <= l ;i++){
          if(temp[i] == 0){
               temp[i] = temp[i-1];
          }
          else{
          	temp[i] += temp[i-1];
          }
     }


     for(int i = 0; i < n; i++){
          cout<<temp[arr1[i]];
          if(i != n-1){
               cout<<",";
          }
     }


}

int main(){

     int t;
     int arr1[10000],arr2[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          int count = 0;
          for(int i = 0; i < n; i++){
               cin>>arr1[i];
          }
          for(int i = 0; i < n; i++){
               cin>>arr2[i];
          }

          countElements2(arr1,arr2,n);
          cout<<endl;

     }

     return 0;
}
