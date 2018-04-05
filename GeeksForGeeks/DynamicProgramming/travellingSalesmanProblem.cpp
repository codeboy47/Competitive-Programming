/*
Given a matrix M of size N where M[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[10000][1000];

// top down dp approach
// time and space complexity is O(2^n * n)
int tsp(int arr[][1000], int n, int index, int mask){

    if(mask == (1<<n)-1){
        return arr[index][0];
    }

    if(dp[mask][index] != -1){
        return dp[mask][index];
    }

    int dist = INT_MAX;
    for(int i = 0; i < n ; i++){
        if(index != i && ((mask>>i) & 1) == 0){
            dist = min(dist, arr[index][i] + tsp(arr,n,i,mask|(1<<i)));
        }
    }

    return dp[mask][index] = dist;

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int arr[1000][1000];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>arr[i][j];
            }
        }


        for(int i = 0; i < (1<<n); i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }

        cout<<tsp(arr,n,0,1)<<endl;
    }

    return 0;
}
