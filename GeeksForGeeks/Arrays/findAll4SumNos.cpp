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
void findQuadlets(int *arr, int n, int sum){

    set<pair< pair<int,int> , pair<int,int> > > sp;
    sort(arr,arr+n);
    bool f = false;

    for(int k = 0; k < n-3; k++){
        for(int i = k+1; i < n-2; i++){
            int s = i+1, e = n-1;
            int p = 37;
            while(s < e){
                if(arr[k] + arr[s] + arr[e] + arr[i] == sum){
                    f = true;
                    sp.insert(make_pair(make_pair(arr[k],arr[i]),make_pair(arr[s],arr[e])));

                    s++;
                    e--;
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

    if(!sp.empty()){
          for(auto it = sp.begin(); it != sp.end(); it++){
               cout<<it->first.first<<" "<<it->first.second<<" "<<it->second.first<<" "<<it->second.second<<" $";
          }
          cout<<endl;
     }
     else{
          cout<<-1<<endl;
     }

    return;

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
void findQuadlets2(int *arr, int n, int Sum){

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
     set<pair< pair<int,int> , pair<int,int> > > sp;
     while(s < size && e >= 0){
          if(temp[s].sum + temp[e].sum == Sum && noCommon(temp[s],temp[e])){
               int aux[4];
               aux[0] = arr[temp[s].first];
               aux[1] = arr[temp[s].second];
               aux[2] = arr[temp[e].first];
               aux[3] = arr[temp[e].second];

               sort(aux,aux+4);

               sp.insert(make_pair(make_pair(aux[0],aux[1]),make_pair(aux[2],aux[3])));

               s++;
               e--;
          }
          else if(temp[s].sum + temp[e].sum > Sum){
               e--;
          }
          else{
               s++;
          }
     }

     if(!sp.empty()){
          for(auto it = sp.begin(); it != sp.end(); it++){
               cout<<it->first.first<<" "<<it->first.second<<" "<<it->second.first<<" "<<it->second.second<<" $";
          }
          cout<<endl;
     }
     else{
          cout<<-1<<endl;
     }

}
int main(){

     int t;
     int arr[10000];
     cin>>t;
     while(t--){
          int n,sum;
          cin>>n>>sum;
          int count = 0;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }
          findQuadlets2(arr,n,sum);
     }

     return 0;
}
