#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n)
void SubarraySumEqualToX(int arr[], int n, int x){

     int i,sum = 0;
     int s = 0, e = 0;
     for( i = 0; i < n; i++){
          sum += arr[i];
          while(sum > x && s < i){
               sum -= arr[s];
               s++;
          }
          if(sum == x){
              e = i;
              break;
          }
     }

     if(s >= e){
         cout<<-1<<endl;
         return;
     }
     cout<<s+1<<" "<<e+1<<endl;
}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n,x;
          cin>>n>>x;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          SubarraySumEqualToX(arr,n,x);
     }

     return 0;
}
