#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;


int maxDivisible(int y, int x){
    int a = x;
    while(y%a == 0){
        y = y/x;
    }
    return y;
}

bool isUgly(int i){
    i = maxDivisible(i,2);
    i = maxDivisible(i,3);
    i = maxDivisible(i,5);
    return i == 1 ? true : false;
}

int findUglyNumbers(int n){
    int count  = 1;
    int i = 1;
    while(count < n){
        i++;
        if(isUgly(i)){
            count++;
        }
    }
    return i;
}


int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;

          cout<<findUglyNumbers(n)<<endl;


     }

     return 0;
}
