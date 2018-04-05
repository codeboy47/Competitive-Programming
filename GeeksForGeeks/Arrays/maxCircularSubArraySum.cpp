#include <bits/stdc++.h>
using namespace std;

int KadaneAlgo(int *arr, int n){

     int ms = INT_MIN,cs = 0;
     for(int i = 0; i < n; i++){
          cs += arr[i];
          ms = max(ms,cs);
          if(cs < 0){
               cs = 0;
          }
     }

     return ms;
}

// time complexity is O(n)
void maxCircularSubArraySum(int *arr, int n){

     int sum = 0;
     for(int i = 0; i < n; i++){
          sum += arr[i];
     }

     int maxNegSum = 0;
     int cs = 0;
     for(int i = 0; i < n; i++){
          cs += arr[i];
          maxNegSum = min(maxNegSum,cs);
          if(cs > 0){
               cs = 0;
          }
     }

     int ans1 = KadaneAlgo(arr,n);
     int ans2 = sum - maxNegSum;

     if(ans2 != 0)
          cout<<max(ans1,ans2)<<endl;
     else
          cout<<ans1<<endl;

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

          maxCircularSubArraySum(arr,n);

     }

     return 0;
}
