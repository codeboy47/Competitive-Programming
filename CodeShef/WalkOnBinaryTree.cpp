#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


int main(){

     int t,n,q;
     cin>>t;

     while(t--){
          cin>>n>>q;
          long x = 0;
          long visitCount = 0;
          long nodes = (1<<(n+1));
          bool arr[nodes];
          memset(arr,false,sizeof(arr));
          while(q--){

               vector<long> v;
               //int *arr = new bool[nodes];

               char ch;
               cin>>ch;
               if(ch == '!'){
                    long c;
                    cin>>c;
                    long a = (1<<c);
                    long b = (1<<n);
                    x =  (x + a)%b;
				long decNo = x;
                    while(decNo>0){
                         v.push_back(decNo%2);
                         decNo=decNo/2;
                    }

                    while(v.size() < n){
                    	v.push_back(0);
                    }

                    if(arr[1] == false){
                    	arr[1] = true;
                    	visitCount++;
                    }

                    long index = 1;
                    for(long i = v.size()-1; i >= 0; i--){
                    	 if(v[i] == 1){
                              index = 2*index + 1;
                         }
                         if(v[i] == 0){
                              index = 2*index;
                         }
                         if(arr[index] == false){
                         	arr[index] = true;
                              visitCount++;
                         }
                    }
                    v.clear();
               }
               if(ch == '?'){
                    cout<<visitCount<<endl;
               }
          }
     }

     return 0;
}
