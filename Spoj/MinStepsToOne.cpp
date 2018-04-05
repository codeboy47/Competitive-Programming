#include <bits/stdc++.h>
using namespace std;

/*
On a positive integer, you can perform any one of the following 3 steps. 1.) Subtract 1 from it. 2)
If its divisible by 2, divide by 2. 3) If its divisible by 3, divide by 3.
Now the question is, given a positive integer n, find the minimum number of steps that takes n to 1.
*/

// recursion
int minStepsToOne(int n){

    if(n < 1) return INT_MAX;
    if(n == 1) return 0;

    int sub = INT_MAX;
    int divBy2 = INT_MAX;
    int divBy3 = INT_MAX;

    sub = minStepsToOne(n-1);

    if(n%2==0)
        divBy2 = minStepsToOne(n/2);

    if(n%3==0)
        divBy3 = minStepsToOne(n/3);

    return 1 + min(sub,min(divBy2,divBy3));
}

// bottom up
void minStepsToOne2(int *dp, int N_MAX){

    dp[0] = 0;
    dp[1] = 0;


    for(int i = 2; i <= N_MAX; i++){

        dp[i] = 1 + dp[i-1];
        if(i%2 == 0){
            dp[i] = min(dp[i],1 + dp[i/2]);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i],1 + dp[i/3]);
        }
    }

}


int main(){

    const int N_MAX = 20000001;
	int *dp = new int[N_MAX];
    minStepsToOne2(dp,N_MAX);

	int t;
	cin>>t;
	for(int i = 0; i < t; i++){
	    int n;
	    cin>>n;
	    cout<<"Case "<<i+1<<": "<<dp[n]<<endl;
	}
    return 0;
}
