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
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long no;
        cin >> no;
        if(no%7 == 0 || no%4 == 0 || no%11 == 0 || no%15==0)
            cout<<"Yes"<<endl;
        else if(no > ((7*4) - 7 - 4)){ /* using Chicken McNugget Theorem 
This theorem states that for two relatively prime integers a, b and non-negative integers x, y, 
the largest number that can not be of the form ax + by is ab - a - b. As a consequence of this theorem,
any number greater than 17 is a lucky number.*/
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
