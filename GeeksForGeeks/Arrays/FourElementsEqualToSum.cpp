#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

// time complexity is O(n^3)
int findQuadlets(int *arr, int n, int sum){

    sort(arr,arr+n);
    for(int k = 0; k < n-3; k++){
        for(int i = k+1; i < n-2; i++){
            int s = i+1, e = n-1;
            while(s < e){
                if(arr[k] + arr[s] + arr[e] + arr[i] == sum){
                    return 1;
                }
                else if(arr[k] + arr[i] + arr[s] + arr[e]  > sum){
                    e--;
                }
                else{
                    s++;
                }
            }
        }
    }
    return 0;

}

class pairSum{
public :
     int first;
     int second;
     int sum;
};

bool compare(pairSum &a, pairSum &b){
     return a.sum < b.sum;
}

bool noCommon(pairSum &a, pairSum &b)
{
    if (a.first == b.first || a.first == b.second ||
            a.second == b.first || a.second == b.second)
        return false;
    return true;
}

// time complexity is O(n^2logn)
int findQuadlets2(int *arr, int n, int Sum){

     int size = (n*(n-1))/2;
     pairSum *temp = new pairSum[size];

     int k = 0;
     for(int i = 0; i < n-1; i++){
          for(int j = i+1; j < n; j++){
               temp[k].first = i;
               temp[k].second = j;
               temp[k].sum = arr[i] + arr[j];
               k++;
          }
     }

     sort(temp,temp + size, compare);

     int s = 0, e = size-1;
     while(s < e){
          if(temp[s].sum + temp[e].sum == Sum && noCommon(temp[s],temp[e])){
               return 1;
          }
          else if(temp[s].sum + temp[e].sum > Sum){
               e--;
          }
          else{
               s++;
          }
     }

     return 0;

}
int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n,sum;
          cin>>n;
          int count = 0;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }
          cin>>sum;
          cout<<findQuadlets2(arr,n,sum)<<endl;
     }

     return 0;
}
