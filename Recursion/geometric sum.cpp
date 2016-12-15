#include<iostream>
using namespace std;

float gm(float k,float s){
    static float i = 1;
    if(i < k){
        s = s + 1/(2*i);
        i = i + 1;
        return gm(k,s);
    }else{
        return s;
    }
}

int main(){
    float k;
    cin>>k;
    cout<<gm(k,1);
    return 0;
}
