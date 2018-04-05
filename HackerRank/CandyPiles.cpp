#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n,small = INT_MAX,count = 0;
    cin >> n; // no of piles
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i]; // candies in piles
    }
    for(int c_i = 0; c_i < n; c_i++){
        small = min(small,c[c_i]); // candies in piles
    }
    for(int c_i = 0; c_i < n; c_i++){
        if(small == c[c_i]){
            count++;
        }
    }
    if(count == 1){
        int j = small;
        small = small*2;
        for(int c_i = 0; c_i < n; c_i++){
            if(j != c[c_i])
            small = min(small,c[c_i]); // candies in piles
        }
        cout<<small<<" "<<1;
  
    }else{
        cout<<small<<" "<<n;
    }
    
    return 0;
}
