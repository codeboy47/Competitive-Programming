#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long f(long a[],long x,long n,long count){
    if(count == 0){
        return x;
    }
    for(long i = 1;i <= n;i++){
        if(x == a[i]){
            return f(a,i,n,count-1);
        }
    }
    return x;
}

int main() {
    long n,a[100000];
    //cout<<"dhfjjf";
    cin>>n;
    for(long i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(long i = 1;i <= n;i++){
        cout<<f(a,i,n,2)<<endl;
        //cout<<a[i]<<endl;
    }
    return 0;
}
