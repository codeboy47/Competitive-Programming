#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(int *arr, int n){

    int s = 0, e = n-1;

    int sumL = 0, sumR = 0;
    while(s < e){

        if(arr[s]+sumL == arr[e]+sumR){
            sumL += arr[s];
            sumR += arr[e];
            s++;
            e--;

        }
        if(arr[s]+sumL > arr[e]+sumR){
            sumR += arr[e];
            e--;
        }
        if(arr[s]+sumL < arr[e]+sumR){
            sumL += arr[s];
            s++;
        }

    }

    return (sumL == sumR && s == e) ? s+1 : -1;
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

          cout<<equilibriumPoint(arr,n)<<endl;

     }

     return 0;
}
