/* Given an array of n integers. Find the minimum length of the subset with the maximum OR value
among all subsets of the given array.
*/
#include <iostream>
#include <climits>
using namespace std;

void findMinLength(int *arr, int n, int i, int len, int output, pair<int,int> &p){

     if(i == n){
          if(output > p.first){
               p.first = output;
               p.second = len;
               return;
          }
          if(p.first == output){
               p.second = min(p.second,len);
               return;
          }
          return;
     }

     int x = output;
     output = arr[i] | output;

     findMinLength(arr,n,i+1,len+1,output,p);

     findMinLength(arr,n,i+1,len,x,p);

}


int main(){

     int n;
     cin>>n;
     int arr[100000];

     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     pair<int,int> p;
     p.first = INT_MIN;
     p.second = INT_MAX;

     int output = 0;
     findMinLength(arr,n,0,0,output,p);

     cout<<p.second<<endl<<p.first<<endl;

     return 0;

}
