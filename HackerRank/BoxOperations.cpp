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
    int n,l,r,op,i,j,sum=0,small = 100000;
    float no;
    int q;
    cin >> n >> q;
    int box[100000];
    //vector<int> box(n);
    for(int box_i = 0; box_i < n; box_i++){
       cin >> box[box_i];
    }
    for(i = 0;i<q;i++){
        cin>>op;
        if(op == 1){
            cin>>l>>r>>no;
            for( j = l;j <= r;j++){
                box[j] = box[j] + no;
                //cout<<box[j]<<" ";
            }  
        }
        if(op == 2){
            cin>>l>>r>>no;
            for( j = l;j <= r;j++){
                //if(no < 0) no = no*(-1);
                box[j] = floor(box[j]/no);
                //if(floor(box[j]) != box[j])
                //box[j] = floor(box[j]);
                //cout<<box[j]<<" ";
            }  
        }
        if(op == 3){
            cin>>l>>r;
            for( j = l;j <= r;j++){
                small = min(box[j],small);
                //sum = sum + box[j];
            }
            cout<<small<<endl;
        }
        if(op == 4){
            cin>>l>>r;
            for( j = l;j <= r;j++){
                sum = sum + box[j];
            }
            cout<<sum<<endl;
            
        }
        sum = 0;
        small = 100000;
        
    }
    // your code goes here
    return 0;
}
