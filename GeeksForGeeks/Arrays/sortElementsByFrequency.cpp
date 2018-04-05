#include <bits/stdc++.h>
using namespace std;

bool compares(pair<int,int> a, pair<int,int> b){

     // if frequency is same
     if(a.second == b.second){
          return a.first < b.first;
     }
     else{
          return a.second > b.second;
     }

}

void sortElementByFrequency(int arr[], int n){

     unordered_map<int,int> hash;

     for(int i = 0; i < n; i++){
          if(hash.count(arr[i]) == 0){
               hash[arr[i]] = 1;
          }
          else{
               hash[arr[i]]++;
          }
     }

     vector<pair<int,int> > v;
     for(auto it = hash.begin(); it != hash.end(); it++){
          v.push_back(make_pair(it->first,it->second));
     }

     sort(v.begin(),v.end(), compares);

     for(int i = 0; i < v.size(); i++){
          int count = v[i].second;
          while(count--){
               cout<<v[i].first<<" ";
          }
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

          sortElementByFrequency(arr,n);
     }

     return 0;
}
