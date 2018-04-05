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

// time complexity is O(n^2)
int countTriangles(int arr[], int n){

    sort(arr,arr+n);
    int count  = 0;
    for(int i = 0; i < n-2; i++){
        int k = i+2;
        for(int j = i+1; j < n-1; j++){
            while(k < n && arr[i] + arr[j] > arr[k]){
                k++;
            }
            count += k - j - 1;
        }
    }

    return count;
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

          cout<<countTriangles(arr,n)<<endl;


     }

     return 0;
}
