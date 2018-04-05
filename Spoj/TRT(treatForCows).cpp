#include <bits/stdc++.h>
using namespace std;

// recursive approach
int maxPrice(int price[], int start, int end, int year){
    //Base case, stop when star of array becomes more than end.
    if(start > end)
        return 0;

    //Including the wine with starting index in our solution
    int incStart = price[start] * year + maxPrice(price,start + 1, end, year + 1);

    //Including the wine with ending index in our solution
    int incEnd = price[end] * year + maxPrice(price, start, end-1, year + 1);

    //return the most optimal answer
    return max(incStart, incEnd);
}

// bottom up dp
int maxPriceDP(int *price, int n){

    int dp[n][n];

    //Initialize the dp array
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            dp[i][j] = 0;
            //cout<<dp[i][j]<<" ";
        }
    }

    int year = n;
    for(int k = 0; k < n; k++){
        int i = 0;
        for(int j = k; j < n; i++,j++){
            if(i == j){
                dp[i][j] = year*price[i];
            }
            else{
                dp[i][j] = max(price[i]*year + dp[i+1][j], price[j]*year + dp[i][j-1]);
            }
        }
        year--;
    }


    return dp[0][n-1];
}
int main(){

    int n;
    cin>>n;
    int arr[10000];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<maxPrice(arr,0,n-1,1)<<endl;
    cout<<maxPriceDP(arr,n)<<endl;

    return 0;
}
