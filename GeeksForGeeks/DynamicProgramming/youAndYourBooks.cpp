/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are requried to complete this method */
int max_Books(int a[], int n, int k)
{

    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = 0;
    }
    if(a[0] <= k)
        dp[0] = a[0];

    for(int i = 1; i < n; i++){
        if(a[i] <= k){
            dp[i] = a[i] + dp[i-1];
        }
    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[i]);
    }
    return ans;

}
