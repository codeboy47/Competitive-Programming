#include <iostream>
#include <set>
#include <queue>
using namespace std;


// time complexity is O(k + (n-k)log(k))
// use set as min heap to store k largest elements of array
void KLargestELementsInArray(int *arr, int n, int k){

     set<int> s;
     int i;
     for(i = 0; i < k; i++){ // -->  O(k) to build a min heap
          s.insert(arr[i]);
     }

     for( ; i < n; i++){  // -->  (n-k)times
          if(arr[i] > *(s.begin())){
               auto it = s.begin();
               s.erase(it);
               s.insert(arr[i]);  // -->  O(logk) - heapify
          }
     }

     for(auto it = s.begin(); it != s.end(); it++){
          cout<<*it<<" ";
     }
     cout<<endl;

}


int main(){

     int n,k;
     cin>>n>>k;  // n = 7 and k = 3
     int arr[100000];  // arr = {1, 23, 12, 9, 30, 2, 50}
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     KLargestELementsInArray(arr,n,k); //  50, 30 and 23

     return 0;
}
