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
    bool flag = false;
    int n;
    int c;
    int m;
    cin >> n >> c >> m;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
       cin >> p[i];
    }
    int maxPasng = c*m;
    for(int i = 0; i < n; i++){
       if(p[i] > maxPasng){
           cout<<"No";
           flag = true;
           break;
       }
    }
    if(flag == false)
    cout<<"Yes";
    return 0;
}
