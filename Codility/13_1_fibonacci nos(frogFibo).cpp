#include<iostream>
using namespace std;
int fibo(int n){
	int c=0,a=0,b=1;
	while(n>=c){
		c=a+b;
		a=b;
		b=c;
		if(c==n)    return 1;
	}
	return 0;
}
int solution(int A[], int N) {
    // write your code in C99
    int i,j=0,f,count=0,sum=N+2,k;
    for(i=0;i<N  ;i++){
        f=fibo(j+1);
        k=fibo(N+1);
        if(k==1)  return 1;
        if(A[i]==1 && f==1){
            sum=sum-(j+1);
            count++;
            j=0;
        }
        j++;
    }
    f=fibo(sum);
    if(f==1){
        sum=0;
        count++;
    }
    //printf("%d",sum);
    if(sum==0) return count;
    else return -1;
}
