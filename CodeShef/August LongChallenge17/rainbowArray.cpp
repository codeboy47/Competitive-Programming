#include <bits/stdc++.h>
using namespace std;

int main(){

     int t;
     scanf("%d", &t);
     while(t--){
          int n;
          int arr[10000];
          scanf("%d", &n);
          for(int i = 0; i < n ; i++){
               scanf("%d", &arr[i]);
          }

          int s = 0, e = n-1;
          int counter  = 1;
          bool flag = true;
          while(s <= e){
               if(counter-1 == arr[s]){
                    counter--;
               }
               if(arr[s] != arr[e] || arr[s] != counter || arr[e] != counter){
                    flag = false;
                    break;
               }
               s++;
               e--;
               counter++;
          }

          if(flag == true && counter == 8){
               cout<<"yes"<<endl;
          }else{
               cout<<"no"<<endl;
          }
     }
     return 0;
}
