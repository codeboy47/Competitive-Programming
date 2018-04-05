#include <bits/stdc++.h>
using namespace std;

// recursive approach
int findMinSteps(int i, int step, int d){

    if(i == d){
        return 0;
    }

    if(abs(i) > d){
        return 10000;
    }

    int left = findMinSteps(i+step,step+1,d) + 1;

    int right = findMinSteps(i-step,step+1,d) + 1;

    return min(left,right);
}

// O(n) approach
int findMinSteps2(int d){

    int i = 0, step = 0;
    while(i < d){
        step++;
        i += step;
    }

    if((i-d)&1)
        step++;

    return step;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int destination;
        cin>>destination;

        cout<<findMinSteps2(destination)<<endl;

    }

    return 0;
}
