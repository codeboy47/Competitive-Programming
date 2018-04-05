#include <iostream>
#include <algorithm>
using namespace std;

int countTripletsSmallerThanX(int arr[], int n, int sum){

     sort(arr,arr+n);

     int count  = 0;
     for(int i = 0; i < n; i++){
          int s = i+1, e = n-1;
          int x = sum - arr[i];
          while(s < e){
               if(arr[s] + arr[e] + arr[i] < sum){
                    count += e - s;
                    s++;
               }
               else if(arr[s] + arr[e] + arr[i] >= sum){
                    e--;
               }
          }
     }

     return count;

}


int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n,sum;
          cin>>n>>sum;
          int count = 0;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          cout<<countTripletsSmallerThanX(arr,n,sum)<<endl;
     }

     return 0;
}
