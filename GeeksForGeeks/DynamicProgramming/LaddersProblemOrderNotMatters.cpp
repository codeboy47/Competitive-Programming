#include <bits/stdc++.h>
using namespace std;

int waysTopDown(int n, int level, bool *h){

    if(n < 0)  return 0;

    if(n == 0){
        if(!h[level]){
            h[level] = true;
            return 1; // add only diff levels
        }
        return 0;
    }

    return waysTopDown(n-1,level+1,h) + waysTopDown(n-2,level+1,h);
}

int shortcut(int n){
    return n/2 + 1;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        bool h[100];
        memset(h,false,sizeof(bool)*100);
        int n;
        cin>>n;
        //cout<<waysTopDown(n,0,h)<<endl;
        cout<<shortcut(n)<<endl;
    }
    return 0;
}
