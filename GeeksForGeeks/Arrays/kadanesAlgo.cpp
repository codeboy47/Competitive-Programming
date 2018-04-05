#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int *arr, int n){

    int cs = 0;
    int ms = INT_MIN;
    for(int i = 0; i < n; i++){
        cs = max(arr[i],cs+arr[i]);
        ms = max(ms,cs);
    }
    return ms;
}

int maxSubArraySum2(int *arr, int n){

    int ms = INT_MIN, cs = 0;

    for(int i = 0; i < n; i++){
        cs += arr[i];

        if(ms < cs){
            ms = cs;
        }

        if(cs < 0){
            cs = 0;
        }
    }

    return ms;

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

          cout<<maxSubArraySum(arr,n)<<endl;

     }

     return 0;
}
