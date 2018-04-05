/*
You are give an array. You have to sort array according to the frequency of no in array
Note : Frequency of an element in array is unique
Sample Input :
10
3 4 5 2 5 2 4 2 4 2
ans : 3 5 4 2
10
2 5 2 8 5 6 8 8 2 8
ans : 6 5 2 8
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int sortWithRespectToFrequency(int *arr, int n){

     unordered_map<int,int> hash;
     for(int i = 0; i < n; i++){
          if(!hash.count(arr[i])){
               hash[arr[i]] = 0;
          }
          hash[arr[i]]++;
     }

     for(auto it = hash.begin(); it != hash.end(); it++){
          arr[it->second-1] = it->first;
     }

     for(int i = 0; i < hash.size(); i++){
          cout<<arr[i]<<" ";
     }
}

int main(){

     int n;
     int arr[100000];
     cin>>n;
     for(int i = 0; i < n; i++){
          cin>>arr[i];
     }

     sortWithRespectToFrequency(arr,n);
     cout<<endl;
     return 0;
}
