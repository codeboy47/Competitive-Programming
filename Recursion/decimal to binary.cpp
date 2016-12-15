#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int n){
    static int i=0, power=1;
    if(n==0) return i;
    else{
        i = i + (n%2)*power;
        power = power*10;
        decimalToBinary(n/2);
    }
    return i;
}
/*
int decimalToBinary(int n){
    int i=0, power=1;
    while(n!=0){
        i = i + (n%2)*power;
        power = power*10;
        n = n/2;
    }
    return i;
}
*/
int main(){
    int n;
    cin>>n;
    cout<<decimalToBinary(n);
    return 0;
}
