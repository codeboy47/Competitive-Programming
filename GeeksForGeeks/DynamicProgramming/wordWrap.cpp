#include <bits/stdc++.h>
using namespace std;

void printSolution(int *p, int n){

    if(p[n] != 1){
        printSolution(p,p[n]-1);
    }

    cout<<p[n]<<" "<<n<<" ";

    return;
}

void wordWrap(int *arr, int n, int m){

    int extras[n+1][n+1]; // for storing extra spaces
    int lC[n+1][n+1]; // line cost

    int cost[n+1];

    int print[n+1]; // for storing solution

    // we 1st calculate extra spaces in single line
    for(int i = 1; i <= n; i++){
        extras[i][i] = m - arr[i-1];
        for(int j = i+1; j <= n; j++){
            extras[i][j] = extras[i][j-1] - arr[j-1] - 1;
        }
    }

    // we calculate line cost of each line
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(extras[i][j] < 0){
                lC[i][j] = INT_MAX;
            }
            else if(j == n && extras[i][j] >= 0){
                lC[i][j] = 0;
            }
            else{
                lC[i][j] = extras[i][j]*extras[i][j];
            }
        }
    }

    // calculate total cost from 1 to j and store words
    cost[0] = 0;
    for(int j = 1; j <= n; j++){
        cost[j] = INT_MAX;
        for(int i = 1; i <= j; i++){
            if(lC[i][j] != INT_MAX && cost[i-1] != INT_MAX && cost[j] > cost[i-1] + lC[i][j]){
                cost[j] = cost[i-1] + lC[i][j];
                print[j] = i;
            }
        }
    }

    printSolution(print,n);
    cout<<endl;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n; // no of words

        cin>>n;

        int arr[10000];
        for(int i = 0; i < n; i++){
            cin>>arr[i]; // contains word width of each word
        }

        int m; // max no of characters allowed per length
        cin>>m;

        wordWrap(arr,n,m);

    }

    return 0;
}
