///Find longest sequence of zeros in binary representation of an integer

#include<iostream>
#include<cmath>
using namespace std;
int solution (int N) {
    int i=1,j=0,r=0,sum=0,a[100],c=0,l=0;
    while(N>0) {
        r = N % 2;
        sum = sum + i*r;
        a[j] = r;
        N = N/2;
        i*= 10;
        j++;
    }
    cout<<sum<<endl;
    for (i=0;i<j;i++) {
        if(a[i]==0 ) {
            c++;
            if(c>l){
                l=c;
            }
        }
        else
            c=0;
    }
    if(l!=0)
        return l;
    else
        return 0;
}
int main () {
    int N;
    cin>>N;
    cout<<endl<<solution(N);
    return 0;
}
