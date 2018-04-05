/*
Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one which came first.
Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

auto compare1 = [] (pair<int,int>  &a, pair<int,int> &b) {
          if(a.second == b.second){
               return a.first < b.first;
          }
          return a.second > b.second ;
};

// OR
bool compare2(pair<int,int>  &a, pair<int,int> &b){
     if(a.second == b.second){
          return a.first < b.first;
     }
     return a.second > b.second ;
}
// class compare is used in priority_queue


// Time complexity is O(NLogN)
int sortByFrequency(int *arr, int n){

     sort(arr,arr+n);

     vector<pair<int,int> > v;
     int k = 0;
     v.push_back(make_pair(arr[0],1));
     for(int i = 1; i < n; i++){
          if(arr[i] == arr[i-1]){
               v[k].second++;
          }
          else{
               k++;
               v.push_back(make_pair(arr[i],1));
          }
     }

     // sort according to frequency
     sort(v.begin(),v.end(),compare2);

     /*for(auto it = v.begin(); it != v.end(); it++){
          cout<<it->first<<" : "<<it->second<<endl;
     }*/

     k = 0;
     for(int i = 0; i < v.size(); i++){
     	int count = v[i].second;
     	while(count != 0){
     		arr[k++] = v[i].first;
     		count--;
     	}
     }

     for(int i = 0; i < n; i++){
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

     sortByFrequency(arr,n);
     cout<<endl;

     return 0;
}
