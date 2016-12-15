#include<iostream>
using namespace std;
/*
int lcm(int a,int b){
    int l = a;
    while(1){
        if(l%a==0 && l%b==0){
            break;
        }
        l++;
    }
    return l;
}
*/

int lcm(int a,int b){
    static int l = a;
    if(l%a==0 && l%b==0) return l;
    else{
        l++;
        return lcm(a,b);
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a>b) cout<<lcm(a,b);
    else cout<<lcm(b,a);
    return 0;
}
