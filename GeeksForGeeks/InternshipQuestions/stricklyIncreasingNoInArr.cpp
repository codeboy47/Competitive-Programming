#include <iostream>
#include <stack>
using namespace std;

void findStrictlyIncreasingElement(int *arr, int n){

     stack<int> s;
     int result[100000];

     for(int i = 0; i < n; i++){

          while(!s.empty() && arr[i] > arr[s.top()]){
               result[s.top()] = arr[i];
               s.pop();
          }
          s.push(i);

     }

     while(!s.empty()){
          result[s.top()] = -1;
          s.pop();
     }

     for(int i = 0; i < n; i++){
          cout<<result[i]<<" ";
     }

}

int main(){

     int arr[10000];
     int n;
     cin>>n;
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     findStrictlyIncreasingElement(arr,n);

     return 0;
}
