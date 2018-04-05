#include <iostream>
#include <string.h>
using namespace std;

int main(){

     int  t;
     int n;
     int arr[10000];
     bool temp[1001];

     cin>>t;
     while(t--){

          memset(temp,false,sizeof(temp));
          cin>>n;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          for(int i = 0; i < n; i++){
               temp[arr[i]] = true;
          }

          int fp = -1,sp = -2;
          cout<<"[ ";
          for(int i = 0; i < 1000; ){
               int j = i;
               for(; j < 1000 && temp[j] == false; ){
                    j++;
               }

               if(i == j-1 && temp[i] == false)
                    cout<<i<<" ";
                else if(i != j)
                    cout<<i<<"-"<<j-1<<" ";
               i = j+1;

          }
          cout<<"]"<<endl;
     }

     return 0;
}
