#include <bits/stdc++.h>
#include <string.h>
using namespace std;


// make array that stores index of element which is greater than current element
int main(){

     long n,q;
     long arr[10000001];
     scanf("%ld %ld",&n,&q);
     for(long i = 0; i < n; i++){
          scanf("%ld", &arr[i]);
     }
     for(long i = 0; i < q; i++){
          long c,index,k,l,r,x;
          scanf("%ld", &c);
          if(c == 1){
               scanf("%ld %ld", &index, &k);
               long jumps = 0;
               long startingIndex;
               long j = index-1;
               bool flag = true;
               while(jumps < k){
                    if(j == n-1){
                         break;
                    }
                    else if(arr[j] < arr[j+1]){
                         j++;
                    }
                    else{
                         startingIndex = j;
                         while(j < n-1 && arr[startingIndex] >= arr[j+1]){
                              j++;
                              if(j-startingIndex >= 100){
                                   flag = false;
                                   break;
                              }
                         }
                         if(flag == false){
                              break;
                         }
                         if(j == n-1){
                              flag = false;
                              break;
                         }
                         j++;
                    }

                    jumps++;
               }

               if(!flag){
                    cout<<startingIndex+1<<endl;
               }
               else{
                    printf("%ld\n", j+1);
               }
          }
          else{
               scanf("%ld %ld %ld", &l, &r, &x);
               for(long j = l-1; j < r; j++){
                    arr[j] += x;
               }

          }
     }

     return 0;
}
