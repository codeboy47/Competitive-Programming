#include<iostream>
using namespace std;
int solution(int X,int Y,int D){
    long long int s;
    long double sol;
    s=Y-X;
    sol=Y-X;
    s=s/D;
    sol=sol/D;
    if(sol>s)
        return s+1;
    else return s;
}
int main(){
    int x,y,d;
    cin>>x;
    cin>>y;
    cin>>d;
    cout<<"steps taken by frog to reach target are "<<solution(x,y,d)<<endl;
}
