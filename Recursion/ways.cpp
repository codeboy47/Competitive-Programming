#include<iostream>
using namespace std;

int ways(int n, int step){
    static int c = 0;
    if(step == n){
        c = c + 1;
        return c;
    }if(step > n) return c;
    c = ways(n,step+1);
    c = ways(n,step+2);
    c = ways(n,step+3);
    return c;
}

int main(){
    int n;
    cin>>n;
    cout<<ways(n,0);
}
