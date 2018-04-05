/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


int findMaxCoins(int A[], int i, int j){

    if(i > j){
        return 0;
    }

    if(i == j){
        return A[i];
    }

    return max( A[i] + min(findMaxCoins(A,i+1,j-1),findMaxCoins(A,i+2,j)),
                               A[j] + min(findMaxCoins(A,i+1,j-1),findMaxCoins(A,i,j-2)) );

}

// bottom up approach
int findMaxCoins2(int A[], int n){

    int dp[n][n];

    for(int k = 0; k < n; k++){
        int i = 0;
        for(int j = k; j < n; i++,j++){
            if(i == j){
                dp[i][j] = A[i];
            }
            else if(j - i == 1){
                dp[i][j] = max(A[i],A[j]);
            }
            else{
                dp[i][j] = max(A[i] + min(dp[i+1][j-1],dp[i+2][j]), A[j] + min(dp[i+1][j-1],dp[i][j-2]) );
            }
        }
    }

    return dp[0][n-1];
}

/*You are required to complete below method */
int maxCoins(int A[],int N)
{
    return findMaxCoins2(A,N);
}
