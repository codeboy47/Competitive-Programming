#include <bits/stdc++.h>
using namespace std;

// both functions time complexity is same
class interval{
public:
     int l;
     int r;
};

bool compare(interval &p1, interval &p2){
     return p1.l < p2.l;
}

void mergeOverlappingIntervals1(interval arr[], int n){

     sort(arr,arr+n,compare);

     // here arr[0].l will be smallest and is fixed but arr[0].r can be largest
     // so we make arr[1].r = arr[0].r so that arr[n-1].r will become largest
     for(int i = 0; i < n-1; i++){
          if(arr[i].r >= arr[i+1].l){
               arr[i+1].r = max(arr[i].r,arr[i+1].r);
               arr[i].r = -1;
               arr[i+1].l = -1;
          }
     }

     for(int i = 0; i < n ; i++){
          if(arr[i].l > 0){
              cout<<arr[i].l<<" ";
          }
          if(arr[i].r > 0){
              cout<<arr[i].r<<" ";
          }
     }
     cout<<endl;

}

bool compare2(interval &p1, interval &p2){
     return p1.r < p2.r;
}

void mergeOverlappingIntervals2(interval arr[], int n){

     sort(arr,arr+n,compare2);

     // here arr[n-1].r will be largest and is fixed but arr[n-1].l can be smallest
     // so we make arr[n-2].l = arr[n-1].l so that arr[0].l will become smallest
     for(int i = n-1; i >= 0; i--){
          if(arr[i-1].r >= arr[i].l){
               arr[i-1].l = min(arr[i].l,arr[i-1].l);
               arr[i-1].r = -1;
               arr[i].l = -1;
          }
     }

     for(int i = 0; i < n ; i++){
          if(arr[i].l > 0){
              cout<<arr[i].l<<" ";
          }
          if(arr[i].r > 0){
              cout<<arr[i].r<<" ";
          }
     }
     cout<<endl;

}

int main(){

     int t;
     interval arr[100000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
               interval p;
               cin>>p.l;
               cin>>p.r;
               arr[i] = p;
          }

          mergeOverlappingIntervals(arr,n);

     }

     return 0;
}
