#include <bits/stdc++.h>
using namespace std;

int main(){

     long t;
     cin>>t;
     long arr[10000000];
     while(t--){
          long d,n;
          cin>>n>>d;
          for(long i = 0; i < n; i++){
               cin>>arr[i];
          }

          long sum = 0;
          for(int i = 0; i < n; i++){
               sum = sum + arr[i];
          }

          if(sum%n != 0){
               cout<<-1<<endl;
          }
          else{
               long av = sum/n;
               //cout<<av<<endl;
               long count = 0;
               for(long i = 0; i < n-d; i++){
                    if(arr[i] < av){
                         count += av - arr[i];
                         arr[i+d] = arr[i+d] - av + arr[i];
                         arr[i] = arr[i] + av - arr[i];
                    }
                    else if(arr[i] > av){

                         count = count + arr[i] - av;
                         //cout<<count<<" ";
                         arr[i+d] = arr[i+d] + arr[i] - av;
                         arr[i] = av;
                         //cout<<arr[i+d]<<endl<<av;
                    }
               }
               bool flag = true;
               for(long i = 0; i < n-1; i++){
                    if(arr[i] != arr[i+1]){
                         flag = false;
                         break;
                    }
               }
               if(flag == false){
                    cout<<-1<<endl;
               }else{
                    cout<<count<<endl;
               }
          }

     }

     return 0;
}
