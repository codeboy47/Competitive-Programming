#include<iostream>
using namespace std;

int noOfZeros(int n){
    static int c = 0,i = 0;
    if(n != 0){
        i = n%10;
        if(i == 0){
            c++;
        }
        return noOfZeros(n/10);
    }else return c;
}
/*
int noOfZeros(int n){
    int i = 0,c = 0;
    while(n!=0){
        i = n%10;
        if(i == 0){
            c++;
        }
        n = n/10;
    }
    return c;
}
*/
int main(){
    int n;
    cin>>n;
    cout<<noOfZeros(n);
    return 0;
}
