#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int *arr, int n){

    int ms = INT_MIN, cs = 0;
    int mstart = 0, mend = 0, cstart = 0, cend = 0;
    bool flag = true;
    for(int i = 0; i < n; i++){

         if(arr[i] < 0){
              cs = 0;
              cstart = i+1;
              cend = i+1;
              flag = false;
         }
         else{
              cs += arr[i];
              if(ms < cs){
                   ms = cs;
                   mstart = cstart;
                   flag = true;
              }
              if(ms == cs){
                   if(i - cstart > mend - mstart){
                        mstart = cstart;
                        mend = i;
                        flag = true;
                   }
              }
              if(flag == true)
                    mend = i;
         }
    }

    //cout<<ms<<endl;

    for(int i = mstart; i <= mend; i++){
        cout<<arr[i]<<" ";
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

          maxSubArraySum(arr,n);

     }

     return 0;
}
