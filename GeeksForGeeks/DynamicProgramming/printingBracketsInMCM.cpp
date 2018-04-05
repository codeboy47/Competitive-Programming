#include <bits/stdc++.h>
using namespace std;


void printBrackets(int i, int j, vector<vector<int>> bracket, char& name)
{
    //cout<<i<<" "<<j<<endl;
    if(i==j)
    {
        cout<<name++;
        return;
    }

    cout<<"(";
    printBrackets(i, bracket[i][j],  bracket, name);
    printBrackets(bracket[i][j] + 1, j,  bracket, name);
    cout<<")";
}

// bottom up
int minIterations2(int *a, int n){

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<vector<int>> bracket(n, vector<int>(n, 0));


    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }

    for(int L=2;L<n;L++)
    {
        for(int i=1;i<n-L+1;i++)
        {
            int j = i+L-1;

            for(int k=i;k<j;k++)
            {
                int val = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];
                if(dp[i][j] > val)
                {
                    dp[i][j] = val;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    printBrackets(1, n-1, bracket, name);
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int arr[10000];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        minIterations2(arr,n);
        cout<<endl;

    }

    return 0;
}
