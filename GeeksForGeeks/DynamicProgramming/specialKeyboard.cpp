#include <bits/stdc++.h>
using namespace std;

/*
The task is to find out the break=point after which we get the above suffix of keystrokes.
Definition of a breakpoint is that instance after which we need to only press
Ctrl-A, Ctrl-C once and the only Ctrl-V’s afterwards to generate the optimal length.
*/

int findoptimal(int N){

    if (N <= 6)
        return N;

    int dp[N+1];


    int i;
    for (i = 0; i <= 6; i++)
        dp[i] = i;

    // Solve all subproblems in bottom manner
    for (i = 7; i <= N; i++) {

        dp[i] = 0;

        for (int b = i-1; b >= 3; b--){

            dp[i] = max(dp[i],(i-b+2)*dp[b-3]);

        }
    }

    return dp[N];
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        cout<<findoptimal(n)<<endl;


    }

    return 0;
}
