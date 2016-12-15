#include<iostream>
using namespace std;

int sumOfDigits(int n,int i){
    static int y;
    if(i != 0){
        y = i%10;
        n = n + y;
        return sumOfDigits(n,i/10);
    }else{
        return n;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<sumOfDigits(0,n);
}
