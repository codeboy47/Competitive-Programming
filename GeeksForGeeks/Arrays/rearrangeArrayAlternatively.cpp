// we use this : arr[i] += arr[max_index] % max_element * max_element to store 2 elements at one index
#include <iostream>
using namespace std;

// time complexity is O(n) and space complexity is O(1)
void rearrangeArrayElements(int *arr ,int n){

    int maxElement = arr[n-1] + 1;

    int maxIndex = n-1, minIndex = 0;
    for(int i = 0; i < n; i++){
         if(i%2==0){
              // this expression is used to store 2 number at one index
              arr[i] = arr[i] + ((arr[maxIndex]%maxElement) * maxElement);
              maxIndex--;
         }
         else{
              arr[i] = arr[i] + ((arr[minIndex]%maxElement) * maxElement);
              minIndex++;
         }
    }

    for(int i = 0; i < n; i++){
         cout<<arr[i]/maxElement<<" ";
    }
    cout<<endl;

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

          rearrangeArrayElements(arr,n);

     }

     return 0;
}
