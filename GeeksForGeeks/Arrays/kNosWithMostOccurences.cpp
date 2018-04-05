// Very important concept
// Asked in Amazon
#include <bits/stdc++.h>
using namespace std;

class compare{
public:
     bool operator () (pair<int,int> &p1, pair<int,int> &p2){
          if(p1.second == p2.second){
               return p1.first < p2.first;
          }
          else{
               return p1.second < p2.second;
          }
     }
};

void kNosWithMostOccurences(int arr[], int n, int k){

     unordered_map<int,int> hash;

     for(int i = 0; i < n; i++){
          if(hash.count(arr[i]) == 0){
               hash[arr[i]] = 1;
          }
          else{
               hash[arr[i]]++;
          }
     }

     vector<pair<int,int>> freqArr(hash.begin(),hash.end());

     priority_queue< pair<int,int>, vector<pair<int,int> > , compare > maxHeap(hash.begin(), hash.end());

     for(int i = 0; i < k; i++){
          cout<<maxHeap.top().first<<" ";
          maxHeap.pop();
     }

     cout<<endl;
}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n,k;
          cin>>n>>k;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          kNosWithMostOccurences(arr,n,k);
     }

     return 0;
}
