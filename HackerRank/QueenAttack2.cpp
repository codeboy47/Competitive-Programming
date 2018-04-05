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
    int k;
    cin >> n >> k;
    int rQ;
    int cQ;
    cin >> rQ >> cQ;  // coordinates of Queen
    
    int countTotal=0,countR=0,countL=0,countUp=0,countDown=0,countNW=0,countSE=0,countNE=0,countSW=0;
    int prevR=0,prevL=0,prevUp=0,prevDown=0,prevNW=0,prevSE=0,prevNE=0,prevSW=0;
    
    countR    = n - cQ;
    countL    = cQ - 1;
    countUp   = n - rQ;
    countDown = rQ - 1;
    
    if(rQ+cQ > n) {
        countNW = n - rQ;
        countSE = n - cQ;
    }  
    if(rQ + cQ <= n){
        countNW = cQ - 1;
        countSE = rQ - 1;
    }    
    if(rQ > cQ){
        countNE = n - rQ;
        countSW = cQ - 1;
    }   
    if(rQ <= cQ){
        countNE = n - cQ;
        countSW = rQ - 1;
    }       
    
    for(int a0 = 0; a0 < k; a0++){
        int rO;
        int cO;
        cin >> rO >> cO;  // coordinates of obstacle
        
        if(cO > cQ && rO == rQ){  // right
            prevR = cO - cQ - 1;
            if(prevR < countR){
                countR = prevR;
            }
        }
        if(cO < cQ && rO == rQ){  // left
            prevL = cQ - cO - 1;
            if(prevL < countL){
                countL = prevL;
            }
        }
        if(rO > rQ && cO == cQ){  // Up
            prevUp = rO - rQ - 1;
            if(prevUp < countUp){
                countUp = prevUp;
            }
        }
        if(rO < rQ && cO == cQ){  // Down
            prevDown = rQ - rO - 1;
            if(prevDown < countDown){
                countDown = prevDown;
            }
        }
        if(rO > rQ && rO+cO == rQ+cQ){  // NW
            prevNW = rO - rQ - 1;
            if(prevNW < countNW){
                countNW = prevNW;
            }
        }
        if(cO > cQ && rO+cO == rQ+cQ){  // SE
            prevSE = cO - cQ - 1;
            if(prevSE < countSE){
                countSE = prevSE;
            }
        }
        if(rO > rQ && rO-rQ == cO-cQ){  // NE
            prevNE = rO - rQ - 1;
            if(prevNE < countNE){
                countNE = prevNE;
            }
        }
        if(rO < rQ && rO-rQ == cO-cQ){  // SW
            prevSW = rQ - rO - 1;
            if(prevSW < countSW){
                countSW = prevSW;
            }
        }
    }
//cout<<countR<<endl<<countL<<endl<<countUp<<endl<<countDown<<endl<<countNW<<endl<<countSE<<endl<<countNE<<endl<<countSW;
    countTotal = countR + countL + countUp + countDown + countNW + countSE + countNE + countSW;
    cout<<countTotal;
    return 0;
}
