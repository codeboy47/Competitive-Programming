// C++ program to print all primes smaller than or equal to
// n using Segmented Sieve

#include <iostream>
#include <cmath>
using namespace std;

int simpleSieve(int limit, int prime[],int c){
    int i,j;
    bool arr[limit+1];
    for(i=0;i<limit;i++){
        arr[i] = true;
    }

    for(i=2;i*i<limit;i++){  // not including 11 for limit = 11 and n = 100
        if(arr[i] == true){
            for(j=2*i;j<limit;j=j+i){
                arr[j] = false;
            }
        }
    }
    i = 0;
    for(j=2;j<limit;j++){
        if(arr[j] == true){
            prime[i] = j;
            c++;
            i++;
            cout<<j<<" ";
        }
    }

    return c;
}

void segmentedSieve(int n){
    int i,j;
    int limit = floor(sqrt(n))+1;
    int prime[n];
    //cout<<sizeof(prime)/sizeof(prime[0])<<"ddd";
    int size = simpleSieve(limit,prime,0);
    //cout<<"size="<<size;
    int low = limit;
    int high = 2*limit; /// i.e if n = 100 ,limit = 11, low =11, high = 22 that is segment difference is 11
    while(low < n){
       bool mark[limit+1];
       for(i=0;i<limit;i++){
            mark[i] = true;
       }
       for(i=0;i<size;i++){
            int loLim = floor(low/prime[i])*prime[i];
            if(loLim < low)
                loLim = loLim + prime[i];
            //if(mark[i] == true)
            for(j = loLim; j < high; j = j + prime[i]){
                mark[j-low] = false;
            }
       }
       for(j = low; j < high; j++){
                if(mark[j-low] == true)
                    cout<<j<<" ";
        }
        low = low + limit;
        high = high + limit;
       	if (high >= n) high = n;
    }
}

int main(){

    int n;
    cin>>n;
    segmentedSieve(n);

    return 0;
}

