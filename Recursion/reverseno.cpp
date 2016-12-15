#include<iostream>
using namespace std;

int reverse(int n,int i){
    static int y = 0;
    if(i != 0){
        y = i%10;
        n = n*10 + y;
        return reverse(n,i/10);
    }else{
        return n;
    }

}

int main(){
    int n;
    cin>>n;
    cout<<reverse(0,n);
}
