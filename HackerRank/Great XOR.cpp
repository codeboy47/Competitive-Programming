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

long decToBin(long a){
    if(a == 1){
        return 1;
    }
    long ans = decToBin(a/2)*10 + (a%2);
    return ans;
}



long XOR(long I,long X){
    long n = I+X;
    long ans = 0;
    long i =0;
    while(n!=0){
        long t = n%10;
        if(t == 2){
            t = 0;
        }
    
        ans = t*pow(10,i)+ans;
        //cout<<"fd="<<ans;
        i++;
        n = n/10;
        
    }
    return ans;
}

int main(){
    int q;
    long count = 0;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        count = 0;
        for(long i = 1; i < x ; i++){
            long I = decToBin(i);
            long X = decToBin(x);
            //cout<<I<<" "<<X;
            long ANS = XOR(I,X);  // binary
            //cout<<"     ANS="<<ANS;
           /* long ans = binToDec(ANS);   // decimal
            if(x + i > ans){
                count++;
            }*/
            if(ANS > X){
                count++;
                //cout<<"     count = "<<count;
            }
            //cout<<endl;
        }
        
      cout<<count<<endl;
        
    }
    return 0;
}
