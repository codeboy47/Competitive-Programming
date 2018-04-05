#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
    
int main(){
    long long int n;
    long long int i=1,count = 0;
    scanf("%lld",&n);
    vector<long long int> a(n);
   
    for(long long int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
 
    while(1){
        const long long int c = 1e9+7;
        i = i%c;
        for(long long int j = 0;j < n;j++){
            if(a[j]%i == 0){
                count++;
            }
        }
        if(count == n-1){
            printf("%lld",i);
            break;
        }
        count = 0;
        i = i + 1;
    }
    return 0;
}

