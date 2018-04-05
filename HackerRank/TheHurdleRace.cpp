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
    int n;
    int l = INT_MIN;
    int k;
    cin >> n >> k;
    //int height[100000];
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    for(int i = 0;i < n; i++){
         l = max(l,height[i]);
    }
    //cout<<l<<" l";
    if(k > l){
        cout<<0;
    }else{
        cout<<l-k;
    }
    // your code goes here
    return 0;
}
